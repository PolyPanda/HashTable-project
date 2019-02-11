//
//  Header.h
//  lab 8
//
//  Created by Andie Yu on 6/4/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//


#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <cstddef> //for NULL
#include <assert.h>

using namespace std;

template <class listdata> //list stores generic listdata, not any specific C++ type
class List {
private:
    struct Node {
        listdata data;
        Node* nextnode;
        Node* previousnode;
        
        Node(listdata data) :
        data(data), nextnode(NULL), previousnode(NULL) {
        }
    };
    
    typedef struct Node *NodePtr;
    
    NodePtr begin;
    NodePtr end;
    NodePtr iterator;
    int length;
    
public:
    
    /**Constructors and Destructors*/
    
    List();
    //Default constructor; initializes and empty list
    //Postcondition:initialize begin,end, and length
    
    List(const List &list);
    
    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition:delete all the pointer node that already used
    //Free the memory
    
    /**Accessors*/
    
    listdata getBegin() const;
    //Returns the first element in the list
    //Precondition:begin node must not be null, must have data
    
    listdata getEnd() const;
    //Returns the last element in the list
    //Precondition:end node must not be null, must have data
    
    bool empty() const;
    //Determines whether a list is empty.
    
    int getLength() const;
    //Returns the size of the list
    
    /**Manipulation Procedures*/
    
    void deleteEnd();
    //Removes the value of the last element in the list
    //Precondition:length not 0
    //Postcondition:end node and only end node have been deleted,
    //if it is the only node in the list. List will be empty
    
    void deleteBegin();
    //Removes the value of the first element in the list
    //Precondition:length not 0
    //Postcondition:First node and only first node have been deleted,
    //if it is the only node in the list. List will be empty
    
    void insertEnd(listdata data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition:inserted node will be the end node in the liked list
    
    void insertBegin(listdata data);
    //Inserts a new element at the start of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition:inserted node will be the begin node in the liked list
    
    void beginIterator();
    
    void deleteIterator();
    
    void insertIterator(listdata);
    
    void advanceIterator();
    
    void reverseIterator();
    
    listdata getIterator()const;
    
    bool offEnd();
    
    bool operator==(const List& list);
    
    void printNumberedList() const;
    
    /**Additional List Operations*/
    
    void print() const;
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
};

template <class listdata>
List<listdata>::List() {
    begin = NULL;
    end = NULL;
    iterator = NULL;
    length = 0;
}

template <class listdata>
List<listdata>::List(const List &list)
{
    if(list.begin == NULL) //If the original list is empty, make an empty list for this list
    {
        begin = end = iterator = NULL;
    }
    else
    {
        begin = new Node(list.begin->data); //calling Node constructor
        NodePtr temp = list.begin; //set a temporary node pointer to point at the first of the original list
        iterator = begin; //set iterator to point to first node of the new list
        while(temp->nextnode != NULL)
        {
            temp = temp->nextnode; //advance up to the next node in the original list
            iterator->nextnode = new Node(temp->data); //using node constructor to create new node w/ copy of data
            iterator = iterator->nextnode; //advance to this new node
        }
        end = iterator; //Why do I need this line of code?
        iterator = NULL;
    }
    length = list.length;
}

template <class listdata>
List<listdata>::~List() {
    NodePtr after = begin;
    NodePtr before;
    while (after != NULL) {
        before = after->nextnode;
        after = before;
        delete after;
    }
}

template <class listdata>
void List<listdata>::print() const
{
    NodePtr temp = begin; //create a temporary iterator
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->nextnode;
        //Add two lines of code here
        
        //Hint: One statement should contain a cout
    }
    cout << endl; //What does this do?
    delete temp;
}

template <class listdata>
void List<listdata>::printNumberedList() const
{
    NodePtr temp = begin; //create a temporary iterator
    int num =1;
    while (temp != NULL) {
        cout<<num++<<". "<<temp->data<<" ";
        temp = temp->nextnode;
        cout<<endl;
        //Add two lines of code here
        
        //Hint: One statement should contain a cout
    }
    cout << endl; //What does this do?
    delete temp;
}

template <class listdata>
bool List<listdata>::empty() const
{
    return length ==0;
}

template <class listdata> //Step 1: template the function
void List<listdata>::insertBegin(listdata data) //step 2 & 3: List is templated and takes in a generic param
{
    if (length == 0)
    {
        begin = new Node(data); //note that although data is of a generic type, we use it as before.
        end = begin;
        
    }
    else
    {
        NodePtr N = new Node(data);
        N->nextnode = begin;
        N->previousnode = NULL; //Need to update the previous pointer of first to point back at the new node
        begin->previousnode = N;
        begin = N;
    }
    length++;
}

template <class listdata>
void List<listdata>::insertEnd(listdata data) {
    if(length == 0) {//why is this necessary
        end = begin = new Node(data);
    } else {
        NodePtr N = new Node(data);
        N->nextnode = NULL;
        end->nextnode = N;
        N->previousnode = end;
        end = N;
    }
    length++;
}

template <class listdata>
void List<listdata>::deleteBegin() {
    assert(!empty());
    if (length == 1)
    {
        delete begin;
        begin = end = NULL;
        length = 0;
        
    } else {
        NodePtr temp = begin; //store this location so we don't lose access to it
        begin = begin->nextnode; //advance the pointer
        begin->previousnode = NULL;
        delete temp; //free the memory for the original begin node
        length--;
    }
}

template <class listdata>
void List<listdata>::deleteEnd()
{
    assert(!empty());
    if (length == 1) {
        delete end;
        begin = NULL;
        end = NULL;
        length = 0;
        //fill in the missing lines here
        
    } else {
        NodePtr temp = begin;
        while (temp->nextnode != end) {
            temp = temp->nextnode; //advance the pointer to find 2nd to last node
        }
        delete end; //free the memory for the original last node
        end = temp; //set the new end node
        end->nextnode = NULL; //so last->next is not pointing at freed memory
        length--;
    }
    
}
template <class listdata>
void List<listdata>::beginIterator()
{
    iterator = begin;
}

template <class listdata>
void List<listdata>::deleteIterator()
{
    assert(!offEnd());
    if(iterator == begin)
    {
        deleteBegin();
    }
    else if(iterator == end)
    {
        deleteEnd();
    }
    else
    {
        iterator->previousnode->nextnode = iterator->nextnode;
        iterator->nextnode->previousnode = iterator->previousnode;
    }
    iterator = NULL;
    length--;
}

template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
    assert(!offEnd());
    if(iterator == end)
    {
        insertEnd(data);
    }
    else{
        NodePtr N = new Node(data);
        N->nextnode = iterator->nextnode;
        N->previousnode = iterator;
        iterator->nextnode->previousnode = N;
        iterator->nextnode = N;
        length++;
    }
}

template <class listdata>
void List<listdata>::advanceIterator()
{
    assert(!empty());
    iterator = iterator->nextnode;
}

template <class listdata>
void List<listdata>::reverseIterator()
{
    //assert(!empty());
    assert(iterator != NULL);
    iterator = iterator->previousnode;
}

template <class listdata>
listdata List<listdata>::getIterator() const
{
    assert(!empty());
    return iterator->data;
}

template <class listdata>
bool List<listdata>:: offEnd()
{
    return iterator == NULL;
}

template <class listdata>
int List<listdata>::getLength() const
{
    return length;
}

template <class listdata>
listdata List<listdata>::getBegin() const
{
    assert(!empty());
    return begin -> data;
}

template <class listdata>
listdata List<listdata>::getEnd() const
{
    assert(!empty());
    return end -> data;
}

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    NodePtr temp1 = begin;
    NodePtr temp2 = list.begin;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->nextnode;
        temp2 = temp2->nextnode;
    }
    return true;
}


#endif /* LIST_H_ */
