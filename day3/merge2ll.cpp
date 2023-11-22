#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
void insert(Node<int>* prev, Node<int>* temp, Node<int>* curr) {
    prev->next = temp;
    temp->next = curr;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }

    Node<int>* mergedList = NULL;
    Node<int>* current = NULL;

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            if (mergedList == NULL) {
                mergedList = first;
                current = first;
            } else {
                current->next = first;
                current = first;
            }
            first = first->next;
        } else {
            if (mergedList == NULL) {
                mergedList = second;
                current = second;
            } else {
                current->next = second;
                current = second;
            }
            second = second->next;
        }
    }

    if (first != NULL) {
        current->next = first;
    } else if (second != NULL) {
        current->next = second;
    }

    return mergedList;
}
