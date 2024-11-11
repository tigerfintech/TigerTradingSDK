 //
//  TBTradePreconditionModel.h
//  TBAccountSystemKit
//
//  Created by swordzhou on 12/15/23.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBTradePreconditionCheckStatus;
typedef NSString *TBTradePreconditionActionType;
typedef NSString *TBTradePreconditionCheckType;
typedef NSString *TBTradePreconditionBizId;

FOUNDATION_EXPORT TBTradePreconditionCheckStatus const _Nonnull kTBTradePreconditionCheckStatusUnsubmit;
FOUNDATION_EXPORT TBTradePreconditionCheckStatus const _Nonnull kTBTradePreconditionCheckStatusPending;
FOUNDATION_EXPORT TBTradePreconditionCheckStatus const _Nonnull kTBTradePreconditionCheckStatusSuccess;
FOUNDATION_EXPORT TBTradePreconditionCheckStatus const _Nonnull kTBTradePreconditionCheckStatusRejected;
FOUNDATION_EXPORT TBTradePreconditionCheckStatus const _Nonnull kTBTradePreconditionCheckStatusExpired;

FOUNDATION_EXPORT TBTradePreconditionActionType const _Nonnull kTBTradePreconditionActionTypeLink;
FOUNDATION_EXPORT TBTradePreconditionActionType const _Nonnull kTBTradePreconditionActionTypeGCS;
FOUNDATION_EXPORT TBTradePreconditionActionType const _Nonnull kTBTradePreconditionActionTypePrompt;

FOUNDATION_EXPORT TBTradePreconditionActionType const _Nonnull kTBTradePreconditionCheckTypeSurvey;
FOUNDATION_EXPORT TBTradePreconditionActionType const _Nonnull kTBTradePreconditionCheckTypePiCertification;
FOUNDATION_EXPORT TBTradePreconditionActionType const _Nonnull kTBTradePreconditionCheckTypeTradePermission;

FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdRiskAsssessment;     // 风险测评
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdPiCertification;     // PI认证
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdTradePermission;     // 交易权限
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdKnowledgeAssessment; // 知识测评
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdAiCertification;     // AI认证
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdRegion;              // 居住国｜国际校验认证
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdOptShortPermission;
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdOptSellQuestionnaire;
FOUNDATION_EXPORT TBTradePreconditionBizId const _Nonnull kTBTradePreconditionBizIdOptBuyQuestionnaire;


@protocol TBTradePreconditionActionModel;

@interface TBTradePreconditionActionModel : JSONModel

@property (nonatomic, copy) TBTradePreconditionActionType type;

@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSString *text;    // type=prompt时存在

@end

@protocol TBTradePreconditionSurveyResultModel;

@interface TBTradePreconditionSurveyResultModel : JSONModel

@property (nonatomic, strong) NSNumber *surveyId;
@property (nonatomic, strong) NSNumber *answerId;
@property (nonatomic, strong) NSNumber *score;

@property (nonatomic, copy) NSString *grade;
@property (nonatomic, copy) NSString *gradeDescription;

@end

@protocol TBTradePreconditionCheckModel;
@interface TBTradePreconditionCheckModel : JSONModel

@property (nonatomic, copy) TBTradePreconditionActionType  type;
@property (nonatomic, copy) TBTradePreconditionCheckStatus status;

@property (nonatomic, strong) TBTradePreconditionSurveyResultModel *surveyResult;

@property (nonatomic, copy) NSString *product;

@end


@interface TBTradePreconditionModel : JSONModel

@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) TBTradePreconditionActionModel *action;
@property (nonatomic, strong) TBTradePreconditionCheckModel  *check;

@property (nonatomic, assign) BOOL passed ;
@property (nonatomic, copy) TBTradePreconditionBizId bizId;


@end

NS_ASSUME_NONNULL_END
