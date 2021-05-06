#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) : data(x),next(nullptr){} //constructor for creating a new node 
};

Node *head;
void insertatbeg(int x){
    Node *newnode= new Node(x);
    newnode->next=head;
    head=newnode;
}

void insertatend(int c){
    Node *newnode= new Node(c);
    Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newnode;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Node *a=new Node(2);
    // struct Node *a=(struct Node*)malloc(sizeof(struct Node)); 
    // a->data=4;
    // a->next=NULL;
    head= new Node(3);
    Node *b=new Node(5);
    head->next=b;
    Node *c=new Node(7);
    b->next=c;
    // insertatbeg(8);
    Node *p=head;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
    

}


