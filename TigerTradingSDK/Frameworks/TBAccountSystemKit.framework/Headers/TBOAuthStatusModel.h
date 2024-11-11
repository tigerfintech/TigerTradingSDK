//
//  TBOAuthStatusModel.h
//  Stock
//
//  Created by donggongfu on 15/12/22.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

#pragma mark - 获取状态接口
@class TBOAuthStatusDataModel;
@interface TBOAuthStatusModel : JSONModel

@property (nonatomic, strong) TBOAuthStatusDataModel *data;
@property (nonatomic, assign) BOOL is_succ;

@end

@class TBOAuthStatusDetailModel;
@interface TBOAuthStatusDataModel : JSONModel

@property (nonatomic, strong) NSNumber *identifier;
@property (nonatomic, strong) NSNumber *uuid; // ???: longlong or NSNumber
@property (nonatomic, copy) NSString *tel_code; // 电话国际区号
//@property (nonatomic, copy) NSString *phone; phone字段不再使用
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *country; // 国家代码
@property (nonatomic, copy) NSString *born_country;//出生国
@property (nonatomic, copy) NSString *legal_residence_country;//法定居住国
@property (nonatomic, copy) NSString *tax_residence_country;//纳税居住国
@property (nonatomic, copy) NSString *current_trade_account; // 当前交易账户类型, IB/BS_CASH/BS_MARGIN
@property (nonatomic, copy) NSString *invite_code;
@property (nonatomic, assign) BOOL    enableAdvisorPost;

// # 账号管理
@property (nonatomic, assign) BOOL    display_virtual_account; // TODO: 改为 displayVirtualAccount
@property (nonatomic, assign) BOOL    display_real_account;

@property (nonatomic, strong) TBOAuthStatusDetailModel *bs_status;
@property (nonatomic, strong) TBOAuthStatusDetailModel *ib_status;
@property (nonatomic, strong) TBOAuthStatusDetailModel *virtual_status;
@property (nonatomic, copy) NSString<Optional> *error;
@property (nonatomic, strong) NSNumber<Optional> *error_code;
@property (nonatomic, copy) NSString<Optional> *error_description;
@property (nonatomic, copy) NSString<Optional> *error_message;
@property (nonatomic, copy) NSString *message;//请求成功时会携带message
@property (nonatomic, assign) BOOL is_real_account;//是否是实盘账户 true为YES，则使用current_trade_account获取实盘交易账户 false为NO，则使用virtual_account获取虚拟盘交易账户
@property (nonatomic, strong) NSNumber *virtual_account;//虚拟盘交易账户

@end

@class TBOAuthStatusMaterialInfoModel;
@class TBOAuthStatusPortalInfoModel;
@class TBOAuthStatusSnsStatusModel;
@interface TBOAuthStatusDetailModel : JSONModel

@property (nonatomic, copy) NSString *quote_type;
@property (nonatomic, copy) NSString *user_location;
@property (nonatomic, assign) NSUInteger status_code;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, assign) BOOL set_trade_password;
@property (nonatomic, assign) BOOL email_active;
@property (nonatomic, assign) NSInteger open_version;
@property (nonatomic, assign) NSInteger open_version_ios;
@property (nonatomic, copy) NSString *btn_text;
@property (nonatomic, copy) NSString *portal_text;
@property (nonatomic, strong) NSNumber *web_signup; //app没有
@property (nonatomic, copy) NSString *link;
@property (nonatomic, strong) NSNumber *hk_left_days;

@property (nonatomic, copy) NSString *perm_link; // fd, nd, 开通期权链接
@property (nonatomic, copy) NSString *margin_link;// fd, nd, 升级保证金链接
@property (nonatomic, copy) NSString *account_ability; // fd, nd, omnibus是cash还是，margin

@property (nonatomic, strong) NSNumber *customer_id; // customerId, 如果已开户，一个账户资料对应一个customerid， 可以用来请求对应的开户开料数据。

@property (nonatomic, strong) NSNumber *current_account_id; // for 模拟盘当前交易账户id
@property (nonatomic, strong) NSNumber *account_id; // 账户id
@property (nonatomic, copy) NSString *account_type; // 账户类型

@property (nonatomic, copy) NSArray *accounts; // 模拟账户列表

@property (nonatomic, assign) BOOL signed_etf_disclaimer;
@property (nonatomic, assign) BOOL signed_option_disclaimer;

@property (nonatomic, copy) NSArray<NSString *> *permission;
@property (nonatomic, copy) NSArray<NSString *> *step;

@property (nonatomic, copy) NSString *bs_type;//omnibus账户类型：现金、保证金

@property (nonatomic, strong) TBOAuthStatusMaterialInfoModel *material_info;
@property (nonatomic, strong) TBOAuthStatusPortalInfoModel *portal_info;
@property (nonatomic, strong) TBOAuthStatusSnsStatusModel *sns_status;

@end

@interface TBOAuthStatusMaterialInfoModel : JSONModel

@property (nonatomic, assign) BOOL has_task_id;//IB开户填写资料资产是否上传
@property (nonatomic, assign) BOOL has_bs_id;//Omnibus开户填写资料资产照片是否上传
@property (nonatomic, copy) NSString *has_country_code;
@property (nonatomic, assign) BOOL has_pic_files;
@property (nonatomic, assign) BOOL has_pic_signature;
@property (nonatomic, assign) BOOL has_pic_passport;
@property (nonatomic, assign) BOOL has_pic_residence;
@property (nonatomic, assign) BOOL wrong_address;
@property (nonatomic, assign) BOOL wrong_assets;
@property (nonatomic, assign) BOOL wrong_basic_profile;
@property (nonatomic, assign) BOOL wrong_files;
@property (nonatomic, assign) BOOL wrong_passport;
@property (nonatomic, assign) BOOL wrong_residence;
@property (nonatomic, assign) BOOL wrong_signature;
@property (nonatomic, assign) BOOL wrong_work_profile;

@end

@interface TBOAuthStatusPortalInfoModel : JSONModel

@property (nonatomic, copy) NSArray<NSString *> *id_proof;
@property (nonatomic, copy) NSArray<NSString *> *residence_addr_proof;
@property (nonatomic, assign) BOOL tax_incentives;
@property (nonatomic, copy) NSArray<NSString *> *wrong_field_proof;

@end

@interface TBOAuthStatusSnsStatusModel : JSONModel

@property (nonatomic, assign) BOOL google_binding;
@property (nonatomic, assign) BOOL facebook_binding;
@property (nonatomic, assign) BOOL twitter_binding;
@property (nonatomic, assign) BOOL wechat_binding;
@property (nonatomic, assign) BOOL weibo_binding;
@property (nonatomic, assign) BOOL xiaomi_binding;
@property (nonatomic, assign) BOOL apple_binding;
@property (nonatomic, assign) BOOL wechat_oa_binding; // 微信公众号绑定状态
@property (nonatomic, assign) BOOL singpass_binding; // singpass绑定状态
@property (nonatomic, copy) NSString *wechat_nickname;

@end

#pragma mark - 查询邮箱验注册激活状态
