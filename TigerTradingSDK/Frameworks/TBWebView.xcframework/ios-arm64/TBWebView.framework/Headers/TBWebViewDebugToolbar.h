//
//  TBWebViewDebugToolbar.h
//  Stock
//
//  Created by ChenXin on 2017/4/14.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TBWebViewDebugToolbarDelegate;

@interface TBWebViewDebugToolbar : UIView

@property (nonatomic, weak) id <TBWebViewDebugToolbarDelegate> delegate;

@property (nonatomic, copy) NSString *urlString;
@property (nonatomic, copy) NSString *strDescribe; // 描述内容

@end

@protocol TBWebViewDebugToolbarDelegate <NSObject>

- (void)debugToolbar:(TBWebViewDebugToolbar *)debugToolbar didChangeUrlString:(NSString *)urlString;
- (void)debugToolbarDidTapRefreshButton:(TBWebViewDebugToolbar *)debugToolbar;
- (void)debugToolbarDidTapClearCacheButton:(TBWebViewDebugToolbar *)debugToolbar;
- (void)debugToolbarDidTapHideButton:(TBWebViewDebugToolbar *)debugToolbar;
- (void)debugToolbarDidTapDebugButton:(TBWebViewDebugToolbar *)debugToolbar;

@end
