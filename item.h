#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "list.h"

class Item{

    private:
        std::string text;
        int listId, id;
        bool completed;
        static int idg;
    public:
        Item();
        ~Item();
        void SetItem(std::string, int);
        void SetCompleted();
        void showItem();
        friend void ResetId(Item);
        friend class List;
        void DeleteItem();
        friend std::ostream& operator<<(std::ostream&, Item);
        friend std::istream& operator>>(std::istream&, Item&);


};

#endif // ITEM_H_INCLUDED
