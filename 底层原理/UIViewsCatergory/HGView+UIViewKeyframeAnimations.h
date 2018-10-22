//
//  HGView+UIViewKeyframeAnimations.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

/*
typedef NS_OPTIONS(NSUInteger, UIViewKeyframeAnimationOptions) {
    UIViewKeyframeAnimationOptionLayoutSubviews            = UIViewAnimationOptionLayoutSubviews, //!< 动画过程中保证子视图跟随运动.
    UIViewKeyframeAnimationOptionAllowUserInteraction      = UIViewAnimationOptionAllowUserInteraction, //!< 动画过程中允许用户交互.
    UIViewKeyframeAnimationOptionBeginFromCurrentState     = UIViewAnimationOptionBeginFromCurrentState, //!< 所有视图从当前状态开始运行.
    UIViewKeyframeAnimationOptionRepeat                    = UIViewAnimationOptionRepeat, //!< 重复运行动画.
    UIViewKeyframeAnimationOptionAutoreverse               = UIViewAnimationOptionAutoreverse, //!< 动画运行到结束点后仍然以动画方式回到初始点.
    UIViewKeyframeAnimationOptionOverrideInheritedDuration = UIViewAnimationOptionOverrideInheritedDuration, //!< 忽略嵌套动画时间设置.
    UIViewKeyframeAnimationOptionOverrideInheritedOptions  = UIViewAnimationOptionOverrideInheritedOptions, //!< 不继承父动画设置或动画类型.
    
    UIViewKeyframeAnimationOptionCalculationModeLinear     = 0 << 10, //!< 连续运算模式, 默认.
    UIViewKeyframeAnimationOptionCalculationModeDiscrete   = 1 << 10, //!< 离散运算模式.
    UIViewKeyframeAnimationOptionCalculationModePaced      = 2 << 10, //!< 均匀执行运算模式.
    UIViewKeyframeAnimationOptionCalculationModeCubic      = 3 << 10, //!< 平滑运算模式.
    UIViewKeyframeAnimationOptionCalculationModeCubicPaced = 4 << 10  //!< 平滑均匀运算模式.
} NS_ENUM_AVAILABLE_IOS(7_0);
 */

@interface HGView (UIViewKeyframeAnimations)
/** 创建一个动画块对象，可用于为当前视图设置基于关键帧的动画 */
+ (void)animateKeyframesWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewKeyframeAnimationOptions)options animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(7_0);
/** 添加指定开始时间、持续时间的关键帧动画(起始和持续时间是0.0和1.0之间的值) */
+ (void)addKeyframeWithRelativeStartTime:(double)frameStartTime relativeDuration:(double)frameDuration animations:(void (^)(void))animations NS_AVAILABLE_IOS(7_0);

@end


