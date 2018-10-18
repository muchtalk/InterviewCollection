//
//  SearchSuperViewController.m
//  Interview
//
//  Created by HG on 2018/10/8.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "SearchSuperViewController.h"

@implementation SearchSuperViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
}

+ (NSArray *)superViews:(UIView *)view {
    if (view == nil) {
        return @[];
    }
    
    NSMutableArray *result = [NSMutableArray array];
    while (view != nil) {
        [result addObject:view];
        view = view.superview;
    }
    return [result copy];
}

//方法1
//一个简单直接的办法：拿第一个路径中的所有节点，去第二个节点中查找。假设路径的平均长度是 N，因为每个节点都要找 N 次，一共有 N 个节点，所以这个办法的时间复杂度是 O（N^2）。


+ (UIView *)commonSuperViewWithViewA:(UIView *)viewA viewB:(UIView *)viewB {
    
    if (viewA == nil || viewB == nil) {
        return nil;
    }

    NSArray *arrayA = [SearchSuperViewController superViews:viewA];
    NSArray *arrayB = [SearchSuperViewController superViews:viewB];
    
    if (arrayA.count == 0 || arrayB.count == 0) {
        return nil;
    }
    
    for (NSUInteger i = 0; i < arrayA.count; i++) {
        UIView *targetView = arrayA[i];
        for (NSUInteger j = 0; j < arrayB.count; j++) {
            if (targetView == arrayB[j]) {
                return targetView;
            }
        }
    }
    return nil;
}

//方法2
//一个改进的办法：我们将一个路径中的所有点先放进 NSSet 中。因为 NSSet 的内部实现是一个 hash 表，所以查找元素的时间复杂度变成了 O（1），我们一共有 N 个节点，所以总时间复杂度优化到了 O（N）。
+ (UIView *)commonSuperViewWithViewA2:(UIView *)viewA viewB:(UIView *)viewB {
    
    if (viewA == nil || viewB == nil) {
        return nil;
    }
    
    NSArray *arrayA = [SearchSuperViewController superViews:viewA];
    NSArray *arrayB = [SearchSuperViewController superViews:viewB];
    NSSet *set = [NSSet setWithArray:arrayB];
    
    if (arrayA.count == 0 || arrayB.count == 0) {
        return nil;
    }
    
    for (NSUInteger i = 0; i < arrayA.count; i++) {
        UIView *targetView = arrayA[i];
        if ([set containsObject:targetView]) {
            return targetView;
        }
    }
    return nil;
}

//方法3
//除了使用 NSSet 外，我们还可以使用类似归并排序的思想，用两个「指针」，分别指向两个路径的根节点，然后从根节点开始，找第一个不同的节点，第一个不同节点的上一个公共节点，就是我们的答案。代码如下：时间复杂度优化到了 O（N）。

+ (UIView *)commonSuperViewWithViewA3:(UIView *)viewA viewB:(UIView *)viewB {
    
    if (viewA == nil || viewB == nil) {
        return nil;
    }
    
    NSArray *arrayA = [SearchSuperViewController superViews:viewA];
    NSArray *arrayB = [SearchSuperViewController superViews:viewB];

    if (arrayA.count == 0 || arrayB.count == 0) {
        return nil;
    }
    
    NSInteger p1 = arrayA.count - 1;
    NSInteger p2 = arrayB.count - 1;
    
    while (p1 >= 0 && p2 >= 0) {
        
        if (arrayA[p1] == arrayB[p2]) {
            return arrayA[p1];
        }
        p1--;
        p2--;
    }
    return nil;
}


// swift 的一些方法
//我们还可以使用 UIView 的 isDescendant 方法来简化我们的代码，不过这样写的话，时间复杂度应该也是 O(N^2) 的。lexrus 提供了如下的 Swift 版本的代码：
//
///// without flatMapextension UIView {
//extension UIView {
//    func commonSuperview(of view: UIView) -> UIView? {
//        if let s = superview {
//            if view.isDescendant(of: s) {
//                return s
//
//            } else {
//                return s.commonSuperview(of: view)
//
//            }
//        }
//        return nil
//    }
//}
//
//特别地，如果我们利用 Optinal 的 flatMap 方法，可以将上面的代码简化得更短，基本上算是一行代码搞定
//extension UIView {
//    func commonSuperview(of view: UIView) -> UIView? {
//        return superview.flatMap {
//            view.isDescendant(of: $0) ? $0 : $0.commonSuperview(of: view)
//
//        }
//    }
//}






@end
