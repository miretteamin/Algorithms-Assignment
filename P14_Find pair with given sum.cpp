#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	unordered_map<int, int>mp;
	string buffer;
	int nb, target, p1, p2;
	getline(cin, buffer);
	istringstream in(buffer);
	while (in >> nb) {
		mp[nb]++;
	}
	cin >> target;
	bool flag = false;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		if (mp.find(target - it->first) != mp.end()) {
			if ((target - it->first) == it->first) {
				if (it->second < 2)
					break;
			}
			flag = true;
			p1 = it->first;
			p2 = target - it->first;
			break;
		}
	}
	if (flag)
		cout << "Pair found (" << p1 << ", " << p2 << ')' << endl;
	else
		cout << "Pair not found" << endl;
	return 0;
}