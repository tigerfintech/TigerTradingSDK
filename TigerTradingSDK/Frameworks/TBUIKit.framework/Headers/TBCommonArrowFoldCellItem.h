//
//  TBCommonArrowFoldCellItem.h
//  TBUIKit
//
//  Created by swordzhou on 11/21/23.
//

#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonArrowFoldCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *viewMoreTitle;
@property (nonatomic, assign) BOOL expanded;            
@property (nonatomic, assign) BOOL showMoreTitle;       ///Default:NO

@property (nonatomic, strong) void(^expandedStatusDidChangedBlock)(BOOL expanded);

@end

NS_ASSUME_NONNULL_END
