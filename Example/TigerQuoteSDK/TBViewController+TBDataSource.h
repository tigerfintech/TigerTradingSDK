//
//  TBViewController+TBDataSource.h
//  TigerQuoteSDK
//
//  Created by wind on 2025/12/18.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBViewController (TBDataSource)

- (void)setupDataSource;

- (NSString *)fetch23Title:(BOOL)isSub;

- (NSString *)fetch930Title;

@end

NS_ASSUME_NONNULL_END
