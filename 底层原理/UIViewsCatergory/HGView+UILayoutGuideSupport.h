//
//  HGView+UILayoutGuideSupport.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

@interface HGView (UILayoutGuideSupport)

/** 此视图拥有布局向导对象的数组 */
@property(nonatomic,readonly,copy) NSArray<__kindof UILayoutGuide *> *layoutGuides NS_AVAILABLE_IOS(9_0);

/** 向视图中添加布局向导 */
- (void)addLayoutGuide:(UILayoutGuide *)layoutGuide NS_AVAILABLE_IOS(9_0);

/** 向视图中添加布局向导 */
- (void)removeLayoutGuide:(UILayoutGuide *)layoutGuide NS_AVAILABLE_IOS(9_0);


@end


