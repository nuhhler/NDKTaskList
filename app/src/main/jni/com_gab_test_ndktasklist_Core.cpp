#include "com_gab_test_ndktasklist_Core.h"

#include <Storage.h>
#include <string>
#include <vector>

JNIEXPORT jint JNICALL Java_com_gab_test_ndktasklist_Core_getNmbTasks
  (JNIEnv *, jclass)
  {
    return Storage::getInstance().getSize();
  }

/*
 * Class:     com_gab_test_ndktasklist_Core
 * Method:    addTask
 * Signature: (Ljava/lang/String;)V
 */
 JNIEXPORT void JNICALL Java_com_gab_test_ndktasklist_Core_addTask
   (JNIEnv *pEnv, jclass, jstring theTask)
  {
     const char* tmpStr =  pEnv->GetStringUTFChars( theTask, NULL);

     Storage::getInstance().addTask( std::string( tmpStr ) );

     pEnv->ReleaseStringUTFChars( theTask, tmpStr);
  }
//
///*
// * Class:     com_gab_test_ndktasklist_Core
// * Method:    getTask
// * Signature: (I)Ljava/lang/String;
// */
JNIEXPORT jstring JNICALL Java_com_gab_test_ndktasklist_Core_getTask
  (JNIEnv *pEnv, jclass , jint index)
  {
    return pEnv->NewStringUTF( Storage::getInstance().getTask(index).c_str() );
  }


/*
 * Class:     com_gab_test_ndktasklist_Core
 * Method:    getTasks
 * Signature: (II)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_gab_test_ndktasklist_Core_getTasks
  (JNIEnv *pEnv , jclass cl, jint first, jint last)
  {
     const vector<string>& res = Storage::getInstance().getTasks( first, last );

     jclass lStringClass = pEnv->FindClass("java/lang/String");
     jobjectArray ret = (jobjectArray)pEnv->NewObjectArray( res.size(), lStringClass, NULL);
     pEnv->DeleteLocalRef( lStringClass );

     for(int i=0; i<res.size(); i++ )
     {
         pEnv->SetObjectArrayElement( ret, i, pEnv->NewStringUTF( res[i].c_str() ) );
         // deleteLocalRef of inserted string?..
     }

     return ret;
  }

/*
 * Class:     com_gab_test_ndktasklist_Core
 * Method:    addTasks
 * Signature: ([Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_gab_test_ndktasklist_Core_addTasks
  (JNIEnv * pEnv, jclass, jobjectArray theTasks)
  {
     int stringCount = pEnv->GetArrayLength(theTasks);
     for (int i=0; i<stringCount; i++)
     {
         jstring jStr = (jstring) pEnv->GetObjectArrayElement( theTasks, i );
         const char * cStr = pEnv->GetStringUTFChars( jStr, NULL );
         Storage::getInstance().addTask( std::string( cStr ) );
         pEnv->ReleaseStringUTFChars( jStr, cStr);
     }
  }