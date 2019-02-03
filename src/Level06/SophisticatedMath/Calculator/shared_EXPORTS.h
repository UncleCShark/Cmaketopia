#ifndef _SHARED_EXPORTS_H__
#define _SHARED_EXPORTS_H__

#if defined(_WIN32) && defined(DLL_BUILD)
    #ifdef shared_EXPORTS
        #define SHARED_EXPORT __declspec(dllexport)
    #else
        #define SHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define SHARED_EXPORT
#endif

#endif /* _SHARED_EXPORTS_H__ */