//
//  Book.cpp
//  lab 8
//
//  Created by Andie Yu on 6/4/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//

//
//  Book.cpp
//  lab 7
//
//  Created by Andie Yu on 5/28/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <string.h>

Book::Book():title(""), author(""), isbn(0), price(0.0){};

Book::Book(string t, string a, unsigned i, double p) {
    title = t;
    author = a;
    isbn = i;
    price = p;
}

/**Access Functions*/

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

unsigned Book::get_isbn() {
    return isbn;
}

double Book::get_price() {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/


bool Book::operator==(const Book& book) {
    return (title == book.title && author==book.author);
}

bool Book:: operator<(const Book &book)
{
    if(this->title.compare(book.title) <0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Book:: operator>(const Book &book)
{
    if(this->title.compare(book.title) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& os, const Book& book)
{
    os <<book.title<<" by "<<book.author<<endl;
    os <<fixed<<setprecision(2)<< "$"<<book.price<<endl;
    os << "ISBN: " << book.isbn<<endl;
    return os;
}

//To-do: Add <, > and << here

