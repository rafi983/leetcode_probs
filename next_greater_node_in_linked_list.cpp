#include <iostream>
#include <vector>
#include <stack>


class Solution {
public:
    std::vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        std::vector<int> answer(values.size(), 0);
        std::stack<int> s; // Stack stores indices

        for (int i = 0; i < values.size(); ++i) {
            while (!s.empty() && values[s.top()] < values[i]) {
                answer[s.top()] = values[i];
                s.pop();
            }
            s.push(i);
        }

        return answer;
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

// Helper function to print a vector
void printVector(const std::vector<int>& nums) {
    std::cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

