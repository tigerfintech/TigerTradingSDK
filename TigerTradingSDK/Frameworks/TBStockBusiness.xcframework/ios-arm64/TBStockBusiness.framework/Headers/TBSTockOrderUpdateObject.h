//
//  TBSTockOrderUpdateObject.h
//  Stock
//
//  Created by zhengzhiwen on 2020/11/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TBWatchListGroup;
#import <TBStockBusinessBaseKit/TBWatchListParamObject.h>


NS_ASSUME_NONNULL_BEGIN

@interface TBSTockOrderUpdateObject : NSObject

@property (nonatomic, assign, readonly) BOOL isParamSymbolEmpty;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSDictionary *parmas;

- (void)generateParamsSelectedGroup:(TBWatchListGroup *)group stocks:(NSArray *)stocks;


@end

NS_ASSUME_NONNULL_END
