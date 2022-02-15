#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	unordered_map<int, int>mp;
	string buffer;
	int nb, res = 100000;
	getline(cin, buffer);
	istringstream in(buffer);
	int idx = 0;
	bool flag = false;
	while (in >> nb) {
		auto it = mp.find(nb);
		if (it == mp.end())
			mp[nb] = idx;
		else {
			res = min(mp[nb], res);
			flag = true;
		}
		idx++;
	}

	if (flag)
		cout << "The minimum index of the repeating element is " << res << endl;
	else
		cout << "Invalid Input" << endl;
	return 0;
}
