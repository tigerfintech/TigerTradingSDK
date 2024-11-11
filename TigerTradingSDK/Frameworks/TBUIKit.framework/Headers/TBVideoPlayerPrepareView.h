//
//  TBVideoPlayerPrepareView.h
//  TBCommunityBusiness
//
//  Created by QXQ on 2022/6/15.
//

#import <UIKit/UIKit.h>
#import "TBCommunityVideoPlayer.h"
#import "TBVideoPlayerProgressView.h"
#import "TBFullScreenVideoPlayerViewController.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBVideoPlayerPrepareViewDelegate <NSObject>

@optional

- (void)videoPlayerDidEndPlayCurrentVideo;

- (void)videoPlayerDidPrepareCurrentVideo;

@end

@interface TBVideoPlayerPrepareView : UIView

@property (nonatomic, strong) UIView *topMask;
@property (nonatomic, strong) CAGradientLayer *topLayer;
@property (nonatomic, strong) UIView *bottomMask;
@property (nonatomic, strong) CAGradientLayer *bottomLayer;
@property (nonatomic, strong) UIView *progressContainerView;
@property (nonatomic, strong, nullable) TBCommunityVideoPlayer *player;
@property (nonatomic, strong) UILabel *playedTimeLabel;
@property (nonatomic, strong) UILabel *remainingTimeLabel;
@property (nonatomic, strong) TBVideoPlayerProgressView *progressView;
@property (nonatomic, strong) UIButton *playButton;

@property (nonatomic, weak) UIViewController *fromViewController;

@property (nonatomic, strong) TBFullScreenVideoPlayerViewController *fullScreenVC;

@property (nonatomic, weak) id <TBVideoPlayerPrepareViewDelegate> delegate;

// 退出全屏后的回调
@property (nonatomic, copy) void (^fullScreenDismissBlock)(void);

@property (nonatomic, copy) void (^fullScreenChangeLessonBlock)(NSString *lessonId);

// 全屏时点击倍速按钮的响应，给TBFullScreenVideoPlayerViewController使用
@property (nonatomic, copy) void (^fullScreenSpeedButtonClickedBlock)(void);
// 全屏时响应控制组件隐藏，给TBFullScreenVideoPlayerViewController使用
@property (nonatomic, copy) void (^fullScreenHideCotrolBlock)(void);

@property (nonatomic, assign) BOOL isFullScreen;

@property (nonatomic, readonly) NSTimeInterval playedTime; ///< 已播时长
@property (nonatomic, readonly) BOOL isPlaying; 

@property (nonatomic, assign) NSTimeInterval historyStartTime; // server 记录观看历史进度
@property (nonatomic, assign) NSTimeInterval totalTime; // 总时长（时间戳）
@property (nonatomic, copy) NSString *totalDuaration; // 总时长（时分秒）
@property (nonatomic, assign) NSInteger speedIndex;
@property (nonatomic, assign) BOOL hideFullScreenButton;
@property (nonatomic, assign) BOOL shouldRecordProgress; // 是否记录播放进度下次续播

@property (nonatomic, assign) BOOL hasMinimizeButton; // 是否有最小化按钮
@property (nonatomic, strong) void (^minimizeBlock)(void);

@property (nonatomic, assign) BOOL hasMuteButton; // 是否有静音按钮
@property (nonatomic, assign) BOOL mutedStart; // 是否静音开始播放

@property (nonatomic, copy) NSString *trackComponentPrefix; // 埋点component参数前缀
@property (nonatomic, copy) NSString *trackPage; // 埋点page参数
@property (nonatomic, copy) NSDictionary *trackCustomizeParams; // 埋点自定义参数

- (void)configWithURL:(NSURL *)url fillInView:(BOOL)fill;
- (void)configWithURL:(NSURL *)url;
- (void)reset;
- (void)play;
- (void)pause;

- (void)setProgress:(CGFloat)progress;
- (void)showControlViews;
- (void)hideControlViews;

@end

NS_ASSUME_NONNULL_END
