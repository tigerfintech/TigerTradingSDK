//
//  TBCardShareView.h
//  TBShareKit
//
//  Created by dulijun on 2023/4/13.
//

#import <UIKit/UIKit.h>
#import "TBCardShareDefine.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBCardShareView : UIView

@property (nonatomic, assign) NSInteger shareType; // 分享的业务类型（如：持仓盈亏比例、持仓盈亏金额。。。）
@property (nonatomic, strong) UILabel *descriptionLabel;  //文字描述
@property (nonatomic, strong) UIImageView *stickerImageView;// 表情
@property (nonatomic, strong) UIButton *editButton;
@property (nonatomic, assign) NSInteger contentIndex; // 卡片文案index（取值范围0~25）
@property (nonatomic, copy) NSString *descriptionText; // 卡片文案内容
@property (nonatomic, copy) NSString *qrLinkUrl; // 二维码链接
@property (nonatomic, copy) NSString *shareText; // 二维码图前的文案
@property (nonatomic, strong) NSMutableDictionary *saDicationary; // 埋点数据（父类中已添加：签名、水印、表情包、文案。其余的子类自行添加）

@property (nonatomic, strong) UIImageView *logoImageView;
@property (nonatomic, strong) UIView *qrImageBackgroundView;
@property (nonatomic, strong) UIImageView *qrImageView;
@property (nonatomic, strong) UILabel *shareTextLabel;
@property (nonatomic, strong) UILabel *dateLabel;
@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UIView *waterMarkView;
@property (nonatomic, strong) UIButton *nicknameButton;
@property (nonatomic, strong) UIButton *nameIconButton;
@property (nonatomic, strong) UIButton *watermarkButton;
@property (nonatomic, assign) BOOL isEditingDisabled; // 是否禁用编辑（表情、表情上方文案）。默认NO：不禁用
@property (nonatomic, assign) CGFloat cardShareViewControllerWidth;

#pragma mark - public

// 生成图片，并显示
- (UIImage *)createImageFromCardViewAndShowInFront;


/// 卡片view高度 (目前生成的卡片view高度都一致，后期如果有高度不同的，在子类中重写该方法返回新值)
/// - Parameter width: cardview所在vc的view.width
- (CGFloat)cardViewHeightWithWidth:(CGFloat)width;

#pragma mark - 给子类调用
/// 返回卡片背景色
/// - Parameters:
///   - index: 表情包index（注意是表情包index，取值范围1~26）
///   - shareType: 分享类型
- (UIColor *)cardBackgroundColorWithIndex:(NSInteger)index withShareType:(TBCardShareType)shareType;

/// 返回卡片中文字颜色
/// - Parameters:
///   - index: 表情包index（注意是表情包index，取值范围1~26）
///   - shareType: 分享类型
- (NSInteger)textColorWithIndex:(NSInteger)index withShareType:(TBCardShareType)shareType;

- (void)setImageAndDescWithNumber:(double)number;

/// 根据表情包索引更新卡片背景色、文字颜色（子类中如果有这些原色，可以先调父类这个方法）
/// - Parameter index: 表情包索引（1~26）
- (void)updateCardBackgroundColorAndTextColorWithStickerIndex:(NSInteger)index;

#pragma mark - 如果子类需要显示表情包，则要重写该方法，返回分享值type（通过这个类型和对应的值，获取表情包）
- (TBCardShareValueType)cardShareValueType;

// stickerTest
@property (nonatomic, strong) UITextField *valueTextField;
- (void)updateMainValue;

@end

NS_ASSUME_NONNULL_END
