#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> rank , parent;
    
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1); 
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
    };

    int findparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    };

    void unionbyrank(int u,int v){
        int ultimateparent_u = findparent(u);
        int ultimateparent_v = findparent(v);
        
        if(ultimateparent_u == ultimateparent_v){
            return;
        }
        if(rank[ultimateparent_u]<rank[ultimateparent_v]){
            parent[ultimateparent_u] = ultimateparent_v;
        }else if (rank[ultimateparent_v]<rank[ultimateparent_u]){
            parent[ultimateparent_v] = ultimateparent_u;
        }else{
            parent[ultimateparent_v] = ultimateparent_u;
            rank[ultimateparent_u]++;
        }
        
    }
};


int main(){
    DisjointSet ds(7);
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    ds.unionbyrank(4,5);
    ds.unionbyrank(6,7);
    ds.unionbyrank(5,6);
    if(ds.findparent(3) == ds.findparent(7)){
        cout << "Connected" << endl;
    }else{
        cout << "Not Connected" << endl;
    }

    ds.unionbyrank(3,7);
    if(ds.findparent(3) == ds.findparent(7)){
        cout << "Connected" << endl;
    }else{
        cout << "Not Connected" << endl;
    }
}