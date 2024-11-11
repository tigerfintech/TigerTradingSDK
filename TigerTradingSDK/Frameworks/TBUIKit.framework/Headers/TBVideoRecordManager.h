//
//  TBVideoRecordManager.h
//  TBUIKit
//
//  Created by chenxin on 2023/3/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBVideoRecordModel : NSObject

@property (nonatomic, assign) NSInteger playedTime;
@property (nonatomic, assign) NSInteger totalTime;
@property (nonatomic, assign) BOOL muted; // 是否静音

@end

@interface TBVideoRecordManager : NSObject

+ (void)saveVideoRecord:(TBVideoRecordModel *)model forUrl:(NSString *)url;

+ (TBVideoRecordModel *)videoRecordForUrl:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
