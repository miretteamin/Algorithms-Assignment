#include <iostream>
#include <vector>
using namespace std;

int getInd(vector<pair<int,int>> v)
{
    int min = v[0].second;
    int minIndex;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].second < min && v[i].second != -1)
        {
            min = v[i].second;
            minIndex = i;
        }
    }
    return v[minIndex].first;
}

int findFun(vector<pair<int,int>> k, int element)
{
    for(int i = 1; i < k.size(); i++)
    {
        if(k[i].first == element && k[i].second != -1)
            return 1;
    }
    return -1;
}

void MST(vector<vector<pair<int,int>>> g)
{
    vector<pair<int,int>> key(g.size());
    for(int i = 2; i < g.size();i++)
    {
        key[i].second = 99999;
        key[i].first = i;
    }
    key[1].second = 0;
    key[1].first = 1;
    key[0].second = 99999;
    key[0].first = 99999;

    int output[g.size()];

    int counter = 1;

    while(counter < g.size())
    {
        int vertix = getInd(key);
        for(int i = 0; i < g[vertix].size();i++)
        {
            pair<int,int> v = g[vertix][i];
            if(findFun(key, v.first) != -1 && v.second < key[v.first].second)
            {
                key[v.first].second  = v.second;
                output[v.first] = vertix;
            }
        }
        key[vertix].second = -1;
        counter++;
    }
    cout<<"v1 start"<<endl;
    for(int i = 2; i < g.size(); i++)
    {
        cout<< 'v'<< i << " "<<'v'<<output[i]<<endl;
    }
}

int main() {
    int vertices, edges;
    cout<<"Enter Number of Vertex in the graph: "<<endl;
    cin>>vertices;
    cout<<"Enter Number of Edges in the graph: "<<endl;
    cin>>edges;
    vector<vector<pair<int,int>>> g(vertices+1);
    for(int i = 0; i < edges; i++)
    {
        string v1,v2;
        int w;
        cout<<"Enter First vertex: "<<endl;
        cin>>v1;
        cout<<"Enter Second vertex: "<<endl;
        cin>>v2;
        cout<<"Enter Edge weight: "<<endl;
        cin>>w;
        v1 = v1[1];
        v2 = v2[1];
        g[stoi(v1)].push_back(make_pair(stoi(v2),w));
        g[stoi(v2)].push_back(make_pair(stoi(v1),w));
    }
    MST(g);

    return 0;
}
