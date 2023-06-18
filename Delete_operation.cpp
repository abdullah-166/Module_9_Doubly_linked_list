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
int size(Node *head)
{
    Node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void delete_at_position(Node *head, int pos)
{
    Node *temp=head;
    for(int i=1; i<=pos-1;i++)
    {
        temp=temp->next;
    }
    Node *deletenode=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete deletenode;
}
void delete_tail(Node *&tail)
{
    Node *deletenode = tail;
    tail=tail->prev;
    delete deletenode;
    tail->next=NULL;
}
void delete_head(Node *&head)
{
    Node *deletenode = head;
    head=head->next;
    delete deletenode;
    head->prev=NULL;
}
int main()
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node *tail=c;
    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;
    b->next=c;
    c->prev=b;
    int pos;
    cin>>pos;
    if(pos>=size(head))
    {
        cout<<"Invalid Position!!!"<<endl;
    }
    else if(pos == 0)
    {
        delete_head(head);
    }
    else if(pos == size(head)-1)
    {
        delete_tail(tail);
    }
    else 
    {
        delete_at_position(head,pos);
    }
    print_normal(head);
    print_reverse(tail);
    return 0;
}