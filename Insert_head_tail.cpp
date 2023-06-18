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
void insert_any_position(Node *head,int pos,int val)
{
    Node* newnode = new Node(val);
    Node *temp=head;
    for(int i=1; i<=pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
    newnode->prev=temp;
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
void insert_head(Node *&head, Node *&tail,int val)
{
    Node *newnode = new Node(val);
    newnode->next=head;
    head->prev=newnode;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    head=newnode;
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
    int pos,val;
    cin>>pos>>val;
    if(pos==0)
    {
        insert_head(head,tail,val);
    }
    else if(pos == size(head))
    {
        insert_tail(head,tail,val);
    }
    else if(pos>=size(head))
    {
        cout<<"Invalid position!!!";
    }
    else
    {
        insert_any_position(head,pos,val);
    }
    cout << endl;
    print_normal(head);
    print_reverse(tail);
    return 0;
}