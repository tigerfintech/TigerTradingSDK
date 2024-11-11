//
//  TBDefenderStubObject.h
//  Stock
//
//  Created by JustLee on 2021/1/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDefenderStubObject : NSObject

- (instancetype)init __unavailable;

+ (TBDefenderStubObject *)shareInstance;

- (BOOL)addFunc:(SEL)sel;

+ (BOOL)addClassFunc:(SEL)sel;


@end

NS_ASSUME_NONNULL_END
