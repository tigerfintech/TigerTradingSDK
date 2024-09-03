//
//  TBStockDetailOrderEditPriceView.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/17.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBOrderTextField.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailOrderEditPriceView : UIView
/// 编辑回调
@property (nonatomic, copy) void(^textFieldCallBack)(NSString * text, BOOL isEditing);

@property (nonatomic, copy) NSNumber *(^futureStringToNumber)(NSString * text);
@property (nonatomic, copy) NSString *(^futureNumberToString)(NSNumber * text);
@property (nonatomic, strong) id /*<TBStockDetailInfoDataSource>*/ secInfo;


@property (nonatomic, copy) void(^textFieldEndEditingCallBack)(NSString * text);

@property (nonatomic, copy) void(^textFieldBecomeFirstResponser)(void);

/// 价格格式化
@property (nonatomic, strong) NSNumberFormatter *priceFormatter;

/// 是否可编辑
@property (nonatomic, assign, getter=isEditAble) BOOL editAble;

- (void)updateContent:(NSString *)title value:(NSString *)value;

@property (nonatomic, assign) double leftMinimumPriceVariation;///<
@property (nonatomic, assign) double rightMinimumPriceVariation;///<

/// 订单价格：限价单会有该textfield
@property (nonatomic, strong) TBOrderTextField *priceTextField;

/// <#注释#>
@property (nonatomic, copy) NSString *secType;

/// 调整priceTextField的宽度，addedWidth为增加的宽度。> 0时，在原有宽度上增加；< 0时，在原有宽度上减少
- (void)updatePriceTextFieldAddedWidth:(CGFloat)addedWidth;
@end

NS_ASSUME_NONNULL_END
