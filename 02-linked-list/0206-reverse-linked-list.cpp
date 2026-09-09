struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* newHead = nullptr;

        while (current != nullptr) {
            ListNode* tempNode = current->next;
            current->next = newHead;
            newHead = current;
            current = tempNode;
        }

        return newHead;
    }
};
