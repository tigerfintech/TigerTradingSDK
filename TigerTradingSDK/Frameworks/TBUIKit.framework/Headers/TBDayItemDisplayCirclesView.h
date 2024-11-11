//
//  TBDayItemDisplayCirclesView.h
//  Future
//
//  Created by Tiger on 2018/6/25.
//  Copyright © 2018  All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDayItemDisplayCirclesView : UIView

@property (nonatomic, copy) NSDictionary *keyAndColorDic;//日期下边的点对应的key与颜色值
@property (nonatomic, copy) NSArray *financeData;

@end

NS_ASSUME_NONNULL_END
