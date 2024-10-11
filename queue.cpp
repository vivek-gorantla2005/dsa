#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 100  // Define the maximum size of the queue

queue<int> q;

void push(int value) {
    if (q.size() >= MAX_SIZE) {  // Check for overflow
        cout << "Queue Overflow\n";
        return;
    }
    q.push(value);  // Enqueue the value
    cout << value << " pushed to the queue." << endl;
}

void pop() {
    if (q.empty()) {  // Check for underflow
        cout << "Queue Underflow\n";
        return;
    }
    cout << q.front() << " popped from the queue." << endl;
    q.pop();  // Dequeue the front element
}

void disp() {
    if (q.empty()) {  // Check if the queue is empty
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue elements: ";
    int size = q.size();  // Get the current size of the queue
    for (int i = 0; i < size; ++i) {
        cout << q.front() << " ";  // Display the front element
        q.push(q.front());          // Reinsert the front element at the back
        q.pop();                    // Remove the front element
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    disp();  

    pop();    
    disp(); 

    return 0;
}
