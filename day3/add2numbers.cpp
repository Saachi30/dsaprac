/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverseList(ListNode* head){
    if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=NULL;
        ListNode* curr;

        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* temp1=reverseList(l1);
        ListNode* temp2=reverseList(l2);
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum;
            if(temp1==NULL){
                sum=temp2->val+carry;
            }
            else if(temp2==NULL){
                sum=temp1->val+carry;
            }
            else{
            sum=temp1->val+temp2->val+carry;
            }
            ListNode* newnode=new ListNode(sum);
            
            if(sum>9){
                newnode->val=sum%10;
                carry=1;
            }
            else{
                carry=0;
            }
            if(ans==NULL){
                ans=newnode;
                curr=ans;
            }
            else{
                curr->next=newnode;
                curr=curr->next;
            }
            if(temp1!=NULL){
            temp1=temp1->next;
            }
            if(temp2!=NULL){
            temp2=temp2->next;
            }
        }
        if(carry==1){
             ListNode* newnode=new ListNode(1);
             curr->next=newnode;
                curr=curr->next;
        }
        return reverseList(ans);
    }
};