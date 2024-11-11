//
//  TBStockSignalLabelView.h
//  StockBusiness
//
//  Created by liuhuan on 2024/5/20.
//  Copyright © 2024 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockSignalLabelView : UIView

@property (nonatomic, assign) CGFloat maxLabelWidth;

- (void)setLabelImageArray:(NSArray<UIImage *> *)array;

@end

NS_ASSUME_NONNULL_END
