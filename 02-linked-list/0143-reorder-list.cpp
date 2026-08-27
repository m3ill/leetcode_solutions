/*
 * Problem: LeetCode 143 - Reorder List
 * Pattern: Middle + Reverse + Merge
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* first = head;
        while (second != nullptr) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;

        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }

        return previous;
    }
};
