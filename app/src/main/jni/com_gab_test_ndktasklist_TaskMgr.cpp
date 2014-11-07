#include "com_gab_test_ndktasklist_TaskMgr.h"

#include <TaskMgr.h>
#include <AndroidTask.h>
#include <AndroidLog.h>

#include <string>
#include <vector>

JNIEXPORT jint JNICALL Java_com_gab_test_ndktasklist_TaskMgr_getNmbTasks
  (JNIEnv *, jclass)
  {
    return TaskMgr::getSize();
  }

/*
 * Class:     com_gab_test_ndktasklist_TaskMgr
 * Method:    addTask
 * Signature: (Ljava/lang/String;)V
 */
 JNIEXPORT void JNICALL Java_com_gab_test_ndktasklist_TaskMgr_addTask
   (JNIEnv *pEnv, jclass, jstring theTask)
  {
     const char* tmpStr =  pEnv->GetStringUTFChars( theTask, NULL);

     TaskMgr::addTask( std::string( tmpStr ) );

     pEnv->ReleaseStringUTFChars( theTask, tmpStr);
  }
//
///*
// * Class:     com_gab_test_ndktasklist_TaskMgr
// * Method:    getTask
// * Signature: (I)Ljava/lang/String;
// */
JNIEXPORT jstring JNICALL Java_com_gab_test_ndktasklist_TaskMgr_getTask
  (JNIEnv *pEnv, jclass , jint index)
  {
    return pEnv->NewStringUTF( TaskMgr::getTask(index)->getName().c_str() );
  }


/*
 * Class:     com_gab_test_ndktasklist_TaskMgr
 * Method:    getTasks
 * Signature: (II)[Ljava/lang/String;
 */
//JNIEXPORT jobjectArray JNICALL Java_com_gab_test_ndktasklist_TaskMgr_getTasks
//  (JNIEnv *pEnv , jclass cl, jint first, jint last)
//  {
//     const vector<string>& res = TaskMgr::getTasks( first, last );
//
//     jclass lStringClass = pEnv->FindClass("java/lang/String");
//     jobjectArray ret = (jobjectArray)pEnv->NewObjectArray( res.size(), lStringClass, NULL);
//     pEnv->DeleteLocalRef( lStringClass );
//
//     for(int i=0; i<res.size(); i++ )
//     {
//         pEnv->SetObjectArrayElement( ret, i, pEnv->NewStringUTF( res[i].c_str() ) );
//         // deleteLocalRef of inserted string?..
//     }
//
//     return ret;
//  }
//
///*
// * Class:     com_gab_test_ndktasklist_TaskMgr
// * Method:    addTasks
// * Signature: ([Ljava/lang/String;)V
// */
//JNIEXPORT void JNICALL Java_com_gab_test_ndktasklist_TaskMgr_addTasks
//  (JNIEnv * pEnv, jclass, jobjectArray theTasks)
//  {
//     int stringCount = pEnv->GetArrayLength(theTasks);
//     for (int i=0; i<stringCount; i++)
//     {
//         jstring jStr = (jstring) pEnv->GetObjectArrayElement( theTasks, i );
//         const char * cStr = pEnv->GetStringUTFChars( jStr, NULL );
//         TaskMgr::addTask( std::string( cStr ) );
//         pEnv->ReleaseStringUTFChars( jStr, cStr);
//     }
//  }

  /*
   * Class:     com_gab_test_ndktasklist_TaskMgr
   * Method:    initAndroidTask
   * Signature: ()V
   */
  JNIEXPORT void JNICALL Java_com_gab_test_ndktasklist_TaskMgr_initAndroidTask
    (JNIEnv * pEnv , jclass )
  {
     ANDROID_LOG_INFO( "run TaskMgr_initAndroidTask" );
     pEnv->GetJavaVM( &AndroidTask::JVM);

     jclass jclassLocalRef = pEnv->FindClass("com/gab/test/ndktasklist/Task");
     if( jclassLocalRef == NULL )
     {
         ANDROID_LOG_ERROR("TaskMgr_initAndroidTask: class is null");
         return;
     }
     AndroidTask::JCLASS = (jclass)pEnv->NewGlobalRef( jclassLocalRef );

     AndroidTask::FID_NAME = pEnv->GetFieldID( AndroidTask::JCLASS, "Name", "Ljava/lang/String;");
     if(AndroidTask::FID_NAME == NULL )
     {
         ANDROID_LOG_ERROR("TaskMgr_initAndroidTask: FID_NAME is null");
         return;
     }

     AndroidTask::FID_ID = pEnv->GetFieldID( AndroidTask::JCLASS, "id", "I");
     if(AndroidTask::FID_ID == NULL )
     {
         ANDROID_LOG_ERROR("TaskMgr_initAndroidTask: FID_ID is null");
         return;
     }

     AndroidTask::FID_IS_DONE = pEnv->GetFieldID( AndroidTask::JCLASS, "isDone", "Z");
     if(AndroidTask::FID_IS_DONE == NULL )
     {
        ANDROID_LOG_ERROR("TaskMgr_initAndroidTask: FID_IS_DONE is null");
        return;
     }

     AndroidTask::MID_CONSTRUCTOR = pEnv->GetMethodID( AndroidTask::JCLASS, "<init>",
                                                                            "(Ljava/lang/String;ZI)V" );
     if(AndroidTask::MID_CONSTRUCTOR == NULL )
     {
        ANDROID_LOG_ERROR("TaskMgr_initAndroidTask: MID_CONSTRUCTOR is null");
        return;
     }
  }