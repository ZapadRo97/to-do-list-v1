#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include "item.h"
class Item;

class List{
    private:
        Item *items;
        std::string name;
        int noItems, id;
        int static idg;
    public:
        List(std::string, int);
        ~List();
        void ShowList();
        void AddListItem(int, std::string);
        List& operator=(const int);

        int GetNumberOfItems();

        List& operator++();
        List operator++(int);

        List& operator--();
        List operator--(int);

        friend std::ostream& operator<<(std::ostream&, List);

        friend std::istream& operator>>(std::istream&, List&);

};

#endif // LIST_H_INCLUDED
