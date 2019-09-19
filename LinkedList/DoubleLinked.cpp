#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *head = NULL;
class DoubleLinkedList
{
private:
    node *back = NULL;
    node *front = NULL;
    node *curr = NULL;

public:
    void addElements(int n)
    {
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;
        curr = head;
        if (head == NULL)
        {
            head = temp;
            back = temp;
        }
        else
        {
            back->next = temp;
            temp->prev = back;
            back = temp;
        }
    }
    void reverseprint(){
        node* temp=new node;
        node* backhead=new node;
        temp=head;
        while(temp->next!=NULL)temp=temp->next;
        backhead=temp;
        while(backhead!=NULL){
            cout<<backhead->data<<" -> ";
            backhead=backhead->prev;
        }
    }
    void display()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ":"
                 << "(" << temp->prev << "," << temp->next << ") -> ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    DoubleLinkedList obj;
    obj.addElements(34);
    obj.addElements(97);
    obj.addElements(54);
    obj.addElements(3);
    obj.addElements(12);
    // obj.display();
    obj.reverseprint();
    return 0;
}