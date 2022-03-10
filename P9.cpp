#include <iostream>
#include <vector>
using namespace std;

struct treeNode{
    treeNode *left;
    treeNode *right;
    treeNode *parent;
    int value;
    int color;
    int sizeOfNode;
};

class RB{
private:
    treeNode *root;
public:
    RB()
    {
        root = NULL;
    }
    void insert(int newValue)
    {
        //0 = black, 1 = red
        treeNode *newNode = new treeNode;
        newNode->value = newValue;
        newNode->color = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->sizeOfNode = 1;
        treeNode *tempRoot;
        if(root == NULL)
        {
            newNode->parent = NULL;// NULL root newelement
            root = newNode;
        }
        else
        {
            tempRoot = root;
            treeNode *parentNode;
            while(tempRoot!= NULL)
            {
                parentNode = tempRoot;
                if(newValue > tempRoot->value)
                {
                    tempRoot = tempRoot->right;
                }
                else
                {
                    tempRoot = tempRoot->left;
                }
                parentNode->sizeOfNode++;
            }

            if(newValue > parentNode->value)
            {
                parentNode->right = newNode;
            }
            else
            {
                parentNode->left = newNode;
            }
            newNode->parent = parentNode;
        }
        rotation(newNode);
    }

    int getUncleColor(treeNode *uncleNode)
    {
        if(uncleNode->parent->parent->left != NULL && uncleNode->parent->parent->right != NULL && uncleNode->parent->parent->right == uncleNode->parent)
        {
            return uncleNode->parent->parent->left->color;
        }
        else if(uncleNode->parent->parent->left != NULL && uncleNode->parent->parent->right != NULL && uncleNode->parent->parent->left == uncleNode->parent)
        {
            return uncleNode->parent->parent->right->color;
        }
        return 0;
    }

    void leftRotate(treeNode *rotationNode)
    {
        if(rotationNode->right == NULL)
        {
            return;
        }
        else
        {
            treeNode *temp = rotationNode->right;
            if(temp->left != NULL)
            {
                rotationNode->sizeOfNode = rotationNode->sizeOfNode - rotationNode->right->sizeOfNode + rotationNode->right->left->sizeOfNode;
                rotationNode->right->sizeOfNode = rotationNode->right->sizeOfNode - rotationNode->right->left->sizeOfNode + rotationNode->sizeOfNode;
                rotationNode->right = temp->left;
                temp->left->parent = rotationNode;
                //temp = rotationNode;
            }
            else {
                rotationNode->sizeOfNode = rotationNode->sizeOfNode - rotationNode->right->sizeOfNode;
                rotationNode->right->sizeOfNode = rotationNode->right->sizeOfNode + rotationNode->sizeOfNode;
                rotationNode->right = NULL;
            }
            if(rotationNode->parent != NULL)
            {
                temp->parent = rotationNode->parent;
            }
            if(rotationNode->parent == NULL)
            {
                root = temp;
            }
            else
            {
                if(rotationNode == rotationNode->parent->left)
                {
                    rotationNode->parent->left = temp;
                }
                else
                {
                    rotationNode->parent->right = temp;
                }
            }
            temp->left = rotationNode;
            rotationNode->parent = temp;
        }
    }

    void rightRotate(treeNode *rotationNode)
    {
        if(rotationNode->left == NULL)
        {
            return;
        }
        else {
            treeNode *temp = rotationNode->left;
            if (temp->right != NULL) {
                rotationNode->sizeOfNode = rotationNode->sizeOfNode - rotationNode->left->sizeOfNode + rotationNode->left->right->sizeOfNode;
                rotationNode->left->sizeOfNode = rotationNode->left->sizeOfNode - rotationNode->left->right->sizeOfNode + rotationNode->sizeOfNode;

                rotationNode->left = temp->right;
                temp->right->parent = rotationNode;
            }
            else
            {
                rotationNode->sizeOfNode = rotationNode->sizeOfNode - rotationNode->left->sizeOfNode;
                rotationNode->left->sizeOfNode = rotationNode->left->sizeOfNode + rotationNode->sizeOfNode;
                rotationNode->left = NULL;
            }
            if (rotationNode->parent != NULL) {
                temp->parent = rotationNode->parent;
            }
            if (rotationNode->parent == NULL) {
                root = temp;
            } else {
                if (rotationNode == rotationNode->parent->left) {
                    rotationNode->parent->left = temp;
                } else {
                    rotationNode->parent->right = temp;
                }
            }
            temp->right = rotationNode;
            rotationNode->parent = temp;
        }
    }

    void rotation(treeNode *fixNode) {
        if (root == fixNode) {
            fixNode->color = 0;
            return;
        }
        while (fixNode->parent != NULL && fixNode->parent->color == 1) {
            int cl = getUncleColor(fixNode);
            if (fixNode->parent->parent->right == fixNode->parent) {
                if (cl == 1) {
                    fixNode->parent->parent->color = 1;
                    fixNode->parent->color = 0;
                    fixNode->parent->parent->left->color = 0;
                    fixNode = fixNode->parent->parent;

                } else {
                    if (fixNode->parent->left == fixNode) {
                        fixNode = fixNode->parent;
                        rightRotate(fixNode);
                    }
                    fixNode->parent->color = 0;
                    fixNode->parent->parent->color = 1;
                    leftRotate(fixNode->parent->parent);
                }
            } else {
                if (cl == 1) {
                    fixNode->parent->parent->color = 1;
                    fixNode->parent->color = 0;
                    fixNode->parent->parent->right->color = 0;
                    fixNode = fixNode->parent->parent;

                } else {
                    if (fixNode->parent->right == fixNode) {
                        fixNode = fixNode->parent;
                        leftRotate(fixNode);
                    }
                    fixNode->parent->color = 0;
                    fixNode->parent->parent->color = 1;
                    rightRotate(fixNode->parent->parent);
                }
            }
            root->color = 0;
        }
    }

    int kthData(treeNode *root, int i)
    {
        treeNode *temp = root;
        int movingIndex = temp->sizeOfNode;
        if(temp->right != NULL)
        {
            movingIndex -= temp->right->sizeOfNode;//root index
        }
        while(temp != NULL)
        {
            if(i == temp->value)
            {
                return movingIndex;
            }
            else if(i < temp->value)
            {
                temp = temp->left;
                if(temp != NULL && temp->right != NULL)
                {

                    movingIndex = movingIndex - 1 - temp->right->sizeOfNode;
                }
                else if(temp != NULL && temp->right == NULL)
                    movingIndex = movingIndex - 1;
                else
                    return -1;
            }
            else
            {
                temp = temp->right;
                if(temp != NULL && temp->left != NULL)
                    movingIndex = movingIndex + 1 + temp->left->sizeOfNode;
                else if(temp != NULL && temp->left == NULL)
                    movingIndex = movingIndex + 1;
                else
                    return -1;
            }
        }
        return -1;
    }

    int kthDataCaller(int i)
    {
        return kthData(root, i);
    }
};

int main()
{
    RB obj;
    int inp;
    cin>>inp;
    vector<int> out;
    for(int i = 0; i < inp; i++)
    {
        int c,p;
        cin>>c;
        cin>>p;
        if(c == 1)
        {
            obj.insert(p);
        }
        else
        {
            out.push_back(obj.kthDataCaller(p));
        }
    }

    for(int i = 0; i < out.size();i++)
    {
        cout<<out[i] << ' ';
    }

    return 0;
}