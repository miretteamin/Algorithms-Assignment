#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int *A = new int[n];
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        A[i] = temp;
    }

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(i < j && A[i] > A[j])
            {
                counter++;
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}
