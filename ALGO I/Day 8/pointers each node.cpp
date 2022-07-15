 class Solution {
public:
       Node* connect(Node* root) {
        if(!root || !root -> left || !root -> right) return root;
        Node *ptr = root;
        while(ptr) {
            ptr -> left -> next = ptr -> right;
            if(ptr -> next)
                ptr -> right -> next = ptr -> next -> left;
            ptr = ptr -> next;
        }
        connect(root -> left);
        return root;
    }
   };

