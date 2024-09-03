//
//  TBCommentRefreshAutoFooter.h
//  Stock
//
//  Created by F.S. on 2019/8/22.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <MJRefresh/MJRefreshAutoNormalFooter.h>
#import <MJRefresh/MJRefresh.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommentRefreshAutoFooter : MJRefreshAutoStateFooter

@property (nonatomic, assign) BOOL refreshOnBottom; ///< 是否触底才刷新

- (void)refreshDisplayColor;

@end

NS_ASSUME_NONNULL_END
