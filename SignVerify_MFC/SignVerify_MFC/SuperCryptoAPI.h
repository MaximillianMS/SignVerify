#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include "WinCryptEx.h"
namespace SuperCryptoAPI
{
	struct Location { //��������� ������ ������� ��������
		DWORD Id;
		std::wstring sName;
		std::vector<std::wstring> aStores; //������ �������� ��������

	};
	struct ProviderInfo
	{
	public:
		std::wstring       sName;
		DWORD       dwType;
		DWORD       dwIndex;
	};
	struct AlgInfo
	{
	public:
		CString sAlgName;
		CString sType;
		DWORD dwAlgId;
		DWORD dwBits;
	};
	inline BOOL WINAPI CertEnumSystemStoreCallback( const void* pvSystemStore, //������, ������� ��� ���������
		DWORD dwFlags,
		PCERT_SYSTEM_STORE_INFO pStoreInfo,
		void* pvReserved,
		void* pvArg ) {
			DWORD Id=(dwFlags & CERT_SYSTEM_STORE_LOCATION_MASK) >> CERT_SYSTEM_STORE_LOCATION_SHIFT; //�������� id �������
			std::wstring storeName = static_cast<const wchar_t*>( pvSystemStore ); //������� ��� ���������
			std::vector<Location>& aLocations = *reinterpret_cast<std::vector<Location>*>( pvArg ); //������� ������ �������
			for(DWORD i=0;i<aLocations.size();i++)
			{
				if(aLocations.at(i).Id==Id)
				{
					Id=i;
					break;
				}
			}
			aLocations.at(Id).aStores.push_back(storeName);
			return TRUE;
	}
	inline void getStores( std::vector<Location>& aLocations ) { //����� ������ ��������
		for ( DWORD i=0 ;i<aLocations.size();i++) { //������� �� ���� ��������
			Location loc=aLocations.at(i);
			DWORD dwFlags = ( loc.Id << CERT_SYSTEM_STORE_LOCATION_SHIFT ) //������� id ������� � ������ ���
				& CERT_SYSTEM_STORE_LOCATION_MASK;
			::CertEnumSystemStore( dwFlags, nullptr, &aLocations, CertEnumSystemStoreCallback );
		}
	}
	inline BOOL WINAPI CertEnumSystemStoreLocationCallback( LPCWSTR pvszStoreLocations, //������, ������ � ������ ������� ������� �������
		DWORD dwFlags,
		void* pvReserved,
		void* pvArg
		) {
			std::vector<Location>& aLocations = *reinterpret_cast<std::vector<Location>*>( pvArg );
			DWORD Id = ( dwFlags & CERT_SYSTEM_STORE_LOCATION_MASK )
				>> CERT_SYSTEM_STORE_LOCATION_SHIFT;
			Location location = { Id, std::wstring( pvszStoreLocations ) }; //��������� � ������ �������
			aLocations.push_back( location );
			return TRUE;
	}
	inline void getLocations(std::vector<Location> &aLocations)
	{ //�������� ������� ��������
		if ( !::CertEnumSystemStoreLocation( 0x0,
			&aLocations,
			CertEnumSystemStoreLocationCallback ) ) 
		{
			//throw std::runtime_error( "CertEnumSystemStoreLocation" );
		}
		else
		{
			SuperCryptoAPI::getStores(aLocations);
		}
	}
	inline void getProviders(std::vector<ProviderInfo> &aProviders) //��������� ������ �����������������
	{
		DWORD       cbName; //����� �����
		DWORD       dwType; //���
		DWORD       dwIndex;//������
		TCHAR        *pszName = NULL;//��������� ���
		dwIndex = 0;
		while(CryptEnumProviders( //���� ��������������� ����������
			dwIndex,
			NULL,
			0,
			&dwType,
			NULL,
			&cbName
			))
		{
			if (!(pszName = (LPTSTR)LocalAlloc(LMEM_ZEROINIT, cbName))) //�������� ������ ��� ������ 
			{                                                           //��� ���� win api.
				exit(1);
			}
			if (CryptEnumProviders( //��� ��� �������� ���������� � ������� ����������������.
				dwIndex++,
				NULL,
				0,
				&dwType,
				pszName,
				&cbName
				))
			{
				ProviderInfo curProv; //������ � ������ �������� ����������������
				curProv.dwIndex=dwIndex;
				curProv.dwType=dwType;
				curProv.sName=pszName;
				aProviders.push_back(curProv);
			}
			else
			{
				exit(1);
			}
			LocalFree(pszName);//������� ������
		}
	}
	inline void getCerts(std::vector <CERT_CONTEXT> &aCerts, HCERTSTORE pMyStore)
	{
		PCCERT_CONTEXT pCurCert=NULL;
		pCurCert=CertEnumCertificatesInStore(pMyStore, pCurCert);
		while(pCurCert!=NULL)
		{
			aCerts.push_back(*pCurCert);
			pCurCert=CertEnumCertificatesInStore(pMyStore, pCurCert);
		}
	}
	inline std::vector<AlgInfo> getAlgs(HCRYPTPROV hMyProv)
	{
		std::vector<AlgInfo> aAlgs;
		if(hMyProv!=NULL)
		{
			DWORD dwDataLen = 1000;
			for(int i=0 ; ; i++)
			{
				DWORD dwFlags=0x58;
				if(i == 0) 
				{
					dwFlags = CRYPT_FIRST;
					CryptGetProvParam(hMyProv, PP_ENUMALGS_EX, NULL, &dwDataLen, dwFlags);
				} 
				else 
				{
					dwFlags = 0;
				}
				PROV_ENUMALGS_EX pAlg_ex;
				// Retrieve information about an algorithm.
				if(!CryptGetProvParam(hMyProv, PP_ENUMALGS_EX, (BYTE*)&pAlg_ex, &dwDataLen, dwFlags)) {
					if(GetLastError() == ERROR_NO_MORE_ITEMS) 
					{
						// Exit the loop.
						break;
					} 
					else
					{
						return aAlgs;
					}
				}
				// Extract algorithm information from 'pbData' buffer.
				AlgInfo alg1;
				alg1.dwAlgId = pAlg_ex.aiAlgid;
				alg1.dwBits = pAlg_ex.dwDefaultLen;
				auto dwNameLen = pAlg_ex.dwNameLen;
				alg1.sAlgName=pAlg_ex.szName;
				// Determine algorithm type.
				switch(GET_ALG_CLASS(alg1.dwAlgId)) {
				case ALG_CLASS_DATA_ENCRYPT: alg1.sType= _T("Encrypt");
					break;
				case ALG_CLASS_HASH: alg1.sType = _T("Hash");
					break;
				case ALG_CLASS_KEY_EXCHANGE: alg1.sType = _T("Exchange");
					break;
				case ALG_CLASS_SIGNATURE: alg1.sType = _T("Signature");
					break;
				default: alg1.sType = _T("Unknown");
				}
				aAlgs.push_back(alg1);
			}
		}
		return aAlgs;
	}
}