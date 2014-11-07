#ifndef _TASKMGR_
#define _TASKMGR_


#include <vector>
#include <string>
#include <Task.h>

using namespace std;

class TaskMgr
{
public :
   static int getSize();
   static void addTask( const string& theSerializedTask );
   static Task* getTask( int index );

private:
   static TaskMgr& getInstance();
   TaskMgr() {};
   TaskMgr& operator=( TaskMgr& );

   vector<Task*> taskList;

};

#endif