#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

bool finishCompare(pair<int,int> &a, pair<int,int> &b)
{
       return a.second < b.second;
}

int main()
{
    vector<pair<int, int>> vec;
    cout << "Input all activities start and finish time in one line separated by spaces" <<endl;
    string buf;
	int first, second;
	getline(cin, buf);
	istringstream str(buf);
	while (str >> first >> second) {
		vec.push_back(make_pair(first, second));
	}
    sort(vec.begin(),vec.end(), finishCompare);


    vector<pair<int, int>>selectedActivity;
    selectedActivity.push_back(vec[0]);
    int i=0;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if(it->first >=selectedActivity[i].second)
        {
            i++;
            selectedActivity.push_back(*it);
        }
    }
    for (auto it = selectedActivity.begin(); it != selectedActivity.end(); it++)
        cout << "{ "<<it->first << ", " << it->second << " }"<< endl;

}
