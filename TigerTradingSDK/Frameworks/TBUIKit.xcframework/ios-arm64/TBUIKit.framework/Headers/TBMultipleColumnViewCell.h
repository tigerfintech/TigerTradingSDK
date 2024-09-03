//
//  TBMultipleColumnTableViewCell.h
//  TBTradeBusiness
//
//  Created by chenxin on 2024/5/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMultipleColumnViewCell : UIView

@property (nonatomic, strong) UIView *contentView;

@property (nonatomic, strong) UILabel *topLabel;

@property (nonatomic, strong) UILabel *bottomLabel;

@property (nonatomic, assign) NSTextAlignment textAlignment;

@property (nonatomic, assign) BOOL hasBottomLabel;

@property (nonatomic, strong) void(^actionBlock)(void);

@end

NS_ASSUME_NONNULL_END
