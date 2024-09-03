//
//  TBSensorsAnalyticsData.h
//  TBToolsKit
//
//  Created by dulijun on 2024/2/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSensorsAnalyticsData : NSObject

@property (nonatomic, copy) NSString *component;
@property (nonatomic, copy) NSString *page;
@property (nonatomic, copy) NSString *arriveFrom;
@property (nonatomic, copy) NSDictionary *extraData; // （可选）自定义数据

// 嘉略管理平台所需参数
@property (nonatomic, copy) NSString *trackSign;
@property (nonatomic, copy) NSString *requirementId;

// 统计事件时长
@property (nonatomic, copy) NSString *startTimer; // 统计事件时长时，在调用end方法时，要赋值

// 开放出来，是为了在统计事件时可以自定义使用（目前除了统计事件，其他埋点都不需要赋值）
@property (nonatomic, copy) NSString *actionType;


// 复制一个实例的所有属性
- (void)copyPropertiesFromInstance:(TBSensorsAnalyticsData *)otherInstance;

@end


@interface TBSAExposureData : TBSensorsAnalyticsData

@property (nonatomic, strong) UIView *view; // 曝光view
@property (nonatomic, copy) NSString *exposureIdentifier; // 曝光标识，用于区分列表元素的特殊场景（UITableView / UICollectionView下的 cell 复用场景），建议客户使用列表元素的数据源中的唯一标识来处理


/* 可自定义曝光条件，满足这些条件时就会上报事件（无特殊情况，这些值不用设置，用默认值，采用统一的曝光条件）*/
@property (nonatomic, assign) CGFloat areaRate; // 曝光的可见比例，有效值范围 0~1。默认值为 0，代表元素只要露出就满足可见比例条件；最大值为 1，代表元素需要完全露出才可满足可见比例条件
@property (nonatomic, assign) NSTimeInterval stayDuration; // 有效停留时长，单位为秒。默认值为 2，代表元素只要满足了可见比例，有效停留时长就可满足

@end

NS_ASSUME_NONNULL_END
