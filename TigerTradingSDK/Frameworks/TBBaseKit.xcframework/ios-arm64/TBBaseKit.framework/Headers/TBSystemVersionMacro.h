//
//  TBSystemVersionMacro.h
//  Pods
//
//  Created by zhengzhiwen on 2021/4/19.
//

#ifndef TBSystemVersionMacro_h
#define TBSystemVersionMacro_h
#import "TBPhoneUtility.h"

#define IS_IOS8                                             ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0 && [[[UIDevice currentDevice] systemVersion] floatValue] < 9.0)
#define DEVICE_OS_VERSION                                   [[[UIDevice currentDevice] systemVersion] floatValue]
#define TBAvalibleOS(x)                                     ([[[UIDevice currentDevice] systemVersion] floatValue] >= (x))

#define TB_IS_UNDER_IOS_VERSION(versionInt) ([[[UIDevice currentDevice] systemVersion] floatValue] < (versionInt))

#define TB_IS_UNDER_IOS7 TB_IS_UNDER_IOS_VERSION(7)
#define TB_IS_UNDER_IOS8 TB_IS_UNDER_IOS_VERSION(8)
#define TB_IS_UNDER_IOS9 TB_IS_UNDER_IOS_VERSION(9)
#define TB_IS_UNDER_IOS10 TB_IS_UNDER_IOS_VERSION(10)
#define TB_IS_UNDER_IOS11 TB_IS_UNDER_IOS_VERSION(11)
#define TB_IS_UNDER_IOS12 TB_IS_UNDER_IOS_VERSION(12)

#define TB_TRADEUP_UNCONFIRMED_ASSERT                                     [TBPhoneUtility tradeUPAssert]


#endif /* TBSystemVersionMacro_h */
