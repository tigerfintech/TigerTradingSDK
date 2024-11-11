//
//  TBWatchListLandscapeHeader.h
//  Stock
//
//  Created by PXJ on 2020/7/27.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBView.h>
typedef void (^TBWatchListLandscapeHeaderBlock)(void);
NS_ASSUME_NONNULL_BEGIN

@class TBWatchListGroup;

@interface TBWatchListLandscapeHeader : TBView
@property (nonatomic, copy) TBWatchListGroup *selectedGroup;
@property (nonatomic, copy) TBWatchListLandscapeHeaderBlock showGroupBlock;
@property (nonatomic, copy) TBWatchListLandscapeHeaderBlock portraitBlock;
@property (nonatomic, copy) TBWatchListLandscapeHeaderBlock settingBlock;
//@property (nonatomic, copy) TBWatchListLandscapeHeaderBlock thumbnailBlock;
@property (nonatomic, copy) TBWatchListLandscapeHeaderBlock refreshBlock;

// 刷新thumbnail的选中状态，状态值从UserDefault里读取
- (void)updateThumbnailBtnState;

@end

NS_ASSUME_NONNULL_END
