//////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//  File:       pchfx.h
//  Content:    D3D shader effects precompiled header
//
//////////////////////////////////////////////////////////////////////////////

#pragma once


#include <d3d11.h>

//#include <d3dx11.h>

#pragma region // Instead of <d3dx11.h> //
#include <cfloat>

#ifndef D3DX11INLINE
#ifdef _MSC_VER
  #if (_MSC_VER >= 1200)
  #define D3DX11INLINE __forceinline
  #else
  #define D3DX11INLINE __inline
  #endif
#else
  #ifdef __cplusplus
  #define D3DX11INLINE inline
  #else
  #define D3DX11INLINE
  #endif
#endif
#endif
#pragma endregion

#undef DEFINE_GUID
#include <INITGUID.h>
#include "d3dx11effect.h"

#define UNUSED (-1)

//////////////////////////////////////////////////////////////////////////

#define offsetof_fx( a, b ) (UINT)offsetof( a, b )

#include "d3dxGlobal.h"

#include <stddef.h>
#include <strsafe.h> // We cannot use ANSI version string helpers compiling for Windows Store App.

#include "Effect.h"
#include "EffectStateBase11.h"
#include "EffectLoad.h"

#include <D3DCompiler.h>

//////////////////////////////////////////////////////////////////////////

namespace D3DX11Effects
{
} // end namespace D3DX11Effects
