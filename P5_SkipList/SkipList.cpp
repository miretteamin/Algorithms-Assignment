#include "SkipList.h"
#include <limits>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

//your code here

//int a = std::numeric_limits<int>::max();
SkipList::SkipList()
{
    height =1;
    header = new node;
    sentinle = new node;
    header->below = nullptr;
    header->aboveLevel = nullptr;
    header->next = sentinle;
    header->value = -1000;
    sentinle->below = nullptr;
    sentinle->aboveLevel = nullptr;
    sentinle->next = nullptr;
    sentinle->value = 1000;
}
bool SkipList::flipCoin()
{
    int flip = (rand()%10);
    if(flip%2==0)
    {
        cout << "Head"<<endl;
        return true;
    }
    else
    {
          cout << "Tail"<<endl;
        return false;

    }
}
int SkipList::searchN(int value)
{
    int stepCount=0;
    node* nextNode = header;
    while(nextNode->next!=nullptr)
    {
        if(nextNode->next->value==value)
        {
            stepCount++;
            return stepCount;
        }
        else if(nextNode->next->value<value)
        {
            stepCount++;
            nextNode= nextNode->next;
        }
        else
        {
            if(nextNode->below!=nullptr)
                nextNode= nextNode->below;
            else
                return -1;
        }
    }
    return -1;
}

void SkipList::insertN(int value)
{
    if(searchN(value)==-1)
    {
        int counter =1;
        node* check = header;
        while(value > check->next->value)
        {
            check = check->next;
        }
        while(check->below!=nullptr)
        {
            check = check->below;
            while(value > check->next->value)
            {
                check = check->next;
            }
        }

        node* newNode = new node;
        newNode->next= check->next;
        check->next = newNode;
        newNode->value = value;
        newNode->below = nullptr;
        newNode->aboveLevel = nullptr;
        cout << "   " <<value << " is inserted." << endl;
        cout << value << ": ";

        while(flipCoin() && counter != 4)
        {
                cout << value << ": ";

            counter++;
            if(counter>height)
            {
                height++;
                header->aboveLevel = new node; //It's allocated
                header->aboveLevel->below = header;
                header->aboveLevel->value = header->value;
                header->aboveLevel->aboveLevel = nullptr;


                sentinle->aboveLevel = new node; //It's allocated
                sentinle->aboveLevel->below = sentinle;
                sentinle->aboveLevel->value = sentinle->value;
                sentinle->aboveLevel->aboveLevel = nullptr;
                sentinle->aboveLevel->next = nullptr;

                header->aboveLevel->next = sentinle->aboveLevel;

                header = header->aboveLevel;
                sentinle = sentinle->aboveLevel;

            }

            newNode->aboveLevel = new node;
            newNode->aboveLevel->below = newNode;
            newNode->aboveLevel->value = newNode->value;
            newNode->aboveLevel->aboveLevel = nullptr;


            node* moving= header;
            for(int i=1; i<=height-counter;i++)
            {
                moving = moving->below;
            }
            while(moving->below->next!=nullptr)
            {
                if((moving->below->next->value!=value)&& (moving->next->next!=nullptr))
                    moving =moving->next;
                else
                    break;
            }


            newNode->aboveLevel->next = moving->next;
            moving->next = newNode->aboveLevel;

            newNode = newNode->aboveLevel;

        }
    }
    else{
            cout << "Already exists";
    }
    cout << endl;
}

int SkipList::getLayer()
{
    return height;
}

void SkipList::printLayer(int layerNum)
{
    if(layerNum>height)
    {
        cout << "Out of range";
    }
    else
    {
        int counter = height;
        node* startLayer = header;
        while(counter>layerNum)
        {
            startLayer =startLayer->below;
            counter--;
        }
        while(startLayer!=nullptr)
        {
            cout << startLayer->value << " " ;
            startLayer =startLayer->next;
        }
    }
}

void SkipList::printSkip()
{
        node* nn = header;
        node *ab;
        while(nn !=nullptr)
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
}


void SkipList::deleteN(int value)
{
    if((searchN(value)!=-1))
    {
        while((searchN(value)!=-1))
        {
            node* found = header;
            while(1)
            {
                if((found->next->value)== value)
                {
                    //found = ;
                    break;
                }
                else if((found->next->value)> value)
                    found = found->below;
                else
                {
                     found = found->next;
                }
            }
            node* temp = found->next;
            node* tempNext = temp->next;
            found->next = tempNext;
            delete (temp);

        }
    }

    else
    {
        cout << "This value does not exist " <<endl;
    }

};

void SkipList::printSkipA()
{
      for(int i= height; i>0; i--)
    {
        printLayer(i);
        cout << endl;
    }
}
