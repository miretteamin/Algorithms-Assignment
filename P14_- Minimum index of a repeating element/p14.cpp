#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	unordered_map<int, int>mp;
	string buffer;
	int nb, res = 0;
	getline(cin, buffer);
	istringstream in(buffer);
	while (in >> nb) {
		mp[nb]++;
	}
	bool flag = false;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second >= 2) {
			flag = true;
			break;
		}
		res++;
	}
	if (flag)
		cout << "The minimum index of the repeating element is " << res << endl;
	else
		cout << "Invalid Input" << endl;
	return 0;
}