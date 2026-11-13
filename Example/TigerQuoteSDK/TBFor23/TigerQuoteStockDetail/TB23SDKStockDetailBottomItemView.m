//
//  TB23SDKStockDetailBottomItemView.m
//  TigerQuoteSDK
//
//  Created by chenxin on 2025/9/8.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TB23SDKStockDetailBottomItemView.h"
#import <TBUIKit/TBUIKit.h>

@implementation TB23SDKStockDetailBottomItemView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        
        self.imageView = [[UIImageView alloc] init];
        
        self.titleLabel = [[UILabel alloc] init];
        self.titleLabel.textColor = COLOR_TITLE;
        self.titleLabel.font = MEDFONTO(10);
        self.titleLabel.textAlignment = NSTextAlignmentCenter;
        
        [self addSubview:self.imageView];
        [self addSubview:self.titleLabel];
        [self.imageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(self).offset(4);
            make.centerX.equalTo(self);
            make.height.equalTo(@22);
            make.width.equalTo(@22);
        }];
        
        [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(self.imageView.mas_bottom).offset(4);
            make.leading.trailing.equalTo(self);
        }];
         
    }
    return self;
}

@end
