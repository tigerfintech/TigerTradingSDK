//
//  UIDevice+TBKNetwork.h
//  TigerBrokersKit
//
//  Created by donggf on 2018/8/21.
//

#import <UIKit/UIKit.h>

@interface UIDevice (TBKNetwork)

/*
 * @method uuid
 * @description apple identifier support iOS6 and iOS5 below
 */
- (NSString *)tbk_macaddress;

- (NSString *)tbk_macaddressMD5;
- (NSString *)tbk_machineType;
- (NSString *)tbk_ostype; // 显示“ios6，ios5”，只显示大版本号

@end
