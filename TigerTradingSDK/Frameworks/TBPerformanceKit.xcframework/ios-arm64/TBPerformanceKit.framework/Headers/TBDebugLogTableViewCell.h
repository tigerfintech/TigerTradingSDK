//
//  TBDebugLogTableViewCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/6/14.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBAppColorManager.h>

@protocol TBDebugLogTableViewCell <NSObject>

- (NSString *)titleString;

- (id )desString;

- (id )detailString;

@end

@interface TBDebugLogTableViewCell : TBTableViewCell

@end

@interface TBDebugLogTableViewCellItem : TBTableViewCellItem

@property (nonatomic, strong) id<TBDebugLogTableViewCell> dataSource;

@end
