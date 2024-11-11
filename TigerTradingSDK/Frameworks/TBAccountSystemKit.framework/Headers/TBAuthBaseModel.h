//
//  TBAuthBaseModel.h
//  TBAccountSystemKit
//
//  Created by donggongfu on 2021/8/24.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAuthBaseModel : JSONModel

@property (nonatomic, assign) BOOL success;
@property (nonatomic, assign) NSTimeInterval serverTime;

@property (nonatomic, strong) NSNumber *errorCode;
@property (nonatomic, copy) NSString *errorMessage;
@property (nonatomic, copy) NSString *errorDescription;
@property (nonatomic, copy) NSString *errorType;

@property (nonatomic, copy) NSDictionary *extra;

@end

NS_ASSUME_NONNULL_END
