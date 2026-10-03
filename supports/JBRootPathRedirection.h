//
//  JBRootPathRedirection.h
//  TrollSpeed
//
//  Shared path redirection helpers, used by both the app and the preference bundle.
//
//  roothide's headers replaced the classic ROOT_PATH / JBROOT_PATH family with the
//  unified jbroot() / rootfs() API. When <roothide.h> is around it deliberately
//  #undefs those legacy macros and redefines them as compile errors, so simply
//  guarding a redefinition with #ifndef silently keeps the poisoned version and
//  every reference fails with "Please upgrade to the roothide APIs".
//
//  Redefining them on top of jbroot() keeps the call sites untouched and resolves
//  the jailbreak root correctly for rootful, rootless and roothide packages alike.
//

#ifndef HUD_JBROOT_PATH_REDIRECTION_H
#define HUD_JBROOT_PATH_REDIRECTION_H

#include <TargetConditionals.h>

#if !TARGET_OS_SIMULATOR && !defined(DISABLE_PATH_REDIRECTION)
    #if __has_include(<roothide.h>)
        #import <roothide.h>
        #undef JBROOT_PATH_CSTRING
        #undef JBROOT_PATH_NSSTRING
        #define JBROOT_PATH_CSTRING(cPath) jbroot(cPath)
        #define JBROOT_PATH_NSSTRING(nsPath) jbroot(nsPath)
    #elif __has_include(<libroot/libroot.h>)
        /* libroot already defines JBROOT_PATH_CSTRING / JBROOT_PATH_NSSTRING. */
        #import <libroot/libroot.h>
    #else
        #define JBROOT_PATH_CSTRING(cPath) cPath
        #define JBROOT_PATH_NSSTRING(nsPath) nsPath
    #endif
#else
    #define JBROOT_PATH_CSTRING(cPath) cPath
    #define JBROOT_PATH_NSSTRING(nsPath) nsPath
#endif

#endif /* HUD_JBROOT_PATH_REDIRECTION_H */