//
//  TBSNShareUtils.h
//  TBTradeBusinessBaseKit
//
//  Created by dulijun on 2023/11/21.
//

#import <Foundation/Foundation.h>
#import "TBSNShareViewFactory.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBSNShareUtils : NSObject

+ (UIImage *)createShareImageWithSNModel:(TBSNShareModel *)model;

@end

NS_ASSUME_NONNULL_END
