#ifndef _TASK_
#define _TASK_

#include <string>
using std::string;

class Task
{
public :

   Task( int id, const string& theName, bool theIsDone );

   virtual const string& getName() const;
   virtual void setName( const string& );

   virtual bool isDone() const;
   virtual void setIsDone( bool );

   virtual int getId() const;
   virtual void setId( int theId );

private:
   int id;
   string name;
   bool is_done;

   Task( const Task& );
   Task& operator= ( const Task& );
};

#endif