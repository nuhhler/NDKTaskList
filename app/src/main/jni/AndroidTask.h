#ifndef _ANDROIDTASK_
#define _ANDROIDTASK_

#include <Task.h>
#include <jni.h>

class AndroidTask: public Task
{
public :
   AndroidTask( int id, const string& theName, bool thIsDone );
   // todo ~AndroidTask();

   // override
   // this methods also modifies corresponded objects in JAVA
   virtual void setName( const string& );
   virtual void setIsDone( bool );
   virtual void setId( int theId );
   virtual void setJavaObject( jobject theObject );

public:
   static jfieldID FID_NAME;
   static jfieldID FID_IS_DONE;
   static jfieldID FID_ID;
   static JavaVM* JVM;
   static jclass JCLASS;
   static jmethodID MID_CONSTRUCTOR;

private:
   jobject aJObject;

   static JNIEnv* getJniEnv();
   AndroidTask( const AndroidTask& );
   AndroidTask& operator= ( const AndroidTask& );
};

#endif