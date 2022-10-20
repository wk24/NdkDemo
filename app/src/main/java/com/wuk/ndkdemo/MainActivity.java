package com.wuk.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Point;
import android.os.Bundle;
import android.widget.TextView;

import com.wuk.ndkdemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'ndkdemo' library on application startup.
    static {
        System.loadLibrary("ndkdemo");
    }

    private ActivityMainBinding binding;

    public String name = "Delusion";



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());


        int s = callPlusMethod();
        changeName();
        // Example of a call to a native method
        TextView tv = binding.sampleText;


        Point point = createPoint();

        tv.setText(stringFromJNI() + "---"+s+"---"+name+
                "---" + point.x);

    }


    public int onPlus(int number1, int number2) {
        int num = number1 + number2;
        return num;
    }


    public native String stringFromJNI();

    /**
     * 互调方法
     * @return
     */
    public native int callPlusMethod();

    /**
     * 修改成员变量
     */
    public native void changeName();

    /**
     * 创建对象
     * @return
     */
    public native Point createPoint();
}