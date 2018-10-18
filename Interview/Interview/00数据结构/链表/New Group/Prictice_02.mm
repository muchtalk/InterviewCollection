//
//  Prictice_02.m
//  Interview
//
//  Created by HG on 2018/10/12.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "Prictice_02.h"

/* 问题
 You are given two non-empty linked lists representing two non-negative integers （非负整数）. The digits are stored in reverse order（逆序） and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume（承担，假设） the two numbers do not contain any leading zero, except the number 0 itself.
 
 Example:
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Explanation: 342 + 465 = 807.
 */


struct ListNode {
     int value;
     ListNode *next;
     ListNode(int x) : value(x), next(NULL) {}
};



@implementation Prictice_02


void addNode(ListNode *prev, ListNode *cur){
    
    cur->next = prev->next;
    prev->next = cur;
}


void addNodeAtHhead(ListNode *head) {
    
    ListNode *cur = new ListNode(9);
    cur->next = head;
    
}

void deleteNode(ListNode *list, ListNode *cur){
    
    ListNode *next = cur->next;
    cur->value = next->value;
    cur->next = next->next;
    
}

void deleteHead(ListNode *head) {
    ListNode *next = head->next;
    head->value = next->value;
    head->next = next->next;
}


//--------------------练习题 --------------------------
int getValueAtIndex(int index,ListNode *list){
    int i = 0;
    while (i <= index && list != nil) {
    
        if (i == index) {
            return list->value;
        }
        
        i++;
        list = list->next;
    }
    return -1;
}

void addNodeAtAtHead(int value,ListNode *list){
    
    ListNode *pre = new ListNode(value);
    pre->next = list;
    list = pre;
    
}

void addAtTail(int tail, ListNode *list){
    ListNode *next = new ListNode(tail);

}



@end
