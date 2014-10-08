#include "com_gab_test_ndktasklist_Core.h"

//#include <Storage.h>
//#include <string>
//#include <vector>

JNIEXPORT jint JNICALL Java_com_gab_test_ndktasklist_Core_getNmbTasks
  (JNIEnv *, jobject)
  {
    //return Storage::getInstance().getSize();
    return 5;
  }

/*
 * Class:     com_gab_test_ndktasklist_Core
 * Method:    addTask
 * Signature: (Ljava/lang/String;)V
 */
//JNIEXPORT void JNICALL Java_com_gab_test_ndktasklist_Core_addTask
//  (JNIEnv * pEnv, jobject obj, jstring theTask)
//  {
//     const char* tmpStr =  pEnv->GetStringUTFChars( theTask, NULL);
//
//     Storage::getInstance().addTask( std::string( tmpStr ) );
//
//     pEnv->ReleaseStringUTFChars( theTask, tmpStr);
//  }
//
///*
// * Class:     com_gab_test_ndktasklist_Core
// * Method:    getTask
// * Signature: (I)Ljava/lang/String;
// */
//JNIEXPORT jstring JNICALL Java_com_gab_test_ndktasklist_Core_getTask
//  (JNIEnv *pEnv, jobject obj, jint index)
//  {
//    return pEnv->NewStringUTF( Storage::getInstance().getTask(index).c_str() );
//  }


/*
 * Class:     com_gab_test_ndktasklist_Core
 * Method:    getTasks
 * Signature: (II)[Ljava/lang/String;
 */
//JNIEXPORT jobjectArray JNICALL Java_com_gab_test_ndktasklist_Core_getTasks
//  (JNIEnv *pEnv , jclass cl, jint first, jint last)
//  {
//     jobjectArray ret;
//     const vector<string>& res = Storage::getInstance().getTasks( first, last );
//
//     ret= (jobjectArray)pEnv->NewObjectArray( res.size(), pEnv->FindClass("java/lang/String"),
//                                                          pEnv->NewStringUTF(""));
//
//     for(int i=0; i<res.size(); i++ )
//     {
//         pEnv->SetObjectArrayElement( ret, i, pEnv->NewStringUTF( res[i].c_str() ) );
//     }
//
//     return ret;
//  }

/*
 * Class:     com_gab_test_ndktasklist_Core
 * Method:    addTask
 * Signature: ([Ljava/lang/String;)V
 */
//JNIEXPORT void JNICALL Java_com_gab_test_ndktasklist_Core_addTask___3Ljava_lang_String_2
//  (JNIEnv *, jclass, jobjectArray);