#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int hashString (string s,int maxSize){
	int code=0;
	for (int i = 0; i < s.length(); i++)
	{
		code += (s[i] - '0' )* pow(17,i+1);
	}
	return code % maxSize;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	/*
	we could store the employees table using hashing so hash every primary key 
	and reorder or store the employees in a list where every employee gets
	 the index resulting from the hash
	and when we try to join we take every foreign key, hash it using the same method and access the index of the list
	this method can get us a complexity of O(M) # M is the number of transactions
	otherwise we can store the employees table in a BST/ AVL  which can get us a complexity of  O(MlogN)
	*/	
	int maxSize = 20;
	vector<vector<string>> employees;
	employees.push_back({"XDFSE1" ,"Jack" ,"Electronics"});
	employees.push_back({"XDVBA2" ,"Mary" ,"Aesthetics"});
	employees.push_back({"XDASA1" ,"Joe" ,"Aesthetics"});

	vector<vector<string>> reOrderedEmployees(maxSize,vector<string>({"","",""}));

	for(auto emp : employees){
		int empIndex = hashString(emp[0],maxSize);
		cout << empIndex << " " << emp[0] << endl;
		reOrderedEmployees[empIndex][0] = emp[0];
		reOrderedEmployees[empIndex][1] = emp[1];
		reOrderedEmployees[empIndex][2] = emp[2];
	}

	vector<vector<string>> transactions;
	transactions.push_back({"TV" ,"XDFSE1" ,"Mark"});
	transactions.push_back({"Radio" ,"XDFSE1" ,"Susan"});
	transactions.push_back({"Skincare Ointment" ,"XDVBA2" ,"Skincare Ointment"});

	for(auto tr : transactions){
		int hash = hashString(tr[1],maxSize);
		cout << tr[0] << " " << tr[1] << " " << tr[2] <<" " << reOrderedEmployees[hash][1] << " " << reOrderedEmployees[hash][2] << endl; 
	}

	
	return 0;
}