#include <bits/stdc++.h>

using namespace std;

// p3 really special subtree

typedef long long  ll;

int parent[3000];

int size[3000];


int findParent(int i){
    if (parent[i] !=  -1){
        return findParent(parent[i]);
    }
    return i;
}
int unite(int i,int x){
    if (size[x] > size[i]){
        parent[i]  = x;
        size[x] += size[i];
        return x;
    }
    else{
        parent[x] = i;
        size[i] += size[x];
        return i;
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    memset(parent,-1,sizeof(int) * (g_nodes+1));
    memset(size,1,sizeof(int) * (g_nodes+1));
    vector<vector<int>> edges;
    for(int i=0;i<g_from.size();i++){
        edges.push_back({g_weight[i],g_from[i],g_to[i]});
    }
    sort(edges.begin(),edges.end());
    int mWeight =0;
    // cout << edges.size() <<endl;
    for(int i=0;i<edges.size();i++){
        int p1 = findParent(edges[i][1]);
        int p2 =findParent(edges[i][2]);
        if ( p1 != p2  ){
            int parent =  unite(edges[i][1], edges[i][2]);
            mWeight += edges[i][0];
            if (size[parent] == g_nodes)break;

        }
    }




    return mWeight;
}

int main()
{
    cout << "Enter the nNodes nEdges and press Enter\n";
    int nodes;
    int edges;
    cin >> nodes >> edges;

    cout << "Enter each edge in format from to weight\n" ;
    vector<int> from(edges);
    vector<int> to(edges);
    vector<int> weight(edges);
    for(int i=0;i<edges;i++){
        cin >> from[i] >> to[i] >> weight[i];
    }
    int res = kruskals(nodes,from, to ,weight);
    cout << res <<endl;

    return 0;
}