//
//  TBRefreshAutoStateFooter.h
//  Stock
//
//  Created by xw.long on 16/4/5.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <MJRefresh/MJRefreshBackNormalFooter.h>

@interface TBRefreshAutoStateFooter : MJRefreshBackNormalFooter

//上拉时立即刷新
@property (nonatomic, assign) BOOL refreshAtPullingUp;

@end
