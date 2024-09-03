//
//  TBCDPStatusModel.h
//  TBAccountSystemKit
//
//  Created by zhangjiangshan on 2024/6/12.
//

@import TBBaseKit;
NS_ASSUME_NONNULL_BEGIN

@interface TBCDPStatusModel : JSONModel
@property(nonatomic, copy) NSString *sub_type; //link, delink
@property(nonatomic, copy) NSString *status; //PENDING, SUCCESS, FAILURE
@property(nonatomic, copy) NSString *reason;

@property(nonatomic, assign) BOOL isApplying;

+ (instancetype)noApplyModel;

- (BOOL)isPending;

- (BOOL)isSuccess;

- (BOOL)isFailure;

/**
 * 是否申请过绑定CDP
 */
- (BOOL)isAppliedBefore;

@end

NS_ASSUME_NONNULL_END
