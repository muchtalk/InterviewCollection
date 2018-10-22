//
//  HGView+UIConstraintBasedLayoutInstallingConstraints.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

//
// UIView Constraint-based Layout Support
//

/*
typedef NS_ENUM(NSInteger, UILayoutConstraintAxis) {
    UILayoutConstraintAxisHorizontal = 0,
    UILayoutConstraintAxisVertical = 1
};
 */

@interface HGView (UIConstraintBasedLayoutInstallingConstraints)

/** 获取所有约束 */
@property(nonatomic,readonly) NSArray<__kindof NSLayoutConstraint *> *constraints NS_AVAILABLE_IOS(6_0);

/** 添加一个约束 */
- (void)addConstraint:(NSLayoutConstraint *)constraint NS_AVAILABLE_IOS(6_0);
/** 添加多个约束 */
- (void)addConstraints:(NSArray<__kindof NSLayoutConstraint *> *)constraints NS_AVAILABLE_IOS(6_0);
/** 移除一个约束 */
- (void)removeConstraint:(NSLayoutConstraint *)constraint NS_AVAILABLE_IOS(6_0);
/** 移除多个约束 */
- (void)removeConstraints:(NSArray<__kindof NSLayoutConstraint *> *)constraints NS_AVAILABLE_IOS(6_0);
@end


