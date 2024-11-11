//
//  TUPASDKUserDataModel.h
//  Stock
//
//  Created by 马超 on 2017/6/28.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TUPASDKUserDataModel : JSONModel

@property (nonatomic, copy) NSString *net_year_income;

@property (nonatomic, copy) NSString *legal_residence_country;
@property (nonatomic, copy) NSString *pic_id_other;
@property (nonatomic, copy) NSString *home_detail;
@property (nonatomic, copy) NSString *home_province;
@property (nonatomic, copy) NSString *home_city;
@property (nonatomic, copy) NSString *home_area;
@property (nonatomic, copy) NSString *home_address; // 居住地址全量

@property (nonatomic, copy) NSString *work_detail;
@property (nonatomic, copy) NSString *work_province;
@property (nonatomic, copy) NSString *work_city;
@property (nonatomic, copy) NSString *work_area;
@property (nonatomic, copy) NSString *work_address; // 工作地址全量

@property (nonatomic, strong) NSNumber *fut_trade_year;
@property (nonatomic, strong) NSNumber *opt_kl;
@property (nonatomic, copy) NSString *id_no;
@property (nonatomic, strong) NSNumber *other_trade_permission;
@property (nonatomic, strong) NSNumber *stk_kl;
@property (nonatomic, strong) NSNumber *opt_trade_per_year;
@property (nonatomic, strong) NSNumber *opt_perm;
@property (nonatomic, copy) NSString *career_other;
@property (nonatomic, copy) NSString *passport_no;
@property (nonatomic, strong) NSNumber *stk_trade_per_year;
@property (nonatomic, copy) NSString *business_other_en;
@property (nonatomic, copy) NSString *pic_passport;
@property (nonatomic, strong) NSNumber *trade_years;
@property (nonatomic, strong) NSNumber *fut_kl;
@property (nonatomic, strong) NSNumber *opt_trade_year;
@property (nonatomic, strong) NSNumber *income;
@property (nonatomic, copy) NSString *net_current_assets;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *invest_target;
@property (nonatomic, copy) NSString *real_name_en;
@property (nonatomic, copy) NSString *pic_id_card;
@property (nonatomic, copy) NSNumber *business;
@property (nonatomic, copy) NSString *business_other;
@property (nonatomic, copy) NSString *company;
@property (nonatomic, strong) NSNumber *option_permission;
@property (nonatomic, copy) NSString *net_assets;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, strong) NSNumber *job;
@property (nonatomic, copy) NSString *birthday;
@property (nonatomic, copy) NSString *id_type;
@property (nonatomic, strong) NSNumber *fut_trade_per_year;
@property (nonatomic, copy) NSString *additional_source_income;
@property (nonatomic, copy) NSString *source_type_other_desc;
@property (nonatomic, copy) NSString *residence_addr;
@property (nonatomic, strong) NSNumber *total_assets;
@property (nonatomic, strong) NSNumber *career;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, strong) NSNumber *age;
@property (nonatomic, copy) NSString *real_name;
@property (nonatomic, copy) NSString *source_type_desc_other;
@property (nonatomic, copy) NSString *signature;
@property (nonatomic, copy) NSString *pic_residence;
@property (nonatomic, strong) NSNumber *fut_perm;
@property (nonatomic, strong) NSNumber *same_residence_addr;
@property (nonatomic, copy) NSString *tax_identification_number;
@property (nonatomic, strong) NSNumber *marital_status;
@property (nonatomic, strong) NSNumber *family_member;

@property (nonatomic, copy) NSString *regulatory_stockholder;
@property (nonatomic, copy) NSString *regulatory_members;
@property (nonatomic, copy) NSString *regulatory_info;
@property (nonatomic, assign) BOOL employer_confirm;
@property (nonatomic, copy) NSString *employer_email;
@property (nonatomic, copy) NSString *employer_phone;

@end
