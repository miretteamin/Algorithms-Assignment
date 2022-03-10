#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int allNumbers[5001];

int getMinSteps(int l, int r){
    if (l > r)
    return 0;
    int minSeq =allNumbers[l];
    int minIndex =l;
    for (int i=l;i<= r;i++){
        if (allNumbers[i]< minSeq){
            minSeq = allNumbers[i];
            minIndex = i;
        }
    }
    for (int i=l;i<=r;i++){
        allNumbers[i] -= minSeq;
    }

    return min(r-l + 1, minSeq + getMinSteps(l,minIndex-1)+ getMinSteps(minIndex+1,r) );

}

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();

	int n ;
	cout << "size: ";
	cin >> n ;
	allNumbers[0] = 0;
	cout << "values: ";
    for (int i=1;i<=n;i++){
        cin >> allNumbers[i];
    }

    int result = getMinSteps(1,n);
    cout << result <<endl;

	return 0;
}
