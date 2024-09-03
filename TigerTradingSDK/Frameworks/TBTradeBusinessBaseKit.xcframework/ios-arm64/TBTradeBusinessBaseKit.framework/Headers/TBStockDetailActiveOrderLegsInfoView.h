//
//  TBStockDetailActiveOrderLegsInfoView.h
//  TBStockBusiness
//
//  Created by 王昌阳 on 2023/4/19.
//

#import <TBUIKit/TBView.h>
@class TBTableViewCellItem;
NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailActiveOrderLegsInfoView : TBView

@property (nonatomic, copy) NSArray<TBTableViewCellItem *> *datas;

@end

NS_ASSUME_NONNULL_END
