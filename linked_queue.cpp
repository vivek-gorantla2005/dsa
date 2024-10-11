#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

class Queue{
    private:
    struct node *f;
    struct node *r;

    public:
    Queue(){
        f = NULL;
        r = NULL;
    }
    void enqueue(int val){
        if(f == NULL && r == NULL){
            f = r = createnode(val);
        }else{
            struct node *newnode = createnode(val);
            r->right = newnode;
            newnode->left = r;
            r = newnode;
        }
    }

    void dequeue(){
        if(f == NULL){
            cout << "Queue is empty" << endl;
            return;
        }
        struct node *temp = f;
        f = f->right;
        free(temp);
    }

    void disp(){
        if(f == NULL){
            cout << "Queue is empty" << endl;
            return;
        }
        struct node *temp = f;
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Queue before dequeuing: ";
    q.disp();
    q.dequeue();
    cout << "Queue after dequeuing: ";
    q.disp();
    return 0;
    
}