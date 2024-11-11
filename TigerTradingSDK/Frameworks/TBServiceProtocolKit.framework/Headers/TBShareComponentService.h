//
//  TBShareComponentService.h
//  Pods
//
//  Created by linbingjie on 2022/5/17.
//

#ifndef TBShareComponentService_h
#define TBShareComponentService_h

NS_ASSUME_NONNULL_BEGIN

@protocol TBShareComponentService <NSObject>

// 分享图片
- (void)tbShareKit_shareWithImage:(UIImage *)image inViewController:(UIViewController *)viewController;


/// TODO: 因为要求特殊, 暂时添加一个方法定制分享vc; 分享vc重构, 对外提供统一接口
/// @param image 图片
/// @param viewController vc
/// @param notShow 是否显示
- (void)tbShareKit_shareImage:(UIImage *)image
     inViewController:(UIViewController *)viewController
     withoutShowingIt:(BOOL)notShow
      enableCommunity:(BOOL)enableCommunity;

- (NSObject *)tbShareKit_fetchShareHandler;

- (void)tbShareKit_shareBackFromType:(NSString *)type result:(NSInteger)result;

// 分享图片,允许自选设置是否分享到社区
- (void)tbShareKit_showWithImage:(UIImage *)image
        inViewController:(UIViewController *)viewController
         enableCommunity:(BOOL)enableCommunity;


- (void)tbShareKit_showWithImage:(UIImage *)image
        inViewController:(UIViewController *)viewController
         enableCommunity:(BOOL)enableCommunity
                shareDic:(NSDictionary *)shareDic;

// 分享生成链接的host
- (NSString *)tbShareKit_shareLinkHost;

@end

NS_ASSUME_NONNULL_END

#endif /* TBShareComponentService_h */
