class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* newHead = prev;
        int maxVal = newHead->val;
        curr = newHead;

        while (curr->next) {
            if (curr->next->val < maxVal) {
                curr->next = curr->next->next;
            } else {
                maxVal = curr->next->val;
                curr = curr->next;
            }
        }

        prev = nullptr;
        curr = newHead;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

