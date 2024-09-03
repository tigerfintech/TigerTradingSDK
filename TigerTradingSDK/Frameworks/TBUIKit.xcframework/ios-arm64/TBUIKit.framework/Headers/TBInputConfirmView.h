//
//  TBInputConfirmView.h
//  Stock
//
//  Created by yangfan on 2017/3/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBCommonConfirmView.h"

@interface TBInputConfirmView : TBCommonConfirmView

@property (nonatomic, strong) UITextField           * textField;

@property (nonatomic, assign) int           textFieldMaxLength;
@end
