//
//  TBJumpViewController.h
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/1/15.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBCellModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBFunctionController : UIViewController

@property (nonatomic, copy) NSArray<NSString *> *sectionTitles;

@property (nonatomic, copy) NSDictionary<NSString *, NSArray<TBCellModel *> *> *dataSource;

@end

NS_ASSUME_NONNULL_END
