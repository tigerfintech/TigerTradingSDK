//
//  TBIndicatorExplanationModel.h
//  TBUIKit
//
//  Created by swordzhou on 2022/8/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBIndicatorExplanationModel : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *detail;

@property (nonatomic, copy) NSString *linkUrl;
@property (nonatomic, copy) NSString *linkText;

@property (nonatomic, assign) BOOL rowTitleEnabled;
@property (nonatomic, assign) BOOL columnTitleEnabled;
@property (nonatomic, assign) BOOL checked;

@end

NS_ASSUME_NONNULL_END
