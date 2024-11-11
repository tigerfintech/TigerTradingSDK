//
//  TBScoreTaskModel.h
//  Stock
//
//  Created by chenxin on 2019/4/16.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBScoreTaskAddition : JSONModel

@property (nonatomic, strong) NSNumber *score;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *bonusDescription;

@end

@interface TBScoreTaskModel : JSONModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *score;
@property (nonatomic, copy) NSString *imageUrl;

@property (nonatomic, assign) BOOL isDone; // 是否完成
@property (nonatomic, strong) NSNumber *totalCount; // 当type=more时生效，完成任务需要的总次数
@property (nonatomic, strong) NSNumber *doneCount; // 当type=more时生效，当前完成次数

@property (nonatomic, strong) TBScoreTaskAddition *bonus; // 特殊任务会有附加信息（比如发帖超200字时候，所得积分会双倍、描述信息）

@property (nonatomic, copy) NSString *link; // 点击"去完成"按钮后 根据该参数跳转到相应的页面
@property (nonatomic, copy) NSString *taskDescription;

// 换接口之后 新增加的字段
@property (nonatomic, copy) NSString *taskNameId; // 奖励名称id
@property (nonatomic, copy) NSNumber *userTaskId; // 用户任务的id(仅任务完成后才存在)
@property (nonatomic, copy) NSString *action; // 任务完成需要的行为

@end
