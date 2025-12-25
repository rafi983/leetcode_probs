#include <iostream>
#include <vector>


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to next pair
            prev = first;
        }

        ListNode* newHead = dummy->next;
        // delete dummy; // Optional cleanup
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
