//
//  TBAnalysisManager.h
//  Stock
//
//  Created by yangfan on 2018/10/8.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>

@interface TBAnalysisManager : TBObject

+ (instancetype)manager;

//上一次显示的页面ID
@property (nonatomic, assign) NSInteger lastAppearPage;
@property (nonatomic, copy)   NSString *lastAppearPageString;

//进入某页面，需要传入页面ID
- (void)enterPage:(NSInteger)curPage;
//切换subPage，需要传入页面ID,如果当前处于某个pageController或者某个SegmentController下，需要传入subPage
- (void)changeSubpage:(NSInteger)curPage referPage:(NSInteger)referPage itemId:(NSString *)itemId subPage:(NSInteger)subPage;
//离开某页面，需要传入页面ID,如果当前处于某个pageController或者某个SegmentController下，需要传入subPage
- (void)leavePage:(NSInteger)curPage referPage:(NSInteger)referPage itemId:(NSString *)itemId subPage:(NSInteger)subPage;

@end

#define TBAnalysisKit [TBAnalysisManager manager]
