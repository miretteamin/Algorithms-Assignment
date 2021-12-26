#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();

	// we will assume we have an array of toys  0 for working 1 for defective
	// the serial number is the index
	// we can't use binary search to find the the defective one
	// because we don't have its key
	vector<int> toys = {0,0,0,1,0,1,1,1,1,};
	for  (int i=0;i<toys.size();i++){
		if (toys[i] == 1) {
			cout << "first defective toy at "<<i<< endl;
			break;
		}
	}
	return 0;
}