#include <iostream>
#include <vector>


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        ListNode* curr = head;

        while (curr) {
            // Check if we have k nodes left
            ListNode* check = curr;
            int count = 0;
            while (check && count < k) {
                check = check->next;
                count++;
            }

            if (count < k) {
                prevGroupTail->next = curr;
                break;
            }

            // Reverse k nodes
            ListNode* groupHead = curr;
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;

            for (int i = 0; i < k; ++i) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            prevGroupTail->next = prev;
            groupHead->next = curr;

            prevGroupTail = groupHead;
        }

        return dummy->next;
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
