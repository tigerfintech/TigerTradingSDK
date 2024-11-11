//
//  TBWatchListGroupTableMenuView.h
//  Stock
//
//  Created by PXJ on 2020/8/20.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBView.h>
#import "TBWatchListGroupManager.h" // business

#define WatchListGroupTableWidth (248)
NS_ASSUME_NONNULL_BEGIN
@class TBWatchListGroupMenuView;

@protocol TBWatchListGroupTableMenuViewDelegate <NSObject>
@required
- (void)menuViewDidSelectedGroup:(TBWatchListGroup *)group;
@end

typedef void (^TappedGroupManageBlock) (void);
typedef void (^TappedAddGroupManageBlock)(void);
typedef void (^TappedDismissMenuBlock)(void);
@interface TBWatchListGroupMenuView : TBView

- (instancetype)initWithFrame:(CGRect)frame showBottomButton:(BOOL)showBottomButton;

- (void)removeWatchListGroupMenuView;
- (void)dismissWatchListGroupMenuView;
- (void)showWatchListGroupMenuView;

@property (nonatomic, weak) id<TBWatchListGroupTableMenuViewDelegate> delegate;

@property (nonatomic, copy) TappedDismissMenuBlock dismissMenuBlock;

- (void)refreshGroups;

@end



NS_ASSUME_NONNULL_END
