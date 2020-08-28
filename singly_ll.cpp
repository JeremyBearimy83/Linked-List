#include <iostream>

using namespace std;

//NODE CLASS , EACH NODE HAS  DATA, A UNIQUE KEY AND A POINTER OF TYPE NODE
//TO THE NEXT NODE
class Node
{
public:
    int data;
    int key;
    Node *next;

    //DEFAULT CONSTRUCTOR
    Node()
    {
        data = 0;
        key = 0;
        next = NULL;
    }

    //PARAMETERIZED CONTRUCTOR
    Node(int d, int k)
    {
        data = d;
        key = k;
    }
};

//SINGLY LINKED LIST CLASS FOR SINGLY LINKED LIST
//ONE INSTANCE VARIABLE => POINTER TO THE HEAD NODE

class SinglyLinkedList
{
public:
    Node *head;

    //DEFAULT CONSTRUCTOR
    SinglyLinkedList()
    {
        head = NULL;
    }

    //PARAMETERIZED CONTRUCTOR
    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    //CHECKS IF NODE EXISTS WITH A PARTICULAR KEY, IF NOT THEN RETURNS NULL
    //IF IT DOES THEN RETURNS THE NODE WITH THAT KEY
    Node *nodeExists(int key)
    {
        Node *ptr = head;
        Node *temp = NULL;
        while (ptr != NULL)
        {
            if (ptr->key == key)
                temp = ptr;
            ptr = ptr->next;
        }
        return temp;
    }

    //APPENDS THE PROVIDED NODE TO THE LAST ELEMENT OF THE LIST
    void appendNode(Node *n)
    {
        //CHECKING IF NODE WITH THAT KEY ALREADY EXISTS
        if (nodeExists(n->key) != NULL)
        {
            cout << "The node you're trying to append should have a unique key!" << endl;
        }

        //IF KEY IS UNIQUE
        else
        {
            //IF LIST IS EMPY SIMPLY MAKE THE HEAD POINT TO THE PROVIDED NODE
            if (head == NULL)
                head = n;

            //ELSE FIND THE END AND APPEND
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                    ptr = ptr->next;
                ptr->next = n;
            }
            cout << "Node appended" << endl;
        }
    }

    //MAKE THE HEAD POINT TO THE GIVEN NODE AFTER CHECKING FOR UNIQUE KEY
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) == NULL)
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }

        else
        {
            cout << "The node you're trying to append must have a unique key." << endl;
        }
    }

    //INSERT NODE AFTER THE NODE WITH THE PROVIDED KEY
    void insertNode(Node *n, int k)
    {
        if (nodeExists(n->key) != NULL)
            cout << "They key with that node already exists" << endl;
        else
        {
            Node *temp = nodeExists(k);
            Node *ptr = head;
            if (temp == NULL)
            {
                cout << "The key you wish to insert after doesn't seem to exist" << endl;
            }
            else
            {
                n->next = temp->next;
                temp->next = n;
                cout << "Node inserted successfully" << endl;
            }
        }
    }

    void reverseLinkedList()
    {

        cout << "\n\n-------FUNCTION EXECUTES-------" << endl;
        static bool madeNewHead = false;
        static Node *oldHead = head;

        if (oldHead->next == NULL)
        {
            cout << "Yaay My code reached the end of the recursion!!" << endl;
            madeNewHead = false;
            return;
        }
        Node *last = oldHead; //THIS IS WHERE THE ERROR IS COMING, IN THE FIRST ITERATION ITSELF I HAVE NO IDEA WHAT IS THE PROBLEM I HAVE DONE THIS STEP MULTIPLE TIMES IN OTHER FUNCTIONS.
        Node *secondLast = oldHead;
        cout << "last: " << last->data << endl;
        cout << "Secondlast: " << secondLast->data << endl;

        while (last->next != NULL)
        {
            last = last->next;
        }
        cout << "last: " << last->data << endl;
        cout << "\n\n-------entering second last while loop-------" << endl
             << endl;
        while (secondLast->next != last)
        {
            secondLast = secondLast->next;
            cout << "last: " << last->data << endl;
            cout << "secondLast: " << secondLast->data << endl;
        }
        cout << "\n\n-------exiting second last while loop-------" << endl;
        cout << "secondLast: " << secondLast->data << endl;

        if (!madeNewHead)
        {
            head = last;
            madeNewHead = true;
        }
        last->next = secondLast;
        secondLast->next = NULL;

        reverseLinkedList();
    }

    //DELETE THE NODE WITH THE GIVEN KEY AFTER CHECKING A FEW THINGS
    void deleteNode(int key)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
        {
            cout << "The node you're trying to delete doesn't exist!";
        }

        else
        {
            Node *ptr = head;
            while (ptr->next != temp)
            {
                ptr = ptr->next;
            }
            ptr->next = temp->next;
            cout << "Node deleted successfully!";
        }
    }

    //PRINT THE LINKED LIST IN A NICE ORGANIZED PICTORIAL WAY
    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in linked list";
        }
        else
        {
            cout << endl
                 << " \n Singly Linked List Values: " << endl;
            Node *temp = head;

            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") --> ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main()
{

    // Node *n0 = new Node(99, 0);

    // SinglyLinkedList s1(n0);

    // Node n01(5, 1);
    // Node *n1 = &n01;
    // Node *n2 = new Node(6, 2);
    // Node *n3 = new Node(7, 3);
    // Node *n4 = new Node(8, 4);
    // Node *n5 = new Node(69, -1);
    // Node *n6 = new Node(65, 10);

    // s1.appendNode(n1);
    // s1.appendNode(n2);
    // s1.appendNode(n3);
    // s1.appendNode(n4);
    // s1.prependNode(n5);
    // s1.insertNode(n6, 2);
    // s1.deleteNode(3);

    // s1.printList();

    // s1.reverseLinkedList();
    // s1.printList();]

    SinglyLinkedList s1;

    Node *n1 = new Node(8, 8);
    Node *n2 = new Node(3, 3);
    Node *n3 = new Node(2, 2);
    Node *n4 = new Node(1, 1);

    s1.appendNode(n1);
    s1.appendNode(n2);
    s1.appendNode(n3);
    s1.appendNode(n4);

    s1.printList();

    s1.reverseLinkedList();

    s1.printList();

    return 0;
}