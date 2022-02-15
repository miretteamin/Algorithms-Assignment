#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	vector<int>vec;
	string buffer;
	int nb;
	getline(cin, buffer);
	istringstream in(buffer);
	while (in >> nb) {
		vec.push_back(nb);
	}
	int include = vec[0], exclude = 0;
	for (int i = 1; i < vec.size(); i++) {
		int temp = max(include, exclude);
		include = exclude + vec[i];
		exclude = temp;
	}
	cout << max(include, exclude) << endl;
	return 0;
}