//
//  TBCollectionSectionHeader.h
//  TBUIKit
//
//  Created by 董恭甫 on 2023/8/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCollectionSectionHeader : UICollectionReusableView

@property (nonatomic, strong) UILabel *label;

@property (nonatomic, assign) BOOL xCentered;
@property (nonatomic, strong) NSNumber *leadingOffset;
@property (nonatomic, strong) NSNumber *trailingOffset;

@property (nonatomic, assign) BOOL yCentered;
@property (nonatomic, strong) NSNumber *topOffset;
@property (nonatomic, strong) NSNumber *bottomOffset;

@end

NS_ASSUME_NONNULL_END
