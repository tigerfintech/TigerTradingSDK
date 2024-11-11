//
//  TBAnimationUtil.h
//  TBUIKit
//
//  Created by dulijun on 2022/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TbAnimationCompletionBlock)(BOOL animationFinished);

@interface TBAnimationUtil : NSObject

// 获取TBResources bundle中的pag文件路径，hasWhiteSkin=YES时如果是白皮肤文件名会拼接_skin2
+ (NSString *)pagPathWithFileName:(NSString *)fileName hasWhiteSkin:(BOOL)hasWhiteSkin;

+ (void)addPostAndNewsDetailShareAnimationToView:(UIView *)inView completion:(TbAnimationCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
