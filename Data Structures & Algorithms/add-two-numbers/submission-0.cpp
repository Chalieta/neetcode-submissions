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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* resPtr = res;
        ListNode* prev = nullptr;
        int carry = 0;

        while (l1 != nullptr && l2 != nullptr) {
            int val = l1->val + l2->val + carry;
            if ( val >= 10) {
                carry = 1;
                resPtr->val = val - 10;
            } else {
                carry = 0;
                resPtr->val = val;
            }
            resPtr->next = new ListNode();
            prev = resPtr;
            resPtr = resPtr->next;
            l1 = l1->next;
            l2 = l2->next; 
        }

        while (l1 != nullptr) {
            int val = l1->val + carry;
            if ( val >= 10) {
                carry = 1;
                resPtr->val = val - 10;
            } else {
                carry = 0;
                resPtr->val = val;
            }
            resPtr->next = new ListNode();
            prev = resPtr;
            resPtr = resPtr->next;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            int val = l2->val + carry;
            if ( val >= 10) {
                carry = 1;
                resPtr->val = val - 10;
            } else {
                carry = 0;
                resPtr->val = val;
            }
            resPtr->next = new ListNode();
            prev = resPtr;
            resPtr = resPtr->next;
            l2 = l2->next;
        }

        if (carry) {
            resPtr->val = 1;
        } else {
            prev->next = nullptr;
            delete resPtr;
        }

        return res;
    }
};
