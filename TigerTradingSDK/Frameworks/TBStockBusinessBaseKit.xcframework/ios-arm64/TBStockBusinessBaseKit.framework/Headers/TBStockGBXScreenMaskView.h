//
//  TBStockGBXScreenMaskView.h
//  Stock
//
//  Created by CharmingQin on 2019/3/1.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockDetailGBXScreenMaskDelegate <NSObject>

- (void)tapUnderlineText;

@end


@interface TBStockGBXScreenMaskView : UIView
- (instancetype)initWithBaseRect:(CGRect)rect;

@property (nonatomic, weak) id<TBStockDetailGBXScreenMaskDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
