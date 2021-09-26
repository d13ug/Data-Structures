#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *deleteHead(Node *head){
    if(head == NULL){
        return NULL;
    }
    else{
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *deleteTail(Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    else{
        Node *temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
        return head;
    }
}

void printList(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    cout<<"Before Deletion : ";
    printList(head);

    head = deleteHead(head);
    cout<<"\nAfter Head Deletion : ";
    printList(head);

    head = deleteTail(head);
    cout<<"\nAfter Tail Deletion : ";
    printList(head);
    return 0;
}