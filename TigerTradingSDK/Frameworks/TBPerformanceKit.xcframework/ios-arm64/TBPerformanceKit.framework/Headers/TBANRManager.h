//
//  TBANRManager.h
//
//  Created by yixiang on 2018/6/14.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

typedef void (^TBANRManagerBlock)(NSDictionary *anrInfo);

@interface TBANRManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, assign) BOOL anrTrackOn; 

/*
 卡顿时长阈值，单位为秒，
 */
@property (nonatomic, assign) CGFloat timeOut;

- (void)addANRBlock:(TBANRManagerBlock)block;

- (void)start;
- (void)stop;

@end
