//
//  TBEmptyView.h
//  TBUIKit
//
//  Created by wind on 2022/11/10.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TBEmptyViewStyle) {
    TBEmptyViewStyleDefault, // 旧布局
    TBEmptyViewStyleModule, // 在模块中展示
    TBEmptyViewStylePage, // 在页面中展示
    TBEmptyViewStyleNew, // 新布局
};

typedef void (^TBEmptyViewActionBlock)(void);

@interface TBEmptyView : UIView

// 展示样式
@property (nonatomic, assign) TBEmptyViewStyle style;

// 是否是请求失败时展示，请求失败时支持刷新
@property (nonatomic, assign) BOOL isFailed;

@property (nonatomic, strong) TBEmptyViewActionBlock actionBlock;

@property (nonatomic, copy) NSString *trackComponent; // 埋点component参数
@property (nonatomic, copy) NSString *trackPage; // 埋点page参数
@property (nonatomic, copy) NSDictionary *trackOtherInfo; // 埋点自定义参数

- (CGFloat)contentHeight;

- (void)updateWithImageName:(NSString *)imageName
                      title:(NSString *)title
                    content:(NSString *)content;

- (void)updateWithImageName:(NSString *)imageName
                      title:(NSString *)title
                    content:(NSString *)content
                buttonTitle:(NSString *)buttonTitle
                actionBlock:(TBEmptyViewActionBlock)actionBlock;

- (void)updateWithImageName:(NSString *)imageName
                    pagPath:(NSString *)pagPath
                      title:(NSString *)title
                    content:(NSString *)content
                buttonTitle:(NSString *)buttonTitle
                actionBlock:(TBEmptyViewActionBlock)actionBlock;

- (void)updateImageWithName:(NSString *)imageName;

- (void)updateImage:(UIImage *)image;

- (void)updatePagWithPath:(NSString *)pagPath;

- (void)updateTitle:(NSString *)title;

- (void)updateContent:(NSString *)content;

- (void)themeChangeColor;

@end
