class Solution {
public:
    
    void copyList(Node* head) {
        
        Node* temp = head, *n = head->next;
        while(temp != NULL) {
            
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = n;
            temp = n;
            if(n != NULL)
                n = n->next; 
        }
    }
    
    void handleRandom(Node* head) {
        
        Node* temp = head;
        
        while(temp != NULL) {
            
            if(temp->random != NULL)
            temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    
    Node* detach(Node* head) {
        
        Node* dummy = new Node(-1);
        Node* tail = dummy, *temp = head;
        
        while(temp != NULL) {
            
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        
        // TC O(N)
        // SC O(1)
        
        if(head == NULL)
            return head;
        
        copyList(head);
        handleRandom(head);
        return detach(head);
        
    }
};
