//
//  TBStockDetailAskBidActivityView.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/1/6.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
//
typedef NS_ENUM(NSUInteger, TBStockDetailAskBidGiftBoxType) {
    TBStockDetailAskBidGiftBoxTypeOne,
    TBStockDetailAskBidGiftBoxTypeTwo,
};

@interface TBStockDetailAskBidActivityView : UIView
@property (nonatomic, assign) TBStockDetailAskBidGiftBoxType giftBoxType;

- (void)startAnimation;
@end

NS_ASSUME_NONNULL_END
