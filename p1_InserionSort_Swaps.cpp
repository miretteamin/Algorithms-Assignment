#include <iostream>
using namespace std;



int main()
{
    int n =0, key, temp, j, num=0;
    cout << "Size: ";
    cin >> n;
    int* arr = new int [n];
    cout << "Enter values: ";
    for (int i=0; i<n; i++)
    {
        cin >> *(arr+i);
    }
    for(int i=1; i<5; i++) //Loop through the unsorted array
    {
        key = arr[i];
        j= i-1;  //The largest number in the sorted array
        while(j>=0 && key < arr[j])
        {
            num++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]= key;

    }
    cout << "Number of swaps: " <<num;
return 0;
}
