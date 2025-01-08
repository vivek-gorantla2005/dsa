#include <iostream>

using namespace std;

class DisjointSet {
    int rank[100];   
    int parent[100]; 

public:
    DisjointSet(int n) {
        for (int i = 1; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ultimateparent_u = findparent(u);
        int ultimateparent_v = findparent(v);

        if (ultimateparent_u == ultimateparent_v) {
            return;
        }
        if (rank[ultimateparent_u] < rank[ultimateparent_v]) {
            parent[ultimateparent_u] = ultimateparent_v;
        } else if (rank[ultimateparent_v] < rank[ultimateparent_u]) {
            parent[ultimateparent_v] = ultimateparent_u;
        } else {
            parent[ultimateparent_v] = ultimateparent_u;
            rank[ultimateparent_u]++;
        }
    }
};

// Custom bubble sort function to sort edges by weight
void bubbleSort(int edges[][3], int num_edges) {
    for (int i = 0; i < num_edges - 1; i++) {
        for (int j = 0; j < num_edges - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                for (int k = 0; k < 3; k++) {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }   
            }
        }
    }
}

// Kruskal's algorithm using static arrays
void KruskalMST(int n, int edges[][3], int num_edges) {
    bubbleSort(edges, num_edges);

    DisjointSet ds(n);
    int mst_weight = 0;
    int mst_edges[100][2];
    int mst_edge_count = 0;

    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        // Check if the current edge forms a cycle
        if (ds.findparent(u) != ds.findparent(v)) {
            // If no cycle, add this edge to the MST
            ds.unionbyrank(u, v);
            mst_weight += weight;
            // Store the edge in the MST array
            mst_edges[mst_edge_count][0] = u;
            mst_edges[mst_edge_count][1] = v;
            mst_edge_count++;
        }
    }
 
    cout << "Minimum Spanning Tree weight: " << mst_weight << endl;
    cout << "Edges in the MST:" << endl;
    for (int i = 0; i < mst_edge_count; i++) {
        cout << mst_edges[i][0] << " - " << mst_edges[i][1] << endl;
    }
}

int main() {
    int n = 7; 
    int num_edges = 7; 

    int edges[7][3] = {
        {1, 2, 1}, {2, 3, 2}, {4, 5, 3}, {6, 7, 4}, {5, 6, 5}, {3, 7, 6}, {2, 5, 7}
    };

    KruskalMST(n, edges, num_edges);

    return 0;
}
