//
//  TBCommunityFocusButton.h
//  TBBusinessSupportKit
//
//  Created by F.S. on 2024/5/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommunityFocusButton : UIButton

@property (nonatomic, strong) UIFont *theFont;
@property (nonatomic, copy) NSString *userId;

@property (nonatomic, strong) UIColor *taTextColor;

@property (nonatomic, assign) BOOL isSearchUI;
@property (nonatomic, assign) BOOL isPostUI;

@property (nonatomic, copy, readonly) NSString *theButtonText; // 展示的文字
@property (nonatomic, assign, readonly) CGFloat theButtonWidth; // 建议宽度
@property (nonatomic, strong, nullable, readonly) NSNumber *status; // 按钮状态

- (void)updateFocusButton:(BOOL)isStarinvestor isFan:(BOOL)isFan isSubcribe:(BOOL)isSubcribe;
- (void)updateFocusButton:(BOOL)isStarinvestor isFan:(BOOL)isFan isHead:(BOOL)isHead isSubcribe:(BOOL)isSubcribe;

+ (NSNumber *)communityFocusButtonStatus:(BOOL)isStarinvestor isFan:(BOOL)isFan isSubcribe:(BOOL)isSubcribe;

@end

NS_ASSUME_NONNULL_END
