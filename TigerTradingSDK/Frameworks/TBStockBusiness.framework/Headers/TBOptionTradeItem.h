//
//  TBOptionTradeItem.h
//  Stock
//
//  Created by liwt on 9/24/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>

@interface TBOptionTradeItem : TBObject

@property (nonatomic, strong) NSNumber *time;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSNumber *volume;
@property (nonatomic, strong) NSNumber *preClose;

- (TBOptionTradeItem *) initWithDictionary:(NSDictionary *)inDic;
- (TBOptionTradeItem *) applyPreclose:(NSNumber *)preClose;
- (void) setValueByOtherItem:(TBOptionTradeItem *)other;

@end
