class Solution {
public:
    int helper(ListNode *head,int k){
        ListNode *temp=head;  
        while(head->next!=head){   
            ListNode *pre=NULL;
            for(int i=1; i<k; i++){
                pre=temp;
                temp=temp->next;
            }
           
            if(temp==head)
                head=head->next;
            pre->next=temp->next;
            delete(temp);
            temp=pre->next;
        }
       
        return head->val;
    }
    int findTheWinner(int n, int k) {
        if(k==1)
            return n;
       
        ListNode *head=NULL,*tail=NULL;
        for(int i=1; i<=n; i++){
            ListNode *node=new ListNode(i);
            if(head==NULL)
                head=tail=node;
            else{
                tail->next=node;
                tail=node;
            }
            tail->next=head;
        }
       
        return helper(head,k);
    }
};