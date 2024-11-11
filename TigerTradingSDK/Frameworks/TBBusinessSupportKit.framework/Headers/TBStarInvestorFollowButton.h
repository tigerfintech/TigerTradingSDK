//
//  TBStarInvestorFollowButton.h
//  TBBusinessSupportKit
//
//  Created by F.S. on 2023/12/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStarInvestorFollowButton : UIButton

@property (nonatomic, strong) UIImageView *icon;
@property (nonatomic, strong) UILabel *label;

@property (nonatomic, assign) BOOL isCenterMode;

- (void)updateFollowStatus:(BOOL)isFan;

@end

NS_ASSUME_NONNULL_END
