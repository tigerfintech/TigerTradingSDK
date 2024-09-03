//
//  TBLoginType.h
//  Pods
//
//  Created by chenxin on 2020/9/15.
//

#ifndef TBLoginType_h
#define TBLoginType_h

/*
 用到TBLoginType的地方比较多，暂时先放在这里
 历史遗留问题，枚举的顺序不能变
 */
typedef NS_ENUM(NSInteger, TBLoginType){
    TBLoginTypeWeChat,  // weChat
    TBLoginTypePhone,  //  phone
    TBLoginTypeWeibo,   //weibo
    TBLoginTypeGuest, // 游客登录模式
    TBLoginTypeEmail,   //email
    TBLoginTypeFaceBook, //facebook
    TBLoginTypeTwitter,
    TBLoginTypeAppleId,
    TBLoginTypeAliAuth, // 阿里一键登录，本质上还是phone登录，在记录本地last login type的时候，还是会标记为TBLoginTypePhone
    TBLoginTypeSingpass,
    TBLoginTypeInstitutionUsername, // 机构：用户名+密码登录
    TBLoginTypeGoogle,
    TBLoginTypeThird, // 外部三方加盟商登录
};

// 上次登录页面，产品新需求，记录上次登录页面， 退出登录优先到上次登录的页面
typedef NS_ENUM(NSInteger, TBLastLoginPage){
    TBLoginPagePhoneVerifyCode,
    TBLoginPageAccountPassword,
    TBLoginPageForiegnPhone,
    TBLoginPagePhoneOneClick,
};

#endif /* TBLoginType_h */
