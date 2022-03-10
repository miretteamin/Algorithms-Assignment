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


    treeNode *search(int value)
    {
        treeNode *temp = root;
        while(temp !=NULL) {
            if (temp->value == value)
                return temp;
            else if (temp->value < value)
                temp = temp->right;
            else if(temp->value <value && temp->right == NULL)
                return NULL;
            else if(temp->value > value)
                temp = temp->left;
            else if(temp ->value > value && temp->left == NULL)
                return NULL;
        }
        return NULL;
    }

    treeNode *successor(treeNode *temp)
    {
        treeNode *c = NULL;
        if(temp->left!=NULL)
        {
            c=temp->left;
            while(c->right!=NULL)
                c=c->right;
        }
        else
        {
            c=temp->right;
            while(c->left!=NULL)
                c=c->left;
        }
        return c;
    }

    void del(int value)
    {
        if(root==NULL)
        {
            return ;
        }
        treeNode *temp;
        temp = search(value);
        treeNode *temp2 = temp;
        while(temp2 != root)
        {
            temp2->sizeOfNode--;
            temp2 = temp2->parent;
        }
        root->sizeOfNode--;
        treeNode *y=NULL;
        treeNode *q=NULL;
        if(temp == NULL)
        {
            cout<<"Element doesn't exist"<<endl;
            return;
        }
        else
        {
            if(temp->left==NULL||temp->right==NULL)
                y=temp;
            else
                y=successor(temp);
            if(y->left!=NULL)
                q=y->left;
            else
            {
                if(y->right!=NULL)
                    q=y->right;
                else
                    q=NULL;
            }
            if(q!=NULL)
                q->parent=y->parent;
            if(y->parent==NULL)
                root=q;
            else
            {
                if(y==y->parent->left)
                    y->parent->left=q;
                else
                    y->parent->right=q;
            }
            if(y!=temp)
            {
                temp->color=y->color;
                temp->value=y->value;
            }
            if(y->color=='b')
                delfix(q);
        }
    }

    void delfix(treeNode *temp)
    {
        treeNode *c;
        while(temp!=root&&temp->color==0)
        {
            if(temp->parent->left==temp)
            {
                c=temp->parent->right;
                if(c->color==1)
                {
                    c->color=0;
                    temp->parent->color=1;
                    leftRotate(temp->parent);
                    c=temp->parent->right;
                }
                if(c->right->color==0&&c->left->color==0)
                {
                    c->color=1;
                    temp=temp->parent;
                }
                else
                {
                    if(c->right->color==0)
                    {
                        c->left->color==0;
                        c->color=1;
                        rightRotate(c);
                        c=temp->parent->right;
                    }
                    c->color=temp->parent->color;
                    temp->parent->color=0;
                    c->right->color=0;
                    leftRotate(temp->parent);
                    temp=root;
                }
            }
            else
            {
                c=temp->parent->left;
                if(c->color==1)
                {
                    c->color=0;
                    temp->parent->color= 1;
                    rightRotate(temp->parent);
                    c=temp->parent->left;
                }
                if(c->left->color==0&&c->right->color==0)
                {
                    c->color='1';
                    temp=temp->parent;
                }
                else
                {
                    if(c->left->color==0)
                    {
                        c->right->color=0;
                        c->color=1;
                        leftRotate(c);
                        c=temp->parent->left;
                    }
                    c->color=temp->parent->color;
                    temp->parent->color=0;
                    c->left->color=0;
                    rightRotate(temp->parent);
                    temp=root;
                }
            }
            temp->color=0;
            root->color=0;
        }
    }

    int kthElement(treeNode *ro, int i)
    {
        if(ro->left == NULL && ro->right == NULL)
        {
            if(i == 1)
            {
                return ro->value;
            }
            else
            {
                return -1;
            }
        }
        else if(ro->left == NULL && ro->right != NULL)
        {
            if(i == 1)
            {
                return ro->value;
            }
            return kthElement(ro->right, i-1);
        }

        int ra = ro->left->sizeOfNode+1;
        if(i == ra)
        {
            return ro->value;
        }
        if(i < ra)
        {
            return kthElement(ro->left, i);
        }
        else
        {
            return kthElement(ro->right, i - ra);
        }
    }
    int kthElementCaller(int i)
    {
        return kthElement(root, i);
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
    vector<int> out;
    while(true)
    {
        int c,p;
        cin>>c;
        if(c == -1)
        {
            break;
        }
        cin>>p;
        if(c == 1)
        {
            obj.insert(p);
        }
        else if(c == 2)
        {
            obj.del(p);
        }
        else if(c == 3)
        {
            out.push_back(obj.kthDataCaller(p));
        }
        else if(c == 4)
        {
            out.push_back(obj.kthElementCaller(p));
        }
    }

    for(int i = 0; i < out.size();i++)
    {
        cout<<out[i] << ' ';
    }
    return 0;
}