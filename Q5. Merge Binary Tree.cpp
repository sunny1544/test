#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left, * right;
};

Node* newNode(int data)
{
    Node* Nnode = new Node;     //建立新的點
    Nnode->data = data;
    Nnode->left = NULL;
    Nnode->right = NULL;
    return Nnode;
}

void inorder(Node* node)
{
    if (!node)
        return;
    inorder(node->left);        //inorder探訪:左中右
    printf("%d ", node->data);
    inorder(node->right);
}

Node* MergeTrees(Node* t1, Node* t2)
{
    if (!t1)         //如果第一棵樹是空,回傳第二棵樹
        return t2;
    if (!t2)        //如果第二棵樹是空,回傳第一棵樹
        return t1;
    t1->data += t2->data;
    t1->left = MergeTrees(t1->left, t2->left);
    t1->right = MergeTrees(t1->right, t2->right);
    return t1;
}

int main()
{
    Node* root1 = newNode(2);   //第一棵樹
    root1->left = newNode(1);
    root1->right = newNode(4);
    root1->left->left = newNode(5);

    Node* root2 = newNode(3);   //第二棵樹
    root2->left = newNode(6);
    root2->right = newNode(1);
    root2->left->right = newNode(2);
    root2->right->right = newNode(7);

    Node* root3 = MergeTrees(root1, root2);
    printf("The Merged Binary Tree (inorder) is:\n");
    inorder(root3);
    return 0;
}