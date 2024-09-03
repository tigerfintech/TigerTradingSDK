//
//  TBStreamPublicPopupModel.h
//  Stock
//
//  Created by chenxin on 2020/5/26.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStreamPublicPopupDisplaySettingsModel : JSONModel

/*
 展示设置类型 可以是:
 once 仅一次
 everyDayOnce 每日一次
 limited 共几次
 */
@property (nonatomic, copy) NSString *type;

// 共几次的次数值
@property (nonatomic, assign) NSInteger maxTimes;

// 1/0 是否可以强制关闭
@property (nonatomic, assign) int forceClose;

// 浮动条是否带icon
@property (nonatomic, assign) int floatingWithIcon;

@end

@interface TBStreamPublicPopupMaterialSettingsModel : JSONModel

// 物料编号
@property (nonatomic, copy) NSString *materialId;

// 随机展示时并发概率设置的权重数
@property (nonatomic, assign) NSInteger concurrent;

// 顺序模式的序号
@property (nonatomic, assign) NSInteger order;

// 展示设置
@property (nonatomic, strong) TBStreamPublicPopupDisplaySettingsModel *displaySettings;

// AB测试分组
@property (nonatomic, copy) NSString *abGroup;

// ipo展示弹窗样式分组 A/B/C
@property (nonatomic, copy) NSString *styleGroup;

@end

@interface TBStreamPublicPopupMaterialInfoModel : JSONModel

// 物料id
@property (nonatomic, copy) NSString *materialId;

@property (nonatomic, copy) NSString *materialName;

// 物料类型
@property (nonatomic, copy) NSString *materialType;

// 物料有效起始时间戳
@property (nonatomic, strong) NSNumber *startTime;

// 物料终止时间戳
@property (nonatomic, strong) NSNumber *endTime;

// app内跳转 取值参考 TBJSEvent 的 goNativePage 部分
@property (nonatomic, copy) NSString *appRedirect;

/// 跳转类型: h5, appRedirect, thirdPartyRedirect
@property (nonatomic, copy) NSString *linkType;

// h5链接
@property (nonatomic, copy) NSString *linkAddrLink;

// 动态跳转链接 域名用{{businessName}}，内部会替换成真实域名并赋值给linkAddrLink
@property (nonatomic, copy) NSString *dynamicJumpUrl;

/*
 1、symbol 列表
 2、当关联股票标的类型为某市场下全部标的时，表示具体的市场:[ US,HK,SI,AU,LN,SZ]
 3、当关联股票标的类型为指定品类时，表示具体的品类:[ option, fund]
 */
@property (nonatomic, copy) NSArray *symbols;

/*
 关联股票标的类型，
 0:全部标的
 1:输入的指定标的
 2:批量上传csv得到的标的
 3:选择全部支持定投
 4:选择全部支持碎股
 5:选择某市场下全部标的
 6:指定品类
 */
@property (nonatomic, assign) NSInteger symbolsType;

// 图片url
@property (nonatomic, copy) NSString *image;

// 文字内容
@property (nonatomic, copy) NSString *text;

// 说明
@property (nonatomic, copy) NSString *desc;

// 按钮文案
@property (nonatomic, copy) NSString *buttonTextHint;

// 标题文案
@property (nonatomic, copy) NSString *titleTextHint;

// 风险提示
@property (nonatomic, copy) NSString *riskWarning;

/*
 二级分类  对应水印
 Ad: 广告
 Campaign: 活动
 Live: 直播
 */
@property (nonatomic, copy) NSString *categoryChildren;
// 绑定的活动id
@property (nonatomic, copy) NSString *campaignId;
// 一级分类
@property (nonatomic, copy) NSString *category;
// 二级分类
@property (nonatomic, copy) NSString *children;

@property (nonatomic, copy) NSDictionary *personalizedConfig;

// 物料对应的id：帖子/新闻详情页ID/社区企业号ID/任务ID
@property (nonatomic, copy) NSArray *detailIds;

@end

@interface TBStreamPublicPopupMaterialModel : JSONModel

// 物料信息
@property (nonatomic, strong) TBStreamPublicPopupMaterialInfoModel *materialInfo;

// 物料在个性化物料中设置的属性
@property (nonatomic, strong) TBStreamPublicPopupMaterialSettingsModel *materialSettings;

// 开屏的arriveFrom信息 为手动赋值
@property (nonatomic, copy) NSString *arriveFrom;
@property (nonatomic, copy) NSString *groupType;


@end

@interface TBStreamPublicPopupSettingsModel : JSONModel

/*
 展示方式, 可以是
 sequence 顺序模式
 random 随机模式
 */
@property (nonatomic, copy) NSString *displayMode;

// 随机展示时的展示次数
@property (nonatomic, assign) NSInteger showTimes;

// 每日最大展示次数
@property (nonatomic, assign) NSInteger everyDayTimes;

// 以下字段暂未使用
@property (nonatomic, strong) NSNumber *createTime;
@property (nonatomic, copy) NSString *groupType;
@property (nonatomic, copy) NSString *location;
@property (nonatomic, copy) NSString *popupId;
@property (nonatomic, copy) NSString *region;

@end

@protocol TBStreamPublicPopupMaterialModel <NSObject>
@end

@interface TBStreamPublicPopupModel : JSONModel

// 分组类型
@property (nonatomic, copy) NSString *groupType;

// 分组类型（包含了附加参数，如果使用groupType作为key缓存数据时，要用他）
@property (nonatomic, copy) NSString *groupTypeWithOptionParameter;

// 有效物料列表
@property (nonatomic, copy) NSArray<TBStreamPublicPopupMaterialModel> *materialList;

// 物料配置信息
@property (nonatomic, strong) TBStreamPublicPopupSettingsModel *popupSettings;

// 是否是随机显示
- (BOOL)isRandomDisplay;

@end

NS_ASSUME_NONNULL_END
