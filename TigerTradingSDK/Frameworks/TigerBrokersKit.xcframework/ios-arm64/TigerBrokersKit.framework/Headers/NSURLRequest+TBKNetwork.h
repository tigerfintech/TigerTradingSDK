//
//  NSURLRequest+TBKNetwork.h
//  TigerBrokersKit
//
//  Created by donggf on 2018/8/21.
//

#import <Foundation/Foundation.h>
//#import "CTService.h" // TODO: 这里有问题, core 依赖 network
@protocol CTServiceProtocol;

@interface NSURLRequest (TBKNetwork)

@property (nonatomic, copy) NSDictionary *tbk_requestParams;

@property (nonatomic, copy) NSDictionary *tbk_actualRequestParams;
@property (nonatomic, copy) NSDictionary *tbk_originRequestParams;
@property (nonatomic, strong) id <CTServiceProtocol> tbk_service;
//@property (nonatomic, strong) CTService *tbk_service;

@end
