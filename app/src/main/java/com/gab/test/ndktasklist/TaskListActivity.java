package com.gab.test.ndktasklist;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.io.IOException;
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

                //Core.addTask( Task.toString(( new Task( text ) ) ) );
//                int last = Core.getNmbTasks();

                try {
                    int last = Core.getNmbTasks();
//                    Core anObj = new Core();
//                    int last = anObj.getNmbTasks();
                    int a = last + 1;
                }
                catch (UnsatisfiedLinkError ex)
                {
                    String aMes = ex.getMessage();
                    int a = 3+3;
                }
                catch (Throwable ex )
                {
                    String aMes = ex.getMessage();
                    int a = 6 + 4;
                }

               // Task ret = Task.fromString( Core.getTask( last ) );

                //String[] arrRet = Core.getTasks( 0, last );

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
