//
//  main.cpp
//  lab 8
//
//  Created by Andie Yu on 6/4/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable ht;
    Book pp("Pride and Prejudice", "Jane Austen", 1234567, 4.95);
    Book c("Contact", "Carl Sagan", 99993339, 9.95);
    Book hg("The Hunger Games", "Suzanne Collins", 12388888, 13.55);
    Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
    Book mhc("The Man in the High Castle", "Philip K Dick", 95959595, 15.95);
    Book bh("Bleak House", "Charles Dickens", 473890238, 8.00);
    
    ht.insertData(pp);
    ht.insertData(c);
    ht.insertData(hg);
    ht.insertData(mhc);
    ht.insertData(bh);
    int index = ht.hash(pp.get_title()+pp.get_author());
    ht.printBucket(index);
    index = ht.hash(c.get_title()+c.get_author());
    ht.printBucket(index);
    index = ht.hash(hg.get_title()+hg.get_author());
    ht.printBucket(index);
    index = ht.hash(hp.get_title()+hp.get_author());
    ht.printBucket(index);
    index = ht.hash(mhc.get_title()+mhc.get_author());
    ht.printBucket(index);
    index = ht.hash(bh.get_title()+bh.get_author());
    ht.printBucket(index);
    cout<<"Finish test Print bucket function. "<<endl;
    cout<<"******************************************"<<endl;
    ht.printTable();
    cout<<"Check search function. "<<endl;
    if (ht.searchData(pp) == -1)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Found"<<endl;
    }
    cout<<"Check remove function"<<endl;
    ht.removeData(bh);
    ht.printTable();
}
