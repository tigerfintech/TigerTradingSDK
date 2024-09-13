//
//  TBOptionRankingItemTableViewCell.h
//  AFNetworking
//
//  Created by 王昌阳 on 2023/8/7.
//

#import <TBStockBusinessBaseKit/TBExcelTableCell.h>
#import "TBOptionTabModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankingItemTableViewCell : TBExcelTableCell

@end

@interface TBOptionRankingItemTableViewCellItem : TBExcelTableCellItem

@property (nonatomic, copy, readonly) NSString *nameCN;
@property (nonatomic, copy, readonly) NSString *symbol;
@property (nonatomic, copy, readonly) NSString *market;
@property (nonatomic, copy, readonly) NSString *secType;

@property (nonatomic, strong, readonly) TBOptionTabBulkOrderItemModel *itemModel;

@property (nonatomic, copy) NSString * leftTopText;
@property (nonatomic, strong) UIImage * leftBottomOneImage;
@property (nonatomic, copy) NSString * leftBottomTwoText;

@property (nonatomic, assign) BOOL isLastItem;

@property (nonatomic, copy) dispatch_block_t forcePortaritBlock;

- (TBOptionRankingItemTableViewCellItem *)applyDataModel:(TBOptionTabBulkOrderItemModel *)model
                                                 headers:(NSArray<TBOptionTabHeaderModel *> *)headers
                                              limitCount:(NSUInteger)limitCount;

@end


NS_ASSUME_NONNULL_END
