#include <iostream>
#include <vector>


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first n + 1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both until first reaches end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node
        ListNode* toDelete = second->next;
        second->next = second->next->next;
        // delete toDelete; // In LeetCode usually we don't delete nodes as they might be used elsewhere or memory management is handled differently, but for local C++ it's good practice. However, to match LeetCode style strictly I might skip it, but for correctness I'll keep it.

        ListNode* newHead = dummy->next;
        // delete dummy;
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
