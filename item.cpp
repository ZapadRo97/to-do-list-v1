#include <string>
#include <iostream>
#include "item.h"


using namespace std;

int Item::idg = -1;

Item::Item() //constructor without parameters
{
    text = "###";
    listId = 0;
    completed = 0;
    id = idg++;
}

void Item::SetItem(string text, int listId)
{
    this->text = text;
    this->listId = listId;
    id = idg++;
}

void Item::DeleteItem()
{
    this->text = "###";
}

Item::~Item() //destructor
{
    idg--;
}

void Item::showItem()
{
    cout<<this->text<<endl;
    cout<<this->completed<<endl;
    cout<<this->id<<endl;

}

void Item::SetCompleted()
{
    this->completed = 1;
}

ostream& operator<<(ostream& out, Item item)
{
    out<<item.text<<" "<<item.id<<" "<<item.completed<<" "<<item.listId<<endl;
    return out;
}


istream& operator>>(istream & in, Item &item)
{
    in>>item.text>>item.id>>item.completed>>item.listId;
    return in;
}

