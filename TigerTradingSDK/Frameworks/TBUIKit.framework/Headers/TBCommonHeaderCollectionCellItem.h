//
//  TBCommonHeaderCollectionCellItem.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2023/1/11.
//

#import <TBUIKit/TBComponentCollectionCellItem.h>


NS_ASSUME_NONNULL_BEGIN

@interface TBCommonHeaderCollectionCellItem : TBComponentCollectionCellItem

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) UIColor *textColor;     // Default:B1
@property (nonatomic, copy) UIFont *textFont;       // Default:14 regular
@property (nonatomic, assign) CGFloat leadingOffset;
@property (nonatomic, assign) CGFloat trailingOffset;
@property (nonatomic, assign) NSTextAlignment textAlignment; // Default:left
@property (nonatomic, assign) BOOL showInfoIcon;

@end

NS_ASSUME_NONNULL_END
