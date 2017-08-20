#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

class Record
{

    private:
        string name;
        string phone;
    public:
        Record(){    name="";    phone="";}
        void getData();
        void putData();
        friend vector<Record> getDataFromFile( char fname[] );
        friend vector<Record> getDataFromFile1();
        friend void displayAll( vector<Record> recs );
        friend void writeToFile( vector<Record> recs, char fname[] );
        friend bool cmp( Record r1, Record r2);
};
void writeToFile( vector<Record> recs, char fname[] );
void displayAll( vector<Record> recs );
vector<Record> getDataFromFile(char fname[]);
vector<Record> getDataFromFile1();
vector<Record> deleteRecord(vector<Record> recs);
vector<Record> editRecord(vector<Record> recs);
bool cmp( Record r1, Record r2);
int getInt();

#endif // RECORD_H_INCLUDED
