#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	unordered_map<int, int>mp;
	string buffer;
	int nb;
	getline(cin, buffer);
	istringstream in(buffer);
	while (in >> nb) {
		mp[nb]++;
	}
	cout << "{";
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		for (int j = 0; j < it->second; j++)
			cout << it->first <<' ';

	}
	cout << "}" << endl;
	return 0;
}