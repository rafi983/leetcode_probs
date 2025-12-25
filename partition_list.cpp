#include <iostream>
#include <vector>


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                less->next = curr;
                less = less->next;
            } else {
                greater->next = curr;
                greater = greater->next;
            }
            curr = curr->next;
        }

        greater->next = nullptr;
        less->next = greaterHead->next;

        ListNode* newHead = lessHead->next;
        // delete lessHead;
        // delete greaterHead;

        return newHead;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val;
        if (curr->next != nullptr) {
            std::cout << " -> ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}
