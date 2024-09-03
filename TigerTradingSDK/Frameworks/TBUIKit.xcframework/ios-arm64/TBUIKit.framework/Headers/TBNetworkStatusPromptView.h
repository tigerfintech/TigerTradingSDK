//
//  TBNetworkStatusPromptView.h
//  TBUIKit
//
//  Created by chenxin on 2023/2/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBNetworkStatusType) {
    TBNetworkStatusTypeNormal,          // 网络正常
    TBNetworkStatusTypeUnstable,        // 网络连接不稳定
    TBNetworkStatusTypeDisconnected,    // 网络已断开
};

typedef void (^TBNetworkStatusRefreshBlock)(void);

typedef void (^TBNetworkStatusChangedBlock)(TBNetworkStatusType statusType);

extern CGFloat const kTBNetworkStatusPromptViewHeight;

@interface TBNetworkStatusPromptView : UIView

@property (nonatomic, strong) TBNetworkStatusRefreshBlock refreshBlock;

@property (nonatomic, assign) TBNetworkStatusType type;

@property (nonatomic, copy) NSString *trackComponent; // 埋点component参数
@property (nonatomic, copy) NSString *trackPage; // 埋点page参数

@property (nonatomic, copy) TBNetworkStatusChangedBlock statusChangedBlock;

@end

NS_ASSUME_NONNULL_END
