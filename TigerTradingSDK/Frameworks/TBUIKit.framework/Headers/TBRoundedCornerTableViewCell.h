//
//  TBRoundedCornerTableViewCell.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2022/11/13.
//

#import <TBUIKit/TBTableViewCell.h>

typedef NS_ENUM(NSUInteger, TBBorderType) {
    TBBorderTypeNone,
    TBBorderTypeTop,
    TBBorderTypeBottom,
    TBBorderTypeAll,
};

NS_ASSUME_NONNULL_BEGIN

@interface TBRoundedCornerTableViewCell : TBTableViewCell

- (void)initSubViews;
- (void)initSubLayouts;

@end

@interface TBRoundedCornerTableViewCellItem : TBTableViewCellItem

@property (nonatomic, assign) TBBorderType borderType;

@end

NS_ASSUME_NONNULL_END
