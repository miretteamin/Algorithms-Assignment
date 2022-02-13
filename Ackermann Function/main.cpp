#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Primitive Funtion is the function that has base case and be computed in finite number of cycles, Function that can be obtained by a successor, zero and projection.
// Ackermann is Total recursive but not primitive recursive Function 
int ack(int m, int n)
{
	if (m == 0)
		return n + 1;

	else if ((m > 0) && (n == 0))
		return ack(m - 1, 1);

	else if ((m > 0) && (n > 0))
		return ack(m - 1, ack(m, n - 1));

}

//vector<vector<int>>ackMemoization(1000, vector<int>(1000, -1));

ll modifiedAck(ll m, ll n)
{
	if (m == 0)
		return n + 1;
	if (m == 1)
		return n + 2;
	if (m == 2)
		return 2 * n + 3;
	if (m > 2 && n == 0)
		return modifiedAck(m - 1, 1);  //return 1 << ((n + 3) - 3); for m = 3
	if ((m > 2) && (n > 0))
		return modifiedAck(m - 1, modifiedAck(m, n - 1));


	/*
	*******Memoization*******
	
		if (ackMemoization[m][n] != -1)
		return ackMemoization[m][n];

		if (m == 0)
			ackMemoization[m][n] = n + 1;

		else if (m > 0 && n == 0)
			ackMemoization[m][n] = modifiedAck(m - 1, 1);

		else
			ackMemoization[m][n] = modifiedAck(m - 1, modifiedAck(m, n - 1));
	*/
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();

	//This Function grows very quickly:

	cout << "Using Recursion and basic Ackermann:\n";
	cout << "m = 0, n = 2  Ack = " << ack(0, 2) << endl;
	cout << "m = 1, n = 2  Ack = " << ack(1, 2) << endl;
	cout << "m = 2, n = 2  Ack = " << ack(2, 2) << endl;
	cout << "m = 3, n = 2  Ack = " << ack(3, 2) << endl;
	cout << "Cannot compute ack(4, 2) using simple recursion as it's about 2*10^19728 \n";

	cout << endl;

	cout << "m = 0, n = 1  Ack = " << ack(0, 1) << endl;
	cout << "m = 1, n = 1  Ack = " << ack(1, 1) << endl;
	cout << "m = 2, n = 1  Ack = " << ack(2, 1) << endl;
	cout << "m = 3, n = 1  Ack = " << ack(3, 1) << endl;
	cout << "Cannot compute ack(4, 1) using simple recursion\n";


	//So, it's an exhaustive function that is hard to be computed

	cout << "------------------------------------------------------------\nUsing Modified Ackermann (Direct Computation)\n\n";

	cout << "m = 0, n = 1  Ack = " << modifiedAck(0, 1) << endl;
	cout << "m = 1, n = 1  Ack = " << modifiedAck(1, 1) << endl;
	cout << "m = 2, n = 1  Ack = " << modifiedAck(2, 1) << endl;
	cout << "m = 3, n = 1  Ack = " << modifiedAck(3, 1) << endl;
	cout << "m = 4, n = 1  Ack = " << modifiedAck(4, 1) << endl;

	// We can optimize more by using Memoization as shown in modifiedAck function Comment Section but has a problem of bad space complexity


	cout << endl << "-------------Sample Inputs------------\n";
	cout << "m = 3, n = 3  Ack = " << modifiedAck(3, 3) << endl;
	cout << "m = 4, n = 1  Ack = " << modifiedAck(4, 1) << endl;

	return 0;
}