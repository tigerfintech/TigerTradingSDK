//
//  TBPlaceOrderGuidePopupTopTableViewCell.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/9.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderGuidePopupTopTableViewCell : TBTableViewCell

@end

@interface TBPlaceOrderGuidePopupTopTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;

@property (nonatomic, strong) NSMutableAttributedString *titleAttributedString;
@property (nonatomic, strong) NSMutableAttributedString *subtitleAttributedString;

@end

NS_ASSUME_NONNULL_END
