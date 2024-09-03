//
//  TBLiveComponentService.h
//  Pods
//
//  Created by 秦晓强 on 2023/4/24.
//

#ifndef TBLiveComponentService_h
#define TBLiveComponentService_h

@protocol TBLiveComponentService <NSObject>


- (void)tbLive_initTTSDKIsReplay:(BOOL)flag;

- (void)tbLive_stopOpenGLESActivity;

- (void)tbLive_startOpenGLESActivity;


@end

#endif /* TBLiveComponentService_h */
