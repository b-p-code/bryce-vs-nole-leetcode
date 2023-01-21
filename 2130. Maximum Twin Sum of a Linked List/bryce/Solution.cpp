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
    int pairSum(ListNode* head) {
        // Speed: 96.18%
        // Memory: 52.77%

        // We need random access, so let's transfer this data to an array
        // This has to happen since anything else using just a linked list
        // will appear to have N^2 time complexity
        ListNode* node = head;

        // Determine the size of the list
        int size = 0;
        while (node != nullptr) {
            size++;
            node = node->next;
        }

        int* vals = new int[size];

        // Extract values
        node = head;
        int k = 0;
        while (node != nullptr && k < size) {
            vals[k] = node->val;
            node = node->next;
            k++;
        }

        // Iterate over array to find max twin sum
        int max = 0;
        int result = 0;
        for (int i = 0, j = size - 1; i < size; i++, j--) {
            result = vals[i] + vals[j];
            if (i != j && result > max) {
                max = result;
            }
        }

        return max;
    }
};