//
//  TBSNShareView.h
//  TBTradeBusinessBaseKit
//
//  Created by dulijun on 2023/11/20.
//

#import <UIKit/UIKit.h>
#import "TBSNShareModel.h"

#define TB_SN_SHARE_TEXT_COLOR(a) RGBACOLOR_HEX(0x993D0F, a)

NS_ASSUME_NONNULL_BEGIN

@interface TBSNShareView : UIView

- (UIImage *)createImageWithModel:(TBSNShareModel *)model;
@property (nonatomic, strong) UIView *contentView; // 用于存放顶部二维码与底部日期之间的内容

// 生成分享图片（子类重写该方法，添加自定义ui到contentView）
- (void)setupContentViewsWithModel:(TBSNShareModel *)model;

@end

NS_ASSUME_NONNULL_END
