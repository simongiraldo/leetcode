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

 #include <cmath>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        
        ListNode* dummyHead = new ListNode();
        ListNode* nodePtr = dummyHead;
        int accomulated = 0;

        while(ptr1 || ptr2) {
            int data1 = 0, data2 = 0;
            
            if(ptr1) data1 = ptr1->val;
            if(ptr2) data2 = ptr2->val;
            
            int result = data1 + data2 + accomulated;
            int value;
            if(result < 10) {
                value = result;
                accomulated = 0;
            } else {
                accomulated = result / 10;
                value = result % 10;
            }

            ListNode* newNode = new ListNode(value);
            nodePtr->next = newNode;
            nodePtr = newNode;

            ptr1 = ptr1 ? ptr1->next : nullptr;
            ptr2 = ptr2 ? ptr2->next : nullptr;

            if(!ptr1 && !ptr2 && accomulated > 0) {
                nodePtr->next = new ListNode(accomulated);
            }
        }

        ListNode* resultNode = dummyHead->next;
        delete dummyHead;

        return resultNode;
    }
};