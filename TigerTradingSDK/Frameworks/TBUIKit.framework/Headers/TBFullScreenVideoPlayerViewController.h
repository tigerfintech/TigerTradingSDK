//
//  TBFullScreenVideoPlayerViewController.h
//  TBCommunityBusiness
//
//  Created by QXQ on 2022/6/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TBVideoPlayerPrepareView;

@protocol TBFullScreenVideoPlayerDelegate <NSObject>

@optional

// 视频标题
- (NSString *)videoTitleAtIndex:(NSInteger)index;

// 视频时长
- (NSString *)videoDurationAtIndex:(NSInteger)index;

// 课程视频数量
- (NSInteger)lessonVideoCount;

// 课程视频是否解锁
- (BOOL)isUnlockLessonAtIndex:(NSInteger)index;

// 点击课程视频
- (void)didSelectLessonAtIndex:(NSInteger)index;

@end

@interface TBFullScreenVideoPlayerViewController : UIViewController
@property (nonatomic, copy) NSString *videoTitle;
@property (nonatomic, assign) BOOL isLesson; // 是否是课程
@property (nonatomic, weak) id<TBFullScreenVideoPlayerDelegate> delegate;

- (void)reloadData;

- (void)addPrepareView:(TBVideoPlayerPrepareView *)prepareView;

- (void)hideVideoListTableView;

@end

NS_ASSUME_NONNULL_END
