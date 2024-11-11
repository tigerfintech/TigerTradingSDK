//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * SDK definitions useful in availability checks for conditionally compiling code.
 *
 * Example:
 *
 *     #if __IPHONE_OS_VERSION_MAX_ALLOWED >= TBKIOS_3_2
 *       // This code will only compile on versions >= iOS 3.2
 *     #endif
 *
 * These macros are defined unconditionally and separately from the __IPHONE_* macros
 * because there might be methods that use the #ifdef state of one of the __IPHONE_ macros
 * to conditionally compile their code (however incorrect this may be).
 */
#define TBKIOS_2_0     20000
#define TBKIOS_2_1     20100
#define TBKIOS_2_2     20200
#define TBKIOS_3_0     30000
#define TBKIOS_3_1     30100
#define TBKIOS_3_2     30200
#define TBKIOS_4_0     40000
#define TBKIOS_4_1     40100
#define TBKIOS_4_2     40200
#define TBKIOS_4_3     40300
#define TBKIOS_4_4     40400
#define TBKIOS_5_0     50000
#define TBKIOS_5_1     50100
#define TBKIOS_6_0     60000
#define TBKIOS_6_1     60100
#define TBKIOS_7_0     70000
#define TBKIOS_7_1     70100
#define TBKIOS_8_0     80000
#define TBKIOS_8_1     80100
#define TBKIOS_8_2     80200
#define TBKIOS_8_3     80300
#define TBKIOS_8_4     80400
#define TBKIOS_9_0     90000
#define TBKIOS_9_1     90100
#define TBKIOS_9_2     90200
#define TBKIOS_9_3     90300
#define TBKIOS_10_0   100000
#define TBKIOS_10_1   100100
#define TBKIOS_10_2   100200
#define TBKIOS_10_3   100300
#define TBKIOS_11_0   110000
#define TBKIOS_11_1   110100
#define TBKIOS_11_2   110200
#define TBKIOS_11_3   110300
#define TBKIOS_11_4   110400
#define TBKIOS_12_0   120000

/**
 * Flesh out the known SDK version numbers.
 */
#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_2_0
#define kCFCoreFoundationVersionNumber_iPhoneOS_2_0 478.23
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_2_1
#define kCFCoreFoundationVersionNumber_iPhoneOS_2_1 478.26
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_2_2
#define kCFCoreFoundationVersionNumber_iPhoneOS_2_2 478.29
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_3_0
#define kCFCoreFoundationVersionNumber_iPhoneOS_3_0 478.47
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_3_1
#define kCFCoreFoundationVersionNumber_iPhoneOS_3_1 478.52
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_3_2
#define kCFCoreFoundationVersionNumber_iPhoneOS_3_2 478.61
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_4_0
#define kCFCoreFoundationVersionNumber_iOS_4_0 550.32
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_4_1
#define kCFCoreFoundationVersionNumber_iOS_4_1 550.38
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_4_2
#define kCFCoreFoundationVersionNumber_iOS_4_2 550.52
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_4_3
#define kCFCoreFoundationVersionNumber_iOS_4_3 550.52
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_5_0
#define kCFCoreFoundationVersionNumber_iOS_5_0 675.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_5_1
#define kCFCoreFoundationVersionNumber_iOS_5_1 690.10
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_6_0
#define kCFCoreFoundationVersionNumber_iOS_6_0 793.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_6_1
#define kCFCoreFoundationVersionNumber_iOS_6_1 793.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_7_0
#define kCFCoreFoundationVersionNumber_iOS_7_0 847.20
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_7_1
#define kCFCoreFoundationVersionNumber_iOS_7_1 847.24
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_8_0
#define kCFCoreFoundationVersionNumber_iOS_8_0 1140.1
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_8_1
#define kCFCoreFoundationVersionNumber_iOS_8_1 1141.14
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_8_2
#define kCFCoreFoundationVersionNumber_iOS_8_2 1142.16
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_8_3
#define kCFCoreFoundationVersionNumber_iOS_8_3 1144.17
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_8_4
#define kCFCoreFoundationVersionNumber_iOS_8_4 1145.15
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_8_x_Max
#define kCFCoreFoundationVersionNumber_iOS_8_x_Max 1199
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_9_0
#define kCFCoreFoundationVersionNumber_iOS_9_0 1240.1
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_9_1
#define kCFCoreFoundationVersionNumber_iOS_9_1 1241.11
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_9_2
#define kCFCoreFoundationVersionNumber_iOS_9_2 1242.13
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_9_3
#define kCFCoreFoundationVersionNumber_iOS_9_3 1242.13
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_9_4
#define kCFCoreFoundationVersionNumber_iOS_9_4 1280.38
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_9_x_Max
#define kCFCoreFoundationVersionNumber_iOS_9_x_Max 1299
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_10_0
#define kCFCoreFoundationVersionNumber_iOS_10_0 1348.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_10_1
#define kCFCoreFoundationVersionNumber_iOS_10_1 1348.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_10_2
#define kCFCoreFoundationVersionNumber_iOS_10_2 1348.22
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_10_3
#define kCFCoreFoundationVersionNumber_iOS_10_3 1349.56
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_11_0
#define kCFCoreFoundationVersionNumber_iOS_11_0 1443.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_11_1
#define kCFCoreFoundationVersionNumber_iOS_11_1 1445.32
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_11_2
#define kCFCoreFoundationVersionNumber_iOS_11_2 1450.14
#endif

// NSFoundationVersionNumber
#ifndef NSFoundationVersionNumber_iPhoneOS_2_0
#define NSFoundationVersionNumber_iPhoneOS_2_0    678.24
#endif

#ifndef NSFoundationVersionNumber_iPhoneOS_2_1
#define NSFoundationVersionNumber_iPhoneOS_2_1  678.26
#endif

#ifndef NSFoundationVersionNumber_iPhoneOS_2_2
#define NSFoundationVersionNumber_iPhoneOS_2_2  678.29
#endif

#ifndef NSFoundationVersionNumber_iPhoneOS_3_0
#define NSFoundationVersionNumber_iPhoneOS_3_0  678.47
#endif

#ifndef NSFoundationVersionNumber_iPhoneOS_3_1
#define NSFoundationVersionNumber_iPhoneOS_3_1  678.51
#endif

#ifndef NSFoundationVersionNumber_iPhoneOS_3_2
#define NSFoundationVersionNumber_iPhoneOS_3_2  678.60
#endif

#ifndef NSFoundationVersionNumber_iOS_4_0
#define NSFoundationVersionNumber_iOS_4_0  751.32
#endif

#ifndef NSFoundationVersionNumber_iOS_4_1
#define NSFoundationVersionNumber_iOS_4_1  751.37
#endif

#ifndef NSFoundationVersionNumber_iOS_4_2
#define NSFoundationVersionNumber_iOS_4_2  751.49
#endif

#ifndef NSFoundationVersionNumber_iOS_4_3
#define NSFoundationVersionNumber_iOS_4_3  751.49
#endif

#ifndef NSFoundationVersionNumber_iOS_5_0
#define NSFoundationVersionNumber_iOS_5_0  881.00
#endif

#ifndef NSFoundationVersionNumber_iOS_5_1
#define NSFoundationVersionNumber_iOS_5_1  890.10
#endif

#ifndef NSFoundationVersionNumber_iOS_6_0
#define NSFoundationVersionNumber_iOS_6_0  992.00
#endif

#ifndef NSFoundationVersionNumber_iOS_6_1
#define NSFoundationVersionNumber_iOS_6_1  993.00
#endif

#ifndef NSFoundationVersionNumber_iOS_7_0
#define NSFoundationVersionNumber_iOS_7_0 1047.20
#endif

#ifndef NSFoundationVersionNumber_iOS_7_1
#define NSFoundationVersionNumber_iOS_7_1 1047.25
#endif

#ifndef NSFoundationVersionNumber_iOS_8_0
#define NSFoundationVersionNumber_iOS_8_0 1140.11
#endif

#ifndef NSFoundationVersionNumber_iOS_8_1
#define NSFoundationVersionNumber_iOS_8_1 1141.1
#endif

#ifndef NSFoundationVersionNumber_iOS_8_2
#define NSFoundationVersionNumber_iOS_8_2 1142.14
#endif

#ifndef NSFoundationVersionNumber_iOS_8_3
#define NSFoundationVersionNumber_iOS_8_3 1144.17
#endif

#ifndef NSFoundationVersionNumber_iOS_8_4
#define NSFoundationVersionNumber_iOS_8_4 1144.17
#endif

#ifndef NSFoundationVersionNumber_iOS_8_x_Max
#define NSFoundationVersionNumber_iOS_8_x_Max 1199
#endif

#ifndef NSFoundationVersionNumber_iOS_9_0
#define NSFoundationVersionNumber_iOS_9_0 1240.1
#endif

#ifndef NSFoundationVersionNumber_iOS_9_1
#define NSFoundationVersionNumber_iOS_9_1 1241.14
#endif

#ifndef NSFoundationVersionNumber_iOS_9_2
#define NSFoundationVersionNumber_iOS_9_2 1242.12
#endif

#ifndef NSFoundationVersionNumber_iOS_9_3
#define NSFoundationVersionNumber_iOS_9_3 1242.12
#endif

#ifndef NSFoundationVersionNumber_iOS_9_4
#define NSFoundationVersionNumber_iOS_9_4 1280.25
#endif

#ifndef NSFoundationVersionNumber_iOS_9_x_Max
#define NSFoundationVersionNumber_iOS_9_x_Max 1299
#endif

/**
 * Checks whether the device's OS version is at least the given version number.
 *
 * @param versionNumber Any value of kCFCoreFoundationVersionNumber from above.
 */
BOOL TBKDeviceOSVersionIsAtLeast(double versionNumber);

/**
 * Use NSClassFromString to fetch the popover controller class.
 *
 * The class is cached to avoid repeated lookups.
 */
Class TBKUIPopoverControllerClass(void);

