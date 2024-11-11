//
//  TBTabItem.h
//  TBUIKit
//
//  Created by 董恭甫 on 2024/1/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 定义app tab需要实现的属性或功能
@protocol TBTabItemProtocol <NSObject>

/// key. 对应`TBTabBarIndex`的String值:
/// Home, Quote, Community, Wealth, Portfolio(Trade?), Profile
@property (nonatomic, copy, readonly) NSString *name;

// 标题, 图标 等. 对应UITabBarItem
@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSString *imageName;
@property (nonatomic, copy, readonly) NSString *selectedImageName;

/// 动画资源文件名. 当前使用PAG
@property (nonatomic, copy, readonly) NSString *animationFileName;

@property (nonatomic, assign) NSUInteger index;

@property (nonatomic, readonly) UIViewController *viewController;

/// 从TabItem生成UITabBarItem, 依赖title, image, index信息
@property (nonatomic, readonly) UITabBarItem *tabBarItem;

@end

@interface TBTabItem : NSObject <TBTabItemProtocol>

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *imageName;
@property (nonatomic, copy) NSString *selectedImageName;
@property (nonatomic, assign) NSUInteger index;

@property (nonatomic, copy) NSString *animationFileName;

@property (nonatomic, copy) NSString *badgeValue;

- (instancetype)initWithName:(NSString *)name;

#pragma mark - WIP

//@property (nonatomic, copy) NSString *protocolName;
//@property (nonatomic, strong) Protocol *protocol;
//@property (nonatomic, assign) SEL selector;
//
//@property (nonatomic, copy) NSString *URLString;

@end

NS_ASSUME_NONNULL_END
