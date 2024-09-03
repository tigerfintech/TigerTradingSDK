//
//  TBDayItemCell.h
//  CalendarX
//
//  Created by Tiger on 2018/5/8.
//

#import <UIKit/UIKit.h>

@class TBDayItem;

@interface TBDayItemCell : UICollectionViewCell

@property (nonatomic, strong, readonly) UILabel *dayLabel;

@property (nonatomic, strong) TBDayItem *dayItem;
@property (nonatomic, assign) BOOL showAfterToday;//是否显示今天之后的状态

@property (nonatomic, copy) NSDictionary *keyAndColorDic;//日期下边的点对应的key与颜色值
@end
