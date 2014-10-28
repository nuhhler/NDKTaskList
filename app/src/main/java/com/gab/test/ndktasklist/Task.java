package com.gab.test.ndktasklist;

import org.w3c.dom.NameList;

import java.io.Serializable;

/**
 * Created by sdv on 30.09.14.
 */
public class Task implements Serializable{
    public Boolean isDone;
    public String Name;
    public int id;

    private static int counter = 0;


    public Task ( String Name )
    {
        this.Name = Name;
        this.isDone = false;
        id = counter;
        counter += 1;
    }

    // todo should be refactoring with using id
    static String toString( Task task )
    {
        return "Task{" +
                "isDone=" + task.isDone +
                ", Name='" + task.Name + '\'' +
                '}';
    }

    // todo should be refactoring with using id
    static Task fromString( String data )
    {
        String Name = data.substring( data.indexOf("'")+1, data.lastIndexOf("'"));
        Boolean isDone = Boolean.valueOf( data.substring (data.indexOf("=")+1, data.indexOf("'")) );
        Task res = new Task( Name );
        res.isDone = isDone;
        return res;
    }
}
