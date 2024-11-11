//
//  MJRefreshNormalHeader+TBRefreshChangeColor.h
//  Stock
//
//  Created by Pengfei_Luo on 2016/11/24.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <MJRefresh/MJRefresh.h>

@interface MJRefreshNormalHeader (TBRefreshChangeColor)
- (void)refreshHeaderChangeColor;
- (void)hideUpdateTime;
@end

@interface MJRefreshBackNormalFooter (TBRefreshFooterChangeColor)
- (void)refreshFooterChangeColor;
@end
