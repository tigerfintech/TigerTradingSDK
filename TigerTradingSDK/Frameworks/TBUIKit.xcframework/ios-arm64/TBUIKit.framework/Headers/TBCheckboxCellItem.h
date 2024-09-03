//
//  TBCheckboxCellItem.h
//  AFNetworking
//
//  Created by swordzhou on 10/23/23.
//

#import "TBTableViewCellItem.h"
#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCheckboxCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *leftTitle;

@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) BOOL showBottomLine;

@end

@interface TBCheckboxCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
