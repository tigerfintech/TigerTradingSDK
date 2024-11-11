//
//  TBOptionPickOptionCell.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/11/25.
//

#import <TBUIKit/TBTableViewCell.h>

@class TBOptionPickOptionsModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionPickOptionCell : TBTableViewCell

@end

@interface TBOptionPickOptionCellItem : TBTableViewCellItem
@property (nonatomic, strong) TBOptionPickOptionsModel *model;
@end

NS_ASSUME_NONNULL_END
