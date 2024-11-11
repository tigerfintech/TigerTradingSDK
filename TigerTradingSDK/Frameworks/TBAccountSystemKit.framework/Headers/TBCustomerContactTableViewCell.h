//
//  TBCustomerContactTableViewCell.h
//  TBUIKit
//
//  Created by 王昌阳 on 2023/8/2.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCustomerContactTableViewCell : TBTableViewCell

@end

@interface TBCustomerContactTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *contact;

@property (nonatomic, copy, readonly) NSString *iconName;

@end

NS_ASSUME_NONNULL_END
