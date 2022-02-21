#include <iostream>
#include <vector>
using namespace std;


void printL(int**indexDivPtr, int i, int j)
{
    if(i==j)
    {
        cout<< "A"<<(i+1);
    }
    else
    {
        cout << "(";
        printL(indexDivPtr, i, indexDivPtr[i][j]);
        cout << "*";
        printL(indexDivPtr, indexDivPtr[i][j]+1, j);
        cout << ")";

    }


}
void matrix(int*dimPtr, int sizeM)
{
    int j, q;
    int costM[sizeM][sizeM];
    int **indexDiv =  new int*[sizeM];
    for(int i=0; i<sizeM; i++)
    {
        indexDiv[i] = new int [sizeM];
    }
    for(int i=0; i<sizeM; i++)
    {
       costM[i][i] = 0; //When i = j cost will be zero (No multiplications as one matrix we have)
    }
    for(int start=1; start<sizeM; start++)
    {
        for(int i=0 ; i<sizeM-start+1; i++) //the stop condition is number of element - start + 1 as 1 is the start cell itself
        {
            j= i+start;
            costM[i][j]=99999;
            for(int k=i; k<j; k++)
            {
                q = costM[i][k]+costM[k+1][j]+((*(dimPtr+(i)))*(*(dimPtr+k+1))*(*(dimPtr+j+1)));
                if(q<costM[i][j])
                {
                    costM[i][j] =q;
                    indexDiv[i][j] =k;
                }
            }
        }
    }
    printL(indexDiv, 0, sizeM-1);
}


int main()
{
    int n, flag=0;
    cout << "Number of matrices: ";
    cin>>n;
    ++n;
    int *p = new int[n];
    int temp1;
    int temp2;
    cout << "Their compatible dimensions" <<endl;
    cin>>temp1;
    cin>>temp2;
    p[0] = temp1;
    p[1] = temp2;
    for(int i = 2; i < n; i++)
    {
        cin>>temp1;
        if(temp1!=p[i-1])
        {
            flag=1;
            cout << "Not compatible";
            break;
        }
        cin>>temp2;
        p[i] = temp2;
    }
    if(!flag)
    {
        --n;
        matrix(p, n);

    }


    return 0;
}
