// COMSC-210 | Final Exam 2 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Customer.h"
using namespace std;

// Constants
const int NAMES_SIZE = 20;
const int COFFEES_SIZE = 10;
const int MUFFINS_SIZE = 10;
const int BRACELETS_SIZE = 10;
const int INITIAL_QUEUE = 3;
const int ROUNDS = 10;
const int JOIN_QUEUE = 50;

const string NAMES[NAMES_SIZE] = {
    "Alice", "Bob", "Charlie", "Dana", "Eli", "Fiona", "George", "Hannah", "Ian", "Jill", 
    "Kevin", "Luna", "Mason", "Nina", "Oscar", "Paula", "Quinn", "Ryan", "Sophia", "Tyler"
};          // Customer names

const string COFFEES[10] = {
    "Espresso", "Cappuccino", "Latte", "Americano", "Flat White", "Mocha", "Macchiato", "Turkish Coffee", "Cold Brew", "Affogato"
};          // Coffees

const string MUFFINS[10] = {
    "Blueberry", "Chocolate Chip", "Banana Nut", "Lemon Poppy Seed", "Bran", "Corn", "Cranberry Orange", "Pumpkin", "Apple Cinnamon", "Double Chocolate"
};          // Muffins

const string BRACELETS[10] = {
    "Friendship Beads", "Leather Cuff", "Charm Bracelet", "Braided Cord", "Woven Thread", "Macrame", "Beaded Stretch", "Anklet Bracelet", "Personalized Name", "Rainbow Loom"
};          // Bracelets

// Functions prototypes
void simulateCoffeeBooth(Node*& head, Node*& tail);
void displayCoffeeBooth(Node* head);
void simulateMuffinBooth(deque<Customer>& muffinBooth);
void displayMuffinBooth(const deque<Customer>& muffinBooth);
void simulateBraceletBooth(vector<Customer>& braceletBooth);
void displayBraceletBooth(const vector<Customer>& braceletBooth);

// Main function
int main()
{
    // Call srand() and time()
    srand(time(0));

    // Create a head and tail pointer for the Linked List
    Node* head = nullptr;
    Node* tail = nullptr;

    // Create muffin booth deque
    deque<Customer> muffinBooth;

    // Create a bracelet booth vector
    vector<Customer> braceletBooth;

    // Populate the Linked List with some data
    for (int i = 0; i < 3; i++)
    {
        // Create a new Node to store the data
        Node* newNode = new Node;

        // Populate the data
        newNode->name = NAMES[rand() % NAMES_SIZE];
        newNode->order = COFFEES[rand() % COFFEES_SIZE];

        // Add the Node into the Linked List
        // If the Linked List is empty
        if (head == nullptr)
        {
            // We let the newNode be both the head and tail
            head = tail = newNode;
            newNode->next = nullptr;
        }
        // Otherwise, if the Linked List is not empty
        else
        {
            // We add to the tail of the Linked List and set it to be the new tail
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
    }

    // Display the initial queue
    cout << "Coffee Booth Initial Queue: " << endl;
    displayCoffeeBooth(head);
    cout << endl;

    // Simulate the Linked List for 10 Rounds
    for (int i = 0; i < ROUNDS; i++)
    {
        // Display a message
        cout << " --- Simulation: " << i + 1 << " --- " << endl;

        // Display the operations
        cout << "1. Operations:" << endl;

        // Simulate the Coffee Booth Linked List
        cout << "Coffee Booth: " << endl;
        simulateCoffeeBooth(head, tail);

        // Simulate the Muffin Booth deque
        cout << "Muffin Booth: " << endl;
        simulateMuffinBooth(muffinBooth);

        // Simulate the Bracelet Booth vector
        cout << "Bracelet Booth: " << endl;
        simulateBraceletBooth(braceletBooth);

        // Display the queues at the end of the simulation
        cout << "2. Queues: " << endl;

        // Display the queue at the end of the simulation
        cout << "Coffee Booth Queue: " << endl;
        displayCoffeeBooth(head);

        // Display the deque at the end of the simulation
        cout << "Muffin Booth Queue: " << endl;
        displayMuffinBooth(muffinBooth);

        // Display the vector at the end of the simulation
        cout << "Bracelet Booth Vector: " << endl;
        displayBraceletBooth(braceletBooth);

        // Enter a new line after each simulation
        cout << endl;
    }

    return 0;
}

// Function implementations
/*
    simulateCoffeeBooth()
    Simulate the Coffee Booth
    Arguments:
        - head: the Node at the head of the Coffee Booth Linked List
        - tail: the Node at the tail of the Coffee Booth Linked List
    Return: none
*/
void simulateCoffeeBooth(Node*& head, Node*& tail)
{
    // Check whether the queue is empty
    // If the queue if NOT empty
    if (head != nullptr)
    {
        // Then the first customer is always served
        // Display a message
        cout << "    " << head->name << " is served!" << endl;

        // Remove the first customer (customer is served)
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // And there's always a 50% chance a Customer joins the queue
    int chance = rand() % 100 + 1;          // Chance ranges rom 1 -> 100

    // Compare the chance
    if (chance <= JOIN_QUEUE)
    {
        // Create a new Node to store the data
        Node* newNode = new Node;

        // Populate the data
        newNode->name = NAMES[rand() % NAMES_SIZE];
        newNode->order = COFFEES[rand() % COFFEES_SIZE];

        // Add the Node into the Linked List
        // If the Linked List is empty
        if (head == nullptr)
        {
            // We let the newNode be both the head and tail
            head = tail = newNode;
            newNode->next = nullptr;
        }
        // Otherwise, if the Linked List is not empty
        else
        {
            // We add to the tail of the Linked List and set it to be the new tail
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }

        // Display a message
        cout << "    " << newNode->name << " joins the queue!" << endl;
    }
}

/*
    displayCoffeeBooth()
    Display the Coffee Booth queue
    Arguments:
        - head: the Node at the head of the Linked List
    Return: none
*/
void displayCoffeeBooth(Node* head)
{
    // Create and use a Node to traverse the Linked List
    Node* temp = head;

    // Check whether the head was empty
    if (head == nullptr)
    {
        // Display a message
        cout << "(empty)" << endl;
    }

    // Traverse the Linked List
    while (temp != nullptr)
    {
        // Display the Node's data
        cout << "    [" << temp->name << "(" << temp->order << ")]" << endl;

        // Advance the pointer
        temp = temp->next;
    }
}

/*
    simulateMuffinBooth()
    Simulate the Muffin Booth
    Arguments:
        - muffinBooth: the Muffin Booth deque
    Return: none
*/
void simulateMuffinBooth(deque<Customer>& muffinBooth)
{
    // Check whether the deque is empty
    // If it is not empty
    if (muffinBooth.size() > 0)
    {
        // Serve the first Customer
        cout << muffinBooth.at(0).name << " is served!" << endl;

        // Remove the first Customer
        muffinBooth.pop_front();
    }
    // Otherwise if it is empty, we do nothing

    // And there's always a 50% chance a Customer joins the queue
    int chance = rand() % 100 + 1;          // Chance ranges rom 1 -> 100

    // Compare the chance
    if (chance <= JOIN_QUEUE)
    {
        // Create a new Customer to store the data
        Customer temp;

        // Populate the data
        temp.name = NAMES[rand() % NAMES_SIZE];
        temp.order = MUFFINS[rand() % MUFFINS_SIZE];

        // Add the Customer into the Deque
        muffinBooth.push_back(temp);

        // Display a message
        cout << "    " << temp.name << " joins the queue!" << endl;
    }
}

/*
    displayMuffinBooth()
    Display the Muffin Booth queue
    Arguments:
        - muffinBooth: the Muffin Booth deque
    Return: none
*/
void displayMuffinBooth(const deque<Customer>& muffinBooth)
{
    // Check whether the deque was empty
    if (muffinBooth.size() == 0)
    {
        // Display empty message
        cout << "    (empty)" << endl;
    }

    // Iterate through the deque and display each Customer
    for (auto item : muffinBooth)
    {
        cout << "    [" << item.name << "(" << item.order << ")]" << endl;
    }
}

/*
    simulateBraceletBooth()
    Simulate the Bracelet Booth
    Arguments:
        - braceletBooth: the Bracelet Booth vector
    Return: none
*/
void simulateBraceletBooth(vector<Customer>& braceletBooth)
{
    // Check whether the vector is empty
    // If it is not empty
    if (braceletBooth.size() > 0)
    {
        // Serve the first Customer
        cout << braceletBooth.at(0).name << " is served!" << endl;

        // Remove the first Customer
        braceletBooth.erase(braceletBooth.begin());
    }
    // Otherwise if it is empty, we do nothing

    // And there's always a 50% chance a Customer joins the queue
    int chance = rand() % 100 + 1;          // Chance ranges rom 1 -> 100

    // Compare the chance
    if (chance <= JOIN_QUEUE)
    {
        // Create a new Customer to store the data
        Customer temp;

        // Populate the data
        temp.name = NAMES[rand() % NAMES_SIZE];
        temp.order = BRACELETS[rand() % BRACELETS_SIZE];

        // Add the Customer into the Vector
        braceletBooth.push_back(temp);

        // Display a message
        cout << "    " << temp.name << " joins the queue!" << endl;
    }
}

/*
    displayBraceletBooth()
    Display the Bracelet Booth queue
    Arguments:
        - braceletBooth: the Bracelet Booth vector
    Return: none
*/
void displayBraceletBooth(const vector<Customer>& braceletBooth)
{
    // Check whether the vector is empty
    if (braceletBooth.size() == 0)
    {
        // Display empty message
        cout << "    (empty)" << endl;
    }

    // Iterate through the vector and display each Customer
    for (auto item : braceletBooth)
    {
        cout << "    [" << item.name << "(" << item.order << ")]" << endl;
    }
}