package com.modmenu.patcher;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Handler;
import android.provider.Settings;
import android.text.Html;
import android.util.Base64;
import android.util.Log;
import android.widget.Toast;

import java.io.File;
import java.io.FileOutputStream;

import com.modmenu.patcher.service.*;

public class StaticActivity {

    private static final String TAG = "XCEL MODS";
    public static String cacheDir;

    public static void Start(final Context context) {
        Toast.makeText(context, (Html.fromHtml("<font face='bold'> <font color='#ffffff'>XCEL MODS</font></font>")), Toast.LENGTH_LONG).show();

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && !Settings.canDrawOverlays(context)) {
            context.startActivity(new Intent("android.settings.action.MANAGE_OVERLAY_PERMISSION",
                                             Uri.parse("package:" + context.getPackageName())));
                    } else {
            Handler handler = new Handler();
            handler.postDelayed(new Runnable() {
                    @Override
                                public void run() {
                                    context.startService(new Intent(context, Launcher.class));
                                    
                    }
                }, 2500);
        }

        
    }
    

    private static void writeToFile(String name, String base64) {
        File file = new File(cacheDir + name);
        try {
            if (!file.exists()) {
                file.createNewFile();
            }
            FileOutputStream fos = new FileOutputStream(file);
            byte[] decode = Base64.decode(base64, 0);
            fos.write(decode);
            fos.close();
        } catch (Exception e) {
            Log.e(TAG, e.getMessage());
        }
    }
}

