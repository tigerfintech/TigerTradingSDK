//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

// 所有已知的，通用的网络错误类型
// 看注释里写的内容更像是app的错误，可以app的错误单独定义在一个文件里
typedef NS_ENUM (NSInteger, TBKNetworkErrorType) {
    TBKNetworkErrorNone = 0,
    
    TBKNetworkErrorNeedAccessToken, // 需要重新刷新accessToken
    TBKNetworkErrorNeedLogin,       // 需要登陆
    TBKNetworkErrorDefault,         // 没有产生过API请求，这个是manager的默认状态。
    TBKNetworkErrorLoginCanceled,   // 调用API需要登陆态，弹出登陆页面之后用户取消登陆了
    TBKNetworkErrorSuccess,         // API请求成功且返回数据正确，此时manager的数据是可以直接拿来使用的。
    TBKNetworkErrorNoContent,       // API请求成功但返回数据不正确。如果回调数据验证函数返回值为NO，manager的状态就会是这个。
    TBKNetworkErrorParamsError,     // 参数错误，此时manager不会调用API，因为参数验证是在调用API之前做的。
    TBKNetworkErrorTimeout,         // 请求超时。CTAPIProxy设置的是20秒超时，具体超时时间的设置请自己去看CTAPIProxy的相关代码。
    TBKNetworkErrorNoNetwork,       // 网络不通。在调用API之前会判断一下当前网络是否通畅，这个也是在调用API之前验证的，和上面超时的状态是有区别的。
    TBKNetworkErrorCanceled,        // 取消请求
    TBKNetworkErrorNoError,         // 无错误
    TBKNetworkErrorDownGrade,       // APIManager被降级了
};

extern NSString* const kTTNetworkErrorDomain;
extern NSInteger const kTTNetworkErrorCodeInvalidImage;
extern NSString* const kTTErrorResponseDataKey;
