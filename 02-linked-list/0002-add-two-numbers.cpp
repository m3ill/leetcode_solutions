/*
* Problem: LeetCode 2 - Add Two Numbers
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Linked List / Elementary Math
 * Time Complexity: O(max(m, n))
 * Space Complexity: O(max(m, n))
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
    public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        int carry = 0;

        while (l1 || l2 || carry != 0) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int total = val1 + val2 + carry;
            carry = total / 10;//bir üst basamağa gidecek olan
            int digit = total % 10;//o basamağa yazılacak olan

            cur->next = new ListNode(digit);
            cur = cur->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

        }

        ListNode* result = head->next;
        delete head;
        return result;


    }

};
