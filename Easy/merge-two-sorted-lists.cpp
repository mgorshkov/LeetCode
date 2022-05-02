//21. Merge Two Sorted Lists
//Easy
//
//11954
//
//1096
//
//Add to List
//
//Share
//You are given the heads of two sorted linked lists list1 and list2.
//
//Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
//
//Return the head of the merged linked list.
//
//
//
//Example 1:
//
//
//Input: list1 = [1,2,4], list2 = [1,3,4]
//Output: [1,1,2,3,4,4]
//Example 2:
//
//Input: list1 = [], list2 = []
//Output: []
//Example 3:
//
//Input: list1 = [], list2 = [0]
//Output: [0]
//
//
//Constraints:
//
//The number of nodes in both lists is in the range [0, 50].
//-100 <= Node.val <= 100
//Both list1 and list2 are sorted in non-decreasing order.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* node = head;
        
        ListNode* node1 = list1;
        ListNode* node2 = list2;
        
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val < node2->val) {
                // append node1->val
                node = insertNode(head, node, node1->val);
                node1 = node1->next;
            } else {
                // append node2->val;
                node = insertNode(head, node, node2->val);
                node2 = node2->next;
            }
        }
        while (node1 != nullptr) {
            // append node1->val
            node = insertNode(head, node, node1->val);
            node1 = node1->next;
        }
        
        while (node2 != nullptr) {
            // append node2->val
            node = insertNode(head, node, node2->val);
            node2 = node2->next;
        }
        
        return head;
    }
    
private:
    ListNode* createNode(int val) {
        ListNode* newNode = new ListNode;
        newNode->val = val;
        return newNode;
    }
    
    ListNode* insertNode(ListNode*& head, ListNode* node, int val) {
        if (head == nullptr) {
            head = createNode(val);
            node = head;
        } else {
            node->next = createNode(val);
            node = node->next;
        }
        return node;
    }
};
