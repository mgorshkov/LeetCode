//
//  merge-k-sorted-lists.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
//Merge all the linked-lists into one sorted linked-list and return it.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return nullptr;
        
        vector<ListNode*> positions;
        for (auto l : lists)
            positions.push_back(l);
        ListNode* head = nullptr;
        auto ptr = head;
        while (true) {
            bool ended = true;
            for (auto pos : positions) {
                if (pos != nullptr) {
                    ended = false;
                    break;
                }
            }
            if (ended)
                return head;
            // find min
            bool min_inited = false;
            int min = 0;
            int min_pos = 0;
            for (int i = 0; i < positions.size(); ++i) {
                if (positions[i] == nullptr)
                    continue;
                if (!min_inited) {
                    min = positions[i]->val;
                    min_inited = true;
                    min_pos = i;
                } else {
                    if (positions[i]->val < min) {
                        min = positions[i]->val;
                        min_pos = i;
                    }
                }
            }
            auto node = new ListNode();
            node->val = min;
            if (head == nullptr) {
                head = node;
                ptr = head;
            } else {
                ptr->next = node;
                ptr = node;
            }
            positions[min_pos] = positions[min_pos]->next;
        }
        return head;
    }
};
