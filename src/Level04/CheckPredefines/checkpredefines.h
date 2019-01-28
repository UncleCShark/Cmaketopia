/* MSVC check predefined macros for gnu compilers use build-in option: gcc -E -xc++ -dM /dev/null*/
/* https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=vs-2017 */

#define __STRINGVALUE__(x) #x
#define __VALUE__(x) __STRINGVALUE__(x)
#define __PPOUT__(x) "#define " #x " " __VALUE__(x)

#if defined(_ATL_VER)
#pragma message(__PPOUT__(_ATL_VER))
#endif

#if defined(__ATOM__)
#pragma message(__PPOUT__(__ATOM__))
#endif

#if defined(__AVX__)
#pragma message(__PPOUT__(__AVX__))
#endif

#if defined(__AVX2__)
#pragma message(__PPOUT__(__AVX2__))
#endif


#if defined(_CHAR_UNSIGNED)
#pragma message(__PPOUT__(_CHAR_UNSIGNED))
#endif

#if defined(__CLR_VER)
#pragma message(__PPOUT__(__CLR_VER))
#endif

#if defined(_CONTROL_FLOW_GUARD)
#pragma message(__PPOUT__(_CONTROL_FLOW_GUARD))
#endif

#if defined(__COUNTER__)
#pragma message(__PPOUT__(__COUNTER__))
#endif

#if defined(__cplusplus)
#pragma message(__PPOUT__(__cplusplus))
#endif

#if defined(__cplusplus_cli)
#pragma message(__PPOUT__(__cplusplus_cli))
#endif

#if defined(__cplusplus_winrt )
#pragma message(__PPOUT__(__cplusplus_winrt ))
#endif

#if defined(_CPPLIB_VER)
#pragma message(__PPOUT__(_CPPLIB_VER))
#endif
#if defined(_CPPRTTI)
#pragma message(__PPOUT__(_CPPRTTI))
#endif

#if defined(_CPPUNWIND )
#pragma message(__PPOUT__(_CPPUNWIND))
#endif

#if defined(__DATE__ )
#pragma message(__PPOUT__(__DATE__))
#endif

#if defined(_DEBUG )
#pragma message(__PPOUT__(_DEBUG))
#endif

#if defined(_DLL )
#pragma message(__PPOUT__(_DLL))
#endif

#if defined(__FILE__ )
#pragma message(__PPOUT__(__FILE__))
#endif

#if defined(__FUNCDNAME__)
#pragma message(__PPOUT__(__FUNCDNAME__))
#endif

#if defined(__FUNCSIG__)
#pragma message(__PPOUT__(__FUNCSIG__))
#endif

#if defined(__FUNCTION__ )
#pragma message(__PPOUT__(__FUNCTION__))
#endif

#if defined(_INTEGRAL_MAX_BITS )
#pragma message(__PPOUT__(_INTEGRAL_MAX_BITS))
#endif

#if defined(__INTELLISENSE__)
#pragma message(__PPOUT__(__INTELLISENSE__))
#endif

#if defined(_ISO_VOLATILE)
#pragma message(__PPOUT__(_ISO_VOLATILE))
#endif

#if defined(_KERNEL_MODE)
#pragma message(__PPOUT__(_KERNEL_MODE))
#endif

#if defined(__LINE__ )
#pragma message(__PPOUT__(__LINE__))
#endif

#if defined(_M_ALPHA )
#pragma message(__PPOUT__(_M_ALPHA))
#endif

#if defined(_M_AMD64 )
#pragma message(__PPOUT__(_M_AMD64))
#endif

#if defined(_M_ARM )
#pragma message(__PPOUT__(_M_ARM))
#endif

#if defined(_M_ARM_ARMV7VE )
#pragma message(__PPOUT__(_M_ARM_ARMV7VE))
#endif

#if defined(_M_ARM_FP )
#pragma message(__PPOUT__(_M_ARM_FP))
#endif

#if defined(_M_ARM64 )
#pragma message(__PPOUT__(_M_ARM64))
#endif

#if defined(_M_CEE )
#pragma message(__PPOUT__(_M_CEE))
#endif

#if defined(_M_CEE_PURE)
#pragma message(__PPOUT__(_M_CEE_PURE))
#endif

#if defined(_M_CEE_SAFE)
#pragma message(__PPOUT__(_M_CEE_SAFE))
#endif

#if defined(_M_FP_EXCEPT)
#pragma message(__PPOUT__(_M_FP_EXCEPT))
#endif

#if defined(_M_FP_FAST)
#pragma message(__PPOUT__(_M_FP_FAST))
#endif

#if defined(_M_FP_PRECISE)
#pragma message(__PPOUT__(_M_FP_PRECISE))
#endif

#if defined(_M_FP_STRICT)
#pragma message(__PPOUT__(_M_FP_STRICT))
#endif

#if defined(_M_IX86)
#pragma message(__PPOUT__(_M_IX86))
#endif

#if defined(_M_IA64)
#pragma message(__PPOUT__(_M_IA64))
#endif

#if defined(_M_IX86_FP )
#pragma message(__PPOUT__(_M_IX86_FP))
#endif

#if defined(_M_MPPC)
#pragma message(__PPOUT__(_M_MPPC))
#endif

#if defined(_M_MRX000)
#pragma message(__PPOUT__(_M_MRX000))
#endif

#if defined(_M_PPC )
#pragma message(__PPOUT__(_M_PPC))
#endif

#if defined(_M_X64 )
#pragma message(__PPOUT__(_M_X64))
#endif

#if defined(_MANAGED )
#pragma message(__PPOUT__(_MANAGED))
#endif

#if defined(_MFC_VER )
#pragma message(__PPOUT__(_MFC_VER))
#endif

#if defined(_MSC_BUILD )
#pragma message(__PPOUT__(_MSC_BUILD))
#endif

#if defined(_MSC_EXTENSIONS)
#pragma message(__PPOUT__(_MSC_EXTENSIONS))
#endif

#if defined(_MSC_FULL_VER)
#pragma message(__PPOUT__(_MSC_FULL_VER))
#endif

#if defined(_MSC_VER )
#pragma message(__PPOUT__(_MSC_VER))
#endif

#if defined(_MSVC_LANG )
#pragma message(__PPOUT__(_MSVC_LANG))
#endif

#if defined(__MSVC_RUNTIME_CHECKS)
#pragma message(__PPOUT__(__MSVC_RUNTIME_CHECKS))
#endif

#if defined(_MT)
#pragma message(__PPOUT__(_MT))
#endif

#if defined(_NATIVE_WCHAR_T_DEFINED)
#pragma message(__PPOUT__(_NATIVE_WCHAR_T_DEFINED))
#endif

#if defined(_OPENMP)
#pragma message(__PPOUT__(_OPENMP))
#endif

#if defined(_PREFAST_)
#pragma message(__PPOUT__(_PREFAST_))
#endif

#if defined(__STDC__)
#pragma message(__PPOUT__(__STDC__))
#endif

#if defined(_STDC_HOSTED__)
#pragma message(__PPOUT__(_STDC_HOSTED__))
#endif

#if defined(__TIME__)
#pragma message(__PPOUT__(__TIME__))
#endif

#if defined(__TIMESTAMP__)
#pragma message(__PPOUT__(__TIMESTAMP__))
#endif

#if defined(_VC_NODEFAULTLIB )
#pragma message(__PPOUT__(_VC_NODEFAULTLIB))
#endif

#if defined(_WCHAR_T_DEFINED )
#pragma message(__PPOUT__(_WCHAR_T_DEFINED))
#endif

#if defined(_WIN32 )
#pragma message(__PPOUT__(_WIN32))
#endif

#if defined(_WIN64 )
#pragma message(__PPOUT__(_WIN64))
#endif

#if defined(_WINRT_DLL )
#pragma message(__PPOUT__(_WINRT_DLL))
#endif

#if defined(_Wp64)
#pragma message(__PPOUT__(_Wp64))
#endif
