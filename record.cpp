#include "record.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "tinyfiledialogs.h"

using namespace std;
/**
    Function : getInt
*/

int getInt1()
{
    //gets integer from user.
    //this function is safer than using
    //cin >> i;
    string input ="";
    int num;
    while (true)
    {
        getline(cin,input);
        stringstream str(input);
        if (str >> num)
            return num;
        cout << "\nInvalid input. \nRetry: " ;
    }
}


void Record::getData(){
    cout << "\nEnter Name :        " ;
    getline(cin,name);
    cout << "\nEnter phone number :" ;
    getline(cin,phone);
}
void Record::putData(){
    cout << setfill(' ')
    << setw(30) << name
    << setw(30) << phone ;
}
void displayAll(vector<Record> recs){
    // display all records in tabular form
    int n=1;
    cout << setfill(' ') << setw(35) << "Name" << setw(30) << "Phone" ;
    for ( vector< Record >::iterator i = recs.begin(); i != recs.end(); ++i ){
        cout << "\n" << setw(5) <<n++;
        (*i).putData();
    }
}
void writeToFile(vector <Record> recs, char fname[]){
    ofstream outfile(fname);
    for ( vector<Record>::iterator i = recs.begin(); i != recs.end(); ++i ){
            outfile <<(*i).name << "\t" << (*i).phone << "\n";
    }
    outfile.close();
}

vector<Record> getDataFromFile(char fname[]){
    vector<Record> phonebook;
    Record rec;
    ifstream infile(fname);
    if (!infile)    return phonebook;
    string input = "";
    while (getline(infile,rec.name,'\t') and getline(infile,rec.phone,'\n') ){
        phonebook.push_back(rec);
    }
    infile.close();
    return phonebook;

}

vector<Record> getDataFromFile1(){
    vector<Record> phonebook;
    Record rec;
    char const * lFilterPatterns[2] = { "*.txt", "*.text" };
    char const* fname = tinyfd_openFileDialog(
		"let us read the password back",
		"",
		2,
		lFilterPatterns,
		NULL,
		0);
    ifstream infile(fname);
    if (!infile)    return phonebook;
    string input = "";

    while (getline(infile,rec.name,'\t') and getline(infile,rec.phone,'\n') ){
        phonebook.push_back(rec);
    }

    infile.close();
    return phonebook;
}

vector<Record> deleteRecord(vector<Record> recs){
    //delete a record from vector
    if (recs.empty()){
        cout << "\nThere are no records to be deleted !\n" ;
    }
    else{
            cout << "\nEnter record number of record to be deleted: ";
            int pos = getInt();
            if(pos-1 >=recs.size()and pos>0){
                    cout << "\nInvalid record number !\n" ;
            }
            else{
                recs.erase(recs.begin()+pos-1);
            }
    }
    return recs;
}

vector<Record> editRecord(vector<Record> recs){
    if(recs.empty()){
        cout << "\nThere are no record to be edited!\n";
    }
    else {
        cout << "\nEnter record number of record to be edited: ";
        int pos = getInt();
        if(pos-1 >=recs.size() and pos>0){
            cout << "\nInvalid record number !\n" ;
        }
        else{
            cout << "\nThis record will be edited : \n";
            cout << setfill(' ') << setw(30) << "Name" << setw(30) << "Phone\n" ;
            recs[pos-1].putData();
            recs[pos-1].getData();
        }
    }
    return recs;
}


bool cmp( Record r1, Record r2){
    //compare two records using name field
    //used for sorting vector with sort() function
    return r1.name < r2.name;
}
