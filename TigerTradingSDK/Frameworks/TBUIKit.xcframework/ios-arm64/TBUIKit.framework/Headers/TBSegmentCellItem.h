//
//  TBSNSegmentCellItem.h
//  Pods
//
//  Created by swordzhou on 10/8/23.
//

#import "TBTableViewCellItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBSegmentCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL showAlert;       /// Default:NO
@property (nonatomic, assign) BOOL showBottomLine;  /// Default:NO
@property (nonatomic, assign) BOOL dynamicWidth;    /// Default:NO

@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSArray *segmentTitles;

@property (nonatomic, strong) void(^selectedIndexDidChangedBlock)(NSInteger selectedIndex);
@property (nonatomic, strong) void(^alertInfoBlock)(void);

- (CGFloat)titleWidth:(UIFont *)font;

@end

NS_ASSUME_NONNULL_END
