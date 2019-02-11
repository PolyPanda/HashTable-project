//
//  Book.hpp
//  lab 8
//
//  Created by Andie Yu on 6/4/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//

//
//  Book.hpp
//  lab 7
//
//  Created by Andie Yu on 5/28/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//
#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <ostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    unsigned isbn;
    double price;
    
public:
    
    /**Constructors*/
    Book();
    Book(string t, string a, unsigned i, double p);
    
    
    /**Access Functions*/
    string get_title();
    string get_author();
    unsigned get_isbn();
    double get_price();
    
    /**Manipulation Procedures*/
    void set_title(string t);
    void set_author(string a);
    void set_isbn(unsigned i);
    void set_price(double p);
    
    
    /**Additional Functions*/
    
    friend ostream& operator<<(ostream& os, const Book& book);
    //prints out a book to the designated stream in the following format
    //<title> by <author>
    //$<price>
    //isbn #<isbn>
    //note that the << is required to be a friend function, not a member function
    //note2: do not print out the <> as part of the output
    
    bool operator==(const Book& book);
    //compares two books to determine if they are the same book
    
    bool operator<(const Book& book);
    //compares two books to determine if one comes before the other
    //alphabetically by title and secondarily by author if the two
    //books contain the same title
    //returns false if the two books are the same
    
    bool operator>(const Book& book);
    //compares two books to determine if one comes after the other
    //alphabetically by title and secondarily by author if the two
    //books contain the same title
    //returns false if the two books are the same
    
};


#endif /* BOOK_H_ */
