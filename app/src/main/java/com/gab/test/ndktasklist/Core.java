package com.gab.test.ndktasklist;

/**
 * Created by sdv on 01.10.14.
 */
public class Core {

    static {
        System.loadLibrary( "core");
    }

    public static native int getNmbTasks();
    //public static native void addTask( String serializedTask );
    //public static native String getTask( int index );
    //public static native String[] getTasks( int first, int last);
//    public static native void addTask( String[] serializedTasks );

}
