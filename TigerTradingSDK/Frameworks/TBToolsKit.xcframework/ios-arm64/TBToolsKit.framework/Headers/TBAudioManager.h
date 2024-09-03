//
//  TBAudioOperation.h
//  Stock
//
//  Created by liwt on 3/18/15.
//  Copyright (c) 2015 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>


@interface TBThread : NSThread

@end



@interface TBAudioOperation : NSOperation

//@property (nonatomic, strong) void(^complete)(void);
@property (nonatomic, weak) id<AVAudioPlayerDelegate>delegate;

@property (nonatomic, copy) NSString* audioPath;

@end



@interface TBAudioManager : NSObject

+ (TBAudioOperation *)enqueueAudio:(NSString *)path;

+ (TBAudioOperation *)enqueueAudio:(NSString *)path complete:(void(^)(void))complete;

+ (TBAudioOperation *)enqueueAudio:(NSString *)path complete:(void(^)(void))complete delegate:(id<AVAudioPlayerDelegate>)delegate;

+ (TBAudioOperation *)playAudio:(NSString *)path complete:(void(^)(void))complete;

+ (TBAudioOperation *)playAudio:(NSString *)path start:(void(^)(void))startBlock complete:(void(^)(void))complete;

+ (TBAudioOperation *)enqueueAudio:(NSString *)path start:(void(^)(void))startBlock complete:(void(^)(void))complete;

+ (TBAudioOperation *)playAudio:(NSString *)path complete:(void(^)(void))complete delegate:(id<AVAudioPlayerDelegate>)delegate;

+ (TBAudioOperation *)enqueueAudio:(NSString *)path start:(void(^)(void))startBlock complete:(void(^)(void))complete delegate:(id<AVAudioPlayerDelegate>)delegate;

+ (TBAudioOperation *)playAudio:(NSString *)path;

+ (void)cancel;

// 播放某个音频文件
+ (void)playAudioWithName:(NSString *)audioName;

+ (void) playAudio;


@end
