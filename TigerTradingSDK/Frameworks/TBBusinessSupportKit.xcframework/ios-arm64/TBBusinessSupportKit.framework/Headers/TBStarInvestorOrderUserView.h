//
//  TBStarInvestorOrderUserView.h
//  TBBusinessSupportKit
//
//  Created by F.S. on 2023/12/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStarInvestorOrderUserView : UIView

@property (nonatomic, copy) NSString *avatarStr;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *vIntroduction;

@property (nonatomic, assign) CGFloat theViewHeight;
@property (nonatomic, assign) CGFloat theViewWidth;

- (void)updateStarInvestorUserView;

@end

NS_ASSUME_NONNULL_END
