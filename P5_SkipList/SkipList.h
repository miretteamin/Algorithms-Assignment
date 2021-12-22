
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
    SkipList();
    void insertN(int value);
    bool flipCoin();
    int getLayer();
    void printLayer(int layerNum);
    void printSkipA();
    void printSkip();
    int searchN(int value);
};
