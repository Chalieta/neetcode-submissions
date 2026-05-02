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
        if (lists.empty()) {
            return nullptr;
        }
        ListNode* result = new ListNode(0);
        ListNode* resultHead = result;
        
        // Iterate through the list of lists
        // Find the minimum among the head and add it to result, set next node as head for that list
        // Whenever a list is exhausted (head == nullptr), nonEmptyLists--
        int nonEmptyLists = lists.size();
        while (nonEmptyLists > 0) {
            ListNode* minNode = nullptr;
            int minIndex = -1;
            for(int i = 0; i < lists.size(); ++i) {
                if (lists[i] && !minNode) {
                    minNode = lists[i];
                    minIndex = i;
                }

                if (lists[i] && lists[i]->val < minNode->val) {
                    minNode = lists[i];
                    minIndex = i;
                }
            }
            
            result->next = minNode;
            result = result->next;
            minNode = minNode->next;
            lists[minIndex] = minNode;
            
            if (!minNode) {
                nonEmptyLists--;
            }
        }

        return resultHead->next;
    }
};
