//
//  TBCommonToolsHelper+MQTTHelper.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/11/6.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBCommonToolsHelper.h"
#import <tbmqtt/TBMQTTHelper.h>
//#import <TigerPatch/TBPatchHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonToolsHelper (MQTTHelper) <TBMQTTHelperDataSource/*, TBPatchHelperDataSource*/>

@end

NS_ASSUME_NONNULL_END
