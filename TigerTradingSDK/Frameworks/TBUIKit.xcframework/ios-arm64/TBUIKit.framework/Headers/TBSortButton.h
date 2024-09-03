//
//  TBSortButton.h
//  Stock
//
//  Created by JustLee on 2019/1/25.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "TBDiscoverHKBrokersSeatTrackingHeader.h"

/**
 经纪商排序类型
 
 - TBSeatTrackingSortTypeNone: 默认 降序
 - TBSeatTrackingSortTypeAsc: 升序
 - TBSeatTrackingSortTypeDesc: 降序
 */
typedef NS_ENUM(NSUInteger, TBSeatTrackingSortType) {
    TBSeatTrackingSortTypeNone = 0,
    TBSeatTrackingSortTypeDesc,
    TBSeatTrackingSortTypeAsc,
};

@interface TBSortButton : UIButton

- (instancetype)initWithSortType:(TBSeatTrackingSortType)sortType;

@property (nonatomic, assign) TBSeatTrackingSortType sortType;
@property (nonatomic, assign) BOOL showSortIndicator;

@property (nonatomic, copy) NSString *text;

@end
