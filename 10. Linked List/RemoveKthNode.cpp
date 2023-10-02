/*
Problem Statement : We need to remove the Kth node from start of the Linked List. By this we can remove the first, last and any Node present in the Linked List

Test Case:
Linked List = 1 -> 2 -> 3 -> 4 -> 5
Node to be removed = 3

Linked List after removing third Node = 1 -> 2 -> 4 -> 5

*/

#include<iostream>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node(int data)
    {
        val = data;
        this -> next = NULL;
    }
};

class LinkedList
{
    public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void insertAtTail(int val)
    {
        Node* new_node = new Node(val);

        if(head == NULL)
        {
            head = new_node;
            return;
        }

        Node* temp = head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = new_node;
    }

    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    
    }
};

void removeKthNode(Node* &head, int k)
{
    Node* move = head;
    Node* ptr = head;
    int size = 0;

    while(ptr != NULL)
    {
        ptr = ptr -> next;
        size++;
    }

    for(int i=0;i<size-k-1;i++)
    {
        move = move -> next;
    }

    Node* temp = move -> next;

    move -> next = move -> next -> next;

    free(temp);

}

int main()
{
    LinkedList ll;

    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);

    ll.display();

    removeKthNode(ll.head, 3);

    ll.display();
}