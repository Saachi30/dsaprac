/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
int getLen(Node *head) {
  int size = 0;
  Node *temp = head;
  while (temp != NULL) {
    temp = temp->next;
    size++;
  }
  return size;
}
Node *kReverse(Node *head, int k) {
  // Write your code here.
  int count = 0;
  if (head == NULL) {
    return NULL;
  }
  Node *prev = NULL;
  Node *curr = head;
  Node *next = NULL;
  int size=getLen(head);
  //cout<<size;
  if (size / k > 0) {
    while (curr != NULL && count < k) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      count++;
    }

    if (next != NULL) {
      head->next = kReverse(next, k);
    }
    return prev;
  } else {
    return head;
  }
}