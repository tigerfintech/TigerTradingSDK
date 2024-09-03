//
//  TBCardShareTabView.h
//  TBShareKit
//
//  Created by dulijun on 2023/4/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCardShareTabView : UIView

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIImageView *iconImageView;
@property (nonatomic, assign) BOOL isSelected;// 当前是否为选中状态

@end

NS_ASSUME_NONNULL_END
