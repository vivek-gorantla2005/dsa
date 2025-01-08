#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

class Linkedlist{
    private:
    struct node *head;
    
    public:
    Linkedlist(){
        head = NULL;
    };

    struct node *createnode(int data){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    };

    void insertatbeg(int data){
        if(head == NULL){
            head = createnode(data);
        }
        else{
            struct node *newnode = createnode(data);
            newnode->next = head;
            head = newnode;
        }
    }

    void disp(){
        struct node *temp = head;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Linkedlist head;
    head.insertatbeg(10);
    head.insertatbeg(20);
    head.insertatbeg(30);
    head.disp();
    return 0;
}   