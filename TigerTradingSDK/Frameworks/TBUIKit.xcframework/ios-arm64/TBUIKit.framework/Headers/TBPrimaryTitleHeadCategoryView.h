//
//  TBThirdLevelCategoryView.h
//  AFNetworking
//
//  Created by linbingjie on 2023/9/12.
//

#import <TBUIKit/JXCategoryView.h>
#import <TBUIKit/TBJXCategoryTitleBackgroundCellModel.h>
#import <TBUIKit/TBJXCategoryTitleBackgroundCell.h>
#import "JXCategoryTitleView+TBSize.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBPrimaryTitleHeadCategoryView : JXCategoryTitleImageView

@property (nonatomic, strong) UIColor *normalBackgroundColor;
@property (nonatomic, strong) UIColor *normalBorderColor;
@property (nonatomic, strong) UIColor *selectedBackgroundColor;
@property (nonatomic, strong) UIColor *selectedBorderColor;
@property (nonatomic, assign) CGFloat borderLineWidth;
@property (nonatomic, assign) CGFloat backgroundCornerRadius;
@property (nonatomic, assign) CGFloat backgroundWidth;
@property (nonatomic, assign) CGFloat backgroundHeight;
 
///// 设置图片icon
/////   - imageInfoArray: 普通状态
/////   - selectedImageInfoArray: 选中状态
//- (void)configimageInfoArray:(NSArray <id>*)imageInfoArray selectedImageNames:(NSArray <id>*)selectedImageInfoArray;

- (void)configTitles:(NSArray <NSString *>*)titles;
@end

NS_ASSUME_NONNULL_END
