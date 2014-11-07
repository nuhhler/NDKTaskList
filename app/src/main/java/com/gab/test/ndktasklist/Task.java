package com.gab.test.ndktasklist;

import android.util.Log;

import org.w3c.dom.NameList;

import java.io.Serializable;

/**
 * Created by sdv on 30.09.14.
 */
public class Task implements Serializable{
    public boolean isDone;
    public String Name;
    public int id;

    static final String LOG_TAG = "Log Task";

    public Task ( String Name, boolean isDone, int id )
    {
        Log.i(LOG_TAG, "create new Task");
        this.Name = Name;
        this.isDone = isDone;
        this.id = id;
    }
}
