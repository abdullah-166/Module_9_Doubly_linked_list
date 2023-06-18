#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int value)
        {
            this->value=value;
            this->next=NULL;
            this->prev=NULL;
        }
};
void print_left_to_right(Node* head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value << " ";
        temp=temp->next;
    }
    cout<<endl;
}
void print_right_to_left(Node* tail)
{
    Node *temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
int main()
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node *tail=b;
    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;
    print_left_to_right(head);
    print_right_to_left(tail);
    return 0;
}