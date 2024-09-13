//
//  TBOptionPickListCell.h
//  DoraemonKit-DoraemonKit
//
//  Created by 王灵博 on 2021/11/23.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBOptionPickModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionPickListCell : TBTableViewCell

@end


@interface TBOptionPickListCellItem : TBTableViewCellItem
@property (nonatomic, copy)NSString *title;
@property (nonatomic, strong)NSAttributedString *attributedString;
@property (nonatomic, assign) BOOL select;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, assign) TBOptionPickListType type;
@property (nonatomic, copy) NSString *iconUrl;
@property (nonatomic, copy) NSString *subTitle;
@property (nonatomic, strong) UIImage *iconImage;
@end


NS_ASSUME_NONNULL_END
