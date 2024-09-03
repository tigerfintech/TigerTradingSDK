//
//  TBJSInjectionUtils.h
//  Stock
//
//  Created by linbingjie on 2020/2/20.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBJSInjectionUtils : NSObject

/// 获取 settimeout 的function
/// @param callBack js执行的string block
+ (NSString *)fetchSetTimerOut:(NSString *)callBack;


/// 获取 settimeout function
/// @param callBack callback
/// @param responseJson responsejson
+ (NSString *)fetchSetTimerOutCallBack:(NSString *)callBack
                          responseJson:(NSString *)responseJson;

/// 获取 innerhtml
+ (NSString *)fetchInnerHTML;

/// 获取 title
+ (NSString *)fetchDocumentTitle;

/// body bg 设置成白色
+ (NSString *)fetchSetBodyBackGroundWhiteColor;

/// touchcallout 设置成none
+ (NSString *)fetchSetTouchCallOutToNone;

/// 获取当前body的scrollview的高度
+ (NSString *)fetchBodyScrollHeight;

/// 当你触摸并按住触摸的目标，比如一个链接，Safari浏览器将显示链接有关的系统默认菜单。
/// 这个属性可以让你禁用系统默认菜单。
+ (NSString *)configTouchCallOut;

/// 注入获取图片个数添加点击事件的JS
+ (NSString *)injectGetImagesAddJSEvent;

/// 调用“注入获取图片个数添加点击事件的JS”注入的事件
+ (NSString *)configGetImagesAddJSEvent;

/// WK独有的
/// scalestofit参数配置
+ (NSString *)configScalesPageToFit;

// 处理a标签targer=_blank时无法响应点击的问题
+ (NSString *)fetchElemetn_A_Blank_UnableTouch;
@end

NS_ASSUME_NONNULL_END
