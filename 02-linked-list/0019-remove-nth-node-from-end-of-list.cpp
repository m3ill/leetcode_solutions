//
// Created by Mertcan on 31.07.2026.
//

#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {return nullptr;}
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }
        //listede kaç tane değer var onu bulacağız
        ListNode *temp= head;
        int length = 0;
        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }

        if (length == n) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int removed_index = length-n-1;

        temp = head;
        for (int i = removed_index; i > 0; i--) {
            temp = temp->next;
        }

        ListNode* new_node = temp->next;
        temp->next = temp->next->next;
        delete new_node;
        new_node = nullptr;


        return head;
    }
};