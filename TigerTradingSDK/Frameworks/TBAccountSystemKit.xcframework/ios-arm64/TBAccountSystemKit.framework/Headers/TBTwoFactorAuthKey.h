//
//  TBTwoFactorAuthKey.h
//  Stock
//
//  Created by yangfan on 2018/7/17.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBTwoFactorAuthKey : JSONModel

@property (nonatomic, copy) NSString   * name;
@property (nonatomic, copy) NSString   * uuid;
@property (nonatomic, copy) NSString   * key;

@end
