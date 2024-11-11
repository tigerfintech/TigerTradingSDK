//
//  TBObject.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBObject : NSObject

@property (nonatomic, readonly) NSDictionary *dictionary;
@property (nonatomic, strong) NSMutableArray *keys;

- (id)initWithDictionary:(NSDictionary *) inDic;

- (void) updateWithDictionary:(NSDictionary *)inDic;

- (BOOL) autoSetValues;

- (NSMutableDictionary *)dictionaryValue;

+ (NSMutableArray *)dictionaryArrayWithObjectArray:(NSArray *)inArray;

+ (NSMutableArray *)arrayWithDictionaryArray:(NSArray *)inArray;


@end
