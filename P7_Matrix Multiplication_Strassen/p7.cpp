#include <bits/stdc++.h>
using namespace std;

int main()
{
	//Matrix Multiplication Strassen

	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	cout << "Coordinates x then y: ";
	int x, y;
	cin >> x >> y;

	cout << "1. Translate\n2. Scale\n";
	int choice;
	cin >> choice;

	/*
	* Translation:
	* [xNew]	[1, 0, Tx]	 [xOld]
	* [yNew]  = [0, 1, Ty] * [yOld]
	* [1   ]	[0, 0, 1 ]	 [1   ]
	*
	* (Tx = translated value on x axis)
	* (Ty = translated value on y axis)
	*
	* Deduced Equations:
	* xNew = xOld + Tx
	* yNew = yOld + Ty
	*/

	/*
	* Sacling:
	* [xNew]	[a, 0, 0]	[xOld]
	* [yNew]  = [0, b, 0] * [yOld]
	* [1   ]	[0, 0, 1]	[1   ]
	*
	* (a, b = scaling factor)
	*
	* Deduced Equations:
	* xNew = a * xOld
	* yNew = b * yOld
	*/

	switch (choice)
	{
	case 1:
		int tx, ty;
		cout << "transtation value Tx then Ty\n";
		cin >> tx >> ty;
		cout << "New Coordinate: " << x + tx << ' ' << y + ty << endl;
		break;
	case 2:
		int a, b;
		cout << "Scaling value a then b\n";
		cin >> a >> b;
		cout << "New Coordinate: " << x * a << ' ' << y * b << endl;
		break;
	default:
		break;
	}

	return 0;
}