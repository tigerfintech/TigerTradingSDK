//
//  TBPasswordConfirmView.h
//  Stock
//
//  Created by yangfan on 2018/7/13.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import "TBCommonConfirmView.h"

@interface TBPasswordConfirmView : TBCommonConfirmView

@property (nonatomic, copy) NSString * message;
@property (nonatomic, copy, readonly) NSString * password;

@end
