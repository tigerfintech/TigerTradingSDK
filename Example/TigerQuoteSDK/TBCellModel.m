//
//  TBCellModel.m
//  TigerQuoteSDK_Example
//
//  Created by linbingjie on 2024/8/12.
//  Copyright © 2024 linbingjie. All rights reserved.
//

#import "TBCellModel.h"

@implementation TBCellModel

- (instancetype)initWithTitle:(NSString *)title action:(void (^)(void))action {
    self = [super init];
    if (self) {
        _title = title;
        _action = action;
    }
    return self;
}

@end
