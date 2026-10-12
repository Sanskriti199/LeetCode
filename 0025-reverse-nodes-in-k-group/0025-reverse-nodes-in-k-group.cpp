class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k) return head;

        ListNode* prev = nullptr;
        curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};