Node* startofloop(Node* head){
     Node* slow=head;
    Node* fast=head;
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return NULL;
        }
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast){
                Node* intersection=slow;
                slow=head;
                fast=intersection;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }

        }
        return NULL;
    }

Node *removeLoop(Node *head) {
    Node* start=startofloop(head);
    Node* temp=start;
    if(start==NULL){
        return head;
    }
    while(temp->next!=start){
        temp=temp->next;

    }
    temp->next=NULL;
    return head;

}
