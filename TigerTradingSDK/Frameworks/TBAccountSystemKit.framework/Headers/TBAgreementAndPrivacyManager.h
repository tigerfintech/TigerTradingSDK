//
//  TBAgreementAndPrivacyManager.h
//  Stock
//
//  Created by Tiger on 2021/10/22.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAgreementAndPrivacyManager : NSObject

DECLARE_SHARED_INSTANCE(TBAgreementAndPrivacyManager)

// 用户协议和隐私政策富文本
@property (nonatomic, copy, readonly) NSAttributedString *agreementAndPrivacyString;

// 机构协议、隐私政策富文本
@property (nonatomic, copy, readonly) NSAttributedString *institutionAgreementAndPrivacyString;

// 用户协议标题
@property (nonatomic, copy, readonly) NSString *userAgreementTitle;

// 用户协议链接
@property (nonatomic, copy, readonly) NSString *userAgreementUrl;

// 隐私政策标题
@property (nonatomic, copy, readonly) NSString *privacyPolicyTitle;

// 隐私政策链接
@property (nonatomic, copy, readonly) NSString *privacyPolicyUrl;

@end

NS_ASSUME_NONNULL_END
