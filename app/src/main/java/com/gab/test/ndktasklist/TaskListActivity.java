package com.gab.test.ndktasklist;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;


public class TaskListActivity extends Activity {
    private Button addButton;
    private EditText newTaskName;
    private ListView taskListView;
    private SimpleAdapter sAdapter;
    ArrayList<Map<String, Object>> data = new ArrayList<Map<String, Object>>();

    final String ATTRIBUTE_NAME_CHECKED = "checked";
    final String ATTRIBUTE_NAME_TEXT = "text";

    static final String LOG_TAG = "Log MainActivity";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_task_list);

        newTaskName = (EditText) findViewById( R.id.editText );
        addButton = (Button) findViewById( R.id.addButton );

        addButton.setOnClickListener( new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String text = newTaskName.getText().toString();
                newTaskName.setText("");

                try {
                    TaskMgr.AddTask( text );
                    Log.i( LOG_TAG, TaskMgr.GetTask(0) );
//                    Task testTask = new Task( text, false, 0 );
//                    TaskMgr.addTask(Task.toString(testTask));
//                    int last = TaskMgr.getNmbTasks() - 1 ;
//                    String res = TaskMgr.getTask(last);
//                    Task resTask = Task.fromString( res );
//
//                    String[] arr = new String[] { "hello", "world" };
//                    TaskMgr.addTasks(arr);
//                    String[] resArr = TaskMgr.getTasks(0, TaskMgr.getNmbTasks());
//                    int a = last + 1;
                }
                catch (UnsatisfiedLinkError ex)
                {
                    String aMes = ex.getMessage();
                }
                catch (Throwable ex )
                {
                    String aMes = ex.getMessage();
                }

                Map<String, Object> m = new HashMap<String, Object>();
                m.put( ATTRIBUTE_NAME_TEXT, text);
                m.put( ATTRIBUTE_NAME_CHECKED, false);
                data.add( m );
                sAdapter.notifyDataSetChanged();
            }
        });

        String[] from = { ATTRIBUTE_NAME_TEXT, ATTRIBUTE_NAME_CHECKED};
        int[] to = { R.id.tvText, R.id.cbChecked,};
        sAdapter = new SimpleAdapter(this, data, R.layout.task_list_item,from, to);

        taskListView = (ListView)findViewById( R.id.taskListView);
        taskListView.setAdapter( sAdapter );
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.task_list, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
