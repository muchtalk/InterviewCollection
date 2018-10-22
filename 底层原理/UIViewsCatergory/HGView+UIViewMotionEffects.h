//
//  HGView+UIViewMotionEffects.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

@interface HGView (UIViewMotionEffects)
/** 添加运动效果，当倾斜设备时视图稍微改变其位置 */
- (void)addMotionEffect:(UIMotionEffect *)effect NS_AVAILABLE_IOS(7_0);

/** 移除运动效果 */
- (void)removeMotionEffect:(UIMotionEffect *)effect NS_AVAILABLE_IOS(7_0);

/** 所有添加的运动效果 */
@property (copy, nonatomic) NSArray<__kindof UIMotionEffect *> *motionEffects NS_AVAILABLE_IOS(7_0);

@end
