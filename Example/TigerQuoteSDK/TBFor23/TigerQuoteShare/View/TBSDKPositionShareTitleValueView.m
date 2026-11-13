//
//  TBSDKPositionShareTitleValueView.m
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/12.
//

#import "TBSDKPositionShareTitleValueView.h"
#import <TBBaseKit/TBBaseKit.h>
#import <TBUIKit/TBUIKit.h>
#if __has_include(<TBShareKit/TBCardShareDefine.h>)
#import <TBShareKit/TBCardShareDefine.h>
#endif

@implementation TBSDKPositionShareTitleValueView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
#if __has_include(<TBShareKit/TBCardShareDefine.h>)
        _valueLabel = [[UILabel alloc] initWithFont:MEDFONTO(12) color:COLOR_CARD_SHARE(1)];
        _titleLabel = [[UILabel alloc] initWithFont:MEDFONTO_NOADJUST(10) color:COLOR_CARD_SHARE(0.6)];
#endif
        _titleLabel.numberOfLines = 0;
        
        _titleLabel.textAlignment = _valueLabel.textAlignment = NSTextAlignmentCenter;
        
        [self addSubview:_titleLabel];
        [self addSubview:_valueLabel];
        
        _titleLabel.minimumScaleFactor = 0.50;
        _valueLabel.minimumScaleFactor = 0.50;
        
        [_valueLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(self);
            make.leading.equalTo(self.mas_leading).offset(10);
            make.trailing.equalTo(self.mas_trailing).offset(-10);
            make.height.equalTo(@15);
        }];
        [_titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(_valueLabel.mas_bottom).offset(3);
            make.leading.trailing.equalTo(_valueLabel);
            make.bottom.equalTo(self);
        }];
    }
    return self;
}

- (void)setTextColorValue:(NSInteger)textColorValue {
    self.valueLabel.textColor = RGBACOLOR_HEX(textColorValue, 1);
    self.titleLabel.textColor = RGBACOLOR_HEX(textColorValue, 0.6);
}

@end
