#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findTheifIndex(vector<char> temp)
{
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i] == 'T')
            return i;
    }
    return -1;
}

int findPoliceIndex(vector<char> temp)
{
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i] == 'P')
            return i;
    }

    return -1;
}

int main() {
    int n, k;
    cin>>n;
    cin>>k;
    vector<char> arr(n);
    for(int i = 0; i < n; i++)
    {
        char temp;
        cin>>temp;
        arr[i] = temp;
    }
    int counter = 0;
    int theifIndex = findTheifIndex(arr);
    int policeIndex = findPoliceIndex(arr);
    while(theifIndex != -1 && policeIndex != -1)
    {
        if(abs(theifIndex - policeIndex) <= k)
        {
            counter++;
            arr[theifIndex] = 'E';
            arr[policeIndex] = 'E';
            theifIndex = findTheifIndex(arr);
            policeIndex = findPoliceIndex(arr);
        }
        else
        {
            
            if(theifIndex < policeIndex)
            {
                arr[theifIndex] = 'E';
                theifIndex = findTheifIndex(arr);
            }
            else
            {
                arr[policeIndex] = 'E';
                policeIndex = findPoliceIndex(arr);
            }
        }
    }
    cout<<counter<<endl;

    return 0;
}
