#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int key;
    node *left, *right;
};
node *root = NULL;
node *nodeCreation(int data)
{
    node *temp = new node();
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *insert(node *nodeUp, int data)
{
    if (nodeUp == NULL)
        return nodeCreation(data);
    if (nodeUp->key > data)
    {
        nodeUp->left = insert(nodeUp->left, data);
    }
    else if (nodeUp->key < data)
    {
        nodeUp->right = insert(nodeUp->right, data);
    }
    return nodeUp;
}
bool searchNode(node *node, int data)
{
    if (node == NULL)
        return false;
    if (node->key == data)
        return true;
    else if (node->key > data)
        return searchNode(node->left, data);
    else if (node->key < data)
        return searchNode(node->right, data);
    return false;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ", root->key);
        inorder(root->right);
    }
}
int findMax(node *node)
{
    if (node->right == NULL)
        return node->key;
    else
        return findMax(node->right);
}
int findHeight(node *node)
{
    int left = 0, right = 0;
    if (node == NULL)
        return 0;
    else
    {
        left = findHeight(node->left);
        right = findHeight(node->right);
        if (left > right)
            return (left + 1);
        else
            return (right + 1);
    }
}
void printLevel(node *nodeCl)
{
    queue<node *> que;
    if (nodeCl != NULL)
        que.push(nodeCl);
    while (!que.empty())
    {
        node *top = que.front();
        cout << top->key << " ";
        if (top->left)
            que.push(top->left);
        if (top->right)
            que.push(top->right);
        que.pop();
    }
}
void leafSum(node *root, int *sum)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        *sum += root->key;
    leafSum(root->left, sum);
    leafSum(root->right, sum);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 10);
    inorder(root);
    bool ans = searchNode(root, 4);
    char an = ans ? 'f' : 'n';
    cout << an << endl;
    cout << "max: " << findMax(root) << endl;
    cout << "height: " << findHeight(root) << endl;
    cout << "LevelOrder: " << endl;
    printLevel(root);
    int sum = 0;
    leafSum(root, &sum);
    cout << "Sum of leaf nodes " << sum;
    return 0;
}