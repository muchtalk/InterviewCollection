//
//  HGView+UIViewAnimation.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"
/*
 
 动画的曲线枚举
 
typedef NS_ENUM(NSInteger, UIViewAnimationCurve) {
    UIViewAnimationCurveEaseInOut,  //!< 慢进慢出（默认值）.
    UIViewAnimationCurveEaseIn,     //!< 慢进.
    UIViewAnimationCurveEaseOut,    //!< 慢出.
    UIViewAnimationCurveLinear,     //!< 匀速.
 }
 
UIView动画过渡效果
 
typedef NS_ENUM(NSInteger, UIViewAnimationTransition) {
    UIViewAnimationTransitionNone,          //!< 无效果.
    UIViewAnimationTransitionFlipFromLeft,  //!< 沿视图垂直中心轴左到右移动.
    UIViewAnimationTransitionFlipFromRight, //!< 沿视图垂直中心轴右到左移动.
    UIViewAnimationTransitionCurlUp,        //!< 由底部向上卷起.
    UIViewAnimationTransitionCurlDown,      //!< 由顶部向下展开.
};


*/

@interface HGView (UIViewAnimation)

+ (void)beginAnimations:(nullable NSString *)animationID context:(nullable void *)context;/** 开始动画 */
+ (void)commitAnimations;/** 提交动画 */
+ (void)setAnimationDelegate:(nullable id)delegate;/** 设置动画代理, 默认nil */
+ (void)setAnimationWillStartSelector:(nullable SEL)selector;/** 动画将要开始时执行方法（必须要先设置动画代理）, 默认NULL */
+ (void)setAnimationDidStopSelector:(nullable SEL)selector;/** 动画已结束时执行方法（必须要先设置动画代理）, 默认NULL */
+ (void)setAnimationDuration:(NSTimeInterval)duration;/** 设置动画时长, 默认0.2秒 */
+ (void)setAnimationDelay:(NSTimeInterval)delay;/** 动画延迟执行时间, 默认0.0秒 */
+ (void)setAnimationStartDate:(NSDate *)startDate;/** 设置在动画块内部动画属性改变的开始时间, 默认now ([NSDate date]) */
+ (void)setAnimationCurve:(UIViewAnimationCurve)curve;/** 设置动画曲线, 默认UIViewAnimationCurveEaseInOut */
+ (void)setAnimationRepeatCount:(float)repeatCount;/** 动画的重复播放次数， 默认0 */
+ (void)setAnimationRepeatAutoreverses:(BOOL)repeatAutoreverses;/** 设置是否自定翻转当前的动画效果, 默认NO */
+ (void)setAnimationBeginsFromCurrentState:(BOOL)fromCurrentState;/** 设置动画从当前状态开始播放, 默认NO */
+ (void)setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView *)view cache:(BOOL)cache;/** 在动画块中为视图设置过渡动画 */
+ (void)setAnimationsEnabled:(BOOL)enabled;/** 设置是否激活动画 */

#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) BOOL areAnimationsEnabled;/** 返回一个布尔值表示动画是否结束 */

#else
+ (BOOL)areAnimationsEnabled;
#endif
+ (void)performWithoutAnimation:(void (NS_NOESCAPE ^)(void))actionsWithoutAnimation NS_AVAILABLE_IOS(7_0);/** 先检查动画当前是否启用，然后禁止动画，执行block内的方法，最后重新启用动画，而且这个方法不会阻塞基于CoreAnimation的动画 */


#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) NSTimeInterval inheritedAnimationDuration NS_AVAILABLE_IOS(9_0);/** 当前动画的持续时间 */

#else
+ (NSTimeInterval)inheritedAnimationDuration NS_AVAILABLE_IOS(9_0);
#endif

@end
