//
//  TBBaseShareCardView.h
//  TBShareKit
//
//  Created by dulijun on 2023/12/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBBaseShareCardView : UIView

//  顶部：logo 文案 二维码
@property (nonatomic, strong) UIImageView *logoImageView;
@property (nonatomic, strong) UIView *qrImageBackgroundView;
@property (nonatomic, strong) UILabel *shareTextLabel;
@property (nonatomic, strong) UIImageView *qrImageView;

@property (nonatomic, strong) UILabel *mainTitleLabel;  // 主标题
@property (nonatomic, strong) UIImageView *mainImageView;  // 中间大图

@property (nonatomic, strong) UILabel *dateLabel;

@end

NS_ASSUME_NONNULL_END
