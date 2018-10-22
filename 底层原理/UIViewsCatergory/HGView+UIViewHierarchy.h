//
//  HGView+UIViewHierarchy.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

//UIView 层次
@interface HGView (UIViewHierarchy)


@property(nullable, nonatomic,readonly) UIView       *superview;/** 获取父视图 */

@property(nonatomic,readonly,copy) NSArray<__kindof UIView *> *subviews;/** 获取所有子视图 */

@property(nullable, nonatomic,readonly) UIWindow     *window;/** 获取视图所在的Window */


- (void)removeFromSuperview;/** 从父视图中移除控件 */

- (void)insertSubview:(UIView *)view atIndex:(NSInteger)index;/** 插入子视图(将子视图插入到subviews数组中index这个位置) */
- (void)exchangeSubviewAtIndex:(NSInteger)index1 withSubviewAtIndex:(NSInteger)index2;/** 交换subviews数组中所存放子视图的位置 */

- (void)addSubview:(UIView *)view;/** 添加子视图(新添加的视图在subviews数组的后面, 显示在最上面) */

- (void)insertSubview:(UIView *)view belowSubview:(UIView *)siblingSubview;/** 插入子视图(将子视图插到siblingSubview之下) */
- (void)insertSubview:(UIView *)view aboveSubview:(UIView *)siblingSubview;/** 插入子视图(将子视图插到siblingSubview之上) */

- (void)bringSubviewToFront:(UIView *)view;/** 将子视图拉到最上面来显示 */
- (void)sendSubviewToBack:(UIView *)view;/** 将子视图拉到最下面来显示 */

#pragma mark - 系统自动调用 留给子类去实现

- (void)didAddSubview:(UIView *)subview;/** 添加自视图完成后调用 */
- (void)willRemoveSubview:(UIView *)subview;/** 将要移除自视图时调用 */

- (void)willMoveToSuperview:(nullable UIView *)newSuperview;/** 将要移动到新父视图时调用 */
- (void)didMoveToSuperview;/** 移动到新父视图完成后调用 */

- (void)willMoveToWindow:(nullable UIWindow *)newWindow;/** 将要移动到新Window时调用 */
- (void)didMoveToWindow;/** 移动到新Window完成后调用 */

#pragma mark - end


- (BOOL)isDescendantOfView:(UIView *)view;/** 判断view是否为子类 */

- (nullable __kindof UIView *)viewWithTag:(NSInteger)tag;/** 通过tag获得对应的子视图 */


- (void)setNeedsLayout;/** 对现在有布局有调整更改后，使用这个方法进行更新 */
- (void)layoutIfNeeded;/** 强制进行更新layout */

- (void)layoutSubviews;/** 控件的frame发生改变的时候就会调用,一般在这里重写布局子控件的位置和尺寸 */


@property (nonatomic) UIEdgeInsets layoutMargins NS_AVAILABLE_IOS(8_0);/** 设置view之间的间距，该属性只对autolayout布局有效 */
@property (nonatomic) BOOL preservesSuperviewLayoutMargins NS_AVAILABLE_IOS(8_0);/** 是否将当前视图的间距和父视图相同，默认是NO */

- (void)layoutMarginsDidChange NS_AVAILABLE_IOS(8_0);/** 改变view的layoutMargins这个属性时，会触发这个方法 */

/** 视图间距引导 */
@property(readonly,strong) UILayoutGuide *layoutMarginsGuide NS_AVAILABLE_IOS(9_0);

/** 获取此区域的内的布局引导 */
@property (nonatomic, readonly, strong) UILayoutGuide *readableContentGuide  NS_AVAILABLE_IOS(9_0);
@end


