//
//  CCDraggableContainer.h
//  CCDraggableCard-Master
//
//  Created by jzzx on 16/7/6.
//  Copyright © 2016年 Zechen Liu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CCDraggableCardView;
#import <UIKit/UIKit.h>
#import "CCDraggableConfig.h"

@class CCDraggableContainer;


/**
 Delegate
 */
@protocol CCDraggableContainerDelegate <NSObject>

- (void)draggableContainer:(CCDraggableContainer *)draggableContainer
        draggableDirection:(CCDraggableDirection)draggableDirection
                widthRatio:(CGFloat)widthRatio
               heightRatio:(CGFloat)heightRatio;

- (void)draggableCard:(UIView *)draggableCard
        draggableDirection:(CCDraggableDirection)draggableDirection
                disappear:(BOOL)disappear;
//选择某个card
- (void)draggableContainer:(CCDraggableContainer *)draggableContainer
                  cardView:(CCDraggableCardView *)cardView
            didSelectIndex:(NSInteger)didSelectIndex;
//划完最后一个card
- (void)draggableContainer:(CCDraggableContainer *)draggableContainer
 finishedDraggableLastCard:(BOOL)finishedDraggableLastCard;

@end

/**
 DataSource
 */
@protocol CCDraggableContainerDataSource <NSObject>

@required
- (CCDraggableCardView *)draggableContainer:(CCDraggableContainer *)draggableContainer
                               viewForIndex:(NSInteger)index;

- (NSInteger)numberOfIndexs;

@end

/**
 CCDraggableContainer
 */
@interface CCDraggableContainer : UIView

@property (nonatomic, weak) IBOutlet id <CCDraggableContainerDelegate>delegate;
@property (nonatomic, weak) IBOutlet id <CCDraggableContainerDataSource>dataSource;

@property (nonatomic) CCDraggableStyle     style;
@property (nonatomic) CCDraggableDirection direction;

@property (nonatomic, strong)CCDraggableCardView *topCardView;

@property (nonatomic, copy)NSArray<CCDraggableCardView*> *cardsView;

- (instancetype)initWithFrame:(CGRect)frame style:(CCDraggableStyle)style;
- (void)removeForDirection:(CCDraggableDirection)direction;
- (void)reloadData;

@end
