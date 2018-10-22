//
//  HGView+UIViewAnimationWithBlocks.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

/** UIView动画选项
typedef NS_OPTIONS(NSUInteger, UIViewAnimationOptions) {
    UIViewAnimationOptionLayoutSubviews            = 1 <<  0, //!< 动画过程中保证子视图跟随运动.
    UIViewAnimationOptionAllowUserInteraction      = 1 <<  1, //!< 动画过程中允许用户交互.
    UIViewAnimationOptionBeginFromCurrentState     = 1 <<  2, //!< 所有视图从当前状态开始运行.
    UIViewAnimationOptionRepeat                    = 1 <<  3, //!< 重复运行动画.
    UIViewAnimationOptionAutoreverse               = 1 <<  4, //!< 动画运行到结束点后仍然以动画方式回到初始点.
    UIViewAnimationOptionOverrideInheritedDuration = 1 <<  5, //!< 忽略嵌套动画时间设置.
    UIViewAnimationOptionOverrideInheritedCurve    = 1 <<  6, //!< 忽略嵌套动画速度设置.
    UIViewAnimationOptionAllowAnimatedContent      = 1 <<  7, //!< 动画过程中重绘视图（注意仅仅适用于转场动画）.
    UIViewAnimationOptionShowHideTransitionViews   = 1 <<  8, //!< 视图切换时直接隐藏旧视图、显示新视图，而不是将旧视图从父视图移除（仅仅适用于转场动画）.
    UIViewAnimationOptionOverrideInheritedOptions  = 1 <<  9, //!< 不继承父动画设置或动画类型.
    
    UIViewAnimationOptionCurveEaseInOut            = 0 << 16, //!< 动画先缓慢，然后逐渐加速.
    UIViewAnimationOptionCurveEaseIn               = 1 << 16, //!< 动画逐渐变慢.
    UIViewAnimationOptionCurveEaseOut              = 2 << 16, //!< 动画逐渐加速.
    UIViewAnimationOptionCurveLinear               = 3 << 16, //!< 动画匀速执行，默认值.
    
    UIViewAnimationOptionTransitionNone            = 0 << 20, //!< 没有转场动画效果.
    UIViewAnimationOptionTransitionFlipFromLeft    = 1 << 20, //!< 从左侧翻转效果.
    UIViewAnimationOptionTransitionFlipFromRight   = 2 << 20, //!< 从右侧翻转效果.
    UIViewAnimationOptionTransitionCurlUp          = 3 << 20, //!< 向后翻页的动画过渡效果.
    UIViewAnimationOptionTransitionCurlDown        = 4 << 20, //!< 向前翻页的动画过渡效果.
    UIViewAnimationOptionTransitionCrossDissolve   = 5 << 20, //!< 旧视图溶解消失显示下一个新视图的效果.
    UIViewAnimationOptionTransitionFlipFromTop     = 6 << 20, //!< 从上方翻转效果.
    UIViewAnimationOptionTransitionFlipFromBottom  = 7 << 20, //!< 从底部翻转效果.
    
    UIViewAnimationOptionPreferredFramesPerSecondDefault     = 0 << 24, //!< 默认的帧每秒.
    UIViewAnimationOptionPreferredFramesPerSecond60          = 3 << 24, //!< 60帧每秒的帧速率.
    UIViewAnimationOptionPreferredFramesPerSecond30          = 7 << 24, //!< 30帧每秒的帧速率.
    
} NS_ENUM_AVAILABLE_IOS(4_0);
 
 
 
 typedef NS_ENUM(NSUInteger, UISystemAnimation) {
 
    UISystemAnimationDelete,    //!< 系统删除动画
 } NS_ENUM_AVAILABLE_IOS(7_0);
 
 */


@interface HGView (UIViewAnimationWithBlocks)

/** 用于对一个或多个视图的改变的持续时间、延时、选项动画完成时的操作 */
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0);

/** 用于对一个或多个视图的改变的持续时间、选项动画完成时的操作，默认：delay = 0.0, options = 0 */
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0);

/** 用于对一个或多个视图的改变的持续时间内动画完成时的操作，默认：delay = 0.0, options = 0, completion = NULL */
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations NS_AVAILABLE_IOS(4_0);

/** 使用与物理弹簧运动相对应的定时曲线执行视图动画 */
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay usingSpringWithDamping:(CGFloat)dampingRatio initialSpringVelocity:(CGFloat)velocity options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(7_0);

/** 为指定的容器视图创建转换动画 */
+ (void)transitionWithView:(UIView *)view duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(void (^ __nullable)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0);

/** 使用给定的参数在指定视图之间创建转换动画 */
+ (void)transitionFromView:(UIView *)fromView toView:(UIView *)toView duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0); // toView added to fromView.superview, fromView removed from its superview

/** 在一个或多个视图上执行指定的系统提供的动画，以及定义的可选并行动画 */
+ (void)performSystemAnimation:(UISystemAnimation)animation onViews:(NSArray<__kindof UIView *> *)views options:(UIViewAnimationOptions)options animations:(void (^ __nullable)(void))parallelAnimations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(7_0);


@end
