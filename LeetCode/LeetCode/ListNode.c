//
//  List.c
//  LeetCode
//
//  Created by leon on 2020/8/23.
//  Copyright © 2020 leon. All rights reserved.
//

#include <stdio.h>
#include "LeetCode.h"


//MARK: 链表相加
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head =  (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;
    int c = 0;
    while(cur != NULL){
        if (l1 != NULL){
            c += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL){
            c += l2->val;
            l2 = l2->next;
        }
        cur->val = c % 10;
        c /= 10;
        if (l1 != NULL || l2 != NULL || c){
            cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        }
        cur = cur->next;
    }
    return head;
}


//MARK: 86. 分隔链表 --双指针
/*
 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 你应当保留两个分区中每个节点的初始相对位置。
 示例:
 输入: head = 1->4->3->2->5->2, x = 3
 输出: 1->2->2->4->3->5
 */
struct ListNode* partition(struct ListNode* head, int x){
    //before存储着小于x的值，after存储着大于x的值，最后再join起来
    if(head == NULL)  return NULL;
    
    struct ListNode* before = malloc(sizeof(struct ListNode));
    struct ListNode* after = malloc(sizeof(struct ListNode));
    struct ListNode* beforeHead = before;
    struct ListNode* afterHead = after;
    while (head != NULL) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        }else{
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;//记住要收尾
    before->next = afterHead->next;
    struct ListNode* node = beforeHead->next;
    free(beforeHead);
    free(afterHead);
    return node;
}


//MARK: 160. 相交链表
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) { return NULL; }
    int reachEndCount = 0;
    struct ListNode *headATop = headA;
    struct ListNode *headBTop = headB;
    while (reachEndCount < 3) {
        if ( headA && headB && headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
        if (headA == NULL) {
            headA = headBTop;
            reachEndCount++;
        }
        if (headB == NULL) {
            headB = headATop;
            reachEndCount++;
        }
    }
    return NULL;
}

//MARK: 203. 移除链表元素
/*https://leetcode-cn.com/problems/remove-linked-list-elements/
 删除链表中等于给定值 val 的所有节点。
 示例:
 输入: 1->2->6->3->4->5->6, val = 6
 输出: 1->2->3->4->5
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    while(head && head->val == val){//去除开头的
        head = head->next;
    }
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* left = head;
    struct ListNode* right = head->next;
    if (head->val == val) {
        return NULL;
    }
    while (left && right) {
        if (right->val == val) {
            //让right指向下一个非val的节点,
            //这样可以一次删除left 和right中间 等于val的节点
            while (right) {
                right = right->next;
                if (right && right->val != val) {
                    break;
                }
            }
            left->next = right;
            left = left->next;
            if (left) {
                right = left->next;
            }
        }else{
            left = left->next;
            right = right->next;
        }
    }
    
    return head;
    
    //方法2是直接建立一个新链表，遍历原链表，
    //把不等于val的其他链表装入新链表，返回新链表即可
}




//MARK: 234. 回文链表
/*
 输入: 1->2->2->1
 输出: true
 要求时间复杂度是O(n), 空间复杂度是O(1)。
 可以根据快慢指针找到链表中点，再把链表节点后半部分翻转， 前半部分再和后半部分比较
 链表节点是奇数时可以直接取中间， 是偶数时要取后一个节点开始作为后半边节点的开始
 比较完之后要把后半部分链表还原回去
 */

// 1 2 1     其中中点是2
// 1 2 2 1   右边边的2作为中点
struct ListNode* middleOfList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
//    struct ListNode* slow = head;
//    struct ListNode* fast = head->next;
//    while (fast->next && fast->next->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow->next;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct ListNode*  reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    while (head) {
         struct ListNode* next =  head->next;
         head->next = pre;
         pre = head;
         head = next;
    }
    return pre;
}
bool isListPalindrome(struct ListNode* head){
    //空和只有一个都算
    if (head == NULL || head->next == NULL)  return true;
    struct ListNode* leftNode = head;
    struct ListNode* midNode = middleOfList(head);
    struct ListNode* rightNode = reverseList(midNode);
    struct ListNode* rNode = rightNode;
    bool result = true;
    while (rightNode) {//rightNode最后一个指向的是空
        if (leftNode->val != rightNode->val) {
            //不能在这直接return还需要 恢复链表
            result =  false;
            break;
        }
        leftNode = leftNode->next;
        rightNode = rightNode->next;
    }
    //恢复
    reverseList(rNode);
    return result;
}

//MARK: - 旋转链表
/*https://leetcode-cn.com/problems/rotate-list/
 61. 旋转链表
 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

 示例 1:

 输入: 1->2->3->4->5->NULL, k = 2
 输出: 4->5->1->2->3->NULL
 解释:
 向右旋转 1 步: 5->1->2->3->4->NULL
 向右旋转 2 步: 4->5->1->2->3->NULL
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL) return NULL;
     struct ListNode *temp = head;
     //统计个数 顺便定位到最后一个位置（接环）
     int count = 1;
     while(temp->next){
        temp = temp->next;
        count++;
     }
     //闭环
     temp->next = head;
     k = k % count;
     k = count - k;//第k的就是要返回的根节点
     //temp记录前一个节点
     for(int i = 0 ; i < k; i++){
        temp = head;
        head = head->next;
     }
     temp->next = NULL;
     return head;
}
