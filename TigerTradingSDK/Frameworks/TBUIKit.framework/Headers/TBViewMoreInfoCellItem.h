//
//  TBViewMoreInfoCellItem.h
//  Pods
//
//  Created by swordzhou on 2022/8/9.
//

#import "TBTableViewCellItem.h"
#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBViewMoreInfoCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *info;
@property (nonatomic, copy) NSString *viewMoreTitle;

@property (nonatomic, copy) NSString *alertIconName;

@property (nonatomic, strong) UIColor *textColor;

@property (nonatomic, strong) void(^viewMoreBlock)(void);

@end

@interface TBViewMoreInfoCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
