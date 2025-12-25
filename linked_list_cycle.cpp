#include <iostream>
#include <vector>


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

// Helper function to create a linked list with a cycle
// pos is the index (0-indexed) where the tail connects to. -1 means no cycle.
ListNode* createListWithCycle(const std::vector<int>& nums, int pos) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    std::vector<ListNode*> nodes;
    nodes.push_back(head);

    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
        nodes.push_back(curr);
    }

    if (pos >= 0 && pos < nodes.size()) {
        curr->next = nodes[pos];
    }

    return head;
}
