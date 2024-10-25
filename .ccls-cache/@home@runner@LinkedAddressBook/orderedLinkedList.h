#pragma once
#ifndef H_orderedListType
#define H_orderedListType
#include "linkedList.h"
using namespace std;

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    void insert(const Type& newItem);
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
    bool isEmpty() const { return this->first == nullptr; } // Add this function
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type>* current; // Pointer to traverse the list
    current = this->first; // Start the search at the first node
    while (current != nullptr && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    if (found)
        found = (current->info == searchItem); // Test for equality
    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type>* current; // Pointer to traverse the list
    nodeType<Type>* trailCurrent = nullptr; // Pointer just before current
    nodeType<Type>* newNode; // Pointer to create a node
    bool found;
    newNode = new nodeType<Type>; // Create the node
    newNode->info = newItem; // Store newItem in the node
    newNode->link = nullptr; // Set the link field of the node to nullptr

    if (this->first == nullptr) // Case 1: List is empty
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;
        while (current != nullptr && !found) // Search the list
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == this->first) // Case 2: Insert at the beginning
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else // Case 3: Insert in the middle or end
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == nullptr)
                this->last = newNode;
            this->count++;
        }
    }
}

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem); // Reuse the insert method
}

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem); // Reuse the insert method
}

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current; // Pointer to traverse the list
    nodeType<Type>* trailCurrent = nullptr; // Pointer just before current
    bool found;

    if (this->first == nullptr) // Case 1: List is empty
        std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = this->first; // Start the search at the first node
        found = false;
        while (current != nullptr && !found) // Search for the node to delete
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (found) // Node to delete found
        {
            if (current == this->first) // Case 2: Node to delete is the first node
            {
                this->first = this->first->link;
                if (this->first == nullptr) // If list is now empty
                    this->last = nullptr;
            }
            else // Case 3: Node to delete is in the middle or end
            {
                trailCurrent->link = current->link;
                if (current == this->last) // If last node was deleted
                    this->last = trailCurrent;
            }
            delete current; // Free the memory of the deleted node
            this->count--;
        }
        else
            std::cout << "The item to be deleted is not in the list." << std::endl;
    }
}
#endif
