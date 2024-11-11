//
//  TBStockImageBox.h
//  Stock
//
//  Created by 王灵博 on 2020/5/8.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBCommonConfirmView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockImageBox : TBCommonConfirmView
-(instancetype)initWithImage:(UIImage *)image;
@property (nonatomic, copy) void(^onTapBox)(TBCommonConfirmView * confirmView);
@end

NS_ASSUME_NONNULL_END
