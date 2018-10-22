//
//  HGView+UIConstraintBasedCompatibility.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

@interface HGView (UIConstraintBasedCompatibility)


/** 是否启用自动布局约束，默认YES. IB默认是NO */
@property(nonatomic) BOOL translatesAutoresizingMaskIntoConstraints NS_AVAILABLE_IOS(6_0);

/** 是否使用约束布局 */
#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) BOOL requiresConstraintBasedLayout NS_AVAILABLE_IOS(6_0);
#else
+ (BOOL)requiresConstraintBasedLayout NS_AVAILABLE_IOS(6_0);
#endif
@end
