#include <AndroidTask.h>
#include <AndroidLog.h>

jfieldID AndroidTask::FID_NAME = NULL;
jfieldID AndroidTask::FID_IS_DONE = NULL;
jfieldID AndroidTask::FID_ID = NULL;
JavaVM* AndroidTask::JVM = NULL;
jclass AndroidTask::JCLASS = NULL;
jmethodID AndroidTask::MID_CONSTRUCTOR = NULL;

AndroidTask::AndroidTask( int theId, const std::string& theName, bool theIsDone ) :
                             Task( theId, theName, theIsDone )
{
    ANDROID_LOG_INFO( "run AndroidTask::AndroidTask" );
    JNIEnv* pEnv = getJniEnv();
    if ( pEnv == NULL )
        return;

    jstring jName = pEnv->NewStringUTF( theName.c_str() );
    aJObject = pEnv->NewObject( AndroidTask::JCLASS, AndroidTask::MID_CONSTRUCTOR,
                                                     jName, theIsDone, theId );
    if( aJObject == NULL )
    {
        ANDROID_LOG_ERROR( "AndroidTask::AndroidTask: can't create an object" );
        return;
    }

    ANDROID_LOG_INFO( "finish AndroidTask::AndroidTask" );
}

JNIEnv* AndroidTask::getJniEnv()
{

    JavaVMAttachArgs attachArgs;
	attachArgs.version = JNI_VERSION_1_6;
	attachArgs.name = ">>>NativeThread__Any";
	attachArgs.group = NULL;

	JNIEnv* env;
	if ( JVM->AttachCurrentThread(&env, &attachArgs) != JNI_OK) {
	    ANDROID_LOG_ERROR( "AndroidTask::getJniEnv: can't get JNIEnv" );
		env = NULL;
	}

	return env;
}

void AndroidTask::setName( const string& theName )
{
    Task::setName( theName );

    if( aJObject == NULL )
    {
        return;
    }

    JNIEnv* pEnv = getJniEnv();
    if( pEnv == NULL )
    {
        return;
    }
    jstring jName = pEnv->NewStringUTF( theName.c_str() );
    if( jName == NULL )
    {
        return;
    }

    pEnv->SetObjectField( aJObject, FID_NAME, jName );
}

void AndroidTask::setIsDone( bool theIsDone )
{
    Task::setIsDone( theIsDone );

    if( aJObject == NULL )
    {
        return;
    }

    JNIEnv* pEnv = getJniEnv();
    if( pEnv == NULL )
    {
        return;
    }

    pEnv->SetBooleanField( aJObject, FID_IS_DONE, theIsDone );
}

void AndroidTask::setId( int theId )
{
    Task::setId( theId );

    if( aJObject == NULL )
    {
        return;
    }

    JNIEnv* pEnv = getJniEnv();
    if( pEnv == NULL )
    {
        return;
    }

    pEnv->SetIntField( aJObject, FID_ID, theId );
}

void AndroidTask::setJavaObject( jobject theObject )
{
    // todo release previous object
    aJObject = theObject;
}