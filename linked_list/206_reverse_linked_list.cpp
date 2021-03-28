class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;
        
        while (nextNode != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        
        curr->next = prev;
        head = curr;
        
        return head;
    }
};
