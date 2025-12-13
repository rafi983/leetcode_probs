class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);

        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;
        bool result = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        slow->next = reverseList(secondHalfCopy);

        return result;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

