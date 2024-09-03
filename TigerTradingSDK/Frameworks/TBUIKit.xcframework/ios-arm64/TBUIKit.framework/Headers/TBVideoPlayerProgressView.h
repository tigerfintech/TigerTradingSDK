//
//  TBVideoPlayerProgressView.h
//  TBCommunityBusiness
//
//  Created by QXQ on 2022/6/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TBVideoPlayerProgressView;

@protocol TBVideoPlayerProgressViewDelegate <NSObject>

- (void)progressView:(TBVideoPlayerProgressView *)progressView didProgress:(CGFloat)progress;
- (void)progressView:(TBVideoPlayerProgressView *)progressView didEndProgress:(CGFloat)progress;

@end


@interface TBVideoPlayerProgressView : UIView

@property (nonatomic, assign) CGSize dotSize;
@property (nonatomic, assign) CGFloat playProgress;

@property (nonatomic, weak) id<TBVideoPlayerProgressViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
