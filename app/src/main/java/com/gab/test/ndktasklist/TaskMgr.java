package com.gab.test.ndktasklist;

import android.util.Log;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by sdv on 01.10.14.
 */
public class TaskMgr {
    static final String JNI_TAG = "Log From JNI";

    static {
        try {
            System.loadLibrary("core");
            initAndroidTask();
        }
        catch ( UnsatisfiedLinkError ex )
        {
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
        }
        catch( NoClassDefFoundError ex)
        {
            // TaskMgr_initAndroidTask: can't find class 'Task'
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
        }
        catch(  NoSuchFieldError ex)
        {
            // TaskMgr_initAndroidTask: can't find fields of class 'Task'
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
        }
        catch(  NoSuchMethodError ex)
        {
            // TaskMgr_initAndroidTask: can't find constructor of class 'Task'
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
        }
        catch (Throwable ex )
        {
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
        }

        storage = new HashMap<Integer, Task>();
    }

    public static native int getNmbTasks();


//    public static native String[] getTasks( int first, int last);
//    public static native void addTasks( String[] serializedTasks );

    private static native void initAndroidTask();

    public static native void addTask( String name ) throws InstantiationException;
    public static void AddTask( String theName )
    {
        try {
            addTask( theName);
        }
        catch ( InstantiationException ex)
        {
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
        }
        catch (Throwable ex )
        {
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
        }
    }

    public static native String getTask( int index );
    public static String GetTask( int index )
    {
        try {
            return getTask( index );
        }
        catch (Throwable ex )
        {
            String aMes = ex.getMessage();
            Log.e(JNI_TAG, aMes);
            return null;
        }
    }


    private static Map<Integer, Task> storage;

}
