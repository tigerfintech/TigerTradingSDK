//
//  TBOptionAnslysisListCell.h
//  Stock
//
//  Created by 王灵博 on 2020/12/10.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBOptionAnalysisHeader.h"
@class TBOptionUnusualDetailModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionAnslysisListCell : TBTableViewCell

@end

@interface TBOptionAnslysisListCellItem : TBTableViewCellItem
@property(nonatomic, assign)BOOL isHeader;
@property(nonatomic, copy)NSString *timeStr;
@property(nonatomic, strong)TBOptionUnusualDetailModel *model;
@property(nonatomic, copy)NSString *market;
@property(nonatomic, assign)BOOL isIv;
@property(nonatomic, assign)TBOptionChangeType changeType;


/// 是否展示预警
@property (nonatomic, assign) BOOL isShowWatchAlert;
@property (nonatomic, assign) BOOL onWatchAlert;

@end

NS_ASSUME_NONNULL_END
