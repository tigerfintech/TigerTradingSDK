//
//  TBLanguageManager.h
//  Stock
//
//  Created by ChenXin on 16/11/29.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TBLanguageType) {
    TBLanguageTypeDefault,  //自动
    TBLanguageTypeZhHans,   //简体中文
    TBLanguageTypeZhHant,   //繁体中文
    TBLanguageTypeEnglish,  //英文
};

#define TBLocalizedString(key, comment) \
        [TBLanguageManager resourcesLocalizedString:(key) withComment:(comment)]

// 目前统一从壳工程获取多语言，TBResources里的不再使用
#define TBResourcesLocalizedString(key, comment) \
        [TBLanguageManager resourcesLocalizedString:(key) withComment:(comment)]

// 是否使用上下布局
#define TBUseTopToBottomLayout [TBLanguageManager useTopToBottomLayout]

//设置里应用语言改变时的通知
extern NSString *const NOTIFICATION_KEY_LANGUAGE_DID_CHANGE;

@interface TBLanguageManager : NSObject

// 当前设置语言对应的本地化目录名
+ (NSString *)currentLocalizableFolderName;

/*
 获取当前app使用的语言，返回值不会是TBLanguageTypeDefault
 TradeUP使用时需注意返回值只能与枚举值比较，直接当成int使用可能会有问题
 这个方法现在只用来区分中、英文，所以简繁中之外的语言都返回TBLanguageTypeEnglish
 */
+ (TBLanguageType)currentAppLanguageType DEPRECATED_MSG_ATTRIBUTE("use TBSwiftLanguageManager 里方法");

// 根据应用设置语言返回的本地化字符串
+ (NSString *)localizedString:(NSString *)key withComment:(NSString *)comment;
+ (NSString *)resourcesLocalizedString:(NSString *)key withComment:(NSString *)comment;

/**
 * 判断是否使用上下布局，部分页面中文左右布局，英文上下布局
 */
+ (BOOL)useTopToBottomLayout;

// 判断系统语言是否是简体中文
+ (BOOL)isChineseSimpleLanguage;

//请求要传的lang参数值
+ (NSString *)currentLangParameter DEPRECATED_MSG_ATTRIBUTE("use [TBSwiftLanguageManager langParam]");

@end
