//
//  TBCommunityVideoPlayer.h
//  TBCommunityBusiness
//
//  Created by QXQ on 2022/6/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 错误码
typedef NS_ENUM(NSUInteger, TBPlayerErrorCode) {
    /// 无错误
    TBPlayerErrorCodeNoError,
    /// 无视频
    TBPlayerErrorCodeNoVideo,
    /// 加载失败
    TBPlayerErrorCodeLoadFailed,
};

@class TBCommunityVideoPlayer, AVPlayerLayer;

/// 播放状态相关回调
@protocol TBCommunityVideoPlayerDelegate <NSObject>

@required

/// 播放器准备完毕回调
/// @param player player
- (void)playerDidPrepare:(TBCommunityVideoPlayer *)player duration:(NSTimeInterval)duration;

@optional

/// 即将准备完毕回调
/// @param player player
- (void)playerWillPrepare:(TBCommunityVideoPlayer *)player;

/// 开始播放回调
/// @param player player
- (void)playerDidPlay:(TBCommunityVideoPlayer *)player;

/// 开始暂停回调
/// @param player player
- (void)playerDidPause:(TBCommunityVideoPlayer *)player;

/// 播放结束回调
/// @param player player
- (void)playerDidPlayToEndTime:(TBCommunityVideoPlayer *)player;

/// 已重置回调
/// @param player player
- (void)playerDidReset:(TBCommunityVideoPlayer *)player;

/// 失败回调
/// @param player player
/// @param errorCode errorCode
- (void)player:(TBCommunityVideoPlayer *)player didFailWithErrorCode:(TBPlayerErrorCode)errorCode;

/// 当前已缓冲
/// @param player player
/// @param time 时间
/// @param duration 时长
- (void)player:(TBCommunityVideoPlayer *)player didBufferedTime:(NSTimeInterval)time duration:(NSTimeInterval)duration;

/// 播放完成回调
/// @param player player
/// @param time 时间
/// @param duration 时长
- (void)player:(TBCommunityVideoPlayer *)player didPlayedTime:(NSTimeInterval)time duration:(NSTimeInterval)duration;

@end


@interface TBCommunityVideoPlayer : NSObject

/// 视频 url
@property (nonatomic, readonly) NSURL *url;

/// 播放视图
@property (nonatomic, weak) UIView *playView;

/// 播放器
@property (nonatomic, strong, nullable) AVPlayerLayer *playerLayer;

/// 是否在播放
@property (nonatomic, readonly, getter=isPlaying) BOOL playing;

/// 是否已准备
@property (nonatomic, readonly, getter=isReady) BOOL ready;

/// 已播放时长
@property (nonatomic, readonly) NSTimeInterval playedTime;

@property (nonatomic, assign) CGFloat playRate;

@property (nonatomic, assign) BOOL muted; // 是否静音

/// 配置播放器
/// @param url 视频 url
/// @param view inView
/// @param fill 是否铺满
/// @param delegate delegate
- (void)configWithURL:(NSURL *)url
               inView:(UIView *)view
                 fill:(BOOL)fill
             delegate:(id<TBCommunityVideoPlayerDelegate>)delegate;

/// 重置
- (void)reset;

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// 跳到指定进度
/// @param progress 进度
/// @param completion completion
- (void)seekToProgress:(CGFloat)progress completion:(void (^)(BOOL finished))completion;

/// 设置音量
/// @param volume 音量
- (void)setCurrentItemVolume:(CGFloat)volume;

@end

NS_ASSUME_NONNULL_END
