#include <iostream>
#include <time.h>
#include <unistd.h>
#include "SkipList.h"
using namespace std;

int main()
{
    srand(getpid());
    //Problem1
    //Insertion sort
    /*int arr[5] = {1,1,1,2,2};
	int key, temp, j, num=0;
    for(int i=1; i<5; i++) //Loop through the unsorted array
    {
        key = arr[i];
        j= i-1;  //The largaboveLevel->est number in the sorted array
        while(j>=0 && key < arr[j])
        {
            num++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]= key;

    }
    cout << num;*/

    SkipList s;
    s.insertN(5);
    s.insertN(2);
    s.insertN(7);
    s.insertN(30);


    //node *ab = nn->aboveLevel;
    //cout <<s.header.next->value;

   /* while(nn !=nullptr)
    {
        cout << nn->value << endl;
        while(nn->below!=nullptr)
        {
            cout<< nn->below->value <<endl;
            nn = nn->below;
        }
        nn = nn->next;
        if(nn!=nullptr)
        {
                    ab = nn->aboveLevel;
        while( ab != nullptr)
        {
            cout << ab->value <<endl;
            ab = ab->aboveLevel;
        }
        }

    }
*/


   /* node* n = nullptr;
    node *ab = s.header;
    for(int i=0)
    while(ab->below!=nullptr)
    {
        cout << ab->value <<endl;
        ab = ab->below;
    }
    ab = ab->next;
    cout << ab->value <<endl;
    n = ab;
    while(ab->aboveLevel!=nullptr)
    {
        cout << ab->value <<endl;
        ab = ab->aboveLevel;
    }
*/

    /*node *ab = s.sentinle->below;
    while( ab != nullptr)
    {
        cout << ab->value <<endl;
        ab = ab->below;
    }*/


    //cout << "Next: "<<s.header->next->value <<endl;
    //cout << "BelowNext: "<<s.header->next->below->value <<endl;
   // cout << s.header->aboveLevel->next->value;

    /*
    srand(time(0));
    int flip=1;
    flip = (rand()%100)+1;
    while(flip%2 ==0)
    {
        cout<< flip << endl;
        flip = rand()%100;
*/
   // cout<<"Tail" <<endl;
  /*int randomNumber;
  for (int index = 0; index < 10; index++) {
    randomNumber = (rand() % 35) + 1;
    cout << randomNumber << endl;
  }*/
  //s.printSkip();
  s.printSkipA();

  //s.printLayer(3);
  //s.insertN(5);
  cout <<s.searchN(2) << endl;
  cout <<s.searchN(30)<< endl;
  cout <<s.searchN(7)<< endl;
  cout <<s.searchN(15)<< endl;
    cout <<s.searchN(5)<< endl;
s.deleteN(7);
s.deleteN(12);
cout << "After delete" <<endl;
s.printSkip();
    return 0;
}
