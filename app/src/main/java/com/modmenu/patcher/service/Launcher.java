package com.modmenu.patcher.service;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Service;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.ColorStateList;
import android.content.SharedPreferences;
import android.content.res.Resources;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Point;
import android.graphics.PorterDuff;
import android.text.Html;
import android.graphics.Typeface;
import android.graphics.drawable.Drawable;
import android.os.Build;
import android.os.IBinder;
import android.util.Base64;
import android.util.DisplayMetrics;
import android.util.TypedValue;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.graphics.drawable.GradientDrawable;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.CheckBox;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;
import android.view.Gravity;
import android.graphics.PixelFormat;
import android.view.ViewConfiguration;

import com.modmenu.patcher.RUtils;

import java.io.DataOutputStream;
import java.io.IOException;

import java.io.File;

public class Launcher
extends Service {
    final LinearLayout[] contentLayouts;
    float density;
    int dpi;
    RelativeLayout g_iconLayout;
    LinearLayout g_mainLayout;
    final LinearLayout[] layoutParents;
    boolean resetAvailable;
    int scanThread;
    int screenHeight;
    int screenWidth;
    @SuppressLint("StaticFieldLeak")
    static Context ctx;
    final ScrollView[] scrollLayouts;
    int selectedTab;
    final FrameLayout[] tabLayouts;
    int type;
    WindowManager windowManager;
    private RelativeLayout relativeLayout;
    final String[] TABS;

    public Launcher() {
        String[] arrstring = new String[]{"Player World", "Item's", "Vehicle", "Aimbot", "Extras", "Settings", "Info"};
        this.TABS = arrstring;
        this.tabLayouts = new FrameLayout[arrstring.length];
        this.scrollLayouts = new ScrollView[arrstring.length];
        this.layoutParents = new LinearLayout[arrstring.length];
        this.contentLayouts = new LinearLayout[arrstring.length];
        this.resetAvailable = false;
        this.selectedTab = 0;
        this.scanThread = 1;
    }
    @SuppressLint({"NewApi", "ObsoleteSdkInt"})
    private void AddToggle(String name, final int num) {
        Switch switch_ = new Switch((Context)this);
        switch_.setText(name);
        switch_.setTextColor(-1);
		switch_.setPadding(this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f));
        switch_.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -1));
        ColorStateList colorStateList = new ColorStateList((int[][])new int[][]{{-16842912}, {16842912}, new int[0]}, new int[]{-1, -7829368, -1});
        switch_.setButtonTintList(new ColorStateList((int[][])new int[][]{{-16842912}, {16842912}}, new int[]{-1, -1}));
        if (Build.VERSION.SDK_INT >= 21) {
            switch_.setTrackTintList(colorStateList);
            switch_.setTrackTintMode(PorterDuff.Mode.OVERLAY);
         }
         switch_.getThumbDrawable().setTintList(colorStateList);
        if ((Object) 0 instanceof ViewGroup) {
            ((ViewGroup) (Object) 0).addView((View)switch_);
            return;
        }
        this.layoutParents[(Integer) 0].addView((View)switch_);
        switch_.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked){
                    SettingValue(num,isChecked);
                } }); }
    
    @SuppressLint("WrongConstant")
    private void AddButtonHome(String string, int n, int n2, View.OnClickListener onClickListener) {
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setOrientation(1);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(n, n2));
        linearLayout.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f));
        linearLayout.setGravity(17);
        Button button5 = new Button((Context)this);
        button5.setText((CharSequence)string);
        button5.setX((float)this.convertSizeToDp(10.0f));
        button5.setY(10.0f + button5.getX());
        button5.setTextSize(1, 12f);
        button5.setOnClickListener(onClickListener);
        button5.setBackgroundColor(Color.TRANSPARENT);
        button5.setTextColor(-1);
        button5.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -1));
        linearLayout.addView((View)button5);
        }
	@SuppressLint("WrongConstant")
    private void AddButton2(Object object, String string, int n, int n2, View.OnClickListener onClickListener) {	
		LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setOrientation(1);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(n, n2));
        linearLayout.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f));
        linearLayout.setGravity(17);
	    Button button = new Button((Context)this);
        button.setText((CharSequence)string);
        button.setX((float)this.convertSizeToDp(10.0f));
        button.setY(10.0f + button.getY());
        button.setTextSize(1, 12.5f);
        button.setOnClickListener(onClickListener);
        button.setBackgroundColor(Color.argb((int)255, (int)102, (int)102, (int)102));
        button.setTextColor(-1);
        button.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -1));
        linearLayout.addView((View)button);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
        }
    }
	

    
    @SuppressLint("WrongConstant")
    void AddButton(Object object, String string, int n, int n2, View.OnClickListener onClickListener) {
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setOrientation(1);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(n, n2));
        linearLayout.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f));
        linearLayout.setGravity(17);
        Button button = new Button((Context)this);
        button.setText((CharSequence)string);
        button.setTextColor(-1);
        button.setOnClickListener(onClickListener);
        button.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -1));
        GradientDrawable gradientDrawable = new GradientDrawable();
        gradientDrawable.setColor(Color.parseColor("#FF343434"));//Color.argb((int)255, (int)63, (int)63, (int)63));
        gradientDrawable.setStroke(2, Color.argb((int)255, (int)0, (int)0, (int)0));
        button.setBackground((Drawable)gradientDrawable);
        linearLayout.addView((View)button);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
        }
    }
    void AddCheckbox2(Object object,String name,final int num) {
        CheckBox checkBox = new CheckBox(this);
        checkBox.setText(name);
        checkBox.setTextColor(-1);
        checkBox.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-2, -2));
        if (Build.VERSION.SDK_INT >= 21) {
            checkBox.setButtonTintList(new ColorStateList((int[][])new int[][]{{-16842912}, {16842912}}, new int[]{-1, -1}));
        }
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)checkBox);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)checkBox);
        }
        checkBox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked){
                    SettingValue(num,isChecked);
                } }); }
    void AddCheckbox(Object object, String string, CompoundButton.OnCheckedChangeListener onCheckedChangeListener) {
        CheckBox checkBox = new CheckBox((Context)this);
        checkBox.setText((CharSequence)string);
        checkBox.setTextColor(-1);
        checkBox.setOnCheckedChangeListener(onCheckedChangeListener);
        checkBox.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-2, -2));
        if (Build.VERSION.SDK_INT >= 21) {
            checkBox.setButtonTintList(new ColorStateList((int[][])new int[][]{{-16842912}, {16842912}}, new int[]{-1, -1}));
        }
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)checkBox);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)checkBox);
        }
    }

    @SuppressLint({"WrongConstant", "ResourceType"})
    void AddDropdown(Object object, String[] arrstring, AdapterView.OnItemSelectedListener onItemSelectedListener) {
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setOrientation(1);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -2));
        linearLayout.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f));
        linearLayout.setGravity(17);
        Spinner spinner = new Spinner((Context)this, 1);
        GradientDrawable gradientDrawable = new GradientDrawable();
        gradientDrawable.setColor(Color.argb((int)255, (int)32, (int)32, (int)32));
        gradientDrawable.setStroke(2, Color.argb((int)255, (int)0, (int)0, (int)0));
        spinner.setPopupBackgroundDrawable((Drawable)gradientDrawable);
        spinner.setBackground((Drawable)gradientDrawable);
        spinner.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-1, -2));
        @SuppressLint("ResourceType") ArrayAdapter arrayAdapter = new ArrayAdapter((Context)this, 17367048, (Object[])arrstring);
        arrayAdapter.setDropDownViewResource(17367049);
        spinner.setAdapter((SpinnerAdapter)arrayAdapter);
        spinner.setOnItemSelectedListener(onItemSelectedListener);
        spinner.setPadding(0, this.convertSizeToDp(5.0f), 0, this.convertSizeToDp(5.0f));
        linearLayout.addView((View)spinner);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
        }
    }

    @SuppressLint("WrongConstant")
    void AddFloatSeekbar(Object object, String string, final int n, int n2, int n3, final String string2, final String string3, final SeekBar.OnSeekBarChangeListener onSeekBarChangeListener) {
        int n4 = n3;
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -2));
        linearLayout.setOrientation(0);
        TextView textView = new TextView((Context)this);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(string);
        stringBuilder.append(":");
        textView.setText((CharSequence)stringBuilder.toString());
        textView.setTextSize(1, 12.5f);
        textView.setPadding(this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f));
        textView.setTextColor(-1);
        textView.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-2, -2));
        textView.setGravity(3);
        SeekBar seekBar = new SeekBar((Context)this);
        seekBar.setMax(n2);
        if (Build.VERSION.SDK_INT >= 26) {
            seekBar.setMin(n);
            seekBar.setProgress(n);
        }
        if (Build.VERSION.SDK_INT >= 21) {
            seekBar.setThumbTintList(ColorStateList.valueOf((int)-1));
            seekBar.setProgressTintList(ColorStateList.valueOf((int)-1));
        }
        seekBar.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        final TextView textView2 = new TextView((Context)this);
        StringBuilder stringBuilder2 = new StringBuilder();
        stringBuilder2.append(string2);
        stringBuilder2.append(String.valueOf((float)((float)n / 10.0f)));
        stringBuilder2.append(string3);
        textView2.setText((CharSequence)stringBuilder2.toString());
        textView2.setGravity(5);
        textView2.setTextSize(1, 12.5f);
        textView2.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-1, -2));
        textView2.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        textView2.setTextColor(-1);
        if (n4 != 0) {
            if (n4 < n) {
                n4 = n;
            }
            if (n4 > n2) {
                n4 = n2;
            }
            StringBuilder stringBuilder3 = new StringBuilder();
            stringBuilder3.append(string2);
            stringBuilder3.append((float)n4 / (float)n2);
            stringBuilder3.append(string3);
            textView2.setText((CharSequence)stringBuilder3.toString());
            seekBar.setProgress(n4);
        }
        SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = new SeekBar.OnSeekBarChangeListener(){

            public void onProgressChanged(SeekBar seekBar, int n2, boolean bl) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2;
                if (n2 < n) {
                    n2 = n;
                    seekBar.setProgress(n2);
                }
                if ((onSeekBarChangeListener2 = onSeekBarChangeListener) != null) {
                    onSeekBarChangeListener2.onProgressChanged(seekBar, n2, bl);
                }
                TextView textView = textView2;
                StringBuilder stringBuilder = new StringBuilder();
                stringBuilder.append(string2);
                stringBuilder.append(String.valueOf((float)((float)n2 / 10.0f)));
                stringBuilder.append(string3);
                textView.setText((CharSequence)stringBuilder.toString());
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStartTrackingTouch(seekBar);
                }
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStopTrackingTouch(seekBar);
                }
            }
        };
        seekBar.setOnSeekBarChangeListener(onSeekBarChangeListener2);
        linearLayout.addView((View)textView);
        linearLayout.addView((View)textView2);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            ((ViewGroup)object).addView((View)seekBar);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
            this.layoutParents[(Integer)object].addView((View)seekBar);
        }
    }

    @SuppressLint("WrongConstant")
    void AddRadioButton(Object object, String[] arrstring, int n, RadioGroup.OnCheckedChangeListener onCheckedChangeListener) {
        RadioGroup radioGroup = new RadioGroup((Context)this);
        RadioButton[] arrradioButton = new RadioButton[arrstring.length];
        radioGroup.setOrientation(1);
        for (int i = 0; i < arrstring.length; ++i) {
            arrradioButton[i] = new RadioButton((Context)this);
            if (i == n) {
                arrradioButton[i].setChecked(true);
            }
            arrradioButton[i].setPadding(this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f));
            arrradioButton[i].setText((CharSequence)arrstring[i]);
            arrradioButton[i].setTextSize(1, 12.5f);
            arrradioButton[i].setId(i);
            arrradioButton[i].setGravity(5);
            arrradioButton[i].setTextColor(-1);
            radioGroup.addView((View)arrradioButton[i]);
        }
        radioGroup.setOnCheckedChangeListener(onCheckedChangeListener);
        radioGroup.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-1, -2));
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)radioGroup);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)radioGroup);
        }
    }

    @SuppressLint("WrongConstant")
    void AddSeekbar(Object object, String string, final int n, int n2, int n3, final String string2, final String string3, final SeekBar.OnSeekBarChangeListener onSeekBarChangeListener) {
        int n4 = n3;
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -2));
        linearLayout.setOrientation(0);
        TextView textView = new TextView((Context)this);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(string);
        stringBuilder.append(":");
        textView.setText((CharSequence)stringBuilder.toString());
        textView.setTextSize(1, 12.5f);
        textView.setPadding(this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f));
        textView.setTextColor(-1);
        textView.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-2, -2));
        textView.setGravity(3);
        SeekBar seekBar = new SeekBar((Context)this);
        seekBar.setMax(n2);
        if (Build.VERSION.SDK_INT >= 26) {
            seekBar.setMin(n);
            seekBar.setProgress(n);
        }
        if (Build.VERSION.SDK_INT >= 21) {
            seekBar.setThumbTintList(ColorStateList.valueOf((int)-1));
            seekBar.setProgressTintList(ColorStateList.valueOf((int)-1));
        }
        seekBar.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        final TextView textView2 = new TextView((Context)this);
        StringBuilder stringBuilder2 = new StringBuilder();
        stringBuilder2.append(string2);
        stringBuilder2.append(n);
        stringBuilder2.append(string3);
        textView2.setText((CharSequence)stringBuilder2.toString());
        textView2.setGravity(5);
        textView2.setTextSize(1, 12.5f);
        textView2.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-1, -2));
        textView2.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        textView2.setTextColor(-1);
        if (n4 != 0) {
            if (n4 < n) {
                n4 = n;
            }
            if (n4 > n2) {
                n4 = n2;
            }
            StringBuilder stringBuilder3 = new StringBuilder();
            stringBuilder3.append(string2);
            stringBuilder3.append(n4);
            stringBuilder3.append(string3);
            textView2.setText((CharSequence)stringBuilder3.toString());
            seekBar.setProgress(n4);
        }
        SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = new SeekBar.OnSeekBarChangeListener(){

            public void onProgressChanged(SeekBar seekBar, int n2, boolean bl) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2;
                if (n2 < n) {
                    n2 = n;
                    seekBar.setProgress(n2);
                }
                if ((onSeekBarChangeListener2 = onSeekBarChangeListener) != null) {
                    onSeekBarChangeListener2.onProgressChanged(seekBar, n2, bl);
                }
                TextView textView = textView2;
                StringBuilder stringBuilder = new StringBuilder();
                stringBuilder.append(string2);
                stringBuilder.append(n2);
                stringBuilder.append(string3);
                textView.setText((CharSequence)stringBuilder.toString());
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStartTrackingTouch(seekBar);
                }
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStopTrackingTouch(seekBar);
                }
            }
        };
        seekBar.setOnSeekBarChangeListener(onSeekBarChangeListener2);
        linearLayout.addView((View)textView);
        linearLayout.addView((View)textView2);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            ((ViewGroup)object).addView((View)seekBar);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
            this.layoutParents[(Integer)object].addView((View)seekBar);
        }
    }

    @SuppressLint("WrongConstant")
    void AddSelectList(Object object, String string, final String[] arrstring, final OnListChoosedListener onListChoosedListener) {
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setOrientation(1);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -2));
        linearLayout.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(15.0f));
        linearLayout.setGravity(17);
        final Button button = new Button((Context)this);
        button.setText((CharSequence)string);
        button.setTextColor(-1);
        AlertDialog.Builder builder = new AlertDialog.Builder((Context)this, 3);
        builder.setTitle((CharSequence)string);
        builder.setCancelable(true);
        builder.setItems((CharSequence[])arrstring, new DialogInterface.OnClickListener(){

                public void onClick(DialogInterface dialogInterface, int n) {
                    OnListChoosedListener onListChoosedListener2 = onListChoosedListener;
                    if (onListChoosedListener2 != null) {
                        onListChoosedListener2.onChoosed(n);
                    }
                    button.setText((CharSequence)arrstring[n]);
                }
            });
        final AlertDialog alertDialog = builder.create();
        if (Build.VERSION.SDK_INT >= 26) {
            alertDialog.getWindow().setType(2038);
        } else {
            alertDialog.getWindow().setType(2002);
        }
        button.setOnClickListener(new View.OnClickListener(){

                public void onClick(View view) {
                    alertDialog.show();
                }
            });
        button.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -1));
        GradientDrawable gradientDrawable = new GradientDrawable();
        gradientDrawable.setColor(Color.argb((int)255, (int)32, (int)32, (int)32));
        gradientDrawable.setStroke(2, Color.argb((int)255, (int)0, (int)0, (int)0));
        button.setBackground((Drawable)gradientDrawable);
        linearLayout.addView((View)button);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
        }
    }

    void AddText(Object object, String string, int n, int n2, String string2) {
        TextView textView = new TextView((Context)this);
        textView.setText((CharSequence)string);
        textView.setTextColor(Color.parseColor((String)string2));
        textView.setTypeface(null, n2);
        textView.setPadding(this.convertSizeToDp(5.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(5.0f));
        textView.setTextSize(1, (float)n);
        textView.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-2, -2));
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)textView);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)textView);
        }
    }

    void AddTextNormal(Object object, String string, int n, int n2, String string2) {
        TextView textView = new TextView((Context)this);
        textView.setText((CharSequence)string);
        textView.setTextColor(Color.parseColor((String)string2));
        textView.setTypeface(Typeface.DEFAULT);
        textView.setPadding(this.convertSizeToDp(5.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(5.0f));
        textView.setTextSize(1, (float)n);
        textView.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-2, -2));
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)textView);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)textView);
        }
    }
    @SuppressLint("WrongConstant")
    LinearLayout CreateHorizontalHolder(Object object) {
        RelativeLayout relativeLayout = new RelativeLayout((Context)this);
        relativeLayout.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-1, -2));
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -2));
        linearLayout.setOrientation(0);
        relativeLayout.addView((View)linearLayout);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)relativeLayout);
            return linearLayout;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)relativeLayout);
        }
        return linearLayout;
    }

    int convertSizeToDp(float f) {
        return Math.round((float)TypedValue.applyDimension((int)1, (float)f, (DisplayMetrics)this.getResources().getDisplayMetrics()));
    }

    public IBinder onBind(Intent intent) {
        return null;
    }

    @SuppressLint("WrongConstant")
    void AddSeekbarng(Object object, String string, final int n, int n2, int n3, final String string2, final String string3, final SeekBar.OnSeekBarChangeListener onSeekBarChangeListener) {
        int n4 = n3;
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -2));
        linearLayout.setOrientation(0);
        TextView textView = new TextView((Context)this);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(string);
        stringBuilder.append(":");
        textView.setText((CharSequence)stringBuilder.toString());
        textView.setTextSize(1, 12.5f);
        textView.setPadding(this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f));
        textView.setTextColor(-1);
        textView.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-2, -2));
        textView.setGravity(3);
        SeekBar seekBar = new SeekBar((Context)this);
        seekBar.setMax(n2);
        if (Build.VERSION.SDK_INT >= 26) {
            seekBar.setMin(n);
            seekBar.setProgress(n);
        }
        if (Build.VERSION.SDK_INT >= 21) {
            seekBar.setThumbTintList(ColorStateList.valueOf((int)-1));
            seekBar.setProgressTintList(ColorStateList.valueOf((int)-1));
        }
        seekBar.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        final TextView textView2 = new TextView((Context)this);
        StringBuilder stringBuilder2 = new StringBuilder();
        stringBuilder2.append(string2);
        stringBuilder2.append(n);
        stringBuilder2.append(string3);
        textView2.setText((CharSequence)stringBuilder2.toString());
        textView2.setGravity(5);
        textView2.setTextSize(1, 12.5f);
        textView2.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-1, -2));
        textView2.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        textView2.setTextColor(-1);
        if (n4 != 0) {
            if (n4 < n) {
                n4 = n;
            }
            if (n4 > n2) {
                n4 = n2;
            }
            StringBuilder stringBuilder3 = new StringBuilder();
            stringBuilder3.append(string2);
            stringBuilder3.append(n4);
            stringBuilder3.append(string3);
            textView2.setText((CharSequence)stringBuilder3.toString());
            seekBar.setProgress(n4);
        }
        SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = new SeekBar.OnSeekBarChangeListener(){

            public void onProgressChanged(SeekBar seekBar, int n2, boolean bl) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2;
                if (n2 < n) {
                    n2 = n;
                    seekBar.setProgress(n2);
                }
                if ((onSeekBarChangeListener2 = onSeekBarChangeListener) != null) {
                    onSeekBarChangeListener2.onProgressChanged(seekBar, n2, bl);
                }
                TextView textView = textView2;
                StringBuilder stringBuilder = new StringBuilder();
                stringBuilder.append(string2);
                stringBuilder.append(n2);
                stringBuilder.append(string3);
                textView.setText(stringBuilder.toString());
                Range(seekBar.getProgress());
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStartTrackingTouch(seekBar);
                }
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStopTrackingTouch(seekBar);
                }
            }
        };
        seekBar.setOnSeekBarChangeListener(onSeekBarChangeListener2);
        linearLayout.addView((View)textView);
        linearLayout.addView((View)textView2);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            ((ViewGroup)object).addView((View)seekBar);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
            this.layoutParents[(Integer)object].addView((View)seekBar);
        }
    }
    @SuppressLint("WrongConstant")
    void AddSeekbarng2(Object object, String string, final int n, int n2, int n3, final String string2, final String string3, final SeekBar.OnSeekBarChangeListener onSeekBarChangeListener) {
        int n4 = n3;
        LinearLayout linearLayout = new LinearLayout((Context)this);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -2));
        linearLayout.setOrientation(0);
        TextView textView = new TextView((Context)this);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(string);
        stringBuilder.append(":");
        textView.setText((CharSequence)stringBuilder.toString());
        textView.setTextSize(1, 12.5f);
        textView.setPadding(this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(10.0f), this.convertSizeToDp(5.0f));
        textView.setTextColor(-1);
        textView.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-2, -2));
        textView.setGravity(3);
        SeekBar seekBar = new SeekBar((Context)this);
        seekBar.setMax(n2);
        if (Build.VERSION.SDK_INT >= 26) {
            seekBar.setMin(n);
            seekBar.setProgress(n);
        }
        if (Build.VERSION.SDK_INT >= 21) {
            seekBar.setThumbTintList(ColorStateList.valueOf((int)-1));
            seekBar.setProgressTintList(ColorStateList.valueOf((int)-1));
        }
        seekBar.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        final TextView textView2 = new TextView((Context)this);
        StringBuilder stringBuilder2 = new StringBuilder();
        stringBuilder2.append(string2);
        stringBuilder2.append(n);
        stringBuilder2.append(string3);
        textView2.setText((CharSequence)stringBuilder2.toString());
        textView2.setGravity(5);
        textView2.setTextSize(1, 12.5f);
        textView2.setLayoutParams((ViewGroup.LayoutParams)new RelativeLayout.LayoutParams(-1, -2));
        textView2.setPadding(this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f), this.convertSizeToDp(15.0f), this.convertSizeToDp(5.0f));
        textView2.setTextColor(-1);
        if (n4 != 0) {
            if (n4 < n) {
                n4 = n;
            }
            if (n4 > n2) {
                n4 = n2;
            }
            StringBuilder stringBuilder3 = new StringBuilder();
            stringBuilder3.append(string2);
            stringBuilder3.append(n4);
            stringBuilder3.append(string3);
            textView2.setText((CharSequence)stringBuilder3.toString());
            seekBar.setProgress(n4);
        }
        SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = new SeekBar.OnSeekBarChangeListener(){

            public void onProgressChanged(SeekBar seekBar, int n2, boolean bl) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2;
                if (n2 < n) {
                    n2 = n;
                    seekBar.setProgress(n2);
                }
                if ((onSeekBarChangeListener2 = onSeekBarChangeListener) != null) {
                    onSeekBarChangeListener2.onProgressChanged(seekBar, n2, bl);
                }
                TextView textView = textView2;
                StringBuilder stringBuilder = new StringBuilder();
                stringBuilder.append(string2);
                stringBuilder.append(n2);
                stringBuilder.append(string3);
                textView.setText(stringBuilder.toString());
                Range(seekBar.getProgress());
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStartTrackingTouch(seekBar);
                }
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = onSeekBarChangeListener;
                if (onSeekBarChangeListener2 != null) {
                    onSeekBarChangeListener2.onStopTrackingTouch(seekBar);
                }
            }
        };
        seekBar.setOnSeekBarChangeListener(onSeekBarChangeListener2);
        linearLayout.addView((View)textView);
        linearLayout.addView((View)textView2);
        if (object instanceof ViewGroup) {
            ((ViewGroup)object).addView((View)linearLayout);
            ((ViewGroup)object).addView((View)seekBar);
            return;
        }
        if (object instanceof Integer) {
            this.layoutParents[(Integer)object].addView((View)linearLayout);
            this.layoutParents[(Integer)object].addView((View)seekBar);
        }
    }
    static boolean getConfig(String key){
        SharedPreferences sp=ctx.getSharedPreferences("espValue",Context.MODE_PRIVATE);
        return  sp.getBoolean(key,false);
    }
    

    
    
    @SuppressLint("WrongConstant")
    public void onCreate() {
        System.loadLibrary("native");
        FileUtil.writeFile("/storage/emulated/0/Android/ModMenupatcherLogs.txt", "PUBG MOBILE MOD By @jeelpatel188 && desiesp source internal by king cheat");
        ctx=this;
        final LinearLayout linearLayout;
        windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);
        final Point point = new Point();
        windowManager.getDefaultDisplay().getRealSize(point);
        screenWidth = point.x;
        screenHeight = point.y;
        dpi = Resources.getSystem().getDisplayMetrics().densityDpi;
        density = Resources.getSystem().getDisplayMetrics().density;
        final int n = convertSizeToDp(530.0f);
        final int n2 = convertSizeToDp(300.0f);
        g_mainLayout = linearLayout = new LinearLayout((Context)this);
        linearLayout.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams(-1, -1));
        linearLayout.setBackgroundColor(Color.parseColor("#000000"));//Color.argb(255,35,44,44));
        Integer n3 = 1;
        linearLayout.setOrientation(1);
        int n4 = convertSizeToDp(30.0f);
        FrameLayout frameLayout = new FrameLayout(this);
        frameLayout.setClickable(true);
        frameLayout.setFocusable(true);
        frameLayout.setFocusableInTouchMode(true);
        frameLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, n4));
        frameLayout.setBackgroundColor(Color.parseColor("#FF343434"));//Color.argb(255,35,128,128));//Title
        linearLayout.addView(frameLayout);
        TextView textView = new TextView(this);
        textView.setText("𝗣𝗨𝗕𝗚 𝗠𝗢𝗕𝗜𝗟𝗘 𝗘𝗦𝗣");
        textView.setGravity(19);
        textView.setTextColor(-1);
        textView.setTypeface(null, 1);
        textView.setPadding(convertSizeToDp(5.0f),convertSizeToDp(5.0f),convertSizeToDp(5.0f),convertSizeToDp(5.0f));
        textView.setTextSize(1, 15.0f);
        frameLayout.addView(textView);
        final Button button = new Button(this);
        button.setText((CharSequence)"");
        button.setTextColor(-1);
        button.setTextSize(1, 8.0f);
        button.setBackgroundColor(Color.TRANSPARENT);//Color.argb(255, 35,144,144));//BTN CLOSE
        button.setX(n - dpi / 5.5f);
        button.setLayoutParams(new RelativeLayout.LayoutParams((int)((dpi / 5.5f)), n4));
        frameLayout.addView(button);
        ImageView ColseImg = new ImageView(this);
        byte[] arrby2 = Base64.decode(IconClose(), 0);
        ColseImg.setImageBitmap(BitmapFactory.decodeByteArray((byte[])arrby2, (int)0, (int)arrby2.length));
        ColseImg.setBackgroundColor(Color.parseColor("#FF222222"));//Color.argb(255, 35,144,144));//BTN CLOSE
        ColseImg.setX(n - dpi / 5.5f);
        ColseImg.setLayoutParams(new RelativeLayout.LayoutParams((int)((dpi / 5.5f)), n4));
        frameLayout.addView(ColseImg);
        LinearLayout linearLayout2 = new LinearLayout(this);
        linearLayout2.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        Integer n5 = 0;
        linearLayout2.setOrientation(0);
        linearLayout.addView(linearLayout2);
        final LinearLayout linearLayout3 = new LinearLayout(this);
        linearLayout3.setLayoutParams(new LinearLayout.LayoutParams((int)(n / 3.0f), -1));
        linearLayout3.setBackgroundColor(Color.parseColor("#000000"));//Color.argb(255,35,88,88));
        linearLayout3.setOrientation(0);
        linearLayout2.addView(linearLayout3);
        ScrollView scrollView = new ScrollView(this);
        scrollView.setLayoutParams(new RelativeLayout.LayoutParams(-1, -2));
        linearLayout3.addView(scrollView);
        LinearLayout linearLayout4 = new LinearLayout(this);
        linearLayout4.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        linearLayout4.setOrientation(1);
        scrollView.addView(linearLayout4);
        LinearLayout linearLayout5 = new LinearLayout(this);
        linearLayout5.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        linearLayout5.setBackgroundColor(Color.parseColor("#000000"));//Color.argb(255,35,111,111));
        linearLayout5.setOrientation(1);
        linearLayout2.addView(linearLayout5);
        int n6 = 0;
        do {
            int n7 = TABS.length;
            TextView textView2 = textView;
            if (n6 >= n7) break;
            scrollLayouts[n6] = new ScrollView(this);
            ScrollView scrollView2 = scrollLayouts[n6];
            LinearLayout linearLayout6 = linearLayout2;
            scrollView2.setLayoutParams(new RelativeLayout.LayoutParams(-1, -2));
            layoutParents[n6] = new LinearLayout(this);
            layoutParents[n6].setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
            layoutParents[n6].setBackgroundColor(Color.parseColor("#000000"));//Color.argb(255,35,111,111));// BG MENU FITURE
            layoutParents[n6].setOrientation(1);
            scrollLayouts[n6].addView(layoutParents[n6]);
            contentLayouts[n6] = new LinearLayout(this);
            contentLayouts[n6].setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
            contentLayouts[n6].setBackgroundColor(Color.parseColor("#000000"));//Color.argb(255,35,111,111)); //BG MENU ALL
            contentLayouts[n6].setOrientation(1);
            if (n6 != 0) {
                contentLayouts[n6].setVisibility(8);
            }
            contentLayouts[n6].addView(scrollLayouts[n6]);
            linearLayout5.addView(contentLayouts[n6]);
            tabLayouts[n6] = new FrameLayout(this);
            tabLayouts[n6].setLayoutParams(new LinearLayout.LayoutParams(-1, this.convertSizeToDp(60.0f)));
            TextView textView3 = new TextView(this);
            textView3.setText(TABS[n6]);
            textView3.setGravity(17);
            textView3.setTextColor(-1);
            textView3.setTypeface(null, 1);
            int n8 = convertSizeToDp(5.0f);
            int n9 = convertSizeToDp(5.0f);
            LinearLayout linearLayout7 = linearLayout5;
            int n10 = convertSizeToDp(5.0f);
            int n11 = n4;
            textView3.setPadding(n8, n9, n10, convertSizeToDp(5.0f));
            textView3.setTextSize(1, 15.0f);
            tabLayouts[n6].addView((View)textView3);
            GradientDrawable gradientDrawable = new GradientDrawable();
            gradientDrawable.setColor(Color.parseColor("#000000"));//Color.argb(255,35,99,99));//
            if (n6 == 0) {
                gradientDrawable.setStroke(6, Color.argb(255,255,255,255));
            } else {
                gradientDrawable.setStroke(2, Color.parseColor("#000000"));//
            }
            this.tabLayouts[n6].setBackground((Drawable)gradientDrawable);
            linearLayout4.addView((View)this.tabLayouts[n6]);
            final int n12 = n6;
            this.tabLayouts[n6].setOnClickListener(new View.OnClickListener(){

                    public void onClick(View view) {
                        contentLayouts[selectedTab].setVisibility(8);
                        GradientDrawable gradientDrawable = new GradientDrawable();
                        gradientDrawable.setColor(Color.parseColor("#000000"));//Color.argb(255,35,99,99));
                        gradientDrawable.setStroke(2, Color.parseColor("#000000"));//Color.argb(255,255,255,255));
                        tabLayouts[selectedTab].setBackground(gradientDrawable);
                        GradientDrawable gradientDrawable2 = new GradientDrawable();
                        gradientDrawable2.setColor(Color.parseColor("#000000"));//Color.argb(255,35,99,99));
                        gradientDrawable2.setStroke(6, Color.argb(255,255,255,255));
                        tabLayouts[n12].setBackground(gradientDrawable2);
                        contentLayouts[n12].setVisibility(0);
                        selectedTab = n12;
                    }
                });
            ++n6;
            linearLayout5 = linearLayout7;
            linearLayout2 = linearLayout6;
            textView = textView2;
            n4 = n11;
        } while (true);
        this.type = Build.VERSION.SDK_INT >= 26 ? 2038 : 2002;
        
        final WindowManager.LayoutParams layoutParams = new WindowManager.LayoutParams(n, n2, this.type, 520, -3);
        layoutParams.x = 280;//150
        layoutParams.y = 100;//150
        layoutParams.gravity = 51;
        frameLayout.setOnTouchListener(new View.OnTouchListener(){
                float deltaX;
                float deltaY;
                float maxX;
                float maxY;
                float newX;
                float newY;
                float pressedX;
                float pressedY;
                public boolean onTouch(View view, MotionEvent motionEvent) {
                    float f,f2,f3,f4;
                    int n = motionEvent.getActionMasked();
                    if (n == 0) {
                        this.deltaX = (float)layoutParams.x - motionEvent.getRawX();
                        this.deltaY = (float)layoutParams.y - motionEvent.getRawY();
                        this.pressedX = motionEvent.getRawX();
                        this.pressedY = motionEvent.getRawY();
                        return false;
                    }
                    if (n != 1) {
                        float f5;
                        float f6;
                        if (n != 2) {
                            return false;
                        }
                        this.newX = motionEvent.getRawX() + deltaX;
                        this.newY = motionEvent.getRawY() + deltaY;
                        this.maxX = point.x - linearLayout.getWidth();
                        this.maxY = f6 = (point.y - linearLayout.getHeight());
                        float f7 = newX;
                        if (!(f7 < 0.0f || f7 > maxX || (f5 = newY) < 0.0f || f5 > f6)) {
                            linearLayout.setAlpha(1.0f);
                        } else {
                            linearLayout.setAlpha(0.5f);
                        }
                        layoutParams.x = (int)newX;
                        layoutParams.y = (int)newY;
                        windowManager.updateViewLayout(linearLayout,layoutParams);
                        return false;
                    }
                    maxX = point.x - linearLayout.getWidth();
                    maxY = point.y - linearLayout.getHeight();
                    if (newX < 0.0f) {
                        newX = 0.0f;
                    }
                    if ((f = newX) > (f4 = maxX)) {
                        newX = f4;
                    }
                    if (newY < 0.0f) {
                        newY = 0.0f;
                    }
                    if ((f3 = newY) > (f2 = maxY)) {
                        newY = (int)f2;
                    }
                    layoutParams.x = (int)newX;
                    layoutParams.y = (int)newY;
                    windowManager.updateViewLayout(linearLayout,layoutParams);
                    linearLayout.setAlpha(1.0f);
                    return true;
                }
            });
        this.g_iconLayout = relativeLayout = new RelativeLayout(this);
        relativeLayout.setLayoutParams(new RelativeLayout.LayoutParams(-2, -2));
        ImageView imageView = new ImageView(this);
        imageView.setLayoutParams(new ViewGroup.LayoutParams(convertSizeToDp(50.0f), convertSizeToDp(50.0f)));
        relativeLayout.addView((View)imageView);
        byte[] arrby = Base64.decode(Icon(),0); 
        imageView.setImageBitmap(BitmapFactory.decodeByteArray(arrby,0,arrby.length));
        final WindowManager.LayoutParams layoutParams2 = new WindowManager.LayoutParams(-2, -2,type, 8, -3);
        layoutParams2.gravity = 51;
        layoutParams2.x = 0;
        layoutParams2.y = 0;
        relativeLayout.setVisibility(8);
        windowManager.addView(relativeLayout,layoutParams2);
        windowManager.addView(linearLayout,layoutParams);
        relativeLayout.setOnTouchListener(new View.OnTouchListener(){
                float deltaX;
                float deltaY;
                float newX;
                float newY;
                float pressedX;
                float pressedY;

                @SuppressLint("WrongConstant")
                public boolean onTouch(View view, MotionEvent motionEvent) {
                    int n = motionEvent.getActionMasked();
                    if (n != 0) {
                        if (n != 1) {
                            if (n != 2) {
                                return false;
                            }
                            newX = motionEvent.getRawX() + deltaX;
                            newY = motionEvent.getRawY() + deltaY;
                            float f = screenWidth - view.getWidth();
                            float f2 = screenHeight - view.getHeight();
                            if (newX < 0.0f) {
                                newX = 0.0f;
                            }
                            if (newX > f) {
                                newX = f;
                            }
                            if (newY < 0.0f) {
                                newY = 0.0f;
                            }
                            if (newY > f2) {
                                newY = f2;
                            }
                            layoutParams2.x = (int)newX;
                            layoutParams2.y = (int)newY;
                            windowManager.updateViewLayout(relativeLayout,layoutParams2);
                            return false;
                        }
                        int n2 = (int)(motionEvent.getRawX() - pressedX);
                        int n3 = (int)(motionEvent.getRawY() - pressedY);
                        if (n2 == 0 && n3 == 0) {
                            linearLayout.setVisibility(0);
                            relativeLayout.setVisibility(8);
                        }
                        return true;
                    }
                    this.deltaX = layoutParams2.x - motionEvent.getRawX();
                    this.deltaY = layoutParams2.y - motionEvent.getRawY();
                    this.pressedX = motionEvent.getRawX();
                    this.pressedY = motionEvent.getRawY();
                    return false;
                }
            });
        ColseImg.setOnClickListener(new View.OnClickListener(){
                public void onClick(View view) {
                    linearLayout.setVisibility(8);
                    relativeLayout.setVisibility(0);
                }
            });
        button.setOnClickListener(new View.OnClickListener(){
                public void onClick(View view) {
                    linearLayout.setVisibility(8);
                    relativeLayout.setVisibility(0);
                }
            });
        DrawCanvas();
		AddText(0, "If Aimbot Auto On Click Aimbot On And Click Off Aimbot", 14, 1, "#FFFFFFFF");
		
        AddButton(0, "SHOW ONLY PLAYERS+VEHICLE", -1, -2, new View.OnClickListener(){
                public void onClick(View view) {

                }
            });
	    AddCheckbox(0, "Bypass Logo", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Hack(5,isChecked);
                }
            });
        AddToggle("Activate", 0);
        AddToggle("Show Box", 1);
        AddToggle("Show Line", 2);
        AddToggle("Show Distance", 3);
        AddToggle("Show Health", 4);
        AddToggle("Show Player Name", 5);
        AddToggle("Show Player Head", 6);
        AddToggle("Show Skeleton", 8);
        AddToggle("Show 360 Alert", 7);
        AddToggle("Show Grande Warning",9);
        AddToggle("Show Enemies Waepons",10);
        AddText(0, "", 10, 1, "#FFFFFFFF");
        AddText(1, "SPECIAL ITEM'S", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"Flare Gun",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Flare Gun",isChecked);
                }});
        AddCheckbox(1,"DropPlane",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("DropPlane",isChecked);
                }});
        AddCheckbox(1,"CheekPad",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("CheekPad",isChecked);
                }});
        AddCheckbox(1,"Ghillie Suit",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ghillie Suit",isChecked);
                }});
        AddCheckbox(1,"Crate",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Crate",isChecked);
                }});
        AddCheckbox(1,"AirDrop",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("AirDrop",isChecked);
                }});
        AddText(1, "Waepon's", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"M16A4",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("M16A4",isChecked);
                }});
        AddCheckbox(1,"Mk14",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Mk14",isChecked);
                }});
        AddCheckbox(1,"DP28",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("DP28",isChecked);
                }});
        AddCheckbox(1,"G36C",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("G36C",isChecked);
                }});
        AddCheckbox(1,"Mk47 Mutant",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Mk47 Mutant",isChecked);
                }});
        AddCheckbox(1,"Groza",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Groza",isChecked);
                }});
        AddCheckbox(1,"M762",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("M762",isChecked);
                }});
        AddCheckbox(1,"AKM",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("AKM",isChecked);
                }});
        AddCheckbox(1,"M249",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("M249",isChecked);
                }});
        AddCheckbox(1,"AUG",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("AUG",isChecked);
                }});
        AddCheckbox(1,"QBZ",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("QBZ",isChecked);
                }});
        AddCheckbox(1,"M416",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("M416",isChecked);
                }});
        AddCheckbox(1,"SCAR",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("SCAR",isChecked);
                }});
        AddCheckbox(1,"CrossBow",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("CrossBow",isChecked);
                }});
        AddText(1, "SMG", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"PP19",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("PP19",isChecked);
                }});
        AddCheckbox(1,"UMP45",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("UMP45",isChecked);
                }});
        AddCheckbox(1,"TommyGun",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("TommyGun",isChecked);
                }});
        AddCheckbox(1,"Vector",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Vector",isChecked);
                }});
        AddCheckbox(1,"MP5K",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("MP5K",isChecked);
                }});
        AddCheckbox(1,"Bizon",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bizon",isChecked);
                }});
        AddCheckbox(1,"Uzi",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Uzi",isChecked);
                }});
        AddCheckbox(1,"Skorpion",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Skorpion",isChecked);
                }});
        AddText(1, "SNIPER", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"AWM",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("AWM",isChecked);
                }});
        AddCheckbox(1,"Kar98k",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Kar98k",isChecked);
                }});
        AddCheckbox(1,"SKS",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("SKS",isChecked);
                }});
        AddCheckbox(1,"SLR",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("SLR",isChecked);
                }});
        AddCheckbox(1,"QBU",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("QBU",isChecked);
                }});
        AddCheckbox(1,"Mini14",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Mini14",isChecked);
                }});
        AddCheckbox(1,"VSS",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("VSS",isChecked);
                }});
        AddCheckbox(1,"Win94",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Win94",isChecked);
                }});
        AddCheckbox(1,"M24",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("M24",isChecked);
                }});
        AddText(1, "Shotgun", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"SawedOff",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("SawedOff",isChecked);
                }});
        AddCheckbox(1,"DBS",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("DBS",isChecked);
                }});
        AddCheckbox(1,"S686",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("S686",isChecked);
                }});
        AddCheckbox(1,"S12K",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("S12K",isChecked);
                }});
        AddCheckbox(1,"S1897",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("S1897",isChecked);
                }});
        AddCheckbox(1,"DP12",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("DP12",isChecked);
                }});
        AddText(1, "PISTOLS", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"P18C",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("P18C",isChecked);
                }});
        AddCheckbox(1,"Desert Eagle",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Desert Eagle",isChecked);
                }});
        AddCheckbox(1,"R45",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("R45",isChecked);
                }});
        AddCheckbox(1,"P1911",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("P1911",isChecked);
                }});
        AddCheckbox(1,"Pistol",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Pistol",isChecked);
                }});
        AddText(1, "AMMO", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"7.62",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("7.62",isChecked);
                }});
        AddCheckbox(1,"45ACP",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("45ACP",isChecked);
                }});
        AddCheckbox(1,"5.56",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("5.56",isChecked);
                }});
        AddCheckbox(1,"9mm",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("9mm",isChecked);
                }});
        AddCheckbox(1,"300Magnum",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("300Magnum",isChecked);
                }});
        AddCheckbox(1,"12 Guage",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("12 Guage",isChecked);
                }});
        AddCheckbox(1,"Arrow",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Arrow",isChecked);
                }});
        AddText(1, "SCOPE", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"2x",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("2x",isChecked);
                }});
        AddCheckbox(1,"3x",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("3x",isChecked);
                }});
        AddCheckbox(1,"4x",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("4x",isChecked);
                }});
        AddCheckbox(1,"6x",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("6x",isChecked);
                }});
        AddCheckbox(1,"8x",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("8x",isChecked);
                }});
        AddCheckbox(1,"Red Dot",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Red Dot",isChecked);
                }});
        AddCheckbox(1,"Hollow",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Hollow",isChecked);
                }});
        AddCheckbox(1,"Canted",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Canted",isChecked);
                }});
        AddText(1, "ARMOUR", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"Vest L 1",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Vest L 1",isChecked);
                }});
        AddCheckbox(1,"Vest L 2",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Vest L 2",isChecked);
                }});
        AddCheckbox(1,"Vest L 3",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Vest L 3",isChecked);
                }});
        AddCheckbox(1,"Helmet L 1",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Helmet L 1",isChecked);
                }});
        AddCheckbox(1,"Helmet L 2",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Helmet L 2",isChecked);
                }});
        AddCheckbox(1,"Helmet L 3",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Helmet L 3",isChecked);
                }});
        AddCheckbox(1,"Bag L 1",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bag L 1",isChecked);
                }});
        AddCheckbox(1,"Bag L 2",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bag L 2",isChecked);
                }});
        AddCheckbox(1,"Bag L 3",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bag L 3",isChecked);
                }});
        AddText(1, "HEALTH", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"Medkit",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Medkit",isChecked);
                }});
        AddCheckbox(1,"FirstAidKit",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("FirstAidKit",isChecked);
                }});
        AddCheckbox(1,"Bandage",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bandage",isChecked);
                }});
        AddCheckbox(1,"Energy Drink",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Energy Drink",isChecked);
                }});
        AddCheckbox(1,"Adrenaline",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Adrenaline",isChecked);
                }});
        AddCheckbox(1,"PainKiller",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("PainKiller",isChecked);
                }});
        AddText(1, "Guns Comments", 14, 1, "#FFFFFFFF");
        AddCheckbox(1,"Flash Hider Ar",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Flash Hider Ar",isChecked);
                }});
        AddCheckbox(1,"Ar Compensator",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ar Compensator",isChecked);
                }});
        AddCheckbox(1,"Sup Sniper",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Sup Sniper",isChecked);
                }});
        AddCheckbox(1,"Tactical Stock",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Tactical Stock",isChecked);
                }});
        AddCheckbox(1,"Duckbill",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Duckbill",isChecked);
                }});
        AddCheckbox(1,"Suppressor SMG",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Suppressor SMG",isChecked);
                }});
        AddCheckbox(1,"Half Grip",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Half Grip",isChecked);
                }});
        AddCheckbox(1,"Choke",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Choke",isChecked);
                }});
        AddCheckbox(1,"Stock Micro UZI",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Stock Micro UZI",isChecked);
                }});
        AddCheckbox(1,"Flash Hider SMGr",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Flash Hider SMGr",isChecked);
                }});
        AddCheckbox(1,"Suppressor Ar",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Suppressor Ar",isChecked);
                }});
        AddCheckbox(1,"Ex.Qd.Sniper",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ex.Qd.Sniper",isChecked);
                }});
        AddCheckbox(1,"Qd.SMG",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Qd.SMG",isChecked);
                }});
        AddCheckbox(1,"Ex.SMG",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ex.SMG",isChecked);
                }});
        AddCheckbox(1,"Qd.Sniper",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Qd.Sniper",isChecked);
                }});
        AddCheckbox(1,"Ex.Sniper",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ex.Sniper",isChecked);
                }});
        AddCheckbox(1,"Ex.Ar",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ex.Ar",isChecked);
                }});
        AddCheckbox(1,"Ex.Qd.Ar",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ex.Qd.Ar",isChecked);
                }});
        AddCheckbox(1,"Qd.Ar",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Qd.Ar",isChecked);
                }});
        AddCheckbox(1,"Ex.Qd.SMG",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Ex.Qd.SMG",isChecked);
                }});
        AddCheckbox(1,"Quiver CrossBow",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Quiver CrossBow",isChecked);
                }});
        AddCheckbox(1,"Bullet Loop",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bullet Loop",isChecked);
                }});
        AddCheckbox(1,"Thumb Grip",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Thumb Grip",isChecked);
                }});
        AddCheckbox(1,"Laser Sight",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Laser Sight",isChecked);
                }});
        AddCheckbox(1,"Angled Grip",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Angled Grip",isChecked);
                }});
        AddCheckbox(1,"Light Grip",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Light Grip",isChecked);
                }});
        AddCheckbox(1,"Vertical Grip",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Vertical Grip",isChecked);
                }});
        AddCheckbox(1,"Gas Can",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Gas Can",isChecked);
                }});
        AddCheckbox(1,"Compensator SMG",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Compensator SMG",isChecked);
                }});
        AddCheckbox(1,"SniperCompensator",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("SniperCompensator",isChecked);
                }});
        AddCheckbox(2,"Buggy",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Buggy",isChecked);
                }});
        AddCheckbox(2,"UAZ",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("UAZ",isChecked);
                }});
        AddCheckbox(2,"Trike",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Trike",isChecked);
                }});
        AddCheckbox(2,"Dasia",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Dasia",isChecked);
                }});
        AddCheckbox(2,"Jet",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Jet",isChecked);
                }});
        AddCheckbox(2,"Boat",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Boat",isChecked);
                }});
        AddCheckbox(2,"Bus",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bus",isChecked);
                }});
        AddCheckbox(2,"Mirado",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Mirado",isChecked);
                }});
        AddCheckbox(2,"Scooter",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Scooter",isChecked);
                }});
        AddCheckbox(2,"Rony",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Rony",isChecked);
                }});
        AddCheckbox(2,"Snowbike",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Snowbike",isChecked);
                }});
        AddCheckbox(2,"Snowmobile",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Snowmobile",isChecked);
                }});
        AddCheckbox(2,"Tempo",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Tempo",isChecked);
                }});
        AddCheckbox(2,"Truck",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Truck",isChecked);
                }});
        AddCheckbox(2,"LadaNiva",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("LadaNiva",isChecked);
                }});
        AddCheckbox(2,"BRDM",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("BRDM",isChecked);
                }});
        AddCheckbox(2,"Bigfoot",new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    setValue("Bigfoot",isChecked);
                }});
        AddText(3, "AIMBOT SECTION", 14, 1, "#FFFFFFFF");
        AddCheckbox(3, "Stimulation Aimbot 1.0 (Need Bypass)",new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Toast.makeText(getApplicationContext(), (Html.fromHtml("<font face='bold'> <font color='#ffffff'>AIMBOT ON</font></font>")), Toast.LENGTH_LONG).show();
                    SettingValue(11,isChecked);
                }
            });
		AddText(3, "Target Selection Mode ", 14, 1, "#FFFFFFFF");
        AddRadioButton(3, new String[]{"Head","Neck","Body","Waist","Foot"}, 0, new RadioGroup.OnCheckedChangeListener(){
                public void onCheckedChanged(RadioGroup radioGroup, int i) {
                    Target(i);
                }
            });
		AddText(3, "Aiming Priority", 14, 1, "#FFFFFFFF");
        AddRadioButton(3, new String[]{"Distance Priority"," FOV Priority"}, 1, new RadioGroup.OnCheckedChangeListener(){
                public void onCheckedChanged(RadioGroup radioGroup, int i) {
                    AimBy(i);
                }
            });	
        int range =0;
        AddSeekbarng(3, "FOV", 0, 1000, range, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int range, boolean isChecked) {
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                }

                public void onStopTrackingTouch(SeekBar seekBar) {
                }
            });	
		AddText(3, "Aimbot Toggle Mode", 14, 1, "#FFFFFFFF");
        AddRadioButton(3, new String[]{"Nothing","Ads Only", "Fire Only", "Ads & Fire Only"}, 1, new RadioGroup.OnCheckedChangeListener(){
                public void onCheckedChanged(RadioGroup radioGroup, int i) {
                    AimWhen(i);
                }
            });
        AddCheckbox(3, "Aim Knocked", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    SettingValue(13,isChecked);
                }
            });
        AddText(3, "", 15, 1, "#FFFFFFFF");
        AddText(4, "Extras (Memory Risk)", 16, 1, "#FFFFFFFF");
        
        AddCheckbox(4, "Reduce Recoil", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Hack(1,isChecked);
                }
            });
        AddCheckbox(4, "Small Croshhair", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Hack(2,isChecked);
                }
            });           
         AddCheckbox(4, "Flash", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Hack(6,isChecked);
                }
            });     
        AddCheckbox(4, "AimLock", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Hack(3,isChecked);
                }
            });
        AddCheckbox(4, "High View", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Hack(4,isChecked);
                }
            });
            AddCheckbox(4, "CarJump", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Hack(7,isChecked);
                }
            });     
        AddText(4, "", 15, 1, "#00000000");
		AddText(5, "Menu Settings", 14, 1, "#FFFFFFFF");	
		AddButton2(5,"Reset Guest", -1, -2, new View.OnClickListener(){
                public void onClick(View view) {
					SharedPreferences shared = getSharedPreferences("device_id", Context.MODE_PRIVATE);
					shared.edit().putString("random", "").apply();
                    shared.edit().putString("install", RUtils.getRandomText(8) + "-" + RUtils.getRandomText(4) + "-" + RUtils.getRandomText(4) + "-" + RUtils.getRandomText(4) + "-" + RUtils.getRandomText(17)).apply();
                    shared.edit().putString("uuid", RUtils.getRandomText(32)).apply();
					if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
						File databases = new File(getDataDir().getPath() + "/databases");
						if (databases != null && databases.exists() && databases.isDirectory()){
							delete(databases.toString());
						}
                    }
					//  RModsController.showToast(context, "Reset Guest ID has been successful");
                }
            });
        AddButton2(5,"Clear Logs", -1, -2,new View.OnClickListener(){
                public void onClick(View view) {
                    String logsStr = "/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs";
                    File logs = new File(getExternalFilesDir(null).getPath() + logsStr);
                    if (logs.isDirectory() && logs.exists() && logs != null){
                        delete(logs.toString());
                    }

                }
            });

		AddCheckbox(5, "Remove Logs & AntiCheats Data", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Protection(4,isChecked);
                }
            });
	      
        AddCheckbox(5, "Delete Log", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    FileUtil.writeFile("/storage/emulated/0/Android/Alternative Bypass.txt", "PUBG MOBILE MOD By:@ModMenulayerxd");
                    Protection(0,isChecked);
                }
            });
			    
        AddCheckbox(5, "Prevent Anti Crash (Root Only)", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Protection(2,isChecked);
                }
            });
        AddCheckbox(5, "Block Ports", new CompoundButton.OnCheckedChangeListener(){
                public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                    Protection(3,isChecked);
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/StatEventReportedFlag", "StatEventType::APP_LAUNCH=false\nStatEventType::LOADING_COMPLETED=false\n");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs0", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs1", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferTmpDir", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/TGPA", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/cache", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/RoleInfo", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/StatEventReportedFlag", "StatEventType::APP_LAUNCH=false\nStatEventType::LOADING_COMPLETED=false\n");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs0", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs1", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferTmpDir", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/TGPA", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/cache", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.vng.pubgmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/RoleInfo", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/StatEventReportedFlag", "StatEventType::APP_LAUNCH=false\nStatEventType::LOADING_COMPLETED=false\n");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs0", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs1", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferTmpDir", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/TGPA", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/cache", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.rekoo.pubgm/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/RoleInfo", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
                    FileUtil.deleteFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/StatEventReportedFlag", "StatEventType::APP_LAUNCH=false\nStatEventType::LOADING_COMPLETED=false\n");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Pandora", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs0", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferEifs1", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/PufferTmpDir", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/TableDatas", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/TGPA", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/cache", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    FileUtil.writeFile("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/RoleInfo", "TELEGRAM CHANNEL: https://t.me/ModMenulayerxd");
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s down.anticheatexpert.com -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s down.anticheatexpert.com -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s down.anticheatexpert.com -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s down.anticheatexpert.com -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s down.qq.com -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s down.qq.com -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s down.qq.com -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s 49.51.235.24 -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s 49.51.235.24 -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s 49.51.235.24 -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s 49.51.235.24 -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s 49.51.0.0 -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s 49.51.0.0 -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s 49.51.0.0 -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s 49.51.0.0 -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s 49.51.255.255 -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s 49.51.255.255 -j DROP &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I INPUT -s 49.51.255.255 -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        DataOutputStream dataOutputStream = new DataOutputStream(Runtime.getRuntime().exec("sh").getOutputStream());
                        dataOutputStream.writeBytes("iptables -I OUTPUT -s 49.51.255.255 -j REJECT &>/dev/null \n");
                        dataOutputStream.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            });
        
			
		
        
        AddText(5, "ESP Settings", 14, 1, "#FFFFFFFF");
        int itemSize =0;
        AddSeekbar(5, "Item Size", 0, 50, itemSize, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int n, boolean isChecked) {
                    Size(1, n);
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                }

                public void onStopTrackingTouch(SeekBar seekBar) {
                }
            });
        int enemySize =0;
        AddSeekbar(5, "Enemies Count Size", 0, 100, enemySize, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int enemySize, boolean isChecked) {
                    Size(2, enemySize);
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                }

                public void onStopTrackingTouch(SeekBar seekBar) {
                }
            });
        int vehicleSize =0;
        AddSeekbar(5, "Vahicle Size", 0, 50, vehicleSize, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int vehicleSize, boolean isChecked) {
                    Size(3, vehicleSize);
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                }

                public void onStopTrackingTouch(SeekBar seekBar) {
                }
            });
        int fpsRender =0;
        AddSeekbar(5, "Render FPS", 0, 200, fpsRender, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int fpsRender, boolean isChecked) {
                    Size(4, fpsRender);
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                }

                public void onStopTrackingTouch(SeekBar seekBar) {
                }
            });
        int alertSize =0;
        AddSeekbar(5, "Alert 360° Size", 0, 150, alertSize, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int alertSize, boolean isChecked) {
                    Size(5, alertSize);
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                }

                public void onStopTrackingTouch(SeekBar seekBar) {
                }
            });
        AddText(5, "Settings page", 14, 1, "#FFFFFFFF");
       AddFloatSeekbar(5, "Image transparency", 0, 10, 10, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int img, boolean isChecked) {
                    relativeLayout.setAlpha((float)img / 10.0f);
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                    relativeLayout.setVisibility(0);
                }
                public void onStopTrackingTouch(SeekBar seekBar) {
                    relativeLayout.setVisibility(8);
                }
            });
        AddFloatSeekbar(5, " The transparency of the list", 0, 10, 10, "", "", new SeekBar.OnSeekBarChangeListener(){
                public void onProgressChanged(SeekBar seekBar, int trans, boolean isChecked) {
                    linearLayout.setAlpha((float)trans / 10.0f);
                }
                public void onStartTrackingTouch(SeekBar seekBar) {
                }
                public void onStopTrackingTouch(SeekBar seekBar) {
                }
            });
        SeekBar.OnSeekBarChangeListener onSeekBarChangeListener2 = new SeekBar.OnSeekBarChangeListener(){
            int m_Progress;

            public void onProgressChanged(SeekBar seekBar, int n3, boolean isChecked) {
                this.m_Progress = n3;
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
                this.m_Progress = 0;
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                layoutParams.width = n * this.m_Progress / 100;
                layoutParams.height = n2 * this.m_Progress / 100;
                linearLayout3.setLayoutParams((ViewGroup.LayoutParams)new LinearLayout.LayoutParams((int)((float)n / 3.0f), -1));
                windowManager.updateViewLayout((View)linearLayout, (ViewGroup.LayoutParams)layoutParams);
                button.setX((float)(n * this.m_Progress / 100 - (int)((float)dpi / 5.5f)));
            }
        };
        AddSeekbar(5, " List size", 50, 200, 100, "", "%", onSeekBarChangeListener2);
        AddButton(5, "Save settings", -1, -2, new View.OnClickListener(){
                public void onClick(View view) {
                    
                }
            });
        AddText(6, "------------------------------------------------------", 15, 1, "#FF8800FF");
        AddText(6, "             🇮🇳 MOD BY ModMenulayerxd 🇮🇳", 15, 1, "#FFFF0000");
        AddText(6, "             TELEGRAM :@luxclubofficial ", 15, 1, "#FF0012FF");
        AddText(6, "             OWNER :@ModMenulayerxd ", 15, 1, "#FF13FF00");
        AddText(6, "------------------------------------------------------", 15, 1, "#FF8800FF");
        AddText(6, "!WARNING!", 14, 1, "#FFFFFFFF");
        AddTextNormal(6, "Mod Completely By @ModMenulayerXd \nOur channel only share\n\nWe Are not responsible if you get any Ban!\nIt at your own Risk, we are not forcing you to wear Cheats!\n\n\n/>Enjoy 🇮🇳\n\n", 14, 1, "#FFFFFFFF");
         }
    private void DrawCanvas() {

        CanvasDrawingView overlayView = new CanvasDrawingView(this);   int LAYOUT_FLAG;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            LAYOUT_FLAG = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
        } else {
            LAYOUT_FLAG = WindowManager.LayoutParams.TYPE_SYSTEM_OVERLAY;
        }
        final WindowManager.LayoutParams params = new WindowManager.LayoutParams(
            WindowManager.LayoutParams.MATCH_PARENT,
            WindowManager.LayoutParams.MATCH_PARENT, 0, getNavigationBarHeight(),
            LAYOUT_FLAG,
            WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE
            | WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE | WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN | WindowManager.LayoutParams.FLAG_FULLSCREEN,
            PixelFormat.RGBA_8888);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P)
            params.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;

        params.gravity = Gravity.TOP | Gravity.START;        //Initially view will be added to top-left corner
        params.x = 0;
        params.y = 0;
        windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);
        windowManager.addView(overlayView, params);
    }
    private int getNavigationBarHeight() {
        boolean hasMenuKey = ViewConfiguration.get(this).hasPermanentMenuKey();
        int resourceId = getResources().getIdentifier("navigation_bar_height", "dimen", "android");
        if (resourceId > 0 && !hasMenuKey) {
            return getResources().getDimensionPixelSize(resourceId);
        }
        return 0;
    }

    private void  setValue(String key,boolean b) {
        SharedPreferences sp=this.getSharedPreferences("espValue",Context.MODE_PRIVATE);
        SharedPreferences.Editor ed= sp.edit();
        ed.putBoolean(key,b);
        ed.apply();

    }
	public static void delete(String path){
        File dir = new File(path);
        if (dir.isDirectory())
        {
            String[] children = dir.list();
            for (int i = 0; i < children.length; i++)
            {
                new File(dir, children[i]).delete();
            }
        }
    }
    @SuppressLint("WrongConstant")
    public int onStartCommand(Intent intent, int n, int n2) {
        return 2;
    }
    public static interface OnListChoosedListener {
        public void onChoosed(int var1);
    }
    public native void SettingValue(int setting_code,boolean value);
    public native void Hack(int setting_code,boolean jboolean1);
    public native void Protection(int setting_code,boolean jboolean1);
    public static native void Size(int num, float size);
	public native void Range(int range);  
	public native void Target(int i);
    public native void AimBy(int i);
    public native void AimWhen(int i);
    private native String Icon();
    private native String IconClose();
    public static native void DrawOn(CanvasDrawingView espView, Canvas canvas);
    

    public void onTaskRemoved(Intent intent) {
        stopSelf();
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        super.onTaskRemoved(intent);
   }
}
