#include<iostream>
#include<vector>
using namespace std;

void min_heapify(vector<int> &arr,int n,int i){
    int smallest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if(left_child < n && arr[left_child] < arr[smallest]){
        smallest = left_child;
    }

    if(right_child < n && arr[right_child]< arr[smallest]){
        smallest = right_child;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

void build_min_heap(vector<int> &arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        min_heapify(arr, n, i);
    }
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    build_min_heap(arr);
    cout << "Min Heap: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}