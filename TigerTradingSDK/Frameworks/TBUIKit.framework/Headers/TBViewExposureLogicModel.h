//
//  TBViewExposureLogicModel.h
//  Stock
//
//  Created by 王昌阳 on 2020/6/27.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBViewExposureDataSource.h"
@class TBTableViewCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBViewExposureLogicModel : NSObject

- (instancetype)initWithDataSource:(id<TBViewExposureDataSource>)dataSource;

/// 在 cell for item 初始化时调用
- (void)markViewStartAppear;

@end

@interface TBViewExposureLogicManager : NSObject

@property (nonatomic, assign) BOOL showExposureDataToast;///< 是否使用 toast 展示曝光数据

+ (instancetype)manager;

// 监听列表曝光通知
- (void)addListNotificationObservers;

@end


NS_ASSUME_NONNULL_END
