//
//  TBIndicesTableCellItem.h
//  Stock
//
//  Created by PXJ on 2020/6/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBIndicesTableCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSArray *indices;
@property (nonatomic, copy) NSString *market;
+ (TBIndicesTableCellItem *)applyIndices:(NSDictionary *)indices;

- (void)addIndices:(NSDictionary *)indices;
@end


NS_ASSUME_NONNULL_END
