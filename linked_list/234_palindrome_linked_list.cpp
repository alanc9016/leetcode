class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
            
        if (fast != nullptr) { // odd nodes: let right half smaller
            slow = slow->next;
        }
        
        slow = reverse(slow);
        fast = head;
        
        while (slow != nullptr) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    } 
};