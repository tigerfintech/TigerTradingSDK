//
//  TBOptionChainDetailItemViewModel.h
//  TBStockBusiness
//
//  Created by wind on 2023/6/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBOptionChainDetailItemDisplayType) {
    TBOptionChainDetailItemDisplayTypeTitle = 0,
    TBOptionChainDetailItemDisplayTypeSubTitle,
};

@interface TBOptionChainDetailItemViewModel : NSObject

- (instancetype)initWithTitle:(NSString *)title;

- (instancetype)initWithTitle:(NSString *)title titleColor:(nullable UIColor *)titleColor;

- (instancetype)initWithTitle:(NSString *)title titleColor:(nullable UIColor *)titleColor titleFont:(nullable UIFont *)titleFont;

- (instancetype)initWithTitle:(NSString *)title subTitle:(NSString *)subTitle;

- (instancetype)initWithTitle:(NSString *)title
                   titleColor:(nullable UIColor *)titleColor
                    titleFont:(nullable UIFont *)titleFont
                     subTitle:(nullable NSString *)subTitle
                subTitleColor:(nullable UIColor *)subTitleColor
                 subTitleFont:(nullable UIFont *)subTitleFont;

@property (nonatomic, assign, readonly) TBOptionChainDetailItemDisplayType displayType;

@property (nonatomic, copy) NSString *title;

@property (nonatomic, strong) UIColor *titleColor;

@property (nonatomic, strong) UIFont *titleFont;

@property (nonatomic, copy) NSString *subTitle;

@property (nonatomic, strong) UIColor *subTitleColor;

@property (nonatomic, strong) UIFont *subTitleFont;

@end

NS_ASSUME_NONNULL_END
