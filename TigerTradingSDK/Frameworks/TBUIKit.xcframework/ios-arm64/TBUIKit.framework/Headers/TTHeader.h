//
//  TTHeader.h
//  Pods
//
//  Created by chenxin on 2021/4/6.
//

#ifndef TTHeader_h
#define TTHeader_h

/*
 TigerTrade之前使用的是TTNavigator，TradeUP用的是TBKNavigator,
 后者是根据前者改造而来，通过@compatibility_alias设置别名可以避免大量修改代码
 */

#define TBKNAVIGATOR_ENABLE 1

#if TBKNAVIGATOR_ENABLE
#import <TigerBrokersKit/TBKURLAction.h>
#import <TigerBrokersKit/TBKURLMap.h>
#import <TigerBrokersKit/TBKNavigator.h>
#import <TigerBrokersKit/UIViewController+TBKNavigator.h>
#import <TigerBrokersKit/TBKNavigatorRootContainer.h>
#import <TigerBrokersKit/TBKCorePreprocessorMacros.h>

@compatibility_alias TTURLAction TBKURLAction;

@compatibility_alias TTURLMap TBKURLMap;

@compatibility_alias TTBaseNavigator TBKNavigator;

#else
#import "TTURLAction.h"
#import "TTURLMap.h"
#import "TTBaseNavigator.h"
#import "UIViewController+TTNavigator.h"
#import "TTNavigatorRootContainer.h"
#import "TTCorePreprocessorMacros.h"

#endif

#endif /* TTHeader_h */
