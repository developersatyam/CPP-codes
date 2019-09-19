#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
Node *head;
Node *tail;
class list
{

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void createNode(int val)
    {
        Node *temp = new Node;
        temp->data = val;
        temp->link = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->link = temp;
            tail = temp;
        }
    }
    void insertFront(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->link = head;
        head = temp;
    }
    void insertPos(int pos, int value)
    {
        Node *pre = new Node;
        Node *cur = new Node;
        Node *temp = new Node;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->link;
        }
        temp->data = value;
        pre->link = temp;
        temp->link = cur;
    }
    void deleteNode(int pos)
    {
        Node *pre = new Node;
        Node *curr = new Node;
        Node *next = new Node;
        curr = head;
        for (int i = 1; i < pos; i++)
        {
            pre = curr;
            curr = curr->link;
        }
        next = curr->link;
        pre->link = next;
    }
    void display(Node *node)
    {
        Node *temp = new Node;
        temp = node;
        cout << temp->data << " -> ";
        if (temp->link == NULL)
            return;
        display(temp->link);
    }
    void reverseList()
    {
        Node *curr = new Node;
        Node *next = new Node;
        Node *prev = new Node;
        curr = head;
        prev = NULL;
        while (curr != NULL)
        {
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void recReverse(Node* node){
        if(node==NULL){
            cout<<endl;
            return;
        }
        recReverse(node->link);
        cout<<node->data<<"->";
    }
};

int main()
{
    list obj;
    // obj.createNode(5);
    // obj.createNode(34);
    obj.insertFront(98);
    obj.insertFront(18);
    obj.insertFront(23);
    obj.insertFront(54);
    obj.insertPos(2, 43);
    // obj.deleteNode(3);
    obj.display(head);
    cout<<endl;
    obj.recReverse(head);
    return 0;
}