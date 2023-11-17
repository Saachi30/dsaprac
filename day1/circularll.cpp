#include <bits/stdc++.h>
/*************************************************
        Following is the structure of class Node:

        class Node{
        public:
            int data;
            Node* next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }

        }
**************************************************/
bool checkFullCycle(Node *fast, Node *slow, Node *head) {
   Node *intersection = slow;
      slow = head;
      fast = intersection;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      if (slow == head) {
        return true;
      }
      else{
          return false;
      }
}
bool isCircular(Node *head) {
  if (head == nullptr) {
    return true;
  }

  Node *slow = head;
  Node *fast = head;

  while (slow != NULL && fast != NULL && fast->next!=NULL && slow->next!=NULL) {
    fast = fast->next;
    if (fast != NULL) {
      fast = fast->next;
    }
    slow = slow->next;

    if (slow == fast) {
     return checkFullCycle(fast, slow, head);
    }
  }
  return false;
}

//Alternate approach but TLE

// bool isCircular(Node* head){
//     // Write your code here.
//     Node* curr=head;
//     if(head==NULL){
//         return true;
//     }
//    while(curr->next!=NULL && curr->next!=head){

//        curr=curr->next;

//    }
//    return (curr->next==head);

// }
