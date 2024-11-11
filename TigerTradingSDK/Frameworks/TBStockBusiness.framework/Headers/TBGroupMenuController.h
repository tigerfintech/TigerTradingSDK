//
//  TBGroupMenuController.h
//  Stock
//
//  Created by zhengzhiwen on 2020/10/13.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBStockBusiness/TBWatchListGroupMenuView.h>
@class TBWatchListGroupMenuView;

NS_ASSUME_NONNULL_BEGIN

//只有横屏用
@interface TBGroupMenuController : NSObject

@property (nonatomic, strong, nullable) TBWatchListGroupMenuView *groupEditView;
@property (nonatomic, weak) id<TBWatchListGroupTableMenuViewDelegate> delegate;


- (void)dismissMenuView:(void(^)(void))complete;
- (void)fetchWatchListGroups;
- (void)setupMembers;
- (void)showWatchListGroupMenuView;
- (void)refreshGroups;

@end

NS_ASSUME_NONNULL_END
