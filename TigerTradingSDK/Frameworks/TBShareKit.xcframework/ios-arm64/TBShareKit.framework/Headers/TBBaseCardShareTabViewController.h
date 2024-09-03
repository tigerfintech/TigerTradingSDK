//
//  TBBaseCardShareTabViewController.h
//  TBShareKit
//
//  Created by dulijun on 2024/4/19.
//

#import <TBUIKit/TBBaseViewController.h>
#import "TBCardShareModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBBaseCardShareTabViewController : TBBaseViewController

@property (nonatomic, copy) NSArray <TBCardShareModel *>*shareItemArray;
@property (nonatomic, assign) CGFloat defaultTabIndex;

- (CGFloat)currentTabIndex;


#pragma mark - 子类重写
#pragma mark 指定底部tab 图片、title
// 底部tab对应的图标
- (NSDictionary *)tabIconMapDictionary;
// 底部tab对应的title
- (NSDictionary *)tabTitleMapDictionary;

#pragma mark 设置是否在分享成功后，是否为用户额外解锁一个表情
- (BOOL)shouldUnlockOneNewEmojiAfterShare;

#pragma mark 埋点
// 上报埋点：share按钮click
- (void)trackEventShareButtonClick;

@end

NS_ASSUME_NONNULL_END
