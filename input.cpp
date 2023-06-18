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
void print_normal(Node* head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value << " ";
        temp=temp->next;
    }
    cout<<endl;
}
void print_reverse(Node* tail)
{
    Node *temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
void insert_tail(Node *&head,Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=tail->next;
}
int main()
{
    Node * head = NULL;
    Node * tail = NULL;
    int val;
    while(true)
    {
        cin>> val;
        if(val==-1)
        {
            break;
        }
        insert_tail(head,tail,val);
    }
    print_normal(head);
    print_reverse(tail);
    return 0;
}