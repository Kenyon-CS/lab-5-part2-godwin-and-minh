#ifndef H_orderedListType
#define H_orderedListType

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered doubly linked list.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    void insert(const Type& newItem);
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
    void mergeLists(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2);
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current = this->first;  // Accessing 'first' from the base class

    while (current != NULL && !found)
    {
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    }

    if (found)
        found = (current->info == searchItem);

    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode = new nodeType<Type>;

    newNode->info = newItem;
    newNode->link = NULL;

    if (this->first == NULL)  // Accessing 'first' from the base class
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        bool found = false;

        while (current != NULL && !found)
        {
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }

        if (current == this->first)
        {
            newNode->link = this->first;
            this->first = newNode;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == NULL)
                this->last = newNode;
        }
        this->count++;
    }
}

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if (this->first == NULL)
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found)
        {
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }

        if (current == NULL)
            cout << "The item to be deleted is not in the list." << endl;
        else if (current->info == deleteItem)
        {
            if (this->first == current)
            {
                this->first = this->first->link;
                if (this->first == NULL)
                    this->last = NULL;
                delete current;
            }
            else
            {
                trailCurrent->link = current->link;
                if (current == this->last)
                    this->last = trailCurrent;
                delete current;
            }
            this->count--;
        }
        else
        {
            cout << "The item to be deleted is not in the list." << endl;
        }
    }
}

// Function to merge two ordered linked lists
template <class Type>
void orderedLinkedList<Type>::mergeLists(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2)
{
    nodeType<Type> *current1 = list1.first; // Accessing 'first' from the base class
    nodeType<Type> *current2 = list2.first; // Accessing 'first' from the base class

    // Inserting the nodes in the two lists in order 
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->info <= current2->info)
        {
            insert(current1->info);
            current1 = current1->link;
        }
        else
        {
            insert(current2->info);
            current2 = current2->link;
        }
    }

    // Merging list1 into the main list
    while (current1 != NULL)
    {
        insert(current1->info);
        current1 = current1->link;
    }

    // Merging list2 into the main list
    while (current2 != NULL)
    {
        insert(current2->info);
        current2 = current2->link;
    }

    // Destroy the two lists after use
    list1.destroyList();
    list2.destroyList();
}

#endif