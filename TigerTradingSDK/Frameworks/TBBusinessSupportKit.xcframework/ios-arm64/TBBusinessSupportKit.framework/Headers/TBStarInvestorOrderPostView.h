//
//  TBStarInvestorOrderPostView.h
//  TBBusinessSupportKit
//
//  Created by F.S. on 2023/12/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStarInvestorOrderPostView : UIView

@property (nonatomic, copy) NSString *shareReason;

@property (nonatomic, assign) CGFloat theViewWidth;
@property (nonatomic, assign) CGFloat theViewHeight; // 通过计算得出

- (void)updateStarInvestorPostView;

@end

NS_ASSUME_NONNULL_END
