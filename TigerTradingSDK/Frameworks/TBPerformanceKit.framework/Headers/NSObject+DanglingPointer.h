//
//  NSObject+DanglingPointer.h
//  TBDefenderDemo
//
//  Created by JustLee on 2021/1/29.
//


#import <Foundation/Foundation.h>

@interface NSObject (DanglingPointer)

- (void)tb_danglingPointer_dealloc;

@end
