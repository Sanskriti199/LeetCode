class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }
        
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) pq.push(node->next);
            }
        
            return head->next;
        }
};
