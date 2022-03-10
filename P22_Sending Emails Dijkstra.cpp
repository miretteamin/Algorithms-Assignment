#include <iostream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

int** graph;
string MessageShort(vector<int>InitialData)
{
        int*distance = new int[InitialData.at(0)];
        for (int j = 0; j < InitialData.at(0); j++)
        {
            distance[j] = 10000;
        }
        distance[InitialData.at(2)] = 0;
        stack<int> s;
        s.push(InitialData.at(2));
        for (int i = 0; i < InitialData.at(0) - 1; i++)
        {
            int compare = s.top();
            s.pop();
            while(!s.empty())
            {
                compare=distance[s.top()]<distance[compare]?s.top():compare;
                s.pop();
            }
            for (int j = 0; j < InitialData.at(0); j++)
                if ( graph[compare][j] != 0  && distance[compare] + graph[compare][j] < distance[j] && distance[compare] != 10000)
                {
                    distance[j] = distance[compare] + graph[compare][j];
                    s.push(j);
                }
        }
        if (distance[InitialData.at(3)]==10000)
            return "unreachable";
        else
            return to_string(distance[InitialData.at(3)]);
}

int main()
{
    vector<string> outputCases;
    int times;
    cin>> times;
    cin.ignore();
    while(times--)
    {
        vector<int>InitialData;
        string buf;
        int input;
        getline(cin, buf);
        istringstream str(buf);
        while (str >> input ) {
            InitialData.push_back(input);
        }
        graph = new int* [InitialData.at(0)];
        for(int i=0; i< InitialData.at(0); i++)
            graph[i] = new int [InitialData.at(0)];

        for(int i=0; i<InitialData.at(0); i++ )
            for(int j=0; j<InitialData.at(0); j++ )
                    graph[i][j]=0;
        int flag=0, error=0;
        for(int i=0; i<InitialData.at(1); i++)
        {
            int r, c, v;
            cin >> r;
            cin >> c;
            cin >> v;
            if(r>=InitialData.at(0) || c>=InitialData.at(0) || r<0 ||c <0)
                error =1;
            else
            {
                graph[r][c] = v;
                graph[c][r] = v;
            }
            flag=1;
        }
        if(flag)
        {
            cin.ignore();
            flag=0;
        }
        if(!error)
            outputCases.push_back(MessageShort(InitialData));
            else
            {
                cout << "Wrong input route"<<endl;
                error=0;
            }
    }
     for (int i=0; i<outputCases.size(); i++)
    {
        cout << "Case #" <<i+1 << ": " <<outputCases[i] <<endl;
    }
}

