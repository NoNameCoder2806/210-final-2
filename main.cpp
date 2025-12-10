// COMSC-210 | Final Exam 2 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>
#include"Node.h"
using namespace std;

// Constants
const int NAMES_SIZE = 20;
const int COFFEE_SIZE = 10;
const int INITIAL_QUEUE = 3;
const int ROUNDS = 10;
const int JOIN_QUEUE = 50;

const string NAMES[NAMES_SIZE] = {
    "Alice", "Bob", "Charlie", "Dana", "Eli", "Fiona", "George", "Hannah", "Ian", "Jill", 
    "Kevin", "Luna", "Mason", "Nina", "Oscar", "Paula", "Quinn", "Ryan", "Sophia", "Tyler"
};          // Customer names

const string COFFEE[10] = {
    "Espresso", "Cappuccino", "Latte", "Americano", "Flat White", "Mocha", "Macchiato", "Turkish Coffee", "Cold Brew", "Affogato"
};          // Coffee

// Functions prototypes
void simulateCoffeeBooth(Node*& head, Node*& tail);

// Main function
int main()
{
    // Call srand() and time()
    srand(time(0));

    // Create a head and tail pointer for the Linked List
    Node* head = nullptr;
    Node* tail = nullptr;

    // Populate the Linked List with some data
    for (int i = 0; i < 3; i++)
    {
        // Create a new Node to store the data
        Node* newNode = new Node;

        // Populate the data
        newNode->name = NAMES[rand() % NAMES_SIZE];
        newNode->order = COFFEE[rand() % COFFEE_SIZE];

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

    // Display the data
    Node* temp = head;
    while (temp != nullptr)
    {
        // Display the node's data
        cout << temp->name << ", order: " << temp->order << endl;

        // Advance the pointer
        temp = temp->next;
    }

    return 0;
}

// Function implementations
/*
    simulateCoffeeBooth()
    Simulate the Coffee Booth 1 time
    Arguments:
        - head: the Node at the head of the Linked List
        - tail: the Node at the tail of the Linked List
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
        newNode->order = COFFEE[rand() % COFFEE_SIZE];

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
}