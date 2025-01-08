#include<iostream>
#include<stack>
using namespace std;
#define MAX 100
stack<int> s;

void push(int ele){
    if(s.size() == MAX-1){
        cout<<("Stack Overflow\n");
        return;
    }
    s.push(ele);
}

int pop(){
    if(s.empty()){
        cout<<("Stack Underflow\n");
        return -1;
    }
    int temp = s.top();
    s.pop();
    return temp;
}

void disp(){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    disp();
    return 0;
}