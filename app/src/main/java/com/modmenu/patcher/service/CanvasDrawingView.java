package com.modmenu.patcher.service;


import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.view.View;
import java.text.SimpleDateFormat;
import java.util.Date;

import android.util.Log;
import android.graphics.Typeface;
import android.graphics.Rect;
import android.graphics.drawable.GradientDrawable;

import static com.modmenu.patcher.service.Launcher.getConfig;

public class CanvasDrawingView extends View implements Runnable {
    Paint mStrokePaint;
    Paint mStrokePaint2;
    Paint mFilledPaint;
    Paint mFilledPaint2;
    Paint mTextPaint;
    Paint mTextPaint2;
    Paint mTextPaint3;
    Paint mStrokeFov;
    Paint mTextStroke;
    Paint mTextStroke2;
    Thread mThread;
    Paint paint31 = new Paint();
    Rect eRect;
    GradientDrawable eGradientDrawable;
    int eColor[] = {Color.TRANSPARENT,Color.GREEN,Color.TRANSPARENT};
    public static int FPS = 200;
    Date time;
    SimpleDateFormat formatter;
    static Context ctx;
    long sleepTime = ((long) (1000 / FPS));



    public CanvasDrawingView(Context context) {
        super(context, null, 0);
        InitializePaints();
        setFocusableInTouchMode(false);
        setBackgroundColor(0);
        Thread thread = new Thread(this);
        this.mThread = thread;
        thread.start();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        if (canvas != null && getVisibility() == VISIBLE) {
            ClearCanvas(canvas);
            int height = canvas.getHeight();
            float f = (height - 20);
            Launcher.DrawOn(this, canvas);
        }
    }

    public void run() {
        android.os.Process.setThreadPriority(10);
        while (this.mThread.isAlive() && !this.mThread.isInterrupted()) {
            try {
                long t1 = System.currentTimeMillis();
                postInvalidate();
                Thread.sleep(Math.max(Math.min(0, this.sleepTime - (System.currentTimeMillis() - t1)), this.sleepTime));
            } catch (InterruptedException it) {
                Log.e("OverlayThread", it.getMessage());
            }
        }
    }
    public void InitializePaints() {
        eRect = new Rect(-100,60,100,100);
        eGradientDrawable = new GradientDrawable();
        eGradientDrawable.setOrientation(GradientDrawable.Orientation.LEFT_RIGHT);
        eGradientDrawable.setColors(eColor);
        eGradientDrawable.setShape(GradientDrawable.RECTANGLE);
        eGradientDrawable.setBounds(eRect);

        mStrokePaint = new Paint();
        mStrokePaint.setStyle(Paint.Style.STROKE);
        mStrokePaint.setAntiAlias(true);
        mStrokePaint.setColor(Color.rgb(0, 0, 0));

        mFilledPaint = new Paint();
        mFilledPaint.setStyle(Paint.Style.FILL);
        mFilledPaint.setAntiAlias(true);
        mFilledPaint.setColor(Color.rgb(0, 0, 0));

        mStrokePaint2 = new Paint();
        mStrokePaint2.setStyle(Paint.Style.STROKE);
        mStrokePaint2.setAntiAlias(true);
        mStrokePaint2.setColor(Color.rgb(0, 0, 0));

        mFilledPaint2 = new Paint();
        mFilledPaint2.setStyle(Paint.Style.FILL);
        mFilledPaint2.setAntiAlias(true);
        mFilledPaint2.setColor(Color.rgb(0, 0, 0));

        mTextPaint = new Paint();
        mTextPaint.setStyle(Paint.Style.FILL_AND_STROKE);
        mTextPaint.setAntiAlias(true);
        mTextPaint.setColor(Color.rgb(0, 0, 0));
        mTextPaint.setTextAlign(Paint.Align.CENTER);
        mTextPaint.setStrokeWidth(1.1f);

        mTextPaint2 = new Paint();
        mTextPaint2.setStyle(Paint.Style.FILL_AND_STROKE);
        mTextPaint2.setAntiAlias(true);
        mTextPaint2.setColor(Color.rgb(0, 0, 0));
        mTextPaint2.setTextAlign(Paint.Align.CENTER);
        mTextPaint2.setStrokeWidth(1.1f);

        mTextPaint3 = new Paint();
        mTextPaint3.setStyle(Paint.Style.FILL_AND_STROKE);
        mTextPaint3.setAntiAlias(true);
        mTextPaint3.setColor(Color.rgb(0, 0, 0));
        mTextPaint3.setTextAlign(Paint.Align.CENTER);
        mTextPaint3.setStrokeWidth(1.1f);

        mTextStroke = new Paint();
        mTextStroke.setStyle(Paint.Style.FILL_AND_STROKE);
        mTextStroke.setAntiAlias(true);
        mTextStroke.setColor(Color.parseColor("#000000"));
        mTextStroke.setTextAlign(Paint.Align.CENTER);
        mTextStroke.setStrokeWidth(4.0f);
        mTextStroke.setStrokeMiter(4.0f);

        mStrokeFov = new Paint();
        mStrokeFov.setStyle(Paint.Style.STROKE);
        mStrokeFov.setAntiAlias(true);
        mStrokeFov.setColor(Color.parseColor("#000000"));
        mStrokeFov.setStrokeWidth(2.5f);
        mStrokeFov.setStrokeMiter(2.5f);

        mTextStroke2 = new Paint();
        mTextStroke2.setStyle(Paint.Style.FILL_AND_STROKE);
        mTextStroke2.setAntiAlias(true);
        mTextStroke2.setColor(Color.parseColor((String)"#000000"));
        mTextStroke2.setTextAlign(Paint.Align.CENTER);
        mTextStroke2.setStrokeWidth(4.0f);
        mTextStroke2.setStrokeMiter(4.0f);
        mTextStroke2.setTypeface(Typeface.DEFAULT_BOLD);
    }

    public void ClearCanvas(Canvas cvs) {
        cvs.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);
    }
    public void Drawcount(Canvas canvas) {
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-80,50,160,40);
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-72,50,144,40);
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-64,50,128,40);
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-60,50,120,40);
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-56,50,112,40);
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-52,50,104,40);
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-48,50,96,40);
        CanvasDrawFilledRect(canvas,20,0,255,0,canvas.getWidth()/2-44,50,88,40);}
    public void CanvasDrawText3(Canvas cvs, int a, int r, int g, int b,float stroke, String txt, float posX, float posY, float size) {
        mTextPaint.setARGB(a,r, g, b);
        mTextPaint.setTextSize(13);
        mTextPaint.setColor(Color.rgb(255, 255, 255));
        cvs.drawText(txt, posX-76, posY, mTextPaint);
    }
	public void CanvasDrawText22(Canvas cvs, int a, int r, int g, int b,float stroke, String txt, float posX, float posY, float size) {
        mTextPaint.setColor(Color.rgb(r, g, b));
        mTextPaint.setAlpha(a);
        mTextPaint.setStrokeWidth(stroke);
        if (getRight() > 1800 || getBottom() > 1920)
            mTextPaint.setTextSize(4 + size);
        else if (getRight() == 1800 || getBottom() == 1920)
            mTextPaint.setTextSize(2 + size);
        else
            mTextPaint.setTextSize(size);

        cvs.drawText(txt, posX-100, posY, mTextPaint);
    }
    public void CanvasDrawHealth(Canvas cvs, int a, int r, int g, int b, float x, float y, float width, float height) {
        mFilledPaint.setColor(Color.rgb(r, g, b));
        mFilledPaint.setAlpha(a);
        cvs.drawRect(x, y, x + width, y + height, mFilledPaint);

	}
    public void CanvasDrawHealth2(Canvas cvs, int a, int r, int g, int b, float x, float y, float width, float height) {
        mStrokePaint.setStrokeWidth(1.0f);
        mStrokePaint.setColor(Color.rgb(255, 255, 255));
        mStrokePaint.setAlpha(a);
        cvs.drawRect(x, y, x + width, y + height, mStrokePaint);
    }
    public void CanvasDrawLine(Canvas cvs, int a, int r, int g, int b, float lineWidth, float fromX, float fromY, float toX, float toY) {
        mStrokePaint.setColor(Color.rgb(r, g, b));
        mStrokePaint.setAlpha(a);
        mStrokePaint.setStrokeWidth(1.5f);
        cvs.drawLine(fromX, fromY, toX, toY, mStrokePaint);
    }
    public void CanvasDrawFilledCircle(Canvas cvs, int a, int r, int g, int b, float posX, float posY, float radius) {
        mFilledPaint.setColor(Color.rgb(r, g, b));
        mFilledPaint.setAlpha(a);
        cvs.drawCircle(posX, posY, radius, mFilledPaint);
    }

    public void CanvasDrawRect(Canvas cvs, int a, int r, int g, int b, float stroke, float x, float y, float width, float height) {
        mStrokePaint.setStrokeWidth(stroke);
        mStrokePaint.setColor(Color.rgb(r, g, b));
        mStrokePaint.setAlpha(a);
        mStrokePaint.setStrokeWidth(1.5f);
        cvs.drawRect(x, y,  width,  height, mStrokePaint);
    }
    public void CanvasDrawFilledRect(Canvas cvs, int a, int r, int g, int b, float x, float y, float width, float height) {
        mFilledPaint.setColor(Color.rgb(r, g, b));
        mFilledPaint.setAlpha(a);
        cvs.drawRect(x, y, width, height, mFilledPaint);
    }

    public void CanvasDrawFilledRect3(Canvas cvs, int a, int r, int g, int b, float x, float y, float width, float height) {
		// mStrokeFov.setColor(Color.parseColor((String)"#000000"));
        //cvs.drawRect(x-55, y-5,  width+55,  (height), mStrokeFov);
        mFilledPaint2.setColor(Color.rgb(r, g, b));
        mFilledPaint2.setAlpha(a);
        cvs.drawRect(x-55, y-5, width+55, (height), mFilledPaint2);
    }

    public void CanvasDrawRect2(Canvas cvs, int a, int r, int g, int b, float stroke, float x, float y, float width, float height) {
        mFilledPaint.setARGB(a,r, g, b);
        mStrokeFov.setColor(Color.parseColor((String)"#000000"));
        cvs.drawRect(x-55, y-5,  width+55,  (height), mStrokeFov);
        mFilledPaint.setAlpha(500);
        mFilledPaint.setARGB(130,0,0,0);
        cvs.drawRect(x-55, y-5,  width+55,  (height), mFilledPaint);
    }

    public void DebugText(String s) {
        System.out.println(s);
    }

    public void CanvasDrawTextNormal(Canvas cvs, int a, int r, int g, int b, String txt, float posX, float posY, float size) {
        mTextPaint.setARGB(a,r, g, b);
        mTextPaint.setTextSize(size);
        mStrokePaint.setColor(Color.rgb(0, 0, 0));
        cvs.drawText(txt, posX, posY, mTextPaint);
    }
    public void CanvasDrawText(Canvas cvs, int a, int r, int g, int b, String txt, float posX, float posY, float size) {
        mTextStroke.setColor(Color.rgb(r, g, b));
        mTextStroke.setTextSize(size);
        mTextStroke.setColor(Color.parseColor((String)"#000000"));
        cvs.drawText(txt, posX, posY, mTextStroke);
        mTextPaint.setARGB(a,r, g, b);
        mTextPaint.setTextSize(size);
        mStrokePaint.setColor(Color.rgb(0, 0, 0));
        cvs.drawText(txt, posX, posY, mTextPaint);
    }

    public void CanvasDrawTextDistance(Canvas cvs, int a, int r, int g, int b, String txt, float posX, float posY, float size) {
        mTextPaint.setARGB(a,r, g, b);
        mTextPaint.setTextSize(13);
        mTextPaint.setColor(Color.rgb(255, 255, 255));
        cvs.drawText(txt, posX-76, posY, mTextPaint);
    }

    public void CanvasDrawTextAltert(Canvas cvs, int a, int r, int g, int b, String txt, float posX, float posY, float size) {
        mTextStroke.setColor(Color.rgb(r, g, b));
        mTextStroke.setTextSize(size);
        mTextStroke.setColor(Color.parseColor((String)"#000000"));
        cvs.drawText(txt, posX, posY, mTextStroke);
        mTextPaint.setColor(Color.rgb(r, g, b));
        mTextPaint.setTextSize(size);
        cvs.drawText(txt, posX, posY, mTextPaint);
    }
	public void CanvasDrawWeapon(Canvas cvs, int a, int r, int g, int b, int id,int ammo, float posX, float posY, float size) {
        mTextPaint.setARGB(a,r, g, b);
        mTextPaint.setTextSize(size);
        String wname=getWeapon(id);
        if(wname!=null)
            cvs.drawText(wname+": "+ammo, posX, posY, mTextPaint);
    }    
    public void CanvasDrawName(Canvas cvs, int a, int r, int g, int b, String nametxt,int teamid, float posX, float posY, float size) {
        String[] namesp = nametxt.split(":");
        char[] nameint = new char[namesp.length];
        for (int i = 0; i < namesp.length; i++)
            nameint[i] = (char) Integer.parseInt(namesp[i]);
        String realname = new String(nameint);
        mTextPaint.setTextSize(13);
        mTextPaint.setStrokeWidth(1.0f);
        mTextPaint.setStrokeMiter(1.0f);
        mTextPaint.setColor(Color.YELLOW);
        cvs.drawText("" + realname, posX, posY, mTextPaint);
        mTextPaint.setARGB(a,r, g, b);
        mFilledPaint.setARGB(120,0,0,0);
        cvs.drawRect(posX, posY, posX, posY, mFilledPaint);
        mFilledPaint.setAlpha(a);
        mTextPaint.setColor(Color.TRANSPARENT);
        mTextPaint.setTextSize(0);
		cvs.drawText("" + teamid, posX, posY, mTextPaint);
    }
	public void CanvasDrawName3(Canvas cvs, int a, int r, int g, int b, String nametxt,int teamid, float posX, float posY, float size) {
        String[] namesp = nametxt.split(":");
        char[] nameint = new char[namesp.length];
        for (int i = 0; i < namesp.length; i++)
            nameint[i] = (char) Integer.parseInt(namesp[i]);
		String str = "ID:";    
        String realname = new String(nameint);	
        mTextPaint.setARGB(a,r, g, b);
        mTextPaint.setTextSize(size);
        cvs.drawText(str+ realname, posX, posY -50, mTextPaint);
    }
	public void CanvasDrawName4(Canvas cvs, int a, int r, int g, int b, String nametxt, int teamid,float posX, float posY, float size) {
		String[] namesp = nametxt.split(":");
		char[] nameint = new char[namesp.length];
		for (int i = 0; i < namesp.length; i++)
			nameint[i] = (char) Integer.parseInt(namesp[i]);
		String str = "";    
		String realname = new String(nameint);
		mTextPaint.setARGB(a,r, g, b);
		mTextPaint.setTextSize(size);
		cvs.drawText(str + Gender(realname), posX, posY -80, mTextPaint);
	}    
    public void CanvasDrawHead(Canvas cvs, int a, int r, int g, int b, float posX, float posY, float radius) {
        mFilledPaint.setARGB(a,r, g, b);
        mFilledPaint.setAlpha(a);
        mStrokePaint.setColor(Color.rgb(255, 255, 255));
        mStrokePaint.setStrokeWidth(1.5f);
        cvs.drawCircle(posX, posY, radius, mStrokePaint);
    }
    public void CanvasDrawItems(Canvas cvs, String itemName,float distance, float posX, float posY, float size) {
        String realItemName = getItemName(itemName);
        mTextStroke.setTextSize((float)(size));
        mTextStroke.setColor(Color.parseColor((String)"#000000"));
        if(realItemName!=null && !realItemName.equals(""))
            cvs.drawText(realItemName+" ("+Math.round(distance)+"m)", posX, posY, mTextStroke);
        mTextPaint.setTextSize(size);
        mTextPaint.setStrokeWidth(1.0f);
        mTextPaint.setStrokeMiter(1.0f);
        mTextPaint.setTextSize(size);
        if(realItemName!=null && !realItemName.equals(""))
            cvs.drawText(realItemName+" ("+Math.round(distance)+"m)", posX, posY, mTextPaint);
    }
    /*public void CanvasDrawItems(Canvas cvs, String itemName,float distance, float posX, float posY, float size) {
        String realItemName = getItemName(itemName);
        mTextPaint.setTextSize(size);
        if(realItemName!=null && !realItemName.equals(""))
            cvs.drawText(realItemName+" ("+Math.round(distance)+"m)", posX, posY, mTextPaint);
    }*/
    public void CanvasDrawItems(Canvas cvs, int itemID,float distance, float posX, float posY, float size) {
        String realItemName = getItemName(itemID);
        mTextPaint.setTextSize(size);
        if(!realItemName.equals(""))
            cvs.drawText(realItemName+" ("+Math.round(distance)+"m)", posX, posY, mTextPaint);
    }
    public void DrawItemsByID(Canvas cvs, int itemID,float distance, float posX, float posY, float size) {
        String realItemName = getItemName(itemID);
        mTextPaint.setTextSize(size);
        if(!realItemName.equals(""))
            cvs.drawText(realItemName+" ("+Math.round(distance)+"m)", posX, posY, mTextPaint);
    }
    public void CanvasDrawVehicles(Canvas cvs, String itemName,float distance, float posX, float posY, float size) {
        String realVehicleName = getVehicleName(itemName);
        mTextStroke.setTextSize((float)(size));
        mTextStroke.setColor(Color.parseColor((String)"#000000"));
        if(realVehicleName!=null && !realVehicleName.equals(""))
            cvs.drawText(realVehicleName+": "+Math.round(distance)+"m", posX, posY, mTextStroke);
        mTextPaint.setColor(Color.RED);
        mTextPaint.setTextSize(size);
        if(realVehicleName!=null && !realVehicleName.equals(""))
            cvs.drawText(realVehicleName+": "+Math.round(distance)+"m", posX, posY, mTextPaint);
    }

    public void CanvasDrawCircle(Canvas cvs, int a, int r, int g, int b, float posX, float posY, float radius, float stroke) {
        mStrokePaint.setARGB(a,r,g,b);
        mStrokePaint.setStrokeWidth(1.3f);
        cvs.drawCircle(posX, posY, radius, mStrokePaint);
    }
    public void CanvasDrawCircle2(Canvas cvs, int a, int r, int g, int b, float posX, float posY, float radius){
        mStrokePaint.setColor(Color.rgb(r, g, b));
        mStrokePaint.setAlpha(a);
        cvs.drawCircle(posX, posY, radius, mStrokePaint);
    }	
	public void CanvasDrawName2(Canvas cvs, int a, int r, int g, int b, String nametxt,int teamid, float posX, float posY, float size) {
        String[] namesp = nametxt.split(":");
        char[] nameint = new char[namesp.length];
        for (int i = 0; i < namesp.length; i++)
            nameint[i] = (char) Integer.parseInt(namesp[i]);
        String realname = new String(nameint);	
        mTextPaint.setARGB(a,r, g, b);
        mTextPaint.setTextSize(size);
        cvs.drawText(teamid+". "+ Nation(realname), posX, posY -30, mTextPaint);
    }
	private String Gender(String code) {
		if (code.equals("G1"))
		{
			code = "Female";
		}
		else {
			code = new String(Character.toChars((Character.codePointAt(code, 0) - 65) + 127462)) + new String(Character.toChars((Character.codePointAt(code, 1) - 65) + 127462));    
		}
		return code;
	}
	private String Nation(String code) {
		if (code.equals("G1"))
		{
			code = "ERANGEL";
		}
		else {
			code = new String(Character.toChars((Character.codePointAt(code, 0) - 65) + 127462)) + new String(Character.toChars((Character.codePointAt(code, 1) - 65) + 127462));    
		}
		return code;
	}
	
    private String getItemName(String s) {
        //Scopes
        if (s.contains("MZJ_8X")&& getConfig("8x")) { mTextStroke2.setColor(Color.GREEN);
            return "8x";
        }

        if (s.contains("MZJ_2X") && getConfig("2x")) { mTextStroke2.setColor(Color.GREEN);
            return "2x";
        }

        if (s.contains("MZJ_HD") && getConfig("Red Dot")) { mTextStroke2.setColor(Color.GREEN);
            return "Red Dot";
        }

        if (s.contains("MZJ_3X") && getConfig("3x")) { mTextStroke2.setColor(Color.GREEN);
            return "3X";
        }

        if (s.contains("MZJ_QX") && getConfig("Hollow")) { mTextStroke2.setColor(Color.WHITE);
            return "Hollow Sight";
        }

        if (s.contains("MZJ_6X") && getConfig("6x")) { mTextStroke2.setColor(Color.GREEN);
            return "6x";
        }

        if (s.contains("MZJ_4X") && getConfig("4x")) { mTextStroke2.setColor(Color.GREEN);
            return "4x";
        }

        if (s.contains("MZJ_SideRMR") && getConfig("Canted")) { mTextStroke2.setColor(Color.GREEN);
            return "Canted Sight";
        }


        //AR and smg
        if (s.contains("AUG") && getConfig("AUG")) { mTextStroke2.setColor(Color.GREEN);
            return "AUG";
        }

        if (s.contains("M762") && getConfig("M762")) { mTextStroke2.setColor(Color.GREEN);
            return "M762";
        }

        if (s.contains("SCAR") && getConfig("SCAR-L")) { mTextStroke2.setColor(Color.GREEN);
            return "SCAR-L";
        }

        if (s.contains("M416") && getConfig("M416")) { mTextStroke2.setColor(Color.GREEN);
            return "M416";
        }

        if (s.contains("M16A4") && getConfig("M16A4")) { mTextStroke2.setColor(Color.GREEN);
            return "M16A-4";
        }

        if (s.contains("Mk47") && getConfig("Mk47 Mutant")) { mTextStroke2.setColor(Color.GREEN);
            return "Mk47 Mutant";
        }

        if (s.contains("G36") && getConfig("G36C")) { mTextStroke2.setColor(Color.GREEN);
            return "G36C";
        }

        if (s.contains("QBZ") && getConfig("QBZ")) { mTextStroke2.setColor(Color.GREEN);
            return "QBZ";
        }

        if (s.contains("AKM") && getConfig("AKM")) { mTextStroke2.setColor(Color.GREEN);
            return "AKM";
        }

        if (s.contains("Groza") && getConfig("Groza")) { mTextStroke2.setColor(Color.GREEN);
            return "Groza";
        }

        if (s.contains("PP19") && getConfig("Bizon")) { mTextStroke2.setColor(Color.WHITE);
            return "Bizon";
        }

        if (s.contains("TommyGun") && getConfig("TommyGun")) { mTextStroke2.setColor(Color.WHITE);
            return "TommyGun";
        }

        if (s.contains("MP5K") && getConfig("MP5K")) { mTextStroke2.setColor(Color.WHITE);
            return "MP5K";
        }

        if (s.contains("UMP9") && getConfig("UMP")) { mTextStroke2.setColor(Color.CYAN);
            return "UMP";
        }

        if (s.contains("Vector") && getConfig("Vector")) { mTextStroke2.setColor(Color.WHITE);
            return "Vector";
        }

        if (s.contains("MachineGun_Uzi") && getConfig("Uzi")) { mTextStroke2.setColor(Color.WHITE);
            return "Uzi";
        }

        if (s.contains("DP28") && getConfig("DP28")) { mTextStroke2.setColor(Color.GREEN);
            return "DP28";
        }

        if (s.contains("M249") && getConfig("M249")) { mTextStroke2.setColor(Color.GREEN);;
            return "M249";
        }

        //snipers

        if (s.contains("AWM") && getConfig("AWM")) { mTextStroke2.setColor(Color.BLUE);
            return "AWM";
        }

        if (s.contains("QBU") && getConfig("QBU")) { mTextStroke2.setColor(Color.GREEN);
            return "QBU";
        }

        if (s.contains("SLR") && getConfig("SLR")) { mTextStroke2.setColor(Color.GREEN);
            return "SLR";
        }

        if (s.contains("SKS") && getConfig("SKS")) { mTextStroke2.setColor(Color.GREEN);
            return "SKS";
        }

        if (s.contains("Mini14") && getConfig("Mini14")) { mTextStroke2.setColor(Color.GREEN);
            return "Mini14";
        }

        if (s.contains("M24") && getConfig("M24")) { mTextStroke2.setColor(Color.GREEN);
            return "M24";
        }

        if (s.contains("Kar98k") && getConfig("Kar98k")) { mTextStroke2.setColor(Color.GREEN);
            return "Kar98k";
        }

        if (s.contains("VSS") && getConfig("VSS")) { mTextStroke2.setColor(Color.GREEN);
            return "VSS";
        }

        if (s.contains("Win94") && getConfig("Win94")) { mTextStroke2.setColor(Color.GREEN);
            return "Win94";
        }

        if (s.contains("Mk14") && getConfig("Mk14")) { mTextStroke2.setColor(Color.GREEN);
            return "Mk14";
        }

//shotguns and hand weapons
        if (s.contains("S12K") && getConfig("S12K")) { mTextStroke2.setColor(Color.WHITE);
            return "S12K";
        }

        if (s.contains("DBS") && getConfig("DBS")) { mTextStroke2.setColor(Color.RED);
            return "DBS";
        }

        if (s.contains("S686") && getConfig("S686")) { mTextStroke2.setColor(Color.WHITE);
            return "S686";
        }

        if (s.contains("S1897") && getConfig("S1897")) { mTextStroke2.setColor(Color.WHITE);
            return "S1897";
        }

        if (s.contains("Sickle") && getConfig("Sickle")) { mTextStroke2.setColor(Color.WHITE);
            return "Sickle";
        }

        if (s.contains("Machete") && getConfig("Machete")) { mTextStroke2.setColor(Color.WHITE);
            return "Machete";
        }

        if (s.contains("Cowbar") && getConfig("Cowbar")) { mTextStroke2.setColor(Color.WHITE);
            return "Cowbar";
        }

        if (s.contains("CrossBow") && getConfig("CrossBow")) { mTextStroke2.setColor(Color.WHITE);
            return "CrossBow";
        }

        if (s.contains("Pan") && getConfig("Pan")) { mTextStroke2.setColor(Color.WHITE);
            return "Pan";
        }

        //pistols

        if (s.contains("SawedOff") && getConfig("SawedOff")) { mTextStroke2.setColor(Color.WHITE);
            return "SawedOff";
        }

        if (s.contains("R1895") && getConfig("R1895")) { mTextStroke2.setColor(Color.WHITE);
            return "R1895";
        }

        if (s.contains("Vz61") && getConfig("Vz61")) { mTextStroke2.setColor(Color.WHITE);
            return "Vz61";
        }

        if (s.contains("P92") && getConfig("P92")) { mTextStroke2.setColor(Color.WHITE);
            return "P92";
        }

        if (s.contains("P18C") && getConfig("P18C")) { mTextStroke2.setColor(Color.WHITE);
            return "P18C";
        }

        if (s.contains("R45") && getConfig("R45")) { mTextStroke2.setColor(Color.WHITE);
            return "R45";
        }

        if (s.contains("P1911") && getConfig("P1911")) { mTextStroke2.setColor(Color.WHITE);
            return "P1911";
        }

        if (s.contains("DesertEagle") && getConfig("Desert Eagle")) { mTextStroke2.setColor(Color.WHITE);
            return "DesertEagle";
        }


        //Ammo
        if (s.contains("Ammo_762mm") && getConfig("7.62")) { mTextPaint2.setARGB(255, 92, 36, 28);
            return "7.62";
        }

        if (s.contains("Ammo_45AC") && getConfig("45ACP")) { mTextPaint2.setColor(Color.LTGRAY);
            return "45ACP";
        }

        if (s.contains("Ammo_556mm") && getConfig("5.56")) { mTextPaint2.setColor(Color.GREEN);
            return "5.56";
        }

        if (s.contains("Ammo_9mm") && getConfig("9mm")) { mTextPaint2.setColor(Color.YELLOW);
            return "9mm";
        }

        if (s.contains("Ammo_300Magnum") && getConfig("300Magnum")) { mTextStroke2.setColor(Color.BLUE);
            return "300Magnum";
        }

        if (s.contains("Ammo_12Guage") && getConfig("12 Guage")) { mTextPaint2.setARGB(255, 156, 91, 81);
            return "12 Guage";
        }

        if (s.contains("Ammo_Bolt") && getConfig("Arrow")) { mTextStroke2.setColor(Color.WHITE);
            return "Arrow";
        }

        //bag helmet vest
        if (s.contains("Bag_Lv3") && getConfig("Bag L 3")) { mTextStroke2.setColor(Color.CYAN);
            return "Bag lvl 3";
        }

        if (s.contains("Bag_Lv1")  && getConfig("Bag L 1")) { mTextPaint2.setARGB(255, 127, 154, 250);
            return "Bag lvl 1";
        }

        if (s.contains("Bag_Lv2") && getConfig("Bag L 2")) { mTextPaint2.setARGB(255, 77, 115, 255);
            return "Bag lvl 2";
        }

        if (s.contains("Armor_Lv2") && getConfig("Vest L 2")) { mTextPaint2.setARGB(255, 77, 115, 255);
            return "Vest lvl 2";
        }


        if (s.contains("Armor_Lv1") && getConfig("Vest L 1")) { mTextPaint2.setARGB(255, 127, 154, 250);
            return "Vest lvl 1";
        }


        if (s.contains("Armor_Lv3") && getConfig("Vest L 3")) { mTextStroke2.setColor(Color.CYAN);
            return "Vest lvl 3";
        }


        if (s.contains("Helmet_Lv2") && getConfig("Helmet 2")) { mTextStroke2.setColor(Color.WHITE);
            return "Helmet lvl 2";
        }

        if (s.contains("Helmet_Lv1") && getConfig("Helmet 1")) { mTextStroke2.setColor(Color.WHITE);
            return "Helmet lvl 1";
        }

        if (s.contains("Helmet_Lv3") && getConfig("Helmet 3")) { mTextStroke2.setColor(Color.CYAN);
            return "Helmet lvl 3";
        }

        //Healthkits
        if (s.contains("Pills") && getConfig("PainKiller")) { mTextStroke2.setColor(Color.WHITE);
            return "Painkiller";
        }

        if (s.contains("Injection") && getConfig("Adrenaline")) { mTextStroke2.setColor(Color.WHITE);
            return "Adrenaline";
        }

        if (s.contains("Drink") && getConfig("Energy Drink")) { mTextStroke2.setColor(Color.WHITE);
            return "Energy Drink";
        }

        if (s.contains("Firstaid") && getConfig("FirstAidKit")) { mTextStroke2.setColor(Color.WHITE);
            return "FirstAidKit";
        }

        if (s.contains("Bandage") && getConfig("Bandage")) { mTextStroke2.setColor(Color.WHITE);
            return "Bandage";
        }

        if (s.contains("FirstAidbox") && getConfig("Medkit")) { mTextStroke2.setColor(Color.WHITE);
            return "Medkit";
        }

        //Throwables
        if (s.contains("Grenade_Stun") && getConfig("Stung")) { mTextStroke2.setColor(Color.WHITE);
            return "Stung";
        }

        if (s.contains("Grenade_Shoulei") && getConfig("Grenade")) { mTextStroke2.setColor(Color.RED);
            return "Grenade";
        }

        if (s.contains("Grenade_Smoke") && getConfig("Smoke")) { mTextStroke2.setColor(Color.GRAY);
            return "Smoke";
        }

        if (s.contains("Grenade_Burn") && getConfig("Molotov")) { mTextStroke2.setColor(Color.RED);
            return "Molotov";
        }


        //others
        if (s.contains("Large_FlashHider") && getConfig("Flash Hider Ar")) { mTextStroke2.setColor(Color.WHITE);
            return "Flash Hider Ar";
        }

        if (s.contains("QK_Large_C") && getConfig("Ar Compensator")) { mTextStroke2.setColor(Color.WHITE);
            return "Ar Compensator";
        }

        if (s.contains("Mid_FlashHider") && getConfig("Flash Hider SMG")) { mTextStroke2.setColor(Color.WHITE);
            return "Flash Hider SMG";
        }

        if (s.contains("QT_A_") && getConfig("Tactical Stock")) { mTextStroke2.setColor(Color.WHITE);
            return "Tactical Stock";
        }

        if (s.contains("DuckBill") && getConfig("Duckbill")) { mTextStroke2.setColor(Color.WHITE);
            return "DuckBill";
        }

        if (s.contains("Sniper_FlashHider") && getConfig("Flash Hider Snp")) { mTextStroke2.setColor(Color.WHITE);
            return "Flash Hider Sniper";
        }

        if (s.contains("Mid_Suppressor") && getConfig("Suppressor SMG")) { mTextStroke2.setColor(Color.WHITE);
            return "Suppressor SMG";
        }

        if (s.contains("HalfGrip") && getConfig("Half Grip")) { mTextStroke2.setColor(Color.WHITE);
            return "Half Grip";
        }


        if (s.contains("Choke") && getConfig("Choke")) { mTextStroke2.setColor(Color.WHITE);
            return "Choke";
        }

        if (s.contains("QT_UZI") && getConfig("Stock Micro UZI")) { mTextStroke2.setColor(Color.WHITE);
            return "Stock Micro UZI";
        }

        if (s.contains("QK_Sniper") && getConfig("SniperCompensator")) { mTextStroke2.setColor(Color.WHITE);
            return "Sniper Compensator";
        }

        if (s.contains("Sniper_Suppressor") && getConfig("Sup Sniper")) { mTextStroke2.setColor(Color.WHITE);
            return "Suppressor Sniper";
        }

        if (s.contains("Large_Suppressor") && getConfig("Suppressor Ar")) { mTextStroke2.setColor(Color.WHITE);
            return "Suppressor Ar";
        }


        if (s.contains("Sniper_EQ_") && getConfig("Ex.Qd.Sniper")) { mTextStroke2.setColor(Color.WHITE);
            return "Ex.Qd.Sniper";
        }

        if (s.contains("Mid_Q_") && getConfig("Qd.SMG")) { mTextStroke2.setColor(Color.WHITE);
            return "Qd.SMG";
        }

        if (s.contains("Mid_E_") && getConfig("Ex.SMG")) { mTextStroke2.setColor(Color.WHITE);
            return "Ex.SMG";
        }

        if (s.contains("Sniper_Q_") && getConfig("Qd.Sniper")) { mTextStroke2.setColor(Color.WHITE);
            return "Qd.Sniper";
        }

        if (s.contains("Sniper_E_") && getConfig("Ex.Sniper")) { mTextStroke2.setColor(Color.WHITE);
            return "Ex.Sniper";
        }

        if (s.contains("Large_E_") && getConfig("Ex.Ar")) { mTextStroke2.setColor(Color.WHITE);
            return "Ex.Ar";
        }

        if (s.contains("Large_EQ_") && getConfig("Ex.Qd.Ar")) { mTextStroke2.setColor(Color.WHITE);
            return "Ex.Qd.Ar";
        }

        if (s.contains("Large_Q_") && getConfig("Qd.Ar")) { mTextStroke2.setColor(Color.WHITE);
            return "Qd.Ar";
        }

        if (s.contains("Mid_EQ_") && getConfig("Ex.Qd.SMG")) { mTextStroke2.setColor(Color.WHITE);
            return "Ex.Qd.SMG";
        }

        if (s.contains("Crossbow_Q") && getConfig("Quiver CrossBow")) { mTextStroke2.setColor(Color.WHITE);
            return "Quiver CrossBow";
        }

        if (s.contains("ZDD_Sniper") && getConfig("Bullet Loop")) { mTextStroke2.setColor(Color.WHITE);
            return "Bullet Loop";
        }


        if (s.contains("ThumbGrip") && getConfig("Thumb Grip")) { mTextStroke2.setColor(Color.WHITE);
            return "Thumb Grip";
        }

        if (s.contains("Lasersight") && getConfig("Laser Sight")) { mTextStroke2.setColor(Color.WHITE);
            return "Laser Sight";
        }

        if (s.contains("Angled") && getConfig("Angled Grip")) { mTextStroke2.setColor(Color.WHITE);
            return "Angled Grip";
        }

        if (s.contains("LightGrip") && getConfig("Light Grip")) { mTextStroke2.setColor(Color.WHITE);
            return "Light Grip";
        }

        if (s.contains("Vertical") && getConfig("Vertical Grip")) { mTextStroke2.setColor(Color.WHITE);
            return "Vertical Grip";
        }

        if (s.contains("GasCan") && getConfig("Gas Can")) { mTextStroke2.setColor(Color.WHITE);
            return "Gas Can";
        }

        if (s.contains("Mid_Compensator") && getConfig("Compensator SMG")) { mTextStroke2.setColor(Color.WHITE);
            return "Compensator SMG";
        }


        //special
        if (s.contains("Flare") && getConfig("Flare Gun")) { mTextStroke2.setColor(Color.BLUE);
            return "Flare Gun";
        }

        if (s.contains("Ghillie") && getConfig("Ghillie Suit")) { mTextStroke2.setColor(Color.BLUE);
            return "Ghillie Suit";
        }
        if (s.contains("CheekPad") && getConfig("CheekPad")) { mTextStroke2.setColor(Color.BLUE);
            return "CheekPad";
        }
        if ( s.contains("PickUpListWrapperActor") && getConfig("Crate")) { mTextStroke2.setColor(Color.BLUE);
            return "Crate";
        }
        if ((s.contains("AirDropPlane") )&& getConfig("DropPlane")) { mTextStroke2.setColor(Color.BLUE);
            return "DropPlane";
        }
        if ((s.contains("AirDrop")  )&& getConfig("AirDrop")) { mTextStroke2.setColor(Color.BLUE);
            return "AirDrop";
        }
        //return s;
        return null;

    }
    private String getWeapon(int id){
        if(id==101006)
            return "AUG";

        if(id==101008)
            return "M762" ;

        if(id==101003)
            return "SCAR-L";

        if(id==101004)
            return "M416";

        if(id==101002)
            return "M16A-4";

        if(id==101009)
            return "Mk47 Mutant";

        if(id==101010)
            return "G36C";

        if(id==101007)
            return "QBZ";

        if(id==101001)
            return "AKM";

        if(id==101005)
            return "Groza";

        if(id==102005)
            return "Bizon";

        if(id==102004)
            return "TommyGun";

        if(id==102007)
            return "MP5K";

        if(id==102002)
            return "UMP";

        if(id==102003)
            return "Vector";

        if(id==102001)
            return "Uzi";

        if(id==105002)
            return "DP28";

        if(id==105001)
            return "M249";

        //snipers

        if(id==103003)
            return "AWM";

        if(id==103010)
            return "QBU";

        if(id==103009)
            return "SLR";

        if(id==103004)
            return "SKS";

        if(id==103006)
            return "Mini14";

        if(id==103002)
            return "M24";

        if(id==103001)
            return "Kar98k";

        if(id==103005)
            return "VSS";

        if(id==103008)
            return "Win94";

        if(id==103007)
            return "Mk14";

//shotguns and hand weapons
        if(id==104003)
            return "S12K";

        if(id==104004)
            return "DBS";

        if(id==104001)
            return "S686";

        if(id==104002)
            return "S1897";

        if(id==108003)
            return "Sickle";

        if(id==108001)
            return "Machete";

        if(id==108002)
            return "Crowbar";

        if(id==107001)
            return "CrossBow";

        if(id==108004)
            return "Pan";

        //pistols

        if(id==106006)
            return "SawedOff";

        if(id==106003)
            return "R1895";

        if(id==106008)
            return "Vz61";

        if(id==106001)
            return "P92";

        if(id==106004)
            return "P18C";

        if(id==106005)
            return "R45";

        if(id==106002)
            return "P1911";

        if(id==106010)
            return "DesertEagle";

        return null;

    }
    private String getVehicleName(String s){
        if(s.contains("Buggy") && getConfig("Buggy"))
            return "Buggy";

        if(s.contains("UAZ") && getConfig("UAZ"))
            return "UAZ";

        if(s.contains("MotorcycleC") && getConfig("Trike") )
            return "Trike";

        if(s.contains("Motorcycle") && getConfig("Bike"))
            return "Bike";

        if(s.contains("Dacia") && getConfig("Dacia"))
            return "Dacia";

        if(s.contains("AquaRail") && getConfig("Jet"))
            return "Jet";

        if(s.contains("PG117") && getConfig("Boat"))
            return "Boat";

        if(s.contains("MiniBus") && getConfig("Bus"))
            return "Bus";

        if(s.contains("Mirado") && getConfig("Mirado"))
            return "Mirado";

        if(s.contains("Scooter") && getConfig("Scooter"))
            return "Scooter";

        if(s.contains("Rony") && getConfig("Rony"))
            return "Rony";

        if(s.contains("Snowbike") && getConfig("Snowbike"))
            return "Snowbike";

        if(s.contains("Snowmobile") && getConfig("Snowmobile"))
            return "Snowmobile";

        if(s.contains("Tuk") && getConfig("Tempo"))
            return "Tempo";

        if(s.contains("PickUp") && getConfig("Truck"))
            return "Truck";

        if(s.contains("BRDM") && getConfig("BRDM"))
            return "BRDM";

        if(s.contains("LadaNiva") && getConfig("LadaNiva"))
            return "LadaNiva";

        if(s.contains("Bigfoot") && getConfig("Monster Truck"))
            return "Monster Truck";

        return "";
    }
        public String getItemName(int id) {
        //Scopes
        if (id == 203005 && getConfig("8x")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "8x";
        }

        if (id == 203003 && getConfig("2x")) { mTextPaint.setARGB(255, 230, 172, 226);
            return "2x";
        }

        if (id == 203001 && getConfig("Red Dot")) { mTextPaint.setARGB(255, 230, 172, 226);
            return "Red Dot";
        }

        if (id == 203014 && getConfig("3x")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "3X";
        }

        if (id == 203002 && getConfig("Hollow")) { mTextPaint.setARGB(255, 153, 75, 152);
            return "Hollow Sight";
        }

        if (id == 203015 && getConfig("6x")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "6x";
        }

        if (id == 203004 && getConfig("4x")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "4x";
        }

        if (id == 203018 && getConfig("Canted")) { mTextPaint.setARGB(255, 153, 75, 152);
            return "Canted Sight";
        }


        //AR and smg
        if (id == 101006 && getConfig("AUG")) { mTextPaint.setARGB(255, 52, 224, 63);
            return "AUG";
        }

        if (id == 101008 && getConfig("M762")) { mTextPaint.setARGB(255, 43, 26, 28);
            return "M762";
        }

        if (id == 101003 && getConfig("SCAR-L")) { mTextPaint.setARGB(255, 52, 224, 63);
            return "SCAR-L";
        }

        if (id == 101004 && getConfig("M416")) { mTextPaint.setARGB(255, 115, 235, 223);
            return "M416";
        }

        if (id == 101002 && getConfig("M16A4")) { mTextPaint.setARGB(255, 116, 227, 123);
            return "M16A-4";
        }

        if (id == 101009 && getConfig("Mk47 Mutant")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "Mk47 Mutant";
        }

        if (id == 101010 && getConfig("G36C")) { mTextPaint.setARGB(255, 116, 227, 123);
            return "G36C";
        }

        if (id == 101007 && getConfig("QBZ")) { mTextPaint.setARGB(255, 52, 224, 63);
            return "QBZ";
        }

        if (id == 101001 && getConfig("AKM")) { mTextPaint.setARGB(255, 43, 26, 28);
            return "AKM";
        }

        if (id == 101005 && getConfig("Groza")) { mTextPaint.setARGB(255, 43, 26, 28);
            return "Groza";
        }

        if (id == 102005 && getConfig("Bizon")) { mTextPaint.setARGB(255, 255, 246, 0);
            return "Bizon";
        }

        if (id == 102004 && getConfig("TommyGun")) { mTextPaint.setARGB(255, 207, 207, 207);
            return "TommyGun";
        }

        if (id == 102007 && getConfig("MP5K")) { mTextPaint.setARGB(255, 207, 207, 207);
            return "MP5K";
        }

        if (id == 102002 && getConfig("UMP")) { mTextPaint.setARGB(255, 207, 207, 207);
            return "UMP";
        }

        if (id == 102003 && getConfig("Vector")) { mTextPaint.setARGB(255, 255, 246, 0);
            return "Vector";
        }

        if (id == 102001 && getConfig("Uzi")) { mTextPaint.setARGB(255, 255, 246, 0);
            return "Uzi";
        }

        if (id == 105002 && getConfig("DP28")) { mTextPaint.setARGB(255, 43, 26, 28);
            return "DP28";
        }

        if (id == 105001 && getConfig("M249")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "M249";
        }

        //snipers

        if (id == 103003 && getConfig("AWM")) { mTextPaint.setColor(Color.BLACK);
            return "AWM";
        }

        if (id == 103010 && getConfig("QBU")) { mTextPaint.setARGB(255, 207, 207, 207);
            return "QBU";
        }

        if (id == 103009 && getConfig("SLR")) { mTextPaint.setARGB(255, 43, 26, 28);
            return "SLR";
        }

        if (id == 103004 && getConfig("SKS")) { mTextPaint.setARGB(255, 43, 26, 28);
            return "SKS";
        }

        if (id == 103006 && getConfig("Mini14")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "Mini14";
        }

        if (id == 103002 && getConfig("M24")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "M24";
        }

        if (id == 103001 && getConfig("Kar98k")) { mTextPaint.setARGB(255, 247, 99, 245);
            return "Kar98k";
        }

        if (id == 103005 && getConfig("VSS")) { mTextPaint.setARGB(255, 255, 246, 0);
            return "VSS";
        }

        if (id == 103008 && getConfig("Win94")) { mTextPaint.setARGB(255, 207, 207, 207);
            return "Win94";
        }

        if (id == 103007 && getConfig("Mk14")) { mTextPaint.setColor(Color.BLACK);
            return "Mk14";
        }

//shotguns and hand weapons
        if (id == 104003 && getConfig("S12K")) { mTextPaint.setARGB(255, 153, 109, 109);
            return "S12K";
        }

        if (id == 104004 && getConfig("DBS")) { mTextPaint.setARGB(255, 153, 109, 109);
            return "DBS";
        }

        if (id == 104001 && getConfig("S686")) { mTextPaint.setARGB(255, 153, 109, 109);
            return "S686";
        }

        if (id == 104002 && getConfig("S1897")) { mTextPaint.setARGB(255, 153, 109, 109);
            return "S1897";
        }

        if (id == 108003 && getConfig("Sickle")) { mTextPaint.setARGB(255, 102, 74, 74);
            return "Sickle";
        }

        if (id == 108001 && getConfig("Machete")) { mTextPaint.setARGB(255, 102, 74, 74);
            return "Machete";
        }

        if (id == 108002 && getConfig("Crowbar")) { mTextPaint.setARGB(255, 102, 74, 74);
            return "Crowbar";
        }

        if (id == 107001 && getConfig("CrossBow")) { mTextPaint.setARGB(255, 102, 74, 74);
            return "CrossBow";
        }

        if (id == 108004 && getConfig("Pan")) { mTextPaint.setARGB(255, 102, 74, 74);
            return "Pan";
        }

        //pistols

        if (id == 106006 && getConfig("SawedOff")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "SawedOff";
        }

        if (id == 106003 && getConfig("R1895")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "R1895";
        }

        if (id == 106008 && getConfig("Vz61")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "Vz61";
        }

        if (id == 106001 && getConfig("P92")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "P92";
        }

        if (id == 106004 && getConfig("P18C")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "P18C";
        }

        if (id == 106005 && getConfig("R45")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "R45";
        }

        if (id == 106002 && getConfig("P1911")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "P1911";
        }

        if (id == 106010 && getConfig("Desert Eagle")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "DesertEagle";
        }


        //Ammo
        if (id == 302001 && getConfig("7.62")) { mTextPaint.setARGB(255, 92, 36, 28);
            return "7.62";
        }

        if (id == 305001 && getConfig("45ACP")) { mTextPaint.setColor(Color.LTGRAY);
            return "45ACP";
        }

        if (id == 303001 && getConfig("5.56")) { mTextPaint.setColor(Color.GREEN);
            return "5.56";
        }

        if (id == 301001 && getConfig("9mm")) { mTextPaint.setColor(Color.YELLOW);
            return "9mm";
        }

        if (id == 306001 && getConfig("300Magnum")) { mTextPaint.setColor(Color.BLACK);
            return "300Magnum";
        }

        if (id == 304001 && getConfig("12 Guage")) { mTextPaint.setARGB(255, 156, 91, 81);
            return "12 Guage";
        }

        if (id == 307001 && getConfig("Arrow")) { mTextPaint.setARGB(255, 156, 113, 81);
            return "Arrow";
        }

        //bag helmet vest
        if ((id == 501006 || id == 501003) && getConfig("Bag L 3")) { mTextPaint.setARGB(255, 36, 83, 255);
            return "Bag lvl 3";
        }

        if ((id == 501004 || id == 501001) && getConfig("Bag L 1")) { mTextPaint.setARGB(255, 127, 154, 250);
            return "Bag lvl 1";
        }

        if ((id == 501005 || id == 501002) && getConfig("Bag L 2")) { mTextPaint.setARGB(255, 77, 115, 255);
            return "Bag lvl 2";
        }

        if (id == 503002 && getConfig("Vest L 2")) { mTextPaint.setARGB(255, 77, 115, 255);
            return "Vest lvl 2";
        }


        if (id == 503001 && getConfig("Vest L 1")) { mTextPaint.setARGB(255, 127, 154, 250);
            return "Vest lvl 1";
        }


        if (id == 503003 && getConfig("Vest L 3")) { mTextPaint.setARGB(255, 36, 83, 255);
            return "Vest lvl 3";
        }


        if (id == 502002 && getConfig("Helmet 2")) { mTextPaint.setARGB(255, 77, 115, 255);
            return "Helmet lvl 2";
        }

        if (id == 502001 && getConfig("Helmet 1")) { mTextPaint.setARGB(255, 127, 154, 250);
            return "Helmet lvl 1";
        }

        if (id == 502003 && getConfig("Helmet 3")) { mTextPaint.setARGB(255, 36, 83, 255);
            return "Helmet lvl 3";
        }

        //Healthkits
        if (id == 601003 && getConfig("PainKiller")) { mTextPaint.setARGB(255, 227, 91, 54);
            return "Painkiller";
        }

        if (id == 601002 && getConfig("Adrenaline")) { mTextPaint.setARGB(255,204, 193, 190);
            return "Adrenaline";
        }

        if (id == 601001 && getConfig("Energy Drink")) { mTextPaint.setARGB(255, 54, 175, 227);
            return "Energy Drink";
        }

        if (id == 601005 && getConfig("FirstAidKit")) { mTextPaint.setARGB(255, 194, 188, 109);
            return "FirstAidKit";
        }

        if (id == 601004 && getConfig("Bandage")) { mTextPaint.setARGB(255, 43, 189, 48);
            return "Bandage";
        }

        if (id == 601006 && getConfig("Medkit")) { mTextPaint.setARGB(255, 0, 171, 6);
            return "Medkit";
        }

        //Throwables
        if (id == 602001 && getConfig("Stung")) { mTextPaint.setARGB(255,204, 193, 190);
            return "Stung";
        }

        if (id == 602004 && getConfig("Grenade")) { mTextPaint.setARGB(255, 2, 77, 4);
            return "Grenade";
        }

        if (id == 602002 && getConfig("Smoke")) { mTextPaint.setColor(Color.WHITE);
            return "Smoke";
        }

        if (id == 602003 && getConfig("Molotov")) { mTextPaint.setARGB(255, 230, 175, 64);
            return "Molotov";
        }


        //others
        if (id == 201010 && getConfig("Flash Hider Ar")) { mTextPaint.setARGB(255, 255, 213, 130);
            return "Flash Hider Ar";
        }

        if (id == 201009 && getConfig("Ar Compensator")) { mTextPaint.setARGB(255, 255, 213, 130);
            return "Ar Compensator";
        }

        if (id == 201004 && getConfig("Flash Hider SMG")) { mTextPaint.setARGB(255, 255, 213, 130);
            return "Flash Hider SMG";
        }

        if (id == 205002 && getConfig("Tactical Stock")) { mTextPaint.setARGB(255, 158, 222, 195);
            return "Tactical Stock";
        }

        if (id == 201012 && getConfig("Duckbill")) { mTextPaint.setARGB(255, 158, 222, 195);
            return "Duckbill";
        }

        if (id == 201005 && getConfig("Flash Hider Snp")) { mTextPaint.setARGB(255, 158, 222, 195);
            return "Flash Hider Sniper";
        }

        if (id == 201006 && getConfig("Suppressor SMG")) { mTextPaint.setARGB(255, 158, 222, 195);
            return "Suppressor SMG";
        }

        if (id == 205003 && getConfig("Half Grip")) { mTextPaint.setARGB(255, 155, 189, 222);
            return "Half Grip";
        }

        if (id == 202005 && getConfig("Half Grip")) { mTextPaint.setARGB(255, 155, 189, 222);
            return "Half Grip";
        }

        if (id == 201001 && getConfig("Choke")) { mTextPaint.setARGB(255, 155, 189, 222);
            return "Choke";
        }

        if (id == 205001 && getConfig("Stock Micro UZI")) { mTextPaint.setARGB(255, 155, 189, 222);
            return "Stock Micro UZI";
        }

        if (id == 201003 && getConfig("SniperCompensator")) { mTextPaint.setARGB(255, 60, 127, 194);
            return "Sniper Compensator";
        }

        if (id == 201007 && getConfig("Sup Sniper")) { mTextPaint.setARGB(255, 60, 127, 194);
            return "Suppressor Sniper";
        }

        if (id == 201011 && getConfig("Suppressor Ar")) { mTextPaint.setARGB(255, 60, 127, 194);
            return "Suppressor Ar";
        }


        if (id == 204009 && getConfig("Ex.Qd.Sniper")) { mTextPaint.setARGB(255, 193, 140, 222);
            return "Ex.Qd.Sniper";
        }

        if (id == 204005 && getConfig("Qd.SMG")) { mTextPaint.setARGB(255, 193, 163, 209);
            return "Qd.SMG";
        }

        if (id == 204004 && getConfig("Ex.SMG")) { mTextPaint.setARGB(255, 193, 163, 209);
            return "Ex.SMG";
        }

        if (id == 204008 && getConfig("Qd.Sniper")) { mTextPaint.setARGB(255, 193, 163, 209);
            return "Qd.Sniper";
        }

        if (id == 204007 && getConfig("Ex.Sniper")) { mTextPaint.setARGB(255, 193, 163, 209);
            return "Ex.Sniper";
        }

        if (id == 204011 && getConfig("Ex.Ar")) { mTextPaint.setARGB(255, 193, 163, 209);
            return "Ex.Ar";
        }

        if (id == 204013 && getConfig("Ex.Qd.Ar")) { mTextPaint.setARGB(255, 193, 140, 222);
            return "Ex.Qd.Ar";
        }

        if (id == 204012 && getConfig("Qd.Ar")) { mTextPaint.setARGB(255, 193, 163, 209);
            return "Qd.Ar";
        }

        if (id == 204006 && getConfig("Ex.Qd.SMG")) { mTextPaint.setARGB(255, 193, 140, 222);
            return "Ex.Qd.SMG";
        }

        if (id == 205004 && getConfig("Quiver CrossBow")) { mTextPaint.setARGB(255, 148, 121, 163);
            return "Quiver CrossBow";
        }

        if (id == 204014 && getConfig("Bullet Loop")) { mTextPaint.setARGB(255, 148, 121, 163);
            return "Bullet Loop";
        }


        if (id == 202006 && getConfig("Thumb Grip")) { mTextPaint.setARGB(255, 148, 121, 163);
            return "Thumb Grip";
        }

        if (id == 202007 && getConfig("Laser Sight")) { mTextPaint.setARGB(255, 148, 121, 163);
            return "Laser Sight";
        }

        if (id == 202001 && getConfig("Angled Grip")) { mTextPaint.setARGB(255, 219, 219, 219);
            return "Angled Grip";
        }

        if (id == 202004 && getConfig("Light Grip")) { mTextPaint.setARGB(255, 219, 219, 219);
            return "Light Grip";
        }

        if (id == 202002 && getConfig("Vertical Grip")) { mTextPaint.setARGB(255, 219, 219, 219);
            return "Vertical Grip";
        }

        if (id == 603001 && getConfig("Gas Can")) { mTextPaint.setARGB(255, 255, 143, 203);
            return "Gas Can";
        }

        if (id == 201002 && getConfig("Compensator SMG")) { mTextPaint.setARGB(255, 219, 219, 219);
            return "Compensator SMG";
        }

        //special
        if ((id == 106007 || id == 308001) && getConfig("Flare Gun")) { mTextPaint.setARGB(255, 242, 63, 159);
            return "Flare Gun";
        }

        if ((id == 403989 || id == 403045 || id == 403187 || id == 403188) && getConfig("Gullie Suit")) { mTextPaint.setARGB(255, 139, 247, 67);
            return "Gullie Suit";
        }
        if(id==103011 && getConfig("Mosin")) { mTextPaint.setARGB(255, 36, 83, 255);
            return "Mosin";
        }
        if(id==107005 && getConfig("PanzerFaust")) { mTextPaint.setARGB(255, 36, 83, 255);
            return "PanzerFaust";
        }
        return "";
        // return String.valueOf(id);

    }
    }
    

