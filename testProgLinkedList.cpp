//**********************************************************
// Author: D.S. Malik
//
// This program tests the various operations on an ordered
// linked list.
//**********************************************************

#include <iostream>                         // Line 1
#include "linkedList.h"                     // Line 2
#include "orderedLinkedList.h"              // Line 3

using namespace std;                        // Line 4

int main()                                  // Line 5
{
    orderedLinkedList<int> list1, list2, newList;   // Line 6
    int num;                                        // Line 7

    cout << "Line 8: Enter numbers for list1 ending with -999:" << endl;  // Line 8
    cin >> num;                                                             // Line 9

    while (num != -999)                                                     // Line 10
    {
        list1.insert(num);                                                  // Line 11
        cin >> num;                                                         // Line 12
    }

    cout << "Line 13: Enter numbers for list2 ending with -999:" << endl;   // Line 13
    cin >> num;                                                             // Line 14

    while (num != -999)                                                     // Line 15
    {
        list2.insert(num);                                                  // Line 16
        cin >> num;                                                         // Line 17
    }

    cout << "Line 18: list1: ";                                             // Line 18
    list1.print();                                                          // Line 19
    cout << endl;                                                           // Line 20

    cout << "Line 21: list2: ";                                             // Line 21
    list2.print();                                                          // Line 22
    cout << endl;                                                           // Line 23

    newList.mergeLists(list1, list2);                                       // Line 24

    cout << "Line 25: Merged list: ";                                       // Line 25
    newList.print();                                                        // Line 26
    cout << endl;                                                           // Line 27

    return 0;                                                               // Line 28
}