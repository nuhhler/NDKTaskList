#include <Storage.h>

Storage& Storage::getInstance()
{
   static Storage instance;
   return instance;
}

int Storage::getSize() const
{
   return taskList.size();
}

void Storage::addTask( string theSerializedTask)
{
   taskList.push_back( theSerializedTask );
}

void Storage::addTasks( vector<string> theTasks )
{
   taskList.insert( taskList.end(), theTasks.begin(), theTasks.end() );
}

string Storage::getTask( int index ) const
{
   return taskList.at(index);
}

vector<string> Storage::getTasks( int first, int last) const
{
   vector<string> ret( last-first );
   copy( taskList.begin() + first, taskList.begin() + last, ret.begin() );
//   for( int i = first; i<last ; i++)
//   {
//      ret.push_back( taskList.at(i) );
//   }
   return ret;
}
