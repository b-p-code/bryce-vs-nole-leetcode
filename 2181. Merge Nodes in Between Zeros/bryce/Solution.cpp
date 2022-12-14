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
    ListNode* mergeNodes(ListNode* head) {
		// Pretty fast
		// Speed: 94.90%
		// Memory: 68.57%
        if (head == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;

        while (second != nullptr) {
            // Use this pointer to keep track of the element right before the last zero
            prev = first;

            if (second->val == 0) {
                first->next = second;
                first = second;
            } else {
                first->val += second->val;
            }
            second = second->next;
        }

        // Remove last element
        prev->next = nullptr;

        return head;
    }
};