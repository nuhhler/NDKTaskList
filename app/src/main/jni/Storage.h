#ifndef _STORAGE_
#define _STORAGE_


#include <vector>
#include <string>

using namespace std;

class Storage
{
public :
   static Storage& getInstance();
   Storage() {};
   Storage& operator=( Storage& );

   int getSize() const;
   void addTask( string theSerializedTask );
   void addTasks( vector<string> theTasks );
   string getTask( int index ) const;
   vector<string> getTasks( int first, int last) const;

private:
   vector<string> taskList;

};

#endif