#ifndef _TASK_
#define _TASK_

#include <string>
using std::string;

class Task
{
public :
   const string& getName() const;
   void setName( const string& );

   bool isDone() const;
   void setIsDone( bool );

   int getId() const;

private:
   int id;
   string name;
   bool is_done;

   Task( int id, const string& theName, bool thIsDone );
   Task( const Task& );
   Task& operator= ( const Task& );
};

#endif