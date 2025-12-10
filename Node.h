// COMSC-210 | Final Exam 2 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <string>
using namespace std;

// Linked List's Node struct
struct Node
{
    // Members
    string name;           // The name of the customer
    string order;          // The order of the customer
    Node* next;            // The next member of the Linked List
};