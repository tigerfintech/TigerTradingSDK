//
//  TBVideoModel.h
//  Stock
//
//  Created by chenxin on 2023/3/30.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

#define kTBVideoRatio (9.0 / 16)

@interface TBVideoModel : JSONModel

@property (nonatomic, copy) NSString *gid; // 素材ID

@property (nonatomic, copy) NSString *url; // 素材播放URL

@property (nonatomic, copy) NSString *title; // 素材标题

@property (nonatomic, copy) NSString *subtitle; // 副标题

@property (nonatomic, copy) NSString *desc; // 图文信息(仅source_type=3时生效)

@property (nonatomic, copy) NSString *duration; // 素材视频时长

@property (nonatomic, copy) NSString *thumbnail; // 素材封面图

/*
 素材内容类型
 0: 视频
 2: 文字
 */
@property (nonatomic, assign) NSInteger contentType;

@property (nonatomic, copy) NSString *jumpName; // 跳转按钮文案
@property (nonatomic, copy) NSString *jumpUrl; //跳转链接

// 埋点相关
@property (nonatomic, copy) NSString *trackComponentPrefix; // 埋点component参数前缀
@property (nonatomic, copy) NSString *trackPage; // 埋点page参数
@property (nonatomic, copy) NSDictionary *trackCustomizeParams; // 埋点自定义参数

@end

NS_ASSUME_NONNULL_END
