#pragma once

#define BLOCKI_UNUSED(PARAM) (void)PARAM

#ifndef BLOCKI_PLATFORM_WIN
	#ifdef _WIN32
		#define BLOCKI_PLATFORM_WIN 1
	#else
		#error Blocki does not yet support this platform.
	#endif
#endif

#ifndef BLOCKI_IMPORT_SYMBOL
	#ifdef BLOCKI_PLATFORM_WIN
		#define BLOCKI_EXPORT_SYMBOL __declspec(dllexport)
		#define BLOCKI_IMPORT_SYMBOL __declspec(dllimport)
	#endif
#endif

#ifndef BLOCKI_BUILD_STATIC
	#ifdef BLOCKI_EXPORTS
		#define BLOCKI_API BLOCKI_EXPORT_SYMBOL
	#else
		#define BLOCKI_API BLOCKI_IMPORT_SYMBOL
	#endif
#else
	#define BLOCKI_API
	#define BLOCKI_STATIC_LINKAGE 1
#endif