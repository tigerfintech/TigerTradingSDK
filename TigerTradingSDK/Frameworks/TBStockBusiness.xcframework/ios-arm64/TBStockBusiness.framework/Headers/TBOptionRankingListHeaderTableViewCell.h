//
//  TBOptionRankingListHeaderTableViewCell.h
//  TBStockBusiness
//
//  Created by 王昌阳 on 2023/8/7.
//

#import <TBStockBusinessBaseKit/TBExcelTableHeaderCell.h>
#import "TBOptionTabModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankingListHeaderTableViewCell : TBExcelTableHeaderCell

@end

@interface TBOptionRankingListHeaderTableViewCellItem : TBExcelTableHeaderCellItem

@property (nonatomic, copy) NSString *leftTitle;
@property (nonatomic, assign) BOOL rotate;
@property (nonatomic, copy) NSArray <TBOptionTabHeaderModel *> *headers;

@property (nonatomic, assign) NSInteger sortType;

- (void)updateSortType:(TBOptionTabHeaderModel *)headers;

- (void)applyLeftTitle:(NSString *)leftTitle
                rotate:(BOOL)rotate
               headers:(NSArray<TBOptionTabHeaderModel *> *)headers
            limitCount:(NSUInteger)limitCount;

@end

NS_ASSUME_NONNULL_END
