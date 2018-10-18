//
//  main.m
//  Interview
//
//  Created by HG on 27/09/2018.
//  Copyright © 2018 HG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

/*
typedef struct Node{
    int val;
    struct Node *next;
}ListNode;


int test(){
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;
    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    return &a;
}





ListNode* getInterSectionNode(ListNode *listA, ListNode *listB){
    std::set<int> test_set;
    const int A_len = 7;
    const int B_len = 8;
    
    int a[A_len] = {5,1,4,8,10,1,3};
    int b[B_len] = {2,7,1,3,1,6,0,1};
    
    for (int i = 0; i < A_len; i++) {
        test_set.insert(a[i]);
    }
    
    for (int i = 0; i < B_len; i++) {
        if (test_set.find(b[i]) != test_set.end()) {
            printf("b[%d] = %d in array",i,b[i]);
        }
        
    }

}


// 如果是递归节点呢？
ListNode *reverseBetween(ListNode *head,int m, int n){
    
    int change_len = n - m + 1; //计算要逆置节点长度
    ListNode *pre_head = NULL;//  初始化逆置节点的前驱
    ListNode *result = head; // 最终转换完成后的节点的头
    
    //这个while 循环为了找到逆置节点的前驱
    while (head && --m) {
        pre_head = head; // 当m减少到0的时候 停止循环
        head = head->next; //走向下一次循环
    }
    
    //
    ListNode *modify_list_tail = head;
    ListNode *new_head = NULL; //逆置段的新的头结点
    while (head && change_len) {
        ListNode *next = head->next;
        head->next = new_head; // 将head 的next 指向 新表的头几点new_head;
        new_head = head;       // 更新new_head
        head = next;           // 继续交换下一个节点
        change_len--;
    }
    modify_list_tail->next = head;// 链接逆置后的链表尾与逆置段的最后一个节点
    
    if (pre_head) {                 // 如果pre_head 不为空说明不是从第一个节点开始逆置的  （M>1）
        pre_head->next = new_head; // 将逆置列表开始的节点前驱与逆置后的头节点链接
    }else{
        result = new_head;         // 如果pre_head为空说明m== 1 从第一个节点开始逆置结果就是逆置后的头节点
    }
    return result;
}



void swap (int &a, int &b){
    
}


int main(int argc, char *argv[]) {
    
    int array[10] = {24, 17, 85, 13, 9, 54, 76, 45, 5, 63};
    
    int num = sizeof(array)/sizeof(int);
    
    for (int i = 0; i< num-1; i++){
        
        for (int j = 0; i < num - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < num; i++) {
        
        printf("%d", array[i]);
        if(i == num-1) {
            printf("\n");
        }else {
            printf(" ");
            
        }
        
    }
    
}

*/

// 求两个链表的交点

int main(int argc, char * argv[]) {
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
