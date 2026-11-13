//
//  TBOptionDetailViewController.h
//  TigerQuoteSDK_Example
//
//  Created by wind on 2025/3/7.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionDetailViewController : UIViewController

@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *optionSymbol;

@property (nonatomic, copy) NSArray *legsInfoArr;

@property (nonatomic, assign) BOOL isCombine;

@end

NS_ASSUME_NONNULL_END
