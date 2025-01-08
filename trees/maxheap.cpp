#include<iostream>
#include<vector>
using namespace std;

void max_heapify(vector<int> &arr,int n,int i){
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if(left_child < n && arr[left_child] > arr[largest]){
        largest = left_child;
    }

    if(right_child < n && arr[right_child]> arr[largest]){
        largest = right_child;
    }

    if(largest != i){
        
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void build_max_heapify(vector<int> &arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        max_heapify(arr, n, i);
    }
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    build_max_heapify(arr);
    cout << "Max Heap: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}