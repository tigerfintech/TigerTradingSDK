//
//  TBFundDetailBannerCell.h
//  TBFundMall
//
//  Created by wind on 2023/6/16.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFundDetailBannerCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray *materialList;
@property (nonatomic, copy) void(^bannerCloseBlock)(NSArray *materialList);

@property (nonatomic, assign) BOOL isLargeModel;

@property (nonatomic, strong) UIColor *bgColor;
@property (nonatomic, assign) BOOL timerEnabled;

@end

@interface TBFundDetailBannerCell : TBTableViewCell

- (void)updateTimerStatus;

@end


NS_ASSUME_NONNULL_END
