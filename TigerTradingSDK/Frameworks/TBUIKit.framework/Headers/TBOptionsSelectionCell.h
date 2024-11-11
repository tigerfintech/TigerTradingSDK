//
//  TBPlaceOrderBriefDurationTableViewCell.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2022/4/26.
//  撤销前有效

#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@class TBRoundedCornerActionTypeView;

@interface TBOptionsSelectionCell : TBTableViewCell

@property (nonatomic, strong, readonly) TBRoundedCornerActionTypeView *typeView;

- (void)initSubViews;

- (void)initSubLayouts;

@end


NS_ASSUME_NONNULL_END
