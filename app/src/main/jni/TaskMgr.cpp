#include <TaskMgr.h>
#include <Task.h>
#include <AndroidTask.h>
#include <AndroidLog.h>

TaskMgr& TaskMgr::getInstance()
{
   static TaskMgr instance;
   return instance;
}

int TaskMgr::getSize()
{
   return getInstance().taskList.size();
}

void TaskMgr::addTask( const string& theName)
{
   ANDROID_LOG_INFO("TaskMgr::addTask");
   Task* aTask = new AndroidTask ( getSize(), theName, false );
   if( !aTask)
       return;

   getInstance().taskList.push_back( aTask );
}

Task* TaskMgr::getTask( int index )
{
   return getInstance().taskList.at(index);
}

