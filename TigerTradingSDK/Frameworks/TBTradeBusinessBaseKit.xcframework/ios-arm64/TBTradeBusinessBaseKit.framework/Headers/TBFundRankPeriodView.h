//
//  TBFundRankPeriodView.h
//  TBFundMall
//
//  Created by wind on 2023/2/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFundRankPeriodView : UIView

@property (nonatomic, copy) NSArray *titles;
@property (nonatomic, assign) NSInteger selectedIndex;
@property (nonatomic, copy) void (^changeIndex)(NSInteger selectedIndex);

@end

NS_ASSUME_NONNULL_END
