#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};


class Stack{
    private:
    struct node *top;

    public:
    
    Stack(){
        top = NULL;
    };

    int gettop(){
        if(top == NULL){
            return 0;
        }
        return top->data;
    }

    void push(int val){
        if(top == NULL){
        top = new node();
        top->data = val;
        top->next = NULL;
        }else{
            struct node *temp = new node();
            temp->data = val;
            temp->next = top;
            top = temp;
        }
    }

    void pop(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return;
        }
        struct node *temp = top;
        top = top->next;
        free(temp);

    }

    void disp(){
        struct node *temp = top;
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.gettop() << endl;
    s.disp();
    s.pop();
    s.disp();
    return 0;
}