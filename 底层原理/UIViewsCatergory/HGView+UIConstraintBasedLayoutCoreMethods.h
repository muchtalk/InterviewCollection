//
//  HGView+UIConstraintBasedLayoutCoreMethods.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

@interface HGView (UIConstraintBasedLayoutCoreMethods)

- (void)updateConstraintsIfNeeded NS_AVAILABLE_IOS(6_0);/** 更新视图和其子视图的约束 */

- (void)updateConstraints NS_AVAILABLE_IOS(6_0) NS_REQUIRES_SUPER;/** 为视图更新约束，可以重写这个方法来设置当前view局部的布局约束 */

- (BOOL)needsUpdateConstraints NS_AVAILABLE_IOS(6_0);/** 视图的约束是否需要更新 */

- (void)setNeedsUpdateConstraints NS_AVAILABLE_IOS(6_0);/** 设置视图的约束需要更新，调用这个方法，系统会调用updateConstraints去更新布局 */


@end
