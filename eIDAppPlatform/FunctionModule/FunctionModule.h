// FunctionModule.h

#pragma once

#include "winscard.h"

using namespace System;

namespace FunctionModule {

	public ref class ReaderDriver
	{
		// TODO: �ڴ˴���Ӵ���ķ�����
	public:

		long lRet;

		SCARDCONTEXT hContextHandle;

		SCARDHANDLE hCardHandle;

		DWORD dwReaderLength;

		array<char>^ cReaderList;


	public:

		long getReaderList(){

			dwReaderLength = 0;

			cli::pin_ptr<SCARDCONTEXT> lphContextHandle = &hContextHandle;
			cli::pin_ptr<DWORD> lpdwReaderLength = &dwReaderLength; 
			

			lRet = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, lphContextHandle);
			if(lRet != SCARD_S_SUCCESS){
				return lRet;
			}

			lRet = SCardListReaders(hContextHandle, SCARD_ALL_READERS, NULL, lpdwReaderLength);
			if(lRet != SCARD_S_SUCCESS){
				return lRet;
			}

			cReaderList = gcnew array<char>(dwReaderLength);
			cli::pin_ptr<char> pcReaderList = &cReaderList[0];
			lRet = SCardListReaders(hContextHandle, SCARD_ALL_READERS, (LPTSTR)pcReaderList, lpdwReaderLength);
			if(lRet != SCARD_S_SUCCESS){
				return lRet;
			}

			return lRet;
		}
	};
}
