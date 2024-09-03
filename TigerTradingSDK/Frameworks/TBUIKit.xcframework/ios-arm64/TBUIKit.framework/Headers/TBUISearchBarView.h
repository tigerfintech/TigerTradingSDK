//
//  TBUISearchBarView.h
//  TBUIKit
//
//  Created by linbingjie on 2023/7/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    TBUISearchColorType_A1,
    TBUISearchColorType_A4
} TBUISearchColorType;

@interface TBUISearchBarView : UIView

/// SearchBar底层颜色根据superview的背景颜色是不同的 （默认使用A1，开发根据UI设置）
/// - Parameter colorType: type
- (void)updateUIWithSuperBGColor:(TBUISearchColorType)colorType;

/// 更新是否可编辑状态，编辑状态可直接通过 UIView 的 userInteractionEnabled 获取
- (void)updateUserInteractionStatus:(BOOL)enabled;

/// 设置searchbar的placeholder
- (void)updateSearchBarPlaceHolder:(NSString *)placeHolder;

/// dismiss显示与否需要通过这个api触发
- (void)dismissButtonHidden:(BOOL)isHidden;

// 外部自己处理searchbar的delegate逻辑
@property (nonatomic, strong) UISearchBar *searchBar;
// 外部自己处理button的相关action逻辑
@property (nonatomic, strong) UIButton *dismissBtn;

@end

NS_ASSUME_NONNULL_END
