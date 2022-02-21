#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

/*
    SkipList();
    void insertN(int value);
    void deleteN(int value);
    bool flipCoin();
    int getLayer();
    void printLayer(int layerNum);
    void printSkipA();
    void printSkip();
    int searchN(int value);
*/

struct node
{
    int value;
    node* next;
    node* below;
    node* aboveLevel =nullptr;
};

class SkipList
{
public:
    node* header;
    node* sentinle;
    int height;
    SkipList()
    {
        height =1;
        header = new node;
        sentinle = new node;
        header->below = nullptr;
        header->aboveLevel = nullptr;
        header->next = sentinle;
        header->value = -100000;
        sentinle->below = nullptr;
        sentinle->aboveLevel = nullptr;
        sentinle->next = nullptr;
        sentinle->value = 100000;
    }

    bool flipCoin()
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

    int searchN(int value)
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

    void insertN(int value)
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

    void deleteN(int value)
    {
        cout << "delete " << value <<endl;
        if((searchN(value)!=-1))
        {

            node* found = header;
            while(found!= nullptr)
            {
                if((found->next->value)== value)
                {
                    node* temp = found->next;
                    node* tempNext = temp->next;
                    found->next = tempNext;
                    delete (temp);
                    found = header->below;
                }
                else if(value> found->next->value)
                {
                    found = found->next;
                }
                else
                {
                    found = found->below;
                }
            }
        }
        else
        {
            cout << "This value does not exist " <<endl;
        }
        cout <<endl;
    }


    void getLayers()
    {
        cout << "Number of layers: " << height <<endl;
        cout <<endl;
    }

    void printLayer(int layerNum)
    {
        if(layerNum>height)
        {
            cout << "Out of range" <<endl;;
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

    void printSkip()
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



    void printSkipA()
    {
        cout << " Print skip layer by layer" << endl;
        for(int i= height; i>0; i--)
        {
            printLayer(i);
            cout << endl;
        }
        cout << endl;
    }

};

int main()
{
    srand(getpid());
    SkipList s;
    s.insertN(5);
    s.insertN(2);
    s.insertN(7);
    s.insertN(30);
    s.printSkipA();
    cout <<endl;
    cout << "Search for 2 -> " << s.searchN(2) << endl;
    cout << "Search for 30 -> " << s.searchN(30)<< endl;
    cout << "Search for 7 -> " << s.searchN(7)<< endl;
    cout << "Search for 15 -> " << s.searchN(15)<< endl;
    cout <<"Search for 5 -> " << s.searchN(5)<< endl;
    cout <<endl;
    s.deleteN(30);
    s.printSkipA();
    s.deleteN(2);
    s.printSkipA();
    s.insertN(12);
    s.printSkipA();
    s.deleteN(21);

    cout << " Print layer 2"<< endl;
    s.printLayer(2);
    cout <<endl;
    cout <<endl;
    cout << " Print layer 3"<< endl;
    s.printLayer(3);
    cout <<endl;
    cout <<endl;

    s.getLayers();
    cout << "Print skip another approach" <<endl;
    s.printSkip();
    return 0;
}


