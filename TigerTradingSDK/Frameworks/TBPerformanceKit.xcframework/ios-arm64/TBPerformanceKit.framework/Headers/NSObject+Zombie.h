//
//  NSObject+Zombie.h
//  Stock
//
//  Created by yangfan on 2018/6/13.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>

#define  kZombieObjectOrignalClassKey @"kZombieObjectOrignalClassKey"
#define  kZombieObjectDetectKey @"kZombieObjectDetectKey"

@interface NSObject (Zombie)

- (void)zombieDealloc;
+ (BOOL)needReplace;
+ (void)freeZombie;

@end
