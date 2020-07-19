//
//  LeetCode1.h
//  LeetCode
//
//  Created by leon on 2020/6/19.
//  Copyright © 2020 leon. All rights reserved.
//

#ifndef LeetCode1_h
#define LeetCode1_h

#include <stdio.h>

//2. 两数相加
struct ListNode {
     int val;
     struct ListNode *next;
};
//?
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);


/// 反转字符串
void reverseString(char* s, int sSize);

//最长不重复字符的长度
int lengthOfLongestSubstring(char * s);

//整数反转 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
int reverse(int x) ;

//判断数字是否是回文数
int isPalindrome(int x);

//最长回文子串
char * longestPalindrome(char * s);

//26. 删除排序数组中的重复项 (双直指针)
int removeDuplicates(int* nums, int numsSize);

//质数个数
int countPrimes(int n);

double Power(double base, int exponent);
#endif /* LeetCode1_h */
