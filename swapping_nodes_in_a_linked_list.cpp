class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;

        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        temp = first;
        while (temp->next != nullptr) {
            temp = temp->next;
            second = second->next;
        }

        int tempVal = first->val;
        first->val = second->val;
        second->val = tempVal;

        return head;
    }
};

