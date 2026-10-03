//
//  HUDHelper.h
//  TrollSpeed
//
//  Created by Lessica on 2024/1/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

OBJC_EXTERN BOOL IsHUDEnabled(void);
OBJC_EXTERN void SetHUDEnabled(BOOL isEnabled);

/* Stops a HUD that is still running an older build and brings up the current
   one. Call once when the app comes to the foreground. */
OBJC_EXTERN void HUDReloadIfStale(void);

OBJC_EXTERN NSString *HUDBuildVersionString(void);
OBJC_EXTERN NSString *HUDPidFilePath(void);

#if DEBUG
OBJC_EXTERN void SimulateMemoryPressure(void);
#endif

OBJC_EXTERN NSUserDefaults *GetStandardUserDefaults(void);

NS_ASSUME_NONNULL_END
