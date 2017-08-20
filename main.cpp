/**
    @author: Mihai Cornel   mhcrnl@gmail.com
    @file:  main.cpp
    @date:  19.08.2017
    @library:   tinyfiledialogs
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <iomanip>
/**
    Includerea librariei tinyfiledialogs. Poate fi obtinuta
    de la adresa:
    https://sourceforge.net/u/mhcrnl/tinyfiledialogs/ci/master/tree/
*/
#include "tinyfiledialogs.h"
#include "record.h"
using namespace std;

/**
    Functia getInt - returneaza optiunea utilizatorului
*/
int getInt(){
    string input = "";
    int num;
    while(true){
        getline(cin,input);
        stringstream str(input);
        if(str>>num){
            return num;
        }
        cout<<"\nIntrare invalida. \tReincercati: ";
    }
}
/**
    Functia menu() - meniul programului
*/
int menu(){
    string title = "Meniul Aplicatiei";
    string choices[] = { "Introduceti un nou contact", "Editati contactul",
        "Afisati contactele", "Stergeti", "Exit", "GitHub push"};
    cout<<'\t'<<title<<endl;
    cout<<'\t'<<setfill('-')<<setw(title.length());
    for(int i=0; i<6; i++){
        cout<<'\n'<< i+1 <<'\t'<<choices[i]<<endl;
    }
    cout<<"\nIntroduceti alegerea dvs: ";
    return getInt() ;
}

int runProgram(){
    char fname[] = "Record.txt";
    char const * lFilterPatterns[2] = { "*.txt", "*.text" };
    /*
    char lTheOpenFileName[] =tinyfd_openFileDialog(
		"let us read the password back",
		"",
		2,
		lFilterPatterns,
		NULL,
		0);
		*/
    vector<Record> phoneBook = getDataFromFile1();
    Record rec;
    int choice = menu();
    while(true){
        if(not phoneBook.empty()){
            sort(phoneBook.begin(),phoneBook.end(),cmp);
        }
        switch(choice){
           case 1:
               rec.getData();
               phoneBook.push_back(rec);
               cout << "\nRecord added.\n" ;
               break;
           case 2:
               phoneBook = editRecord(phoneBook);
               cout << "\nRecord updated.\n" ;
               break;
           case 3:
               displayAll(phoneBook);
               break;
           case 4:
               phoneBook = deleteRecord(phoneBook);
               cout << "\nRecord deleted.\n" ;
               break;
           case 5:
               writeToFile(phoneBook,fname);
               phoneBook.clear();
               return 0;
               break;
            case 6:
                system("./gitpush.sh");
                break;
           default :
               cout << "\nInvalid Choice ! \nRetry :\n" ;
               break;
        }
        getchar();
        //clearScreen;
        choice = menu();
    }
}

int main()
{
    cout << "Hello world! From PhoneBook program." << endl;
    runProgram();
    return 0;
}
