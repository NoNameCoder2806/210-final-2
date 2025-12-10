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

const string NAMES[NAMES_SIZE] = {
    "Alice", "Bob", "Charlie", "Dana", "Eli", "Fiona", "George", "Hannah", "Ian", "Jill", 
    "Kevin", "Luna", "Mason", "Nina", "Oscar", "Paula", "Quinn", "Ryan", "Sophia", "Tyler"
};          // Customer names

const string COFFEE[10] = {
    "Espresso", "Cappuccino", "Latte", "Americano", "Flat White", "Mocha", "Macchiato", "Turkish Coffee", "Cold Brew", "Affogato"
};          // Coffee

// Main function
int main()
{
    // Call srand() and time()
    srand(time(0));

    // Create a Linked List
    Node* linkedList = nullptr;

    // Populate the Linked List with some data
    for (int i = 0; i < 3; i++)
    {
        // Create a new Node to store the data
        Node* newNode = new Node;

        // Populate the data
        newNode->name = NAMES[rand() % NAMES_SIZE];
        newNode->order = COFFEE[rand() % COFFEE_SIZE];

        // 
    }

    return 0;
}