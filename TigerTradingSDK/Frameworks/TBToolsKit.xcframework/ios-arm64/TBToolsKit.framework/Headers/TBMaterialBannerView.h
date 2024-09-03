//
//  TBMaterialBannerView.h
//  TBToolsKit
//
//  Created by chenxin on 2023/11/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMaterialBannerView : UIView

@property (nonatomic, assign) BOOL timerLoop;//是否启用自动轮播，默认不启用
@property (nonatomic, copy) NSArray<NSString *> *bannerArray; // 图片url数组
@property (nonatomic, copy) NSArray<NSNumber *> *couldCloseArray; // 对应图片是否可关闭
@property (nonatomic, strong) void(^bannerActionBlock)(NSInteger bannerIndex);
@property (nonatomic, strong) void(^bannerShowBlock)(NSInteger bannerIndex);
@property (nonatomic, strong) void(^bannerCloseBlock)(NSInteger bannerIndex);

+ (CGFloat)defaultHeight:(CGFloat)width;
+ (CGFloat)heightForImageAspect:(CGFloat)imageAspect width:(CGFloat)width;

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
