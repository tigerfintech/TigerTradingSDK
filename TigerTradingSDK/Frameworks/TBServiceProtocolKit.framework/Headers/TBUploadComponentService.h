//
//  TBUploadComponentService.h
//  TBServiceProtocolKit
//
//  Created by linbingjie on 2023/4/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^TBPublishProgressBlock)(NSInteger uploadBytes, NSInteger totalBytes);
typedef void (^TBPublishCompleteBlock)(NSString *resultVideoURL);

@protocol TBUploadComponentService <NSObject>

/// 上传视频资源
- (void)tbupload_publishVideo:(NSString *)signature
                     videoURL:(NSURL *)videoUrl
       onPublishProgressBlock:(nullable TBPublishProgressBlock)progressBlock
       onPublishCompleteBlock:(nullable TBPublishCompleteBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
