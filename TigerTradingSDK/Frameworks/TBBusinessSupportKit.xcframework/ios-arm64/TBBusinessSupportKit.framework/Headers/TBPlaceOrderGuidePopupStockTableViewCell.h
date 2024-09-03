//
//  TBPlaceOrderGuidePopupStockTableViewCell.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/9.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderGuidePopupStockTableViewCell : TBTableViewCell

@end

@interface TBPlaceOrderGuidePopupStockTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *pic;

@end
NS_ASSUME_NONNULL_END
