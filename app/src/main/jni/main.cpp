#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include "DRAWING/ESP.h"
#include "DRAWING/Hacks.h"
#include "Logger.h"
#include "Config.h"
#define SOCKET_NAME "\0andyougo"
#include <HOOK/Includes/Utils.h>
#if defined(__aarch64__)
#include <HOOK/And64InlineHook/And64InlineHook.hpp>
#else
#include <HOOK/Substrate/SubstrateHook.h>
#include <HOOK/Substrate/CydiaSubstrate.h>
#endif
#include "HOOK/KittyMemory/MemoryPatch.h"
#include "HOOK/Includes/Logger.h"
#include "HOOK/Includes/Utils.h"
using namespace std;
struct My_Patches {
    MemoryPatch
            Bypass,
            Bypass1,
            Bypass2,
            Bypass3,
            Bypass4,
            Bypass5,
            Bypass6,
            Bypass7,
            Bypass8,
            Bypass9,
            Bypass10,
            Bypass11,
            Bypass12,
            Bypass13,
            Bypass14,
            Bypass15,
            Bypass16,
            Bypass17,
            Bypass18,
            Bypass19,
            Bypass20,
            Bypass21,
            Bypass22,
            Bypass23,
            Bypass24,
            Bypass25,
            Bypass26,
            Bypass27,
            Bypass28,
            Bypass29,
            Bypass30,
            Bypass31,
            Bypass32,
            Bypass33,
            Bypass34,
            Bypass35,
            Bypass36,
            Bypass37,
            Bypass38,
            Bypass39,
            Bypass40,
            Bypass41,
            Bypass42,
            Bypass43,
            Bypass44,
            Bypass45,
            Bypass46,
            Bypass47,
            Bypass48,
            Bypass49,
            Bypass50,
            Bypass51,
            Bypass52,
            Bypass53,
            Bypass54,
            Bypass55,
            Bypass56,
            Bypass57,
            Bypass58,
            Bypass59,
            Bypass60,
            Bypass61,
            Bypass62,
            Bypass63,
            Bypass64,
            Bypass65,
            Bypass66,
            Bypass67,
            Bypass68,
            Bypass69,
            Bypass70,
            Bypass71,
            Bypass72,
            Bypass73,
            Bypass74,
            Bypass75,
            Bypass76,
            Bypass77,
            Bypass78,
            Bypass79,
            Bypass80,
            Bypass81,
            Bypass82,
            Bypass83,
            Bypass84,
            Bypass85,
            Bypass86,
            Bypass87,
            Bypass88,
            Bypass89,
            Bypass90,
            Bypass91,
            Bypass92,
            Bypass93,
            Bypass94,
            Bypass95,
            Bypass96,
            Bypass97,
            Bypass98,
            Bypass99,
            Bypass100,
            Bypass101,
            Bypass102,
            Bypass103,
            Bypass104,
            Bypass105,
            Bypass106,
            Bypass107,
            Bypass108,
            Bypass109,
            Bypass110,
            Bypass111,
            Bypass112,
            Bypass113,
            Bypass114,

            Bypass115,
            Bypass116,
            Bypass117,
            Bypass118,
            Bypass119,
            Bypass120,
            Bypass121,
            Bypass122,
            Bypass123,
            Bypass124,
            Bypass125,
            Bypass126,
            Bypass127,
            Bypass128,
            Bypass129,
            Bypass130,
            Bypass131,
            Bypass132,
            Bypass133,
            Bypass134,
            Bypass135,
            Bypass136,
            Bypass137,
            Bypass138,
            Bypass139,
            Bypass140,
            Bypass141,
            Bypass142,
            Bypass143,
            Bypass144,
            Bypass145,
            Bypass146,
            Bypass147,
            Bypass148,
            Bypass149,
            Bypass150,
            Bypass151,
            Bypass152,
            Bypass153,
            Bypass154,
            Bypass155,
            Bypass156,

            Bypass175,
            Bypass176,
            Bypass178,
            Bypass179,
            Bypass180,
            Bypass181,
            Bypass182,
            Bypass183,
            Bypass184,
            Bypass185,
            Bypass186,
            Bypass187,
            Bypass188,
            Bypass189,
            Bypass190,
            Bypass191,
            Bypass192,
            Bypass193,
            Bypass194,
            Bypass195,
            Bypass196,
            Bypass197,
            Bypass198,
            Bypass199,
            Bypass200,
            Bypass201,
            Bypass202,
            Bypass203,
            Bypass204,
            Bypass205,
            Bypass206,
            Bypass207,
            Bypass208,
            Bypass209,
            Bypass210,
            Bypass211,
            Bypass212,
            Bypass213,
            Bypass214,
            Bypass215,
            Bypass216,
            Bypass217,
            Bypass218,
            Bypass219,
            Bypass220,
            Bypass221,
            Bypass222,
            Bypass223,
            Bypass224,
            Bypass225,
            Bypass226,
            Bypass227,
            Bypass228,
            Bypass229,
            Bypass230,
            Bypass231,
            Bypass232,
            Bypass233,
            Bypass234,
            Bypass235,
            Bypass236,
            Bypass237,
            Bypass238,
            Bypass239,
            Bypass240,
            Bypass241,
            Bypass242,
            Bypass243,
            Bypass244,
            Bypass245,
            Bypass246,
            Bypass247,
            Bypass248,
            Bypass249,
            Bypass250,
            Bypass251,
            Bypass252,
            Bypass253,
            Bypass254,
            Bypass255,
            Bypass256,
            Bypass257,
            Bypass258,
            Bypass259,
            Bypass260,
            Bypass261,
            Bypass262,
            Bypass263,
            Bypass264,
            Bypass265,
            Bypass266,
            Bypass267,
            Bypass268,
            Bypass269,
            Bypass270,
            Bypass271,
            Bypass272,
            Bypass273,
            Bypass274,
            Bypass275,
            Bypass276,
            Bypass277,
            Bypass278,
            Bypass279,
            Bypass280,
            Bypass281,
            Bypass282,
            Bypass283,
            Bypass284,
            Bypass285,
            Bypass286,
            Bypass287,
            Bypass288,
            Bypass289,
            Bypass290,
            Bypass291,
            Bypass292,
            Bypass293,
            Bypass294,
            Bypass295,
            Bypass296,
            Bypass297,
            Bypass298,
            Bypass299,
            Bypass300,
            Bypass301,
            Bypass302,
            Bypass303,
            Bypass304,
            Bypass305,
            Bypass306,
            Bypass307,
            Bypass308,
            Bypass309,
            Bypass310,
            Bypass311,
            Bypass312,
            Bypass313,
            Bypass314,
            Bypass315,
            Bypass316,
            Bypass317,
            Bypass318,
            Bypass319,
            Bypass320,
            Bypass321,
            Bypass322,
            flash,
            flash2,
            CarJump,
            Less,
            Small,
            AimLock,
            HIGHView
    ;

} ModMem; bool
        Bypass =false,
        Less = false,
        Small = false,
        FastBulllet = false,
        flash = false,
        CarJump = false,
        AimLock = false,
        HIGHView = false,
        featureHookToggle = false;
void *instanceBtn;
ESP espOverlay;
bool MEMBYPASS = false;
bool BPS = false;
bool BPS2 = false;
bool antiCrash = false;




extern "C"
JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_DrawOn(JNIEnv * env, jclass, jobject espView,
        jobject canvas) {
if (isESP)
{
espOverlay = ESP(env, espView, canvas);
if (espOverlay.isValid())
{
DrawESP(espOverlay, espOverlay.getWidth(), espOverlay.getHeight());
}
}
}

extern "C" {
JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_SettingValue(JNIEnv *, jobject, jint code,
        jboolean jboolean1) {
switch ((int)code)
{
case 0:
isESP = jboolean1;
break;
case 1:
isPlayerBox = jboolean1;
break;
case 2:
isPlayerLine = jboolean1;
break;
case 3:
isPlayerDist = jboolean1;
break;
case 4:
isPlayerHealth = jboolean1;
break;
case 5:
isPlayerName = jboolean1;
break;
case 6:
isPlayerHead = jboolean1;
break;
case 7:
isr360Alert = jboolean1;
break;
case 8:
isSkelton1 = jboolean1;
break;
case 9:
isGrenadeWarning = jboolean1;
break;
case 10:
isEnemyWeapon = jboolean1;
break;
case 11:
aimbot = jboolean1;
if (aimbot != 0)
{
options.openState = 0;
}
else
{
options.openState = -1;
}
break;

case 12:
options.tracingStatus = jboolean1;
break;
case 13:
options.pour = jboolean1;
break;


}
}


extern "C"
JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_Size(JNIEnv * env, jclass type, jint num,
jfloat size) {
switch (num)
{
case 1:
itemSize = size;
break;
case 2:
enemySize = size;
break;
case 3:
vehicleSize = size;
break;
case 4:
fpsRender = size;
break;
case 5:
alertSize = size;
break;
default:
break;
}
}

extern "C"
JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_Protection(JNIEnv *, jobject, jint code,
        jboolean jboolean1) {
switch ((int)code)
{
case 0:
MEMBYPASS = jboolean1;
if (MEMBYPASS) {
} else {
system("rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate/SaveGames/JKGuestRegisterCnt.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
}
break;


case 2: // Fix Crash Root
antiCrash = jboolean1;
if (antiCrash)
{
system("rm -rf /data/data/com.tencent,ig/app_crashrecord"
"touch /data/data/com.tencent,ig/app_crashrecord"
"rm -rf /data/data/com.pubg.krmobile/app_crashrecord"
"touch /data/data/com.pubg.krmobile/app_crashrecord"
"rm -rf /data/data/com.pubg.krmobile/app_crashrecord"
"touch /data/data/com.pubg.krmobile/app_crashrecord"
"rm -rf /data/data/com.pubg.krmobile/app_crashrecord"
"touch /data/data/com.pubg.krmobile/app_crashrecord"
"chmod 000 /data/data/com.pubg.krmobile/files/tss_tmp"
"chmod 000 /data/data/com.pubg.krmobile/files/tss_tmp"
"chmod 000 /data/data/com.pubg.krmobile/files/tss_tmp"
"chmod 000 /data/data/com.pubg.krmobile/files/tss_tmp");
}
else
{
system("rm -rf /data/data/com.tencent,ig/app_crashrecord"
"rm -rf /data/data/com.pubg.krmobile/app_crashrecord"
"rm -rf /data/data/com.pubg.krmobile/app_crashrecord"
"rm -rf /data/data/com.pubg.krmobile/app_crashrecord"
"chmod 777 /data/data/com.pubg.krmobile/files/tss_tmp"
"chmod 777 /data/data/com.pubg.krmobile/files/tss_tmp"
"chmod 777 /data/data/com.pubg.krmobile/files/tss_tmp"
"chmod 777 /data/data/com.pubg.krmobile/files/tss_tmp");
}
break;
case 3:
BPS2 = jboolean1;
if (BPS2)
{
system("iptables -I INPUT -s down.anticheatexpert.com -j DROP &>/dev/null"
"iptables -I OUTPUT -s down.anticheatexpert.com -j DROP &>/dev/null"
"iptables -I INPUT -s down.qq.com -j DROP &>/dev/null"
"iptables -I OUTPUT -s down.qq.com -j DROP &>/dev/null"
"iptables -I INPUT -s down.anticheatexpert.com -j REJECT &>/dev/null"
"iptables -I OUTPUT -s down.anticheatexpert.com -j REJECT &>/dev/null"
"iptables -I INPUT -s down.qq.com -j REJECT &>/dev/null"
"iptables -I OUTPUT -s down.qq.com -j REJECT &>/dev/null"
"iptables -I OUTPUT -s com.tencent.quantum.share.QuantumFileProvider -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.googlefirebase.provider.FirebaseInitProvider -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.helpshift.support.provider.HelpshiftFileProvider -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.facebook.internal.FacebookInitprovider -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.pubg.krmobile.OBBDownloaderService    -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.tencent.quantum.IGFirebaseInstanceIDService -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.google.firebase.messaging.FirebaseMessagingService -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.tencent.imsdk.android.webview.qq.WebViewService -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.tencent.midas.oversea.newnetwork.service.APNetDetectService -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.tencent.midas.oversea.business.h5.WebService -j DROP &>/dev/null"
"iptables -I OUTPUT -s com.tencent.quantum.download.GCBGDownloadService -j DROP &>/dev/null"
"iptables -I OUTPUT -s down.anticheatexpert.com -j DROP &>/dev/null"
"iptables -I INPUT -s tencentgames.helpshift.com -j DROP &>/dev/null="
"iptables -I INPUT -s *:443 -j DROP &>/dev/null"
"iptables -I INPUT -s *:9031 -j DROP &>/dev/null"
"iptables -I INPUT -s *:9030 -j DROP &>/dev/null"
"iptables -I INPUT  -s pubgm.igamecj.com -j REJECT &>/dev/null"
"iptables -I OUTPUT -s pubgm.igamecj.com -j REJECT &>/dev/null"
"iptables -I INPUT  -s tencent.igamecj.com -j REJECT &>/dev/null"
"iptables -I OUTPUT -s tencent.igamecj.com -j REJECT &>/dev/null"
"iptables -I INPUT  -s report.igamecj.com -j REJECT &>/dev/null"
"iptables -I OUTPUT -s report.igamecj.com -j REJECT &>/dev/null"
"iptables -I OUTPUT -s gl.lobby.igamecj.com -j REJECT &>/dev/null"
"touch /storage/emulated/0/iptables_off.sh su -c iptables -F iptables -F su -c iptables --flush"
"chmod 777 /sdcard/iptables_off.sh");
}
else
{
system("su -c iptables -F"
"iptables -F"
"su -c iptables --flush"
"iptables --flushl"
"touch /storage/emulated/0/Android/ASU.txt IDIOT_KONTOL_BABI_ASU_BANGSAD_GADA_AHLAK_LO_PAKE_CIT");
}
break;
case 4:
system("makdir /storage/emulated/0/Android/modmenuLogs SUCCESSFUL CLEAR"
"rm -rf /storage/emulated/0/tencent"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15150.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15151.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15153.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15154.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15155.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15156.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15150.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15151.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15153.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15154.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15155.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15156.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15150.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15151.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15153.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15154.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15155.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15156.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15150.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15151.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15153.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15154.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15155.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.4.0.15156.pak"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_137_1.3.0.14926_20210324214115_1851371208_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14923.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14924.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14925.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14926.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14927.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14928.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/login-identifier.txt"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/ProgramBinaryCache"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate/SaveGames/JKGuestRegisterCnt.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_137_1.3.0.14926_20210324214115_1851371208_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp0"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp1"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/pufferTempDir"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Pandora"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp0"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp1"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/pufferTempDir"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Pandora"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp0"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp1"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/pufferTempDir"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Pandora"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp0"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/puffer_temp1"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/pufferTempDir"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Pandora"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14923.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14924.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14925.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14926.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14927.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14928.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/login-identifier.txt"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/ProgramBinaryCache"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate/SaveGames/JKGuestRegisterCnt.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_137_1.3.0.14926_20210324214115_1851371208_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14923.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14924.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14925.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14926.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14927.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14928.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/login-identifier.txt"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/ProgramBinaryCache"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate/SaveGames/JKGuestRegisterCnt.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_137_1.3.0.14926_20210324214115_1851371208_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14923.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14924.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14925.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14926.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14927.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14928.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/login-identifier.txt"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/ProgramBinaryCache"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate/SaveGames/JKGuestRegisterCnt.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/MMKV"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.3.0.14922_20210309205606_824662004_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations/concurrent"
"rm -rf third_party.java_src.error_prone.project.annotations.Google_internal"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.3.0.14922_20210309205606_824662004_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations/concurrent"
"rm -rf third_party.java_src.error_prone.project.annotations.Google_internal"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.3.0.14922_20210309205606_824662004_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations/concurrent"
"rm -rf third_party.java_src.error_prone.project.annotations.Google_internal"
"rm -rf /storage/emulated/0/Android/.backups"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.3.0.14922_20210309205606_824662004_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/core_patch_1.4.0.15152.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14921.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/game_patch_1.3.0.14922.pak"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini"
"rm -rf /sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.4.0.15156_20210520180349_1414572672_cures.ifs.res"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs"
"rm -rf /storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations"
"rm -rf src/main/java/com/google/errorprone/annotations/concurrent"
"rm -rf third_party.java_src.error_prone.project.annotations.Google_internal");
break;
default:
break;
}
}

extern "C"
JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_Range(JNIEnv *, jobject, jint range)
{
options.aimingRange = 1 + range;
}

extern "C" JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_Target(JNIEnv *, jobject, jint i)
{
options.aimbotmode = i;
}

extern "C" JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_AimWhen(JNIEnv *, jobject, jint i)
{
options.aimingState = i;
}

extern "C" JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_AimBy(JNIEnv *, jobject, jint i)
{
options.priority = i;
}


extern "C" {
JNIEXPORT void JNICALL
Java_com_modmenu_patcher_service_Launcher_Hack(JNIEnv *, jobject, jint code,
        jboolean jboolean1) {
switch ((int)code) {
case 1:
Less = jboolean1;
if (Less) {
ModMem.Less.Modify();
} else {
ModMem.Less.Restore();
}
break;
case 2:
Small = jboolean1;
if (Small) {
ModMem.Small.Modify();
} else {
ModMem.Small.Restore();
}
break;
break;
case 3:
AimLock = jboolean1;
if (AimLock) {
ModMem.AimLock.Modify();
} else {
ModMem.AimLock.Restore();
}
break;
case 4:
HIGHView = jboolean1;
if (HIGHView) {
ModMem.HIGHView.Modify();
} else {
ModMem.HIGHView.Restore();
}
break;
case 5:
Bypass = jboolean1;
if (Bypass) {
ModMem.Bypass.Modify();
ModMem.Bypass1.Modify();
ModMem.Bypass2.Modify();
ModMem.Bypass3.Modify();
ModMem.Bypass4.Modify();
ModMem.Bypass5.Modify();
ModMem.Bypass6.Modify();
ModMem.Bypass7.Modify();
ModMem.Bypass8.Modify();
ModMem.Bypass9.Modify();
ModMem.Bypass10.Modify();
ModMem.Bypass11.Modify();
ModMem.Bypass12.Modify();
ModMem.Bypass13.Modify();
ModMem.Bypass14.Modify();
ModMem.Bypass15.Modify();
ModMem.Bypass16.Modify();
ModMem.Bypass17.Modify();
ModMem.Bypass18.Modify();
ModMem.Bypass19.Modify();
ModMem.Bypass20.Modify();
ModMem.Bypass21.Modify();
ModMem.Bypass22.Modify();
ModMem.Bypass23.Modify();
ModMem.Bypass24.Modify();
ModMem.Bypass25.Modify();
ModMem.Bypass26.Modify();
ModMem.Bypass27.Modify();
ModMem.Bypass28.Modify();
ModMem.Bypass29.Modify();
ModMem.Bypass30.Modify();
ModMem.Bypass31.Modify();
ModMem.Bypass32.Modify();
ModMem.Bypass33.Modify();
ModMem.Bypass34.Modify();
ModMem.Bypass35.Modify();
ModMem.Bypass36.Modify();
ModMem.Bypass37.Modify();
ModMem.Bypass38.Modify();
ModMem.Bypass39.Modify();
ModMem.Bypass40.Modify();
ModMem.Bypass41.Modify();
ModMem.Bypass42.Modify();
ModMem.Bypass43.Modify();
ModMem.Bypass44.Modify();
ModMem.Bypass45.Modify();
ModMem.Bypass46.Modify();
ModMem.Bypass47.Modify();
ModMem.Bypass48.Modify();
ModMem.Bypass49.Modify();
ModMem.Bypass50.Modify();
ModMem.Bypass51.Modify();
ModMem.Bypass52.Modify();
ModMem.Bypass53.Modify();
ModMem.Bypass54.Modify();
ModMem.Bypass55.Modify();
ModMem.Bypass56.Modify();
ModMem.Bypass57.Modify();
ModMem.Bypass58.Modify();
ModMem.Bypass59.Modify();
ModMem.Bypass60.Modify();
ModMem.Bypass61.Modify();
ModMem.Bypass62.Modify();
ModMem.Bypass63.Modify();
ModMem.Bypass64.Modify();
ModMem.Bypass65.Modify();
ModMem.Bypass66.Modify();
ModMem.Bypass67.Modify();
ModMem.Bypass68.Modify();
ModMem.Bypass69.Modify();
ModMem.Bypass70.Modify();
ModMem.Bypass71.Modify();
ModMem.Bypass72.Modify();
ModMem.Bypass73.Modify();
ModMem.Bypass74.Modify();
ModMem.Bypass75.Modify();
ModMem.Bypass76.Modify();
ModMem.Bypass77.Modify();
ModMem.Bypass78.Modify();
ModMem.Bypass79.Modify();
ModMem.Bypass80.Modify();
ModMem.Bypass81.Modify();
ModMem.Bypass82.Modify();
ModMem.Bypass83.Modify();
ModMem.Bypass84.Modify();
ModMem.Bypass85.Modify();
ModMem.Bypass86.Modify();
ModMem.Bypass87.Modify();
ModMem.Bypass88.Modify();
ModMem.Bypass89.Modify();
ModMem.Bypass90.Modify();
ModMem.Bypass91.Modify();
ModMem.Bypass92.Modify();
ModMem.Bypass93.Modify();
ModMem.Bypass94.Modify();
ModMem.Bypass95.Modify();
ModMem.Bypass96.Modify();
ModMem.Bypass97.Modify();
ModMem.Bypass98.Modify();
ModMem.Bypass99.Modify();
ModMem.Bypass100.Modify();
ModMem.Bypass101.Modify();
ModMem.Bypass102.Modify();
ModMem.Bypass103.Modify();
ModMem.Bypass104.Modify();
ModMem.Bypass105.Modify();
ModMem.Bypass106.Modify();
ModMem.Bypass107.Modify();
ModMem.Bypass108.Modify();
ModMem.Bypass109.Modify();
ModMem.Bypass110.Modify();
ModMem.Bypass111.Modify();
ModMem.Bypass112.Modify();
ModMem.Bypass113.Modify();
ModMem.Bypass114.Modify();
ModMem.Bypass115.Modify();
ModMem.Bypass116.Modify();
ModMem.Bypass117.Modify();
ModMem.Bypass118.Modify();
ModMem.Bypass119.Modify();
ModMem.Bypass120.Modify();
ModMem.Bypass121.Modify();
ModMem.Bypass122.Modify();
ModMem.Bypass123.Modify();
ModMem.Bypass124.Modify();
ModMem.Bypass125.Modify();
ModMem.Bypass126.Modify();
ModMem.Bypass127.Modify();
ModMem.Bypass128.Modify();
ModMem.Bypass129.Modify();
ModMem.Bypass130.Modify();
ModMem.Bypass131.Modify();
ModMem.Bypass132.Modify();
ModMem.Bypass133.Modify();
ModMem.Bypass134.Modify();
ModMem.Bypass135.Modify();
ModMem.Bypass136.Modify();

ModMem.Bypass137.Modify();
ModMem.Bypass138.Modify();
ModMem.Bypass139.Modify();
ModMem.Bypass140.Modify();
ModMem.Bypass141.Modify();
ModMem.Bypass142.Modify();
ModMem.Bypass143.Modify();
ModMem.Bypass144.Modify();
ModMem.Bypass145.Modify();
ModMem.Bypass146.Modify();
ModMem.Bypass147.Modify();
ModMem.Bypass148.Modify();
ModMem.Bypass149.Modify();
ModMem.Bypass150.Modify();
ModMem.Bypass151.Modify();
ModMem.Bypass152.Modify();
ModMem.Bypass153.Modify();
ModMem.Bypass154.Modify();
ModMem.Bypass155.Modify();
ModMem.Bypass156.Modify();

ModMem.Bypass175.Modify();
ModMem.Bypass176.Modify();
ModMem.Bypass178.Modify();
ModMem.Bypass179.Modify();
ModMem.Bypass180.Modify();
ModMem.Bypass181.Modify();
ModMem.Bypass182.Modify();
ModMem.Bypass183.Modify();
ModMem.Bypass184.Modify();
ModMem.Bypass185.Modify();
ModMem.Bypass186.Modify();
ModMem.Bypass187.Modify();
ModMem.Bypass188.Modify();
ModMem.Bypass189.Modify();
ModMem.Bypass190.Modify();
ModMem.Bypass191.Modify();
ModMem.Bypass192.Modify();
ModMem.Bypass193.Modify();
ModMem.Bypass194.Modify();
ModMem.Bypass195.Modify();
ModMem.Bypass196.Modify();
ModMem.Bypass197.Modify();
ModMem.Bypass198.Modify();
ModMem.Bypass199.Modify();
ModMem.Bypass200.Modify();
ModMem.Bypass201.Modify();
ModMem.Bypass202.Modify();
ModMem.Bypass203.Modify();
ModMem.Bypass204.Modify();
ModMem.Bypass205.Modify();
ModMem.Bypass206.Modify();
ModMem.Bypass207.Modify();
ModMem.Bypass208.Modify();
ModMem.Bypass209.Modify();
ModMem.Bypass210.Modify();
ModMem.Bypass211.Modify();
ModMem.Bypass212.Modify();
ModMem.Bypass213.Modify();
ModMem.Bypass214.Modify();
ModMem.Bypass215.Modify();
ModMem.Bypass216.Modify();
ModMem.Bypass217.Modify();
ModMem.Bypass218.Modify();
ModMem.Bypass219.Modify();
ModMem.Bypass220.Modify();
ModMem.Bypass221.Modify();
ModMem.Bypass222.Modify();
ModMem.Bypass223.Modify();
ModMem.Bypass224.Modify();
ModMem.Bypass225.Modify();
ModMem.Bypass226.Modify();
ModMem.Bypass227.Modify();
ModMem.Bypass228.Modify();
ModMem.Bypass229.Modify();
ModMem.Bypass230.Modify();
ModMem.Bypass231.Modify();
ModMem.Bypass232.Modify();
ModMem.Bypass233.Modify();
ModMem.Bypass234.Modify();
ModMem.Bypass235.Modify();
ModMem.Bypass236.Modify();
ModMem.Bypass237.Modify();
ModMem.Bypass238.Modify();
ModMem.Bypass239.Modify();
ModMem.Bypass240.Modify();
ModMem.Bypass241.Modify();
ModMem.Bypass242.Modify();
ModMem.Bypass243.Modify();
ModMem.Bypass244.Modify();
ModMem.Bypass245.Modify();
ModMem.Bypass246.Modify();
ModMem.Bypass247.Modify();
ModMem.Bypass248.Modify();
ModMem.Bypass249.Modify();
ModMem.Bypass250.Modify();
ModMem.Bypass251.Modify();
ModMem.Bypass252.Modify();
ModMem.Bypass253.Modify();
ModMem.Bypass254.Modify();
ModMem.Bypass255.Modify();
ModMem.Bypass256.Modify();
ModMem.Bypass257.Modify();
ModMem.Bypass258.Modify();
ModMem.Bypass259.Modify();
ModMem.Bypass260.Modify();
ModMem.Bypass261.Modify();
ModMem.Bypass262.Modify();
ModMem.Bypass263.Modify();
ModMem.Bypass264.Modify();
ModMem.Bypass265.Modify();
ModMem.Bypass266.Modify();
ModMem.Bypass267.Modify();
ModMem.Bypass268.Modify();
ModMem.Bypass269.Modify();
ModMem.Bypass270.Modify();
ModMem.Bypass271.Modify();
ModMem.Bypass272.Modify();
ModMem.Bypass273.Modify();
ModMem.Bypass274.Modify();
ModMem.Bypass275.Modify();
ModMem.Bypass276.Modify();
ModMem.Bypass277.Modify();
ModMem.Bypass278.Modify();
ModMem.Bypass279.Modify();
ModMem.Bypass280.Modify();
ModMem.Bypass281.Modify();
ModMem.Bypass282.Modify();
ModMem.Bypass283.Modify();
ModMem.Bypass284.Modify();
ModMem.Bypass285.Modify();
ModMem.Bypass286.Modify();
ModMem.Bypass287.Modify();
ModMem.Bypass288.Modify();
ModMem.Bypass289.Modify();
ModMem.Bypass290.Modify();
ModMem.Bypass291.Modify();
ModMem.Bypass292.Modify();
ModMem.Bypass293.Modify();
ModMem.Bypass294.Modify();
ModMem.Bypass295.Modify();
ModMem.Bypass296.Modify();
ModMem.Bypass297.Modify();
ModMem.Bypass298.Modify();
ModMem.Bypass299.Modify();
ModMem.Bypass300.Modify();
ModMem.Bypass301.Modify();
ModMem.Bypass302.Modify();
ModMem.Bypass303.Modify();
ModMem.Bypass304.Modify();
ModMem.Bypass305.Modify();
ModMem.Bypass306.Modify();
ModMem.Bypass307.Modify();
ModMem.Bypass308.Modify();
ModMem.Bypass309.Modify();
ModMem.Bypass310.Modify();
ModMem.Bypass311.Modify();
ModMem.Bypass312.Modify();
ModMem.Bypass313.Modify();
ModMem.Bypass314.Modify();
ModMem.Bypass315.Modify();
ModMem.Bypass316.Modify();
ModMem.Bypass317.Modify();
ModMem.Bypass318.Modify();
ModMem.Bypass319.Modify();
ModMem.Bypass320.Modify();
ModMem.Bypass321.Modify();
ModMem.Bypass322.Modify();
} else {
ModMem.Bypass.Restore();
ModMem.Bypass1.Restore();
ModMem.Bypass2.Restore();
ModMem.Bypass3.Restore();
ModMem.Bypass4.Restore();
ModMem.Bypass5.Restore();
ModMem.Bypass6.Restore();
ModMem.Bypass7.Restore();
ModMem.Bypass8.Restore();
ModMem.Bypass9.Restore();
ModMem.Bypass10.Restore();
ModMem.Bypass11.Restore();
ModMem.Bypass12.Restore();
ModMem.Bypass13.Restore();
ModMem.Bypass14.Restore();
ModMem.Bypass15.Restore();
ModMem.Bypass16.Restore();
ModMem.Bypass17.Restore();
ModMem.Bypass18.Restore();
ModMem.Bypass19.Restore();
ModMem.Bypass20.Restore();
ModMem.Bypass21.Restore();
ModMem.Bypass22.Restore();
ModMem.Bypass23.Restore();
ModMem.Bypass24.Restore();
ModMem.Bypass25.Restore();
ModMem.Bypass26.Restore();
ModMem.Bypass27.Restore();
ModMem.Bypass28.Restore();
ModMem.Bypass29.Restore();
ModMem.Bypass30.Restore();
ModMem.Bypass31.Restore();
ModMem.Bypass32.Restore();
ModMem.Bypass33.Restore();
ModMem.Bypass34.Restore();
ModMem.Bypass35.Restore();
ModMem.Bypass36.Restore();
ModMem.Bypass37.Restore();
ModMem.Bypass38.Restore();
ModMem.Bypass39.Restore();
ModMem.Bypass40.Restore();
ModMem.Bypass41.Restore();
ModMem.Bypass42.Restore();
ModMem.Bypass43.Restore();
ModMem.Bypass44.Restore();
ModMem.Bypass45.Restore();
ModMem.Bypass46.Restore();
ModMem.Bypass47.Restore();
ModMem.Bypass48.Restore();
ModMem.Bypass49.Restore();
ModMem.Bypass50.Restore();
ModMem.Bypass51.Restore();
ModMem.Bypass52.Restore();
ModMem.Bypass53.Restore();
ModMem.Bypass54.Restore();
ModMem.Bypass55.Restore();
ModMem.Bypass56.Restore();
ModMem.Bypass57.Restore();
ModMem.Bypass58.Restore();
ModMem.Bypass59.Restore();
ModMem.Bypass60.Restore();
ModMem.Bypass61.Restore();
ModMem.Bypass62.Restore();
ModMem.Bypass63.Restore();
ModMem.Bypass64.Restore();
ModMem.Bypass65.Restore();
ModMem.Bypass66.Restore();
ModMem.Bypass67.Restore();
ModMem.Bypass68.Restore();
ModMem.Bypass69.Restore();
ModMem.Bypass70.Restore();
ModMem.Bypass71.Restore();
ModMem.Bypass72.Restore();
ModMem.Bypass73.Restore();
ModMem.Bypass74.Restore();
ModMem.Bypass75.Restore();
ModMem.Bypass76.Restore();
ModMem.Bypass77.Restore();
ModMem.Bypass78.Restore();
ModMem.Bypass79.Restore();
ModMem.Bypass80.Restore();
ModMem.Bypass81.Restore();
ModMem.Bypass82.Restore();
ModMem.Bypass83.Restore();
ModMem.Bypass84.Restore();
ModMem.Bypass85.Restore();
ModMem.Bypass86.Restore();
ModMem.Bypass87.Restore();
ModMem.Bypass88.Restore();
ModMem.Bypass89.Restore();
ModMem.Bypass90.Restore();
ModMem.Bypass91.Restore();
ModMem.Bypass92.Restore();
ModMem.Bypass93.Restore();
ModMem.Bypass94.Restore();
ModMem.Bypass95.Restore();
ModMem.Bypass96.Restore();
ModMem.Bypass97.Restore();
ModMem.Bypass98.Restore();
ModMem.Bypass99.Restore();
ModMem.Bypass100.Restore();
ModMem.Bypass101.Restore();
ModMem.Bypass102.Restore();
ModMem.Bypass103.Restore();
ModMem.Bypass104.Restore();
ModMem.Bypass105.Restore();
ModMem.Bypass106.Restore();
ModMem.Bypass107.Restore();
ModMem.Bypass108.Restore();
ModMem.Bypass109.Restore();
ModMem.Bypass110.Restore();
ModMem.Bypass111.Restore();
ModMem.Bypass112.Restore();
ModMem.Bypass113.Restore();
ModMem.Bypass114.Restore();

ModMem.Bypass115.Restore();
ModMem.Bypass116.Restore();
ModMem.Bypass117.Restore();
ModMem.Bypass118.Restore();
ModMem.Bypass119.Restore();
ModMem.Bypass120.Restore();
ModMem.Bypass121.Restore();
ModMem.Bypass122.Restore();
ModMem.Bypass123.Restore();
ModMem.Bypass124.Restore();
ModMem.Bypass125.Restore();
ModMem.Bypass126.Restore();
ModMem.Bypass127.Restore();
ModMem.Bypass128.Restore();
ModMem.Bypass129.Restore();
ModMem.Bypass130.Restore();
ModMem.Bypass131.Restore();
ModMem.Bypass132.Restore();
ModMem.Bypass133.Restore();
ModMem.Bypass134.Restore();
ModMem.Bypass135.Restore();
ModMem.Bypass136.Restore();
ModMem.Bypass137.Restore();
ModMem.Bypass138.Restore();
ModMem.Bypass139.Restore();
ModMem.Bypass140.Restore();
ModMem.Bypass141.Restore();
ModMem.Bypass142.Restore();
ModMem.Bypass143.Restore();
ModMem.Bypass144.Restore();
ModMem.Bypass145.Restore();
ModMem.Bypass146.Restore();
ModMem.Bypass147.Restore();
ModMem.Bypass148.Restore();
ModMem.Bypass149.Restore();
ModMem.Bypass150.Restore();
ModMem.Bypass151.Restore();
ModMem.Bypass152.Restore();
ModMem.Bypass153.Restore();
ModMem.Bypass154.Restore();
ModMem.Bypass155.Restore();
ModMem.Bypass156.Restore();

ModMem.Bypass175.Restore();
ModMem.Bypass176.Restore();
ModMem.Bypass178.Restore();
ModMem.Bypass179.Restore();
ModMem.Bypass180.Restore();
ModMem.Bypass181.Restore();
ModMem.Bypass182.Restore();
ModMem.Bypass183.Restore();
ModMem.Bypass184.Restore();
ModMem.Bypass185.Restore();
ModMem.Bypass186.Restore();
ModMem.Bypass187.Restore();
ModMem.Bypass188.Restore();
ModMem.Bypass189.Restore();
ModMem.Bypass190.Restore();
ModMem.Bypass191.Restore();
ModMem.Bypass192.Restore();
ModMem.Bypass193.Restore();
ModMem.Bypass194.Restore();
ModMem.Bypass195.Restore();
ModMem.Bypass196.Restore();
ModMem.Bypass197.Restore();
ModMem.Bypass198.Restore();
ModMem.Bypass199.Restore();
ModMem.Bypass200.Restore();
ModMem.Bypass201.Restore();
ModMem.Bypass202.Restore();
ModMem.Bypass203.Restore();
ModMem.Bypass204.Restore();
ModMem.Bypass205.Restore();
ModMem.Bypass206.Restore();
ModMem.Bypass207.Restore();
ModMem.Bypass208.Restore();
ModMem.Bypass209.Restore();
ModMem.Bypass210.Restore();
ModMem.Bypass211.Restore();
ModMem.Bypass212.Restore();
ModMem.Bypass213.Restore();
ModMem.Bypass214.Restore();
ModMem.Bypass215.Restore();
ModMem.Bypass216.Restore();
ModMem.Bypass217.Restore();
ModMem.Bypass218.Restore();
ModMem.Bypass219.Restore();
ModMem.Bypass220.Restore();
ModMem.Bypass221.Restore();
ModMem.Bypass222.Restore();
ModMem.Bypass223.Restore();
ModMem.Bypass224.Restore();
ModMem.Bypass225.Restore();
ModMem.Bypass226.Restore();
ModMem.Bypass227.Restore();
ModMem.Bypass228.Restore();
ModMem.Bypass229.Restore();
ModMem.Bypass230.Restore();
ModMem.Bypass231.Restore();
ModMem.Bypass232.Restore();
ModMem.Bypass233.Restore();
ModMem.Bypass234.Restore();
ModMem.Bypass235.Restore();
ModMem.Bypass236.Restore();
ModMem.Bypass237.Restore();
ModMem.Bypass238.Restore();
ModMem.Bypass239.Restore();
ModMem.Bypass240.Restore();
ModMem.Bypass241.Restore();
ModMem.Bypass242.Restore();
ModMem.Bypass243.Restore();
ModMem.Bypass244.Restore();
ModMem.Bypass245.Restore();
ModMem.Bypass246.Restore();
ModMem.Bypass247.Restore();
ModMem.Bypass248.Restore();
ModMem.Bypass249.Modify();
ModMem.Bypass250.Restore();
ModMem.Bypass251.Restore();
ModMem.Bypass252.Restore();
ModMem.Bypass253.Restore();
ModMem.Bypass254.Restore();
ModMem.Bypass255.Restore();
ModMem.Bypass256.Restore();
ModMem.Bypass257.Restore();
ModMem.Bypass258.Restore();
ModMem.Bypass259.Restore();
ModMem.Bypass260.Restore();
ModMem.Bypass261.Restore();
ModMem.Bypass262.Restore();
ModMem.Bypass263.Restore();
ModMem.Bypass264.Restore();
ModMem.Bypass265.Restore();
ModMem.Bypass266.Restore();
ModMem.Bypass267.Restore();
ModMem.Bypass268.Restore();
ModMem.Bypass269.Restore();
ModMem.Bypass270.Restore();
ModMem.Bypass271.Restore();
ModMem.Bypass272.Restore();
ModMem.Bypass273.Restore();
ModMem.Bypass274.Restore();
ModMem.Bypass275.Restore();
ModMem.Bypass276.Restore();
ModMem.Bypass277.Restore();
ModMem.Bypass278.Restore();
ModMem.Bypass279.Restore();
ModMem.Bypass280.Restore();
ModMem.Bypass281.Restore();
ModMem.Bypass282.Restore();
ModMem.Bypass283.Restore();
ModMem.Bypass284.Restore();
ModMem.Bypass285.Restore();
ModMem.Bypass286.Restore();
ModMem.Bypass287.Restore();
ModMem.Bypass288.Restore();
ModMem.Bypass289.Restore();
ModMem.Bypass290.Restore();
ModMem.Bypass291.Restore();
ModMem.Bypass292.Restore();
ModMem.Bypass293.Restore();
ModMem.Bypass294.Restore();
ModMem.Bypass295.Restore();
ModMem.Bypass296.Restore();
ModMem.Bypass297.Restore();
ModMem.Bypass298.Restore();
ModMem.Bypass299.Restore();
ModMem.Bypass300.Restore();
ModMem.Bypass301.Restore();
ModMem.Bypass302.Restore();
ModMem.Bypass303.Restore();
ModMem.Bypass304.Restore();
ModMem.Bypass305.Restore();
ModMem.Bypass306.Restore();
ModMem.Bypass307.Restore();
ModMem.Bypass308.Restore();
ModMem.Bypass309.Restore();
ModMem.Bypass310.Restore();
ModMem.Bypass311.Restore();
ModMem.Bypass312.Restore();
ModMem.Bypass313.Restore();
ModMem.Bypass314.Restore();
ModMem.Bypass315.Restore();
ModMem.Bypass316.Restore();
ModMem.Bypass317.Restore();
ModMem.Bypass318.Restore();
ModMem.Bypass319.Restore();
ModMem.Bypass320.Restore();
ModMem.Bypass321.Restore();
ModMem.Bypass322.Restore();
}
break;
case 6:
flash = jboolean1;
if (flash) {
ModMem.flash.Modify();
ModMem.flash2.Modify();
} else {
ModMem.flash.Restore();
ModMem.flash2.Restore();
}
break;
case 7:
CarJump = jboolean1;
if (CarJump) {
ModMem.CarJump.Modify();
} else {
ModMem.CarJump.Restore();
}
break;
}
}
}
void (*old_Update)(void *instance);
void Update(void *instance) { instanceBtn = instance; old_Update(instance); }
void *Super_thread(void *) { ProcMap il2cppMap; do { il2cppMap = KittyMemory::getLibraryMap("libUE4.so");  sleep(1); } while(!il2cppMap.isValid());
    ModMem.Less = MemoryPatch::createWithHex("libUE4.so", 0x14284A8, "00 00 00 00");
    ModMem.Small = MemoryPatch::createWithHex("libUE4.so", 0x1428A60, "00 00 00 00");
    ModMem.AimLock = MemoryPatch::createWithHex("libUE4.so", 0x27238D0, "00 00 00 00");
    ModMem.HIGHView = MemoryPatch::createWithHex("libUE4.so", 0x3A05C20, "00 00 8C 43");
    ModMem.CarJump = MemoryPatch::createWithHex("libUE4.so",0x48F5370, "00 00 00 00", 4);
    ModMem.flash = MemoryPatch::createWithHex("libUE4.so",0x3A5FA5C, "00 00 00 00", 4);
    ModMem.flash2 = MemoryPatch::createWithHex("libUE4.so",0x3F95CBC, "00 00 00 00", 4);
    return NULL;

}
void *hack_thread(void *) { ProcMap il2cppMap; do { il2cppMap = KittyMemory::getLibraryMap("libtersafe.so");  sleep(1); } while(!il2cppMap.isValid());
    ModMem.Bypass = MemoryPatch::createWithHex("libtersafe.so", 0x8a8, "00 00 00 00");
    ModMem.Bypass1 = MemoryPatch::createWithHex("libtersafe.so", 0x2c742c, "00 00 00 00");
    ModMem.Bypass2 = MemoryPatch::createWithHex("libtersafe.so", 0xaf2f0, "00 00 00 00");
    ModMem.Bypass3 = MemoryPatch::createWithHex("libtersafe.so", 0xb67b0, "00 00 00 00");
    ModMem.Bypass4 = MemoryPatch::createWithHex("libtersafe.so", 0xb67d8, "00 00 00 00");
    ModMem.Bypass5 = MemoryPatch::createWithHex("libtersafe.so", 0xbf24c, "00 00 00 00");
    ModMem.Bypass6 = MemoryPatch::createWithHex("libtersafe.so", 0xbff88, "00 00 00 00");
    ModMem.Bypass7 = MemoryPatch::createWithHex("libtersafe.so", 0xc6c3c, "00 00 00 00");
    ModMem.Bypass8 = MemoryPatch::createWithHex("libtersafe.so", 0xc9eec, "00 00 00 00");
    ModMem.Bypass9 = MemoryPatch::createWithHex("libtersafe.so", 0xcbe2c, "00 00 00 00");
    ModMem.Bypass10 = MemoryPatch::createWithHex("libtersafe.so", 0xcbf54, "00 00 00 00");
    ModMem.Bypass11 = MemoryPatch::createWithHex("libtersafe.so", 0xcdb7c, "00 00 00 00");
    ModMem.Bypass12 = MemoryPatch::createWithHex("libtersafe.so", 0xce210, "00 00 00 00");
    ModMem.Bypass13 = MemoryPatch::createWithHex("libtersafe.so", 0xce338, "00 00 00 00");
    ModMem.Bypass14 = MemoryPatch::createWithHex("libtersafe.so", 0xd28f4, "00 00 00 00");
    ModMem.Bypass15 = MemoryPatch::createWithHex("libtersafe.so", 0xd2a1c, "00 00 00 00");
    ModMem.Bypass16 = MemoryPatch::createWithHex("libtersafe.so", 0xd74d0, "00 00 00 00");
    ModMem.Bypass17 = MemoryPatch::createWithHex("libtersafe.so", 0xdd538, "00 00 00 00");
    ModMem.Bypass18 = MemoryPatch::createWithHex("libtersafe.so", 0xdf9b0, "00 00 00 00");
    ModMem.Bypass19 = MemoryPatch::createWithHex("libtersafe.so", 0xdfad8, "00 00 00 00");
    ModMem.Bypass20 = MemoryPatch::createWithHex("libtersafe.so", 0xe1cd8, "00 00 00 00");
    ModMem.Bypass21 = MemoryPatch::createWithHex("libtersafe.so", 0xe2018, "00 00 00 00");
    ModMem.Bypass22 = MemoryPatch::createWithHex("libtersafe.so", 0xe26c4, "00 00 00 00");
    ModMem.Bypass23 = MemoryPatch::createWithHex("libtersafe.so", 0xe5794, "00 00 00 00");
    ModMem.Bypass24 = MemoryPatch::createWithHex("libtersafe.so", 0xf0bb4, "00 00 00 00");
    ModMem.Bypass25 = MemoryPatch::createWithHex("libtersafe.so", 0xf26e4, "00 00 00 00");
    ModMem.Bypass26 = MemoryPatch::createWithHex("libtersafe.so", 0xf2978, "00 00 00 00");
    ModMem.Bypass27 = MemoryPatch::createWithHex("libtersafe.so", 0xffddc, "00 00 00 00");
    ModMem.Bypass28 = MemoryPatch::createWithHex("libtersafe.so", 0x100d98, "00 00 00 00");
    ModMem.Bypass29 = MemoryPatch::createWithHex("libtersafe.so", 0x100f20, "00 00 00 00");
    ModMem.Bypass30 = MemoryPatch::createWithHex("libtersafe.so", 0x10e780, "00 00 00 00");
    ModMem.Bypass31 = MemoryPatch::createWithHex("libtersafe.so", 0x10e8a8, "00 00 00 00");
    ModMem.Bypass32 = MemoryPatch::createWithHex("libtersafe.so", 0x10fde4, "00 00 00 00");
    ModMem.Bypass33 = MemoryPatch::createWithHex("libtersafe.so", 0x10ff0c, "00 00 00 00");
    ModMem.Bypass34 = MemoryPatch::createWithHex("libtersafe.so", 0x1316c0, "00 00 00 00");
    ModMem.Bypass35 = MemoryPatch::createWithHex("libtersafe.so", 0x1317e8, "00 00 00 00");
    ModMem.Bypass36 = MemoryPatch::createWithHex("libtersafe.so", 0x1330dc, "00 00 00 00");
    ModMem.Bypass37 = MemoryPatch::createWithHex("libtersafe.so", 0x136a3c, "00 00 00 00");
    ModMem.Bypass38 = MemoryPatch::createWithHex("libtersafe.so", 0x13d758, "00 00 00 00");
    ModMem.Bypass39 = MemoryPatch::createWithHex("libtersafe.so", 0x13d9c4, "00 00 00 00");
    ModMem.Bypass40 = MemoryPatch::createWithHex("libtersafe.so", 0x143574, "00 00 00 00");
    ModMem.Bypass41 = MemoryPatch::createWithHex("libtersafe.so", 0x143d48, "00 00 00 00");
    ModMem.Bypass42 = MemoryPatch::createWithHex("libtersafe.so", 0x143e70, "00 00 00 00");
    ModMem.Bypass43 = MemoryPatch::createWithHex("libtersafe.so", 0x14a06c, "00 00 00 00");

    ModMem.Bypass44 = MemoryPatch::createWithHex("libtersafe.so", 0x14a960, "00 00 00 00");
    ModMem.Bypass45 = MemoryPatch::createWithHex("libtersafe.so", 0x14aa88, "00 00 00 00");
    ModMem.Bypass46 = MemoryPatch::createWithHex("libtersafe.so", 0x154624, "00 00 00 00");
    ModMem.Bypass47 = MemoryPatch::createWithHex("libtersafe.so", 0x155368, "00 00 00 00");
    ModMem.Bypass48 = MemoryPatch::createWithHex("libtersafe.so", 0x161124, "00 00 00 00");
    ModMem.Bypass49 = MemoryPatch::createWithHex("libtersafe.so", 0x162518, "00 00 00 00");
    ModMem.Bypass50 = MemoryPatch::createWithHex("libtersafe.so", 0x163284, "00 00 00 00");
    ModMem.Bypass51 = MemoryPatch::createWithHex("libtersafe.so", 0x166e44, "00 00 00 00");
    ModMem.Bypass52 = MemoryPatch::createWithHex("libtersafe.so", 0x167e1c, "00 00 00 00");
    ModMem.Bypass53 = MemoryPatch::createWithHex("libtersafe.so", 0x1706d0, "00 00 00 00");
    ModMem.Bypass54 = MemoryPatch::createWithHex("libtersafe.so", 0x1773d8, "00 00 00 00");
    ModMem.Bypass55 = MemoryPatch::createWithHex("libtersafe.so", 0x17b58c, "00 00 00 00");
    ModMem.Bypass56 = MemoryPatch::createWithHex("libtersafe.so", 0x1bbcb0, "00 00 00 00");
    ModMem.Bypass57 = MemoryPatch::createWithHex("libtersafe.so", 0x1ca210, "00 00 00 00");
    ModMem.Bypass58 = MemoryPatch::createWithHex("libtersafe.so", 0x1e3174, "00 00 00 00");
    ModMem.Bypass59 = MemoryPatch::createWithHex("libtersafe.so", 0x22d7b0, "00 00 00 00");
    ModMem.Bypass60 = MemoryPatch::createWithHex("libtersafe.so", 0x22d7d8, "00 00 00 00");
    ModMem.Bypass61 = MemoryPatch::createWithHex("libtersafe.so", 0x22e888, "00 00 00 00");
    ModMem.Bypass62 = MemoryPatch::createWithHex("libtersafe.so", 0x22e8b8, "00 00 00 00");
    ModMem.Bypass63 = MemoryPatch::createWithHex("libtersafe.so", 0x22e918, "00 00 00 00");
    ModMem.Bypass64 = MemoryPatch::createWithHex("libtersafe.so", 0x22ee60, "00 00 00 00");
    ModMem.Bypass65 = MemoryPatch::createWithHex("libtersafe.so", 0x22f258, "00 00 00 00");
    ModMem.Bypass66 = MemoryPatch::createWithHex("libtersafe.so", 0x22f270, "00 00 00 00");
    ModMem.Bypass67 = MemoryPatch::createWithHex("libtersafe.so", 0x22faa4, "00 00 00 00");
    ModMem.Bypass68 = MemoryPatch::createWithHex("libtersafe.so", 0x22fe94, "00 00 00 00");
    ModMem.Bypass69 = MemoryPatch::createWithHex("libtersafe.so", 0x230de4, "00 00 00 00");
    ModMem.Bypass70 = MemoryPatch::createWithHex("libtersafe.so", 0x230f74, "00 00 00 00");
    ModMem.Bypass71 = MemoryPatch::createWithHex("libtersafe.so", 0x2312bc, "00 00 00 00");
    ModMem.Bypass72 = MemoryPatch::createWithHex("libtersafe.so", 0x23135c, "00 00 00 00");
    ModMem.Bypass73 = MemoryPatch::createWithHex("libtersafe.so", 0x2315ec, "00 00 00 00");
    ModMem.Bypass74 = MemoryPatch::createWithHex("libtersafe.so", 0x231674, "00 00 00 00");
    ModMem.Bypass75 = MemoryPatch::createWithHex("libtersafe.so", 0x231918, "00 00 00 00");
    ModMem.Bypass76 = MemoryPatch::createWithHex("libtersafe.so", 0x231938, "00 00 00 00");
    ModMem.Bypass77 = MemoryPatch::createWithHex("libtersafe.so", 0x231a0c, "00 00 00 00");
    ModMem.Bypass78 = MemoryPatch::createWithHex("libtersafe.so", 0x231a10, "00 00 00 00");
    ModMem.Bypass79 = MemoryPatch::createWithHex("libtersafe.so", 0x231c30, "00 00 00 00");
    ModMem.Bypass80 = MemoryPatch::createWithHex("libtersafe.so", 0x231cb4, "00 00 00 00");
    ModMem.Bypass81 = MemoryPatch::createWithHex("libtersafe.so", 0x231ec8, "00 00 00 00");
    ModMem.Bypass82 = MemoryPatch::createWithHex("libtersafe.so", 0x232188, "00 00 00 00");
    ModMem.Bypass83 = MemoryPatch::createWithHex("libtersafe.so", 0x23218c, "00 00 00 00");
    ModMem.Bypass84 = MemoryPatch::createWithHex("libtersafe.so", 0x2326b0, "00 00 00 00");
    ModMem.Bypass85 = MemoryPatch::createWithHex("libtersafe.so", 0x232804, "00 00 00 00");
    ModMem.Bypass86 = MemoryPatch::createWithHex("libtersafe.so", 0x2330fc, "00 00 00 00");

    ModMem.Bypass87 = MemoryPatch::createWithHex("libtersafe.so", 0x2332c8, "00 00 00 00");
    ModMem.Bypass88 = MemoryPatch::createWithHex("libtersafe.so", 0x233524, "00 00 00 00");
    ModMem.Bypass89 = MemoryPatch::createWithHex("libtersafe.so", 0x23366c, "00 00 00 00");
    ModMem.Bypass90 = MemoryPatch::createWithHex("libtersafe.so", 0x23388c, "00 00 00 00");
    ModMem.Bypass91 = MemoryPatch::createWithHex("libtersafe.so", 0x234b5c, "00 00 00 00");
    ModMem.Bypass92 = MemoryPatch::createWithHex("libtersafe.so", 0x236b64, "00 00 00 00");
    ModMem.Bypass93 = MemoryPatch::createWithHex("libtersafe.so", 0x238c98, "00 00 00 00");
    ModMem.Bypass94 = MemoryPatch::createWithHex("libtersafe.so", 0x23a134, "00 00 00 00");
    ModMem.Bypass95= MemoryPatch::createWithHex("libtersafe.so", 0x23a8bc, "00 00 00 00");
    ModMem.Bypass96 = MemoryPatch::createWithHex("libtersafe.so", 0x23b208, "00 00 00 00");
    ModMem.Bypass97 = MemoryPatch::createWithHex("libtersafe.so", 0x23ba1c, "00 00 00 00");
    ModMem.Bypass98 = MemoryPatch::createWithHex("libtersafe.so", 0x23bac8, "00 00 00 00");
    ModMem.Bypass99 = MemoryPatch::createWithHex("libtersafe.so", 0x23bde0, "00 00 00 00");
    ModMem.Bypass100 = MemoryPatch::createWithHex("libtersafe.so", 0x23bf14, "00 00 00 00");
    ModMem.Bypass101 = MemoryPatch::createWithHex("libtersafe.so", 0x23bf34, "00 00 00 00");
    ModMem.Bypass102 = MemoryPatch::createWithHex("libtersafe.so", 0x23c190, "00 00 00 00");
    ModMem.Bypass103 = MemoryPatch::createWithHex("libtersafe.so", 0x23c754, "00 00 00 00");
    ModMem.Bypass104 = MemoryPatch::createWithHex("libtersafe.so", 0x23cb7c, "00 00 00 00");
    ModMem.Bypass105 = MemoryPatch::createWithHex("libtersafe.so", 0x23cbe0, "00 00 00 00");
    ModMem.Bypass106 = MemoryPatch::createWithHex("libtersafe.so", 0x23e684, "00 00 00 00");
    ModMem.Bypass107 = MemoryPatch::createWithHex("libtersafe.so", 0x23e988, "00 00 00 00");
    ModMem.Bypass108 = MemoryPatch::createWithHex("libtersafe.so", 0x23f758, "00 00 00 00");
    ModMem.Bypass109 = MemoryPatch::createWithHex("libtersafe.so", 0x2408cc, "00 00 00 00");
    ModMem.Bypass110 = MemoryPatch::createWithHex("libtersafe.so", 0x240960, "00 00 00 00");
    ModMem.Bypass111 = MemoryPatch::createWithHex("libtersafe.so", 0x241418, "00 00 00 00");
    ModMem.Bypass112 = MemoryPatch::createWithHex("libtersafe.so", 0x241468, "00 00 00 00");
    ModMem.Bypass113 = MemoryPatch::createWithHex("libtersafe.so", 0x2415e4, "00 00 00 00");
    ModMem.Bypass114 = MemoryPatch::createWithHex("libtersafe.so", 0x241880, "00 00 00 00");
    ModMem.Bypass115 = MemoryPatch::createWithHex("libtersafe.so", 0x24191c, "00 00 00 00");
    ModMem.Bypass116 = MemoryPatch::createWithHex("libtersafe.so", 0x241938, "00 00 00 00");
    ModMem.Bypass117 = MemoryPatch::createWithHex("libtersafe.so", 0x241948, "00 00 00 00");
    ModMem.Bypass118 = MemoryPatch::createWithHex("libtersafe.so", 0x241a08, "00 00 00 00");
    ModMem.Bypass119 = MemoryPatch::createWithHex("libtersafe.so", 0x241a2c, "00 00 00 00");
    ModMem.Bypass120 = MemoryPatch::createWithHex("libtersafe.so", 0x24202c, "00 00 00 00");
    ModMem.Bypass121 = MemoryPatch::createWithHex("libtersafe.so", 0x24506c, "00 00 00 00");
    ModMem.Bypass122 = MemoryPatch::createWithHex("libtersafe.so", 0x247d04, "00 00 00 00");
    ModMem.Bypass123 = MemoryPatch::createWithHex("libtersafe.so", 0x24832c, "00 00 00 00");
    ModMem.Bypass124 = MemoryPatch::createWithHex("libtersafe.so", 0x24add4, "00 00 00 00");
    ModMem.Bypass125 = MemoryPatch::createWithHex("libtersafe.so", 0x24c710, "00 00 00 00");
    ModMem.Bypass126 = MemoryPatch::createWithHex("libtersafe.so", 0x24ca50, "00 00 00 00");
    ModMem.Bypass127 = MemoryPatch::createWithHex("libtersafe.so", 0x24d0bc, "00 00 00 00");
    ModMem.Bypass128 = MemoryPatch::createWithHex("libtersafe.so", 0x24d5a0, "00 00 00 00");
    ModMem.Bypass129 = MemoryPatch::createWithHex("libtersafe.so", 0x24de14, "00 00 00 00");

    ModMem.Bypass130 = MemoryPatch::createWithHex("libtersafe.so", 0x24de2c, "00 00 00 00");
    ModMem.Bypass131 = MemoryPatch::createWithHex("libtersafe.so", 0x24e590, "00 00 00 00");
    ModMem.Bypass132 = MemoryPatch::createWithHex("libtersafe.so", 0x24eef0, "00 00 00 00");
    ModMem.Bypass133 = MemoryPatch::createWithHex("libtersafe.so", 0x24f6ac, "00 00 00 00");
    ModMem.Bypass134 = MemoryPatch::createWithHex("libtersafe.so", 0x2509b8, "00 00 00 00");
    ModMem.Bypass135 = MemoryPatch::createWithHex("libtersafe.so", 0x2509c8, "00 00 00 00");
    ModMem.Bypass136 = MemoryPatch::createWithHex("libtersafe.so", 0x25332c, "00 00 00 00");
    ModMem.Bypass137 = MemoryPatch::createWithHex("libtersafe.so", 0x25334c, "00 00 00 00");
    ModMem.Bypass138 = MemoryPatch::createWithHex("libtersafe.so", 0x253368, "00 00 00 00");
    ModMem.Bypass139 = MemoryPatch::createWithHex("libtersafe.so", 0x25345c, "00 00 00 00");
    ModMem.Bypass140 = MemoryPatch::createWithHex("libtersafe.so", 0x253fa0, "00 00 00 00");
    ModMem.Bypass141 = MemoryPatch::createWithHex("libtersafe.so", 0x2592f0, "00 00 00 00");
    ModMem.Bypass142 = MemoryPatch::createWithHex("libtersafe.so", 0x25a23c, "00 00 00 00");
    ModMem.Bypass143 = MemoryPatch::createWithHex("libtersafe.so", 0x26881c, "00 00 00 00");
    ModMem.Bypass144 = MemoryPatch::createWithHex("libtersafe.so", 0x268834, "00 00 00 00");
    ModMem.Bypass145 = MemoryPatch::createWithHex("libtersafe.so", 0x2688bc, "00 00 00 00");
    ModMem.Bypass146 = MemoryPatch::createWithHex("libtersafe.so", 0x26896c, "00 00 00 00");
    ModMem.Bypass147 = MemoryPatch::createWithHex("libtersafe.so", 0x2689b4, "00 00 00 00");
    ModMem.Bypass148 = MemoryPatch::createWithHex("libtersafe.so", 0x26d9d0, "00 00 00 00");
    ModMem.Bypass149 = MemoryPatch::createWithHex("libtersafe.so", 0x26e7b0, "00 00 00 00");
    ModMem.Bypass150 = MemoryPatch::createWithHex("libtersafe.so", 0x26eb64, "00 00 00 00");
    ModMem.Bypass151 = MemoryPatch::createWithHex("libtersafe.so", 0x26f2b4, "00 00 00 00");
    ModMem.Bypass152 = MemoryPatch::createWithHex("libtersafe.so", 0x27ace8, "00 00 00 00");
    ModMem.Bypass153 = MemoryPatch::createWithHex("libtersafe.so", 0x27ade8, "00 00 00 00");
    ModMem.Bypass154 = MemoryPatch::createWithHex("libtersafe.so", 0x283bd4, "00 00 00 00");
    ModMem.Bypass155 = MemoryPatch::createWithHex("libtersafe.so", 0x284bc4, "00 00 00 00");
    ModMem.Bypass156 = MemoryPatch::createWithHex("libtersafe.so", 0x2c73a8, "00 00 00 00");
    ModMem.Bypass175 = MemoryPatch::createWithHex("LIBUE4.SO", 0X63AEC70, "00 00 00 00");
    ModMem.Bypass176 = MemoryPatch::createWithHex("LIBUE4.SO", 0X63AEC2C, "00 00 00 00");
    ModMem.Bypass178 = MemoryPatch::createWithHex("LIBUE4.SO", 0X53F8E30, "00 00 00 00");
    ModMem.Bypass179 = MemoryPatch::createWithHex("LIBUE4.SO", 0X53F6EDC, "00 00 00 00");
    ModMem.Bypass180 = MemoryPatch::createWithHex("LIBUE4.SO", 0X53F6A8C, "00 00 00 00");
    ModMem.Bypass181 = MemoryPatch::createWithHex("LIBUE4.SO", 0X5403820, "00 00 00 00");
    ModMem.Bypass182 = MemoryPatch::createWithHex("LIBUE4.SO", 0X54037AC, "00 00 00 00");
    ModMem.Bypass183 = MemoryPatch::createWithHex("LIBUE4.SO", 0X54018CC, "00 00 00 00");
    ModMem.Bypass184 = MemoryPatch::createWithHex("LIBUE4.SO", 0X644DF18, "00 00 00 00");
    ModMem.Bypass185 = MemoryPatch::createWithHex("LIBUE4.SO", 0X644D3E4, "00 00 00 00");
    ModMem.Bypass186 = MemoryPatch::createWithHex("LIBUE4.SO", 0X644D304, "00 00 00 00");
    ModMem.Bypass187 = MemoryPatch::createWithHex("LIBUE4.SO", 0X63AEC74, "00 00 00 00");
    ModMem.Bypass188 = MemoryPatch::createWithHex("LIBUE4.SO", 0x477680, "00 00 00 00");
    ModMem.Bypass189 = MemoryPatch::createWithHex("LIBUE4.SO", 0x9653EC, "00 00 A0 E3");
    ModMem.Bypass190 = MemoryPatch::createWithHex("LIBUE4.SO", 0xB97BC4, "1E FF 2F E1");
    ModMem.Bypass191 = MemoryPatch::createWithHex("LIBUE4.SO", 0x4774FC, "00 00 00 00");
    ModMem.Bypass192 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476834, "00 00 00 00");
    ModMem.Bypass193 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476584, "00 00 00 00");
    ModMem.Bypass194 = MemoryPatch::createWithHex("LIBUE4.SO", 0x47634C, "00 00 00 00");
    ModMem.Bypass195 = MemoryPatch::createWithHex("LIBUE4.SO", 0x4762F0, "00 00 00 00");
    ModMem.Bypass196 = MemoryPatch::createWithHex("LIBUE4.SO", 0x47602C, "00 00 00 00");
    ModMem.Bypass197 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476020, "00 00 00 00");
    ModMem.Bypass198 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476018, "00 00 00 00");
    ModMem.Bypass199 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18BB6FEC, "00 00 00 00");
    ModMem.Bypass200 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EE6F8, "00 00 00 00");
    ModMem.Bypass201 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F6C, "00 00 00 00");
    ModMem.Bypass202 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F6C, "00 00 00 00");
    ModMem.Bypass203 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F70, "00 00 00 00");
    ModMem.Bypass204 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EF300, "00 00 00 00");
    ModMem.Bypass205 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F6C, "00 00 00 00");
    ModMem.Bypass206 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EF8B8, "00 00 00 00");
    ModMem.Bypass207 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EFA6C, "00 00 00 00");
    ModMem.Bypass208 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18BB6FE4, "00 00 00 00");
    ModMem.Bypass209 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F64, "00 00 00 00");
    ModMem.Bypass210 = MemoryPatch::createWithHex("LIBUE4.SO", 0x8E7CFDC, "00 00 00 00");
    ModMem.Bypass211 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EF8B8, "00 00 00 00");
    ModMem.Bypass212 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F64, "00 00 00 00");
    ModMem.Bypass213 = MemoryPatch::createWithHex("LIBUE4.SO", 0x348044, "00 00 00 00");
    ModMem.Bypass214 = MemoryPatch::createWithHex("LIBUE4.SO", 0x3CB2468, "00 00 00 00");
    ModMem.Bypass215 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1DFB820, "00 00 00 00");
    ModMem.Bypass216 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1DFB770, "00 00 00 00");
    ModMem.Bypass217 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1E78E4C, "00 00 00 00");
    ModMem.Bypass218 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1D09150, "00 00 00 00");
    ModMem.Bypass219 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1C9ACf8, "00 00 00 00");
    ModMem.Bypass220 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1D09134, "00 00 00 00");
    ModMem.Bypass221 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1C8C854, "00 00 00 00");
    ModMem.Bypass222 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1F10E7C, "00 00 00 00");
    ModMem.Bypass223 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1DFB784, "00 00 00 00");
    ModMem.Bypass224 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b5b37c, "00 00 00 00");
    ModMem.Bypass225 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b5a9cc, "00 00 00 00");
    ModMem.Bypass226 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b59cec, "00 00 00 00");
    ModMem.Bypass227 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b5cbe4, "00 00 00 00");
    ModMem.Bypass228 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b5a19c, "00 00 00 00");
    ModMem.Bypass229 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7bba93c, "00 00 00 00");
    ModMem.Bypass230 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7bbab44, "00 00 00 00");
    ModMem.Bypass231 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7bb91d0, "00 00 00 00");
    ModMem.Bypass232 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7bb91e4, "00 00 00 00");
    ModMem.Bypass233 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7bbaf8c, "00 00 00 00");
    ModMem.Bypass234 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7bbcf30, "00 00 00 00");
    ModMem.Bypass235 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7bbdbe0, "00 00 00 00");
    ModMem.Bypass236 = MemoryPatch::createWithHex("LIBUE4.SO", 0x57b228, "00 00 00 00");
    ModMem.Bypass237 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7303968, "00 00 00 00");
    ModMem.Bypass238 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7303980, "00 00 00 00");
    ModMem.Bypass239 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7304fe0, "00 00 00 00");
    ModMem.Bypass240 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7c86024, "00 00 00 00");
    ModMem.Bypass241 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b5893c, "00 00 00 00");
    ModMem.Bypass242 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b58b44, "00 00 00 00");
    ModMem.Bypass243 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b58f28, "00 00 00 00");
    ModMem.Bypass244 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b593a4, "00 00 00 00");
    ModMem.Bypass245 = MemoryPatch::createWithHex("LIBUE4.SO", 0x5471b00, "00 00 00 00");
    ModMem.Bypass246 = MemoryPatch::createWithHex("LIBUE4.SO", 0x5466298, "00 00 00 00");
    ModMem.Bypass247 = MemoryPatch::createWithHex("LIBUE4.SO", 0x545dc38, "00 00 00 00");
    ModMem.Bypass248 = MemoryPatch::createWithHex("LIBUE4.SO", 0x546977c, "00 00 00 00");
    ModMem.Bypass249 = MemoryPatch::createWithHex("LIBUE4.SO", 0x54672ec, "00 00 00 00");
    ModMem.Bypass250 = MemoryPatch::createWithHex("LIBUE4.SO", 0x547fe34, "00 00 00 00");
    ModMem.Bypass251 = MemoryPatch::createWithHex("LIBUE4.SO", 0x63e4564, "00 00 00 00");
    ModMem.Bypass252 = MemoryPatch::createWithHex("LIBUE4.SO", 0x7b5c37c, "00 00 00 00");
    ModMem.Bypass253 = MemoryPatch::createWithHex("LIBUE4.SO", 0xb037580, "00 00 00 00");
    ModMem.Bypass254 = MemoryPatch::createWithHex("LIBUE4.SO", 0x5c74304, "00 00 00 00");
    ModMem.Bypass255 = MemoryPatch::createWithHex("LIBUE4.SO", 0x00001B0E, "00 00 00 00");
    ModMem.Bypass256 = MemoryPatch::createWithHex("LIBUE4.SO", 0x0032CB80, "00 00 00 00");
    ModMem.Bypass257 = MemoryPatch::createWithHex("LIBUE4.SO", 0x000017D0, "00 00 00 00");
    ModMem.Bypass258 = MemoryPatch::createWithHex("LIBUE4.SO", 0x00001D58, "00 00 00 00");
    ModMem.Bypass259 = MemoryPatch::createWithHex("LIBUE4.SO", 0x00322280, "00 00 00 00");
    ModMem.Bypass260 = MemoryPatch::createWithHex("LIBUE4.SO", 0xA4494, "00 00 00 00");
    ModMem.Bypass261 = MemoryPatch::createWithHex("LIBUE4.SO", 0X33C798, "00 00 00 00");
    ModMem.Bypass262 = MemoryPatch::createWithHex("LIBUE4.SO", 0X33CF9C, "00 00 00 00");
    ModMem.Bypass263 = MemoryPatch::createWithHex("LIBUE4.SO", 0x348314, "00 00 00 00");
    ModMem.Bypass264 = MemoryPatch::createWithHex("LIBUE4.SO", 0X5FCCC, "00 00 00 00");
    ModMem.Bypass265 = MemoryPatch::createWithHex("LIBUE4.SO", 0x477680, "00 00 00 00");
    ModMem.Bypass266 = MemoryPatch::createWithHex("LIBUE4.SO", 0x4774FC, "00 00 00 00");
    ModMem.Bypass267 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476834, "00 00 00 00");
    ModMem.Bypass268 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476584, "00 00 00 00");
    ModMem.Bypass269 = MemoryPatch::createWithHex("LIBUE4.SO", 0x47634C, "00 00 00 00");
    ModMem.Bypass270 = MemoryPatch::createWithHex("LIBUE4.SO", 0x4762F0, "00 00 00 00");
    ModMem.Bypass271 = MemoryPatch::createWithHex("LIBUE4.SO", 0x47602C, "00 00 00 00");
    ModMem.Bypass272 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476020, "00 00 00 00");
    ModMem.Bypass273 = MemoryPatch::createWithHex("LIBUE4.SO", 0x476018, "00 00 00 00");
    ModMem.Bypass274 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18BB6FEC, "00 00 00 00");
    ModMem.Bypass275 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EE6F8, "00 00 00 00");
    ModMem.Bypass276 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F6C, "00 00 00 00");
    ModMem.Bypass277 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F6C, "00 00 00 00");
    ModMem.Bypass278 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F70, "00 00 00 00");
    ModMem.Bypass279 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EF300, "00 00 00 00");
    ModMem.Bypass280 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F6C, "00 00 00 00");
    ModMem.Bypass281 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EF8B8, "00 00 00 00");
    ModMem.Bypass282 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EFA6C, "00 00 00 00");
    ModMem.Bypass283 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18BB6FE4, "00 00 00 00");
    ModMem.Bypass284 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F64, "00 00 00 00");
    ModMem.Bypass285 = MemoryPatch::createWithHex("LIBUE4.SO", 0x8E7CFDC, "00 00 00 00");
    ModMem.Bypass286 = MemoryPatch::createWithHex("LIBUE4.SO", 0x217EF8B8, "00 00 00 00");
    ModMem.Bypass287 = MemoryPatch::createWithHex("LIBUE4.SO", 0x18B86F64, "00 00 00 00");
    ModMem.Bypass288 = MemoryPatch::createWithHex("LIBUE4.SO", 0x9653EC, "00 00 00 00");
    ModMem.Bypass289 = MemoryPatch::createWithHex("LIBUE4.SO", 0xB97BC4, "00 00 00 00");
    ModMem.Bypass290 = MemoryPatch::createWithHex("LIBUE4.SO", 0x348044, "00 00 00 00");
    ModMem.Bypass291 = MemoryPatch::createWithHex("LIBUE4.SO", 0x3CB2468, "00 00 00 00");
    ModMem.Bypass292 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1DFB820, "00 00 00 00");
    ModMem.Bypass293 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1DFB770, "00 00 00 00");
    ModMem.Bypass294 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1E78E4C, "00 00 00 00");
    ModMem.Bypass295 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1D09150, "00 00 00 00");
    ModMem.Bypass296 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1C9ACf8, "00 00 00 00");
    ModMem.Bypass297 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1D09134, "00 00 00 00");
    ModMem.Bypass298 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1C8C854, "00 00 00 00");
    ModMem.Bypass299 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1F10E7C, "00 00 00 00");
    ModMem.Bypass300 = MemoryPatch::createWithHex("LIBUE4.SO", 0x1DFB784, "00 00 00 00");
    ModMem.Bypass301 = MemoryPatch::createWithHex("LIBUE4.SO", 0X63AEC70, "00 00 00 00");
    ModMem.Bypass302 = MemoryPatch::createWithHex("LIBUE4.SO", 0X63AEC2C, "00 00 00 00");
    ModMem.Bypass303 = MemoryPatch::createWithHex("LIBUE4.SO", 0X53F8E30, "00 00 00 00");
    ModMem.Bypass304 = MemoryPatch::createWithHex("LIBUE4.SO", 0X53F6EDC, "00 00 00 00");
    ModMem.Bypass305 = MemoryPatch::createWithHex("LIBUE4.SO", 0X53F6A8C, "00 00 00 00");
    ModMem.Bypass306 = MemoryPatch::createWithHex("LIBUE4.SO", 0X5403820, "00 00 00 00");
    ModMem.Bypass307 = MemoryPatch::createWithHex("LIBUE4.SO", 0X54037AC, "00 00 00 00");
    ModMem.Bypass308 = MemoryPatch::createWithHex("LIBUE4.SO", 0X54018CC, "00 00 00 00");
    ModMem.Bypass309 = MemoryPatch::createWithHex("LIBUE4.SO", 0X644DF18, "00 00 00 00");
    ModMem.Bypass310 = MemoryPatch::createWithHex("LIBUE4.SO", 0X644D3E4, "00 00 00 00");
    ModMem.Bypass311 = MemoryPatch::createWithHex("LIBUE4.SO", 0X644D304, "00 00 00 00");
    ModMem.Bypass312 = MemoryPatch::createWithHex("LIBUE4.SO", 0X63AEC74, "00 00 00 00");
    ModMem.Bypass313 = MemoryPatch::createWithHex("Libtersafe.so", 0x00001B0E, "00 00 00 00");
    ModMem.Bypass314 = MemoryPatch::createWithHex("Libtersafe.so", 0x0032CB80, "00 00 00 00");
    ModMem.Bypass315 = MemoryPatch::createWithHex("Libtersafe.so", 0x000017D0, "00 00 00 00");
    ModMem.Bypass316 = MemoryPatch::createWithHex("Libtersafe.so", 0x00001D58, "00 00 00 00");
    ModMem.Bypass317 = MemoryPatch::createWithHex("Libtersafe.so", 0x00322280, "00 00 00 00");
    ModMem.Bypass318 = MemoryPatch::createWithHex("Libtersafe.so", 0xA4494, "00 00 00 00");
    ModMem.Bypass319 = MemoryPatch::createWithHex("Libtersafe.so", 0X33C798, "00 00 00 00");
    ModMem.Bypass320 = MemoryPatch::createWithHex("Libtersafe.so", 0X33CF9C, "00 00 00 00");
    ModMem.Bypass321 = MemoryPatch::createWithHex("Libtersafe.so", 0x348314, "00 00 00 00");
    ModMem.Bypass322 = MemoryPatch::createWithHex("Libtersafe.so", 0X5FCCC, "00 00 00 00");
    return NULL;
}
__attribute__((constructor))
void initializer() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, Super_thread, NULL);
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
    return JNI_VERSION_1_6;
}


JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *vm, void *reserved) {
}
}

