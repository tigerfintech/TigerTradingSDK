//
//  TBOptionStrategyBuilderStrategyBuySellView.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionStrategyBuilderStrategyOptionModel;
@class TBOptionStrategyBuilderStrategyStockModel;

@interface TBOptionStrategyBuilderStrategyBuySellView : UIView

@property (nonatomic, copy) void(^switchAction)(void);

@property (nonatomic, copy) void(^onTappedOptionBlock)(void);

@property (nonatomic, strong) TBOptionStrategyBuilderStrategyOptionModel *model;
@property (nonatomic, strong) TBOptionStrategyBuilderStrategyStockModel *stockModel;

@property (nonatomic, assign) BOOL isOptionInfoHighlight;


- (void)setSwitchOn:(BOOL)isOn;

- (void)setIsTopBorder:(BOOL)isTop;

@end

NS_ASSUME_NONNULL_END
