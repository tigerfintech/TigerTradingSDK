//
//  TBCombineOptionQuoteItemView.h
//  TBStockBusiness
//
//  Created by 骆鹏飞 on 2024/6/12.
//

#import <UIKit/UIKit.h>
@class TBOptionChainAskBidRetModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBCombineOptionQuoteItemView : UIView

@property (nonatomic, strong) TBOptionChainAskBidRetModel *model;

- (void)updateUIWithModel:(TBOptionChainAskBidRetModel *)model market:(NSString *)market;

@end

NS_ASSUME_NONNULL_END
