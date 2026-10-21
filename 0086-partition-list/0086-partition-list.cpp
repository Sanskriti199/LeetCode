class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = new ListNode(0);
        ListNode* largeHead = new ListNode(0);

        ListNode* small = smallHead;
        ListNode* large = largeHead;

        while (head != NULL) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }

            head = head->next;
        }

        large->next = NULL;
        small->next = largeHead->next;

        return smallHead->next;
    }
};