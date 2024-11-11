//
//  TBStockDetailBorderSegmentControl.h
//  TBStockBusiness
//
//  Created by 骆鹏飞 on 2021/12/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailBorderSegmentControl : UIView

@property (nonatomic, strong, nullable) NSArray *titlesArray;

@property (nonatomic, strong, nullable) UIColor *selectedTitleColor;
@property (nonatomic, strong, nullable) UIColor *normalTitleColor;

@property (nonatomic, copy) void (^segementSelectedAction)(NSInteger selectedIndex);


@property (nonatomic, assign) NSInteger selectedIndex;

@end

NS_ASSUME_NONNULL_END
