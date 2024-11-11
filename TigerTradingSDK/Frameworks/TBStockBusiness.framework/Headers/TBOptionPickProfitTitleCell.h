//
//  TBOptionPickProfitTitleCell.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/11/24.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionPickProfitTitleCell : TBTableViewCell

@end

@interface TBOptionPickProfitTitleCellItem : TBTableViewCellItem
@property(nonatomic, strong)NSString *text;
@end


@interface TBOptionPickProfitTextCell : TBTableViewCell

@end

@interface TBOptionPickProfitTextCellItem : TBTableViewCellItem
@property(nonatomic, strong)NSString *text;
@property(nonatomic, strong)NSAttributedString *attribute;
@end

@interface TBOptionPickProfitDetailCell : TBTableViewCell

@end

@interface TBOptionPickProfitDetailCellItem : TBTableViewCellItem
@property(nonatomic, strong)NSString *text;
@property(nonatomic, assign)BOOL isOpen;
@end


NS_ASSUME_NONNULL_END
