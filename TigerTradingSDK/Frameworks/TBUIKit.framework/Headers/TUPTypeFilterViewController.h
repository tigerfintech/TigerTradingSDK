//
//  TUPTypeFilterViewController.h
//  StockGlobal
//
//  Created by chenxin on 2019/8/28.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

/**
 present 该控制器的时候，animated 参数标记为 NO，展示动效内部实现
*/

#import "TBBaseViewController.h"

@protocol TUPTypeFilterDelegate;

@interface TUPTypeFilterViewController : TBBaseViewController

@property (nonatomic, weak) id <TUPTypeFilterDelegate> delegate;

@property (nonatomic, strong) NSArray<NSString *> *typeTitles;
@property (nonatomic, strong) NSArray<NSString *> *typeSubtitles;
//@property (nonatomic, strong) NSArray<DKImagePicker> *imagePickers;

@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, assign) BOOL hidesCheckmark;

@end

@protocol TUPTypeFilterDelegate <NSObject>

@optional

- (void)filterDidSelectIndex:(NSInteger )index;

- (void)filterViewController:(TUPTypeFilterViewController *)filterViewController didSelectIndex:(NSInteger)index;

@end
