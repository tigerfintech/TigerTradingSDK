//
//  MessageWindow.h
//  Pods-TBMessageDemo
//
//  Created by JustLee on 2019/3/12.
//

#import <UIKit/UIKit.h>

@interface MessageWindow : UIWindow

@end

/// 为 MessageWindow 创建一个vc, 重写旋转相关方法, fix弹出黄条会旋转的bug
/// 默认用 UIViewController, 未指定旋转行为
/// Info.plist 支持竖屏, app delegate为fix一个问题支持三面
/// 为了不影响原来的代码, 快速上线, 所以单独创建一个vc类重写旋转相关方法
@interface MessageViewController : UIViewController

@end
