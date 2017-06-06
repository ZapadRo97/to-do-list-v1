#include <string>
#include <iostream>
#include "list.h"

using namespace std;

int List::idg = 0;
Item temp;

List::List(string name, int noItems) //constructor
{
    this->name = name;
    id = idg++;
    this->noItems = noItems;
    this->items = new class Item[noItems];
    ResetId(temp);
    //this->noItems = 0;
}

List::~List() //destructor
{
    idg--;
    delete[] this->items;
}

void ResetId(Item item)
{
    item.idg = 1;
}

int List::GetNumberOfItems()
{
    return this->noItems;
}



void List::ShowList()
{
    for(int i = 0; i< noItems; i++){
        if(items[i].text != "###")
        cout<<items[i].text<<" "<<items[i].completed<<" "<<items[i].id<<endl;
    }
}

void List::AddListItem(int index, string text)
{
    items[index].SetItem(text, id);
}

List& List::operator=(const int nr)
{
    this->noItems = nr;
    return *this;
}

List& List::operator++()
{
    this->noItems++;
    return *this;
}

List List::operator++(int)
{
    List temp = *this;
    ++*this;
    return temp;
}

List& List::operator--()
{
    this->noItems--;
    return *this;
}

List List::operator--(int)
{
    List temp = *this;
    --*this;
    return temp;
}

ostream& operator<<(ostream& out, List listus)
{
    out<<listus.name<<" "<<listus.noItems<<" "<<listus.id<<endl;
    return out;
}


istream& operator>>(istream & in, List &listus)
{
    in>>listus.name>>listus.noItems>>listus.id;
    return in;
}

