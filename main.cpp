//TODO List
#include <string>
#include <iostream>
#include <fstream>
#include "list.h"
#include "item.h"

using namespace std;

int main()
{
    //ofstream todos;
    //todos.open("todos.txt", std::ofstream::out | std::ofstream::trunc);

    fstream todos;

    cout<<"Very Simple TODO List"<<endl;
    int choice = -1;
    int noItems = -1;
    string name;
    cout<<"Enter list name: \n";
    cin>>name;
    List FirstList(name, 10);
    Item FirstItems[100];
    int i = 0;


    cout<<"Commands: \n'1 - show list' \n'2 - add item' \n'3 - remove item' \n'4 - set completed' \n'5 - save' \n'6 - load' \n";

    while(choice != 0){
        cout<<"Introduceti comanda \n";
        cin>>choice;
        if(choice == 1){
            cout<<"Lista: \n"<<FirstList;
            cout<<"Elementele: \n";
            FirstList.ShowList();
        }
        if(choice == 2){
            string text;
            cout<<"Enter text: \n";
            cin>>text;
            FirstList.AddListItem(i, text);
            FirstList++;
            i++;
        }
        if(choice == 3){
            int cho;
            cout<<"Introduceti ID-ul elementului \n";
            cin>>cho;
            FirstItems[cho].DeleteItem();
            //FirstList--;
            i--;
        }
        if(choice == 4){
            int id;
            cout<<"Introduceti ID-ul elementului \n";
            cin>>id;
            FirstItems[id].SetCompleted();
        }
        if(choice == 5){
            todos.open("todos.txt", std::ofstream::out | std::ofstream::trunc);
            todos<<FirstList;
            noItems = FirstList.GetNumberOfItems();
            for(int counter = 0; counter < noItems; counter++)
                todos<<FirstItems[counter];
            todos.close();
            cout<<"Lista salvata in fisier \n";
        }
        if(choice == 6){
            todos.open("todos.txt");
            //do things
            todos>>FirstList;
            noItems = FirstList.GetNumberOfItems();
            for(int counter = 0; counter < noItems; counter++)
                todos>>FirstItems[counter];
            todos.close();
            cout<<"Lista incarcata din fisier \n";
        }
    }
    //cout<<FirstItems[0];

    return 0;
}
