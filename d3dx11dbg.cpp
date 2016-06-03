///////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//  File:       d3dx11dbg.cpp
//  Content:    D3DX11 Effects debugging functions
//
///////////////////////////////////////////////////////////////////////////

#include "pchfx.h"


#ifdef FXDPF

//
// DPF
//

void cdecl D3DXDebugPrintf(UINT lvl, LPCSTR szFormat, ...)
{
    static UINT uDebugLevel = static_cast<UINT>(-1);

	char strA[4096] = {};
    char strB[4096] = {};

	va_list ap = NULL;
    va_start(ap, szFormat);
	vsprintf_s(strA, szFormat, ap);
	strA[ARRAYSIZE(strA) - 1] = '\0';
    va_end(ap);

	sprintf_s(strB, "Effects11: %s\r\n", strA);

    strB[ARRAYSIZE(strB) - 1] = '\0';

    OutputDebugStringA(strB);
}
#else
// This is defined so warning LNK4211 is not generated (object file has no public symbols)
void cdecl D3DXDebugPrintf(UINT lvl, LPCSTR szFormat, ...) {}
#endif


//
// D3DXASSERT
//

#ifdef _DEBUG

int WINAPI D3DXDebugAssert(LPCSTR szFile, int nLine, LPCSTR szCondition)
{
	char str[512] = {};

    // Print message to debug console
	sprintf_s(str, "Assertion failure! (%s %d): %s\r\n", szFile, nLine, szCondition);
    str[511] = 0;
    OutputDebugStringA(str);

    return 0;
}
#endif

