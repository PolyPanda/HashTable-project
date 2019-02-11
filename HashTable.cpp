//
//  HashTable.cpp
//  lab 8
//
//  Created by Andie Yu on 6/4/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//

#include "HashTable.h"

using namespace std;

int HashTable:: hash(string key)
{
    int index, sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i];
    index = sum % SIZE;
    return index;
}

int HashTable:: countBucket(int index)
{
    Table[index].beginIterator();
    int count = 0;
    while (!Table[index].offEnd())
    {
        count++;
        Table[index].advanceIterator();
    }
    return count;
}

int HashTable:: searchData(Book b)
{
    int index = hash(b.get_title()+b.get_author());
    Table[index].beginIterator();
    while (!Table[index].offEnd())
    {
        if (Table[index].getIterator() == b)
        {
            return index;
        }
        Table[index].advanceIterator();
    }
    return -1;
}

void HashTable:: insertData(Book b)
{
    int index = hash(b.get_title()+b.get_author());
    Table[index].insertEnd(b);
}

void HashTable:: removeData(Book b)
{
    int index = hash(b.get_title()+b.get_author());
    Table[index].beginIterator();
    while (!Table[index].offEnd())
    {
        if (Table[index].getIterator() == b)
        {
            Table[index].deleteIterator();
            break;
        }
        Table[index].advanceIterator();
    }
}


void HashTable:: printBucket(int index)
{
    cout<<"Books in Bucket "<<index<<": "<<endl;
    cout<<endl;
    Table[index].beginIterator();
    while (!Table[index].offEnd())
    {
        cout<<Table[index].getIterator();
        Table[index].advanceIterator();
        cout<<endl;
    }

}

void HashTable:: printTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout<<endl;
        cout<<"Bucket :"<<i<<endl;
        Table[i].beginIterator();
        while (!Table[i].offEnd())
        {
            cout<<Table[i].getIterator();
            Table[i].advanceIterator();
            cout<<endl;
        }
        cout<<"Number of books at this bucket: "<<countBucket(i);
        cout<<endl;
        cout<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }
}


