//
//  TBMarketSelectorTagTableViewCell.h
//  TBStockBusiness
//
//  Created by 骆鹏飞 on 2022/6/9.
//

#import <TBUIKit/TBTableViewCell.h>
//@import TBSwiftComponent;

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketSelectorTagTableViewCell : TBTableViewCell
@property (nonatomic, assign) NSInteger selectedIndex;

@end

@interface TBMarketSelectorTagTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *saPage;

@property (nonatomic, copy) NSArray<NSString *> *tags;
@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, copy) void(^segementChangedBlock)(TBMarketSelectorTagTableViewCellItem * item, NSInteger index);

@end

NS_ASSUME_NONNULL_END
