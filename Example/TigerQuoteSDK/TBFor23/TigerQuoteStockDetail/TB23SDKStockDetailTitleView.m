//
//  TB23SDKStockDetailTitleView.m
//  TigerQuoteSDK_Example
//
//  Created by chenxin on 2025/9/12.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TB23SDKStockDetailTitleView.h"
#import <TBUIKit/TBUIKit.h>

@interface TB23SDKStockDetailTitleView ()

@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, strong) UILabel *timeLabel;

@property (nonatomic, strong) UILabel *priceLabel;

@property (nonatomic, strong) UIScrollView *scrollView;

@end

@implementation TB23SDKStockDetailTitleView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.titleLabel = [[UILabel alloc] initWithFont:MEDFONTO(14) color:COLOR_TEXT_COMMON];
        
        self.timeLabel = [[UILabel alloc] initWithFont:FONTO(13) color:COLOR_TITLE];
        self.priceLabel = [[UILabel alloc] initWithFont:FONTO(13) color:COLOR_TITLE];
        
        self.scrollView = [[UIScrollView alloc] init];
        self.scrollView.showsVerticalScrollIndicator = NO;
        self.scrollView.scrollEnabled = NO;
        
        [self addSubview:self.titleLabel];
        [self addSubview:self.scrollView];
        [self.scrollView addSubview:self.timeLabel];
        [self.scrollView addSubview:self.priceLabel];
        
        [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.mas_equalTo(0);
            make.top.mas_equalTo(0);
        }];
        [self.scrollView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.trailing.mas_equalTo(0);
            make.top.equalTo(self.titleLabel.mas_bottom);
            make.bottom.mas_equalTo(0);
        }];
        [self.timeLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.trailing.top.mas_equalTo(0);
            make.height.equalTo(self.scrollView);
        }];
        [self.priceLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.trailing.bottom.mas_equalTo(0);
            make.top.equalTo(self.timeLabel.mas_bottom);
            make.height.equalTo(self.scrollView);
        }];
        
        UIImage *image = TBIconFontImage(TBIconTriangleDown, 18, TB_Icon_Primary);
        UIImageView *iconImageView = [[UIImageView alloc] initWithImage:image];
        iconImageView.contentMode = UIViewContentModeScaleAspectFit;
        [iconImageView setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];
        [self addSubview:iconImageView];
        [iconImageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.equalTo(self.titleLabel.mas_trailing);
            make.centerY.equalTo(self.titleLabel);
            make.trailing.mas_lessThanOrEqualTo(0);
        }];
    }
    return self;
}

- (void)setTitle:(NSString *)title {
    _title = title;
    self.titleLabel.text = title;
}

- (void)setTime:(NSString *)time {
    _time = time;
    self.timeLabel.text = time;
}

- (void)setShouldShowPrice:(BOOL)shouldShowPrice {
    _shouldShowPrice = shouldShowPrice;
    if (shouldShowPrice) {
        [self.scrollView setContentOffset:CGPointMake(0, self.timeLabel.tb_height)];
    }
    else {
        [self.scrollView setContentOffset:CGPointZero];
    }
}

- (void)setAttributedPrice:(NSAttributedString *)attributedPrice {
    self.priceLabel.attributedText = attributedPrice;
}

@end
