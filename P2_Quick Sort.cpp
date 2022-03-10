#include <iostream>
#include <vector>
using namespace std;

long long m_w, m_z;
long long get_random() {
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    long long res = (m_z << 16) + m_w;
    return res % 1000000000;
}

long long partitionQ(long long *arr, long long startIndext, long long endIndex)
{
    long long pivot = *(arr+endIndex);
    long long pIndex = startIndext;
    long long temp;
    for(long long i= startIndext; i<=endIndex; i++)
    {
        if(*(arr+i)<pivot)
        {
            temp = *(arr+pIndex);
            *(arr+pIndex)= *(arr+i);
            *(arr+i) = temp;
            pIndex++;
        }
    }
    temp =  *(arr+pIndex);
    *(arr+pIndex)=pivot;
    *(arr+endIndex) =  temp;
    return pIndex;
}

long long kElement(long long *arr, long long startIndex, long long endIndex, long long k)
{
    if(startIndex == endIndex)
        return arr[startIndex];
    long long t1 = partitionQ(arr, startIndex, endIndex);
    long long rank = t1 - startIndex + 1;
    if(rank == k)
        return arr[t1];
    if(rank > k)
        return kElement(arr, startIndex, t1-1, k);
    else
        return kElement(arr, t1 + 1, endIndex, k - rank);
}

int main() {
    long long aSize;
    long long k; //find k-th minimum element
    cin>>aSize;
    cin>>k;
    cin>>m_w;
    cin>>m_z;
    long long *arr = new long long[aSize];

    for(long long i = 0; i < aSize; i++)
    {
        arr[i] = get_random();
    }
    long long res =  kElement(arr, 0, aSize, k);
    cout<<res<<endl;

    return 0;
}
