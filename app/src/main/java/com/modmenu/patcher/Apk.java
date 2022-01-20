package com.modmenu.patcher;


import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Handler;
import android.os.Process;
import android.provider.Settings;

public class Apk {

    public static void Start(final Context context) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && !Settings.canDrawOverlays(context)) {
            AlertDialog alertDialog = new AlertDialog.Builder(context, 1)
                    .setTitle("No overlay permission")
                    .setMessage("Overlay permission is required for the mod to work. Would you like to grant them on the next screen?")
                    .setPositiveButton("Sim", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            context.startActivity(new Intent("android.settings.action.MANAGE_OVERLAY_PERMISSION",
                                    Uri.parse("package:" + context.getPackageName())));
                            Process.killProcess(Process.myPid());
                        }
                    })
                    .setNegativeButton("No", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {

                        }
                    }).setCancelable(false)
                    .create();
            alertDialog.show();
        } else {
            Handler handler = new Handler();
            final String string = "com.modmenu.patcher.MainActivity";
            handler.postDelayed(new Runnable() {

                @Override
                public void run() {
                    try {
                        context.startService(new Intent(context, Class.forName(string)));
                    } catch (ClassNotFoundException e) {
                        e.printStackTrace();
                    }
                }
            }, 500);
        }
    }
}