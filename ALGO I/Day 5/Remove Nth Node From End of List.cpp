class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        	ListNode* iter = head;
	int len = 0, i = 1;
	while(iter) iter = iter -> next, len++;    
	if(len == n) return head -> next;         
	for(iter = head; i < len - n; i++) iter = iter -> next; 
	iter -> next = iter -> next -> next;    
	return head;
        
    }
};