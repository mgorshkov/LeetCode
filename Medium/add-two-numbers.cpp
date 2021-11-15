//
//  add-two-numbers.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto node1 = l1;
        auto node2 = l2;
        int shift = 0;
        ListNode* prevNodeRes = 0;
        ListNode* rootNodeRes = 0;
        while (node1 != nullptr || node2 != nullptr)
        {
            int res = (node1 != nullptr ? node1->val : 0) +
                (node2 != nullptr ? node2->val : 0) + shift;
            if (res > 9)
                shift = 1;
            else
                shift = 0;
            if (node1 != nullptr)
                node1 = node1->next;
            if (node2 != nullptr)
                node2 = node2->next;
            ListNode* nodeRes = new ListNode(res % 10);
            if (rootNodeRes == nullptr)
                rootNodeRes = nodeRes;
            if (prevNodeRes)
                prevNodeRes->next = nodeRes;
            prevNodeRes = nodeRes;
        }
        if (shift > 0)
        {
            ListNode* nodeRes = new ListNode(shift);
            prevNodeRes->next = nodeRes;
        }
        return rootNodeRes;
    }
};
