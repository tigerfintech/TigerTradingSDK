//
//  TBSNShareViewFactory.h
//  TBTradeBusinessBaseKit
//
//  Created by dulijun on 2023/11/21.
//

#import <Foundation/Foundation.h>
#import "TBSNShareView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBSNShareViewFactory : NSObject

+ (TBSNShareView *)createSNShareViewWithModel:(TBSNShareModel *)model;

@end

NS_ASSUME_NONNULL_END
