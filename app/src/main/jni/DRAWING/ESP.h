#ifndef JEEL_PATEL_DRAWING_H
#define JEEL_PATEL_DRAWING_H
#include "struct.h"

class ESP
{
  private:
	JNIEnv * _env;
	jobject _cvsView;
	jobject _cvs;


  public:
	  ESP()
	{
		_env = nullptr;
		_cvsView = nullptr;
		_cvs = nullptr;
	}

	ESP(JNIEnv * env, jobject cvsView, jobject cvs)
	{
		this->_env = env;
		this->_cvsView = cvsView;
		this->_cvs = cvs;
	}

	bool isValid() const
	{
		return (_env != nullptr && _cvsView != nullptr && _cvs != nullptr);
	}

	int getWidth() const
	{
		if (isValid())
		{
			jclass canvas = _env->GetObjectClass(_cvs);
			jmethodID width = _env->GetMethodID(canvas, "getWidth", "()I");
			  return _env->CallIntMethod(_cvs, width);
		}
		return 0;
	}

	int getHeight() const
	{
		if (isValid())
		{
			jclass canvas = _env->GetObjectClass(_cvs);
			jmethodID width = _env->GetMethodID(canvas, "getHeight", "()I");
			  return _env->CallIntMethod(_cvs, width);
		}
		return 0;
	}

	void CanvasDrawLine(Color color, float thickness, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawLine",
												   "(Landroid/graphics/Canvas;IIIIFFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b,
								 thickness, start.x, start.y, end.x, end.y);
		}
	}

	void CanvasDrawLineBot(Color color, float thickness, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawlinebot = _env->GetMethodID(canvasView, "CanvasDrawLineBot",
													  "(Landroid/graphics/Canvas;IIIIFFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawlinebot, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b,
								 thickness, start.x, start.y, end.x, end.y);
		}
	}

	void CanvasDrawSkeleton(Color color, float thickness, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawskeleton = _env->GetMethodID(canvasView, "CanvasDrawSkeleton",
													   "(Landroid/graphics/Canvas;IIIIFFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawskeleton, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b,
								 thickness, start.x, start.y, end.x, end.y);
		}
	}

	void CanvasDrawRect(Color color, float thickness, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawRect",
												   "(Landroid/graphics/Canvas;IIIIFFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b,
								 thickness, start.x, start.y, end.x, end.y);
		}
	}

	void CanvasDrawRect2(Color color, float thickness, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawRect2",
												   "(Landroid/graphics/Canvas;IIIIFFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b,
								 thickness, start.x, start.y, end.x, end.y);
		}
	}

	void CanvasDrawFilledRect3(Color color, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawFilledRect3",
												   "(Landroid/graphics/Canvas;IIIIFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, start.x, start.y, end.x, end.y);
		}
	}


	void CanvasDrawBox(Color color, float thickness, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawBox",
												   "(Landroid/graphics/Canvas;IIIIFFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b,
								 thickness, start.x, start.y, end.x, end.y);
		}
	}
	void CanvasDrawBox1(Color color, float stroke, Rect rect)
	{
		Vector22 v1 = Vector22(rect.x, rect.y);
		Vector22 v2 = Vector22(rect.x + rect.width, rect.y);
		Vector22 v3 = Vector22(rect.x + rect.width, rect.y + rect.height);
		Vector22 v4 = Vector22(rect.x, rect.y + rect.height);

		CanvasDrawBox(color, stroke, v1, v2);
		CanvasDrawBox(color, stroke, v2, v3);
		CanvasDrawBox(color, stroke, v3, v4);
		CanvasDrawBox(color, stroke, v4, v1);
	}

	void CanvasDrawFilledRect(Color color, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawFilledRect",
												   "(Landroid/graphics/Canvas;IIIIFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, start.x, start.y, end.x, end.y);
		}
	}

	void CanvasDrawFilledRect2(Color color, Vector22 start, Vector22 end)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawFilledRect2",
												   "(Landroid/graphics/Canvas;IIIIFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, start.x, start.y, end.x, end.y);
		}
	}

	void DebugText(char *s)
	{
		jclass cls = _env->GetObjectClass(_cvsView);
		jmethodID mid = _env->GetMethodID(cls, "DebugText", "(Ljava/lang/String;)V");
		jstring name = _env->NewStringUTF(s);
		_env->CallVoidMethod(_cvsView, mid, name);
		_env->DeleteLocalRef(name);
	}

    void CanvasDrawTextNormal(Color color, const char *txt, Vector22 pos, float size)
    {
        if (isValid())
        {
            jclass canvasView = _env->GetObjectClass(_cvsView);
            jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawTextNormal",
                                                   "(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");
            jstring s = _env->NewStringUTF(txt);
            _env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int)color.a, (int)color.r,
                                 (int)color.g, (int)color.b, s, pos.x, pos.y, size);
            _env->DeleteLocalRef(s);
        }
	}
	void CanvasDrawText(Color color, const char *txt, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawText",
												   "(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, s, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}
	void CanvasDrawPoint(Color color, Vector22 pos, float radius)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawfilledcircle = _env->GetMethodID(canvasView, "CanvasDrawPoint",
														   "(Landroid/graphics/Canvas;IIIIFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawfilledcircle, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, pos.x, pos.y, radius);
		}
	}
	void CanvasDrawTextDistance(Color color, const char *txt, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtextdistance = _env->GetMethodID(canvasView, "CanvasDrawTextDistance",
														   "(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtextdistance, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, s, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}

	void CanvasDrawTextName(Color color, const char *txt, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawTextName",
												   "(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, s, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}

	void CanvasDrawTextAltert(Color color, const char *txt, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtextalert = _env->GetMethodID(canvasView, "CanvasDrawTextAltert",
														"(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtextalert, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, s, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}
	void CanvasDrawTextAltert2(Color color, const char *txt, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtextalert = _env->GetMethodID(canvasView, "CanvasDrawTextAltert2",
														"(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtextalert, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, s, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}

	void CanvasDrawWeapon(Color color, int wid,int ammo, Vector22 pos, float size) {
        if (isValid()) {
            jclass canvasView = _env->GetObjectClass(_cvsView);
            jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawWeapon",
                                                   "(Landroid/graphics/Canvas;IIIIIIFFF)V");
            _env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int) color.a, (int) color.r,
                                 (int) color.g, (int) color.b,
                                 wid,ammo, pos.x, pos.y, size);
        }
    }
	void CanvasDrawName(Color color, const char *txt, int teamid, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawName",
												   "(Landroid/graphics/Canvas;IIIILjava/lang/String;IFFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, s, teamid, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}
	   
	void CanvasDrawName2(Color color, const char *txt,int teamid,Vector22 pos, float size) {
        if (isValid()) {
            jclass canvasView = _env->GetObjectClass(_cvsView);
            jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawName2",
                                                   "(Landroid/graphics/Canvas;IIIILjava/lang/String;IFFF)V");
            jstring s=_env->NewStringUTF(txt);
            _env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int) color.a, (int) color.r,
                                 (int) color.g, (int) color.b,
                                 s,teamid, pos.x, pos.y, size);
            _env->DeleteLocalRef(s);
        }
    } 
    void CanvasDrawName3(Color color, const char *txt,Vector22 pos, float size) {
        if (isValid()) {
            jclass canvasView = _env->GetObjectClass(_cvsView);
            jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawName3",
                                                   "(Landroid/graphics/Canvas;IIIILjava/lang/String;IFFF)V");
            jstring s=_env->NewStringUTF(txt);
            _env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int) color.a, (int) color.r,
                                 (int) color.g, (int) color.b,
                                 s,pos.x, pos.y, size);
            _env->DeleteLocalRef(s);
        }
    } 
	void CanvasDrawName4(Color color, const char *txt,Vector22 pos, float size) {
        if (isValid()) {
            jclass canvasView = _env->GetObjectClass(_cvsView);
            jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawName4",
                                                   "(Landroid/graphics/Canvas;IIIILjava/lang/String;IFFF)V");
            jstring s=_env->NewStringUTF(txt);
            _env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int) color.a, (int) color.r,
                                 (int) color.g, (int) color.b,
                                 s, pos.x, pos.y, size);
            _env->DeleteLocalRef(s);
        }
    } 
	
	void CanvasDrawVehicles(const char *txt, float distance, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawVehicles",
												   "(Landroid/graphics/Canvas;Ljava/lang/String;FFFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, s, distance, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}
	void CanvasDrawFilledCircle(Color color, Vector22 pos, float radius)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawfilledcircle = _env->GetMethodID(canvasView, "CanvasDrawFilledCircle",
														   "(Landroid/graphics/Canvas;IIIIFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawfilledcircle, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, pos.x, pos.y, radius);
		}
	}
	void CanvasDrawHead(Color color, Vector22 pos, float radius)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawhead = _env->GetMethodID(canvasView, "CanvasDrawHead",
												   "(Landroid/graphics/Canvas;IIIIFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawhead, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, pos.x, pos.y, radius);
		}
	}

	void CanvasDrawOTH(Vector22 start, int num)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawline = _env->GetMethodID(canvasView, "CanvasDrawOTH",
												   "(Landroid/graphics/Canvas;IFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawline, _cvs, num, start.x, start.y);
		}
	}


	void CanvasDrawCircle(Color color, Vector22 pos, float radius, float thickness)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawcircle = _env->GetMethodID(canvasView, "CanvasDrawCircle",
													 "(Landroid/graphics/Canvas;IIIIFFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawcircle, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, pos.x, pos.y, radius, thickness);
		}
	}

	void CanvasDrawCircle2(Color color, Vector22 pos, float radius)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawCircle = _env->GetMethodID(canvasView, "CanvasDrawCircle2",
													 "(Landroid/graphics/Canvas;IIIIFFF)V");
			_env->CallVoidMethod(_cvsView, canvasdrawCircle, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, pos.x, pos.y, radius);
		}
	}
	void CanvasDrawText3(Color color, const char *txt, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawText3",
												   "(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, (int)color.a, (int)color.r,
								 (int)color.g, (int)color.b, s, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}
	void CanvasDrawItems(const char *txt, float distance, Vector22 pos, float size)
	{
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID canvasdrawtext = _env->GetMethodID(canvasView, "CanvasDrawItems",
												   "(Landroid/graphics/Canvas;Ljava/lang/String;FFFF)V");
			jstring s = _env->NewStringUTF(txt);
			_env->CallVoidMethod(_cvsView, canvasdrawtext, _cvs, s, distance, pos.x, pos.y, size);
			_env->DeleteLocalRef(s);
		}
	}
	void CanvasDrawItemByID(int itemID, float distance, Vector22 pos, float size) {
		if (isValid())
		{
			jclass canvasView = _env->GetObjectClass(_cvsView);
			jmethodID drawitemid = _env->GetMethodID(canvasView, "DrawItemsByID",
													 "(Landroid/graphics/Canvas;IFFFF)V");
			_env->CallVoidMethod(_cvsView, drawitemid, _cvs,
								 itemID,distance, pos.x, pos.y, size);
		}
	}
    
};


#endif // JEEL_PATEL_DRAWING_H
