#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> copyMap;
        Node* temp = head;

        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            copyMap.insert({temp, newNode});
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            Node* copy = copyMap[temp];
            copy->next = copyMap[temp->next];
            copy->random = copyMap[temp->random];
            temp = temp->next;
        }

        return copyMap[head];
    }
};
