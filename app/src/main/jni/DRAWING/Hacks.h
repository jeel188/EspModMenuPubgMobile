#ifndef JEEL_PATEL_HACKS_H
#define JEEL_PATEL_HACKS_H
#include "support.h"
#include "init.h"
#include "import.h"
#include "Memory.h"
#include "Process.h"
#include "Color.h"
#include "Config.h"
#include <thread>
#include <sys/uio.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <thread>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <stdio.h>
#include <sys/un.h>
#include <time.h>
#include <ctype.h>
#include <iostream>

Color colorShootEnemy = Color::Red();
Color colorSeekbarAimbotRange = Color::Red();

Response response{};
char weaponData[100];
char VehicleName[50];
char extra[30];
char PlayerNameByte[100];
int type = 69;
int myteamID = 101;
int TeamID;
float Health;
float x, y;
float Distance;
bool isBot;
Offset offset;
Vector3 HeadLocation;
PlayerWeapon Weapon;
PlayerBone Bone;
kaddr pBase;
int botCount, playerCount, grenadeCount;
Color clr, clrHealth, _colorByDistance;
Vector3 Location;

#define PI 3.141592653589793238

char *getNameByte(kaddr address)
{
    char static lj[64];
    memset(lj, 0, 64);
    unsigned short int nameI[32];
    pvm(address, nameI, sizeof(nameI));
    char s[10];
    int i;
    for (i = 0; i < 32; i++)
    {
        if (nameI[i] == 0)
            break;
        sprintf(s, "%d:", nameI[i]);
        strcat(lj, s);
    }
    lj[63] = '\0';

    return lj;
}
uintptr_t getMatrix(uintptr_t base)
{
    return getA(getA(base + offset.viewWorld) + 0x7c); // ViewWorld
}

uintptr_t getEntityAddr(uintptr_t base)
{
    return getA(getA(getA(base + offset.gworld)) + 0x20) + 0x7c; // GWorld
}
PlayerBone getPlayerBone(uintptr_t pBase, struct D3DMatrix viewMatrix)
{
    PlayerBone b;
    b.isBone = true;
    struct D3DMatrix oMatrix;
    kaddr boneAddr = getA(pBase + offset.boneStruct);
    struct D3DMatrix baseMatrix = getOMatrix(boneAddr + offset.boneMatrix);
    //int bones[] = { 4, 3, 0, 11, 32, 12, 33, 63, 62, 52, 56, 53, 57, 54, 58 };
    int bones[15] = {4, 3, 0, 11, 32, 12, 33, 63, 62, 52, 56, 53, 57, 54, 58};

    boneAddr = getA(boneAddr + offset.bonePntr);
    // neck 0
    oMatrix = getOMatrix(boneAddr + (bones[0]) * 48);
    b.neck = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // cheast 1
    oMatrix = getOMatrix(boneAddr + (bones[1]) * 48);
    b.cheast = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // pelvis 2
    oMatrix = getOMatrix(boneAddr + (bones[2]) * 48);
    b.pelvis = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // lSh 3
    oMatrix = getOMatrix(boneAddr + (bones[3]) * 48);
    b.lSh = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // rSh 4
    oMatrix = getOMatrix(boneAddr + (bones[4]) * 48);
    b.rSh = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // lElb 5
    oMatrix = getOMatrix(boneAddr + (bones[5]) * 48);
    b.lElb = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // rElb 6
    oMatrix = getOMatrix(boneAddr + (bones[6]) * 48);
    b.rElb = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // lWr 7
    oMatrix = getOMatrix(boneAddr + (bones[7]) * 48);
    b.lWr = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // rWr 8
    oMatrix = getOMatrix(boneAddr + (bones[8]) * 48);
    b.rWr = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // lTh 9
    oMatrix = getOMatrix(boneAddr + (bones[9]) * 48);
    b.lTh = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // rTh 10
    oMatrix = getOMatrix(boneAddr + (bones[10]) * 48);
    b.rTh = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // lKn 11
    oMatrix = getOMatrix(boneAddr + (bones[11]) * 48);
    b.lKn = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // rKn 12
    oMatrix = getOMatrix(boneAddr + (bones[12]) * 48);
    b.rKn = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // lAn 13
    oMatrix = getOMatrix(boneAddr + (bones[13]) * 48);
    b.lAn = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));
    // rAn 14
    oMatrix = getOMatrix(boneAddr + (bones[14]) * 48);
    b.rAn = World2ScreenMain(viewMatrix, mat2Cord(oMatrix, baseMatrix));

    return b;
}
PlayerWeapon getPlayerWeapon(uintptr_t libbase)
{

    PlayerWeapon p;

    uintptr_t addr[3];

    pvm(getA(libbase + offset.weaponBase), addr, sizeof(addr));

    if (isValid32(addr[0]) && getI(addr[0] + offset.weaponValidation) == offset.weaponValidationValue)
    { //BodySetup* BodySetup;//[Offset: 0xdc up
        p.isWeapon = true;
        p.id = getI(getA(addr[0] + offset.weaponIDPntr) + offset.weaponID);
        p.ammo = getI(addr[0] + offset.ammo);
    }
    else if (isValid32(addr[1]) && getI(addr[1] + offset.weaponValidation) == offset.weaponValidationValue)
    { //PhysicsAsset* PhysicsAsset;//[Offset:
        p.isWeapon = true;
        p.id = getI(getA(addr[1] + offset.weaponIDPntr) + offset.weaponID);
        p.ammo = getI(addr[1] + offset.ammo);
    }
    else if (isValid32(addr[2]) && getI(addr[2] + offset.weaponValidation) == offset.weaponValidationValue)
    {
        p.isWeapon = true;
        p.id = getI(getA(addr[2] + offset.weaponIDPntr) + offset.weaponID);
        p.ammo = getI(addr[2] + offset.ammo);
    }

    return p;
}

kaddr getbsaddr(int pid)
{
    FILE *fp;
    uintptr_t addr = 0;
    char filename[40], buffer[1024];
    snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
    fp = fopen(filename, "rt");
    if (fp != NULL)
    {
        while (fgets(buffer, sizeof(buffer), fp))
        {
            if (strstr(buffer, "libUE4.so"))
            {
                addr = (uintptr_t)strtoul(buffer, NULL, 16);
                break;
            }
        }
        fclose(fp);
    }
    return addr;
}

void p_write(uintptr_t address, void *buffer, int size)
{
    struct iovec local[1];
    struct iovec remote[1];

    local[0].iov_base = (void *)buffer;
    local[0].iov_len = size;
    remote[0].iov_base = (void *)address;
    remote[0].iov_len = size;

    process_vm_writev(target_pid, local, 1, remote, 1, 0);
}
Vector2 getPointingAngle(Vector3 camera, Vector3 xyz, float distance)
{
    Vector2 PointingAngle;
    float ytime = distance / 88000;

    xyz.Z = xyz.Z + 360 * ytime * ytime;

    float zbcx = xyz.X - camera.X;
    float zbcy = xyz.Y - camera.Y;
    float zbcz = xyz.Z - camera.Z;
    PointingAngle.Y = atan2(zbcy, zbcx) * 180 / PI; // 57.3
    PointingAngle.X = atan2(zbcz, sqrt(zbcx * zbcx + zbcy * zbcy)) * 180 / PI;

    return PointingAngle;
}
Options options{
        1, 0, 3, false, 1, false, 201};
void DrawESP(ESP sViewDrawing, int screenWidth, int screenHeight)
{
    response.Success = false;
    botCount = 0;
    playerCount = 0;
    grenadeCount = 0;
    struct Vector3 exyz;
    struct D3DMatrix vMat;
    struct Vector3 xyz;
    Vector2 pointingAngle;
    bool aimbot = false;
    bool aimKnoced = false;
    bool tracingStatus = true;

    uintptr_t yawPitch = 0;
    uintptr_t enAddrPntr;
    uintptr_t aimatRecord = 0;

    float aimRadius = 0;
    int openMirror;
    int fire;
    int aimbotmode = 1; //Head
    int openState = 1;
    int aimingState = 3; //Fire + Scope

    int priority = 1; //CrosaHair
    int pour = 0;
    int aimingRange = 0;
    int firing = 0;
    int ads = 0;
    int aimFor = 1;
    int aimBy = 1;
    int aimWhen = 3;

    aimRadius = (float)options.aimingRange;
    aimFor = options.aimbotmode;
    aimbot = options.openState == 0;
    aimWhen = options.aimingState;
    aimBy = options.priority;
    aimKnoced = options.pour;

    target_pid = find_pid("com.pubg.imobile");

    if (target_pid == 0)
    {
        return;
    }

    libbase = getbsaddr(target_pid);
    uintptr_t vMatrix = getMatrix(libbase);
    uintptr_t cLoc = vMatrix + offset.cLoc;
    uintptr_t fovPntr = vMatrix + offset.fovPntr;
    vMatrix = vMatrix + offset.vMatrix;

    char loaded[0x4000], loadedpn[20];
    char name[100];
    char cont[0x500];
    char boneData[1024];
    float textsize = screenHeight / 50;
    height = screenHeight;
    width = screenWidth;
    pvm(cLoc, &xyz, sizeof(xyz));
    if ((xyz.Z == 88.441124f || xyz.X == 0 || xyz.Z == 5278.43f || xyz.Z == 88.440918f))
    {
    }
    pvm(fovPntr, &response.fov, 4);
    pvm(vMatrix, &vMat, sizeof(vMat));
    enAddrPntr = getEntityAddr(libbase);
    Ulevel ulevel;
    pvm(enAddrPntr, &ulevel, sizeof(ulevel));
    if (ulevel.size < 1 || ulevel.size > 0x1000 || !isValid32(ulevel.addr))
    {
    }
    strcpy(loaded, "");
    float nearest = -1.0f;
    firing = 0;
    ads = 0;
    for (int i = 0; i < ulevel.size; i++)
    {
        uintptr_t pBase = getA(ulevel.addr + i * SIZE);
        if (!isValid32(pBase))
            continue;
        sprintf(loadedpn, "%lx,", pBase);
        if (strstr(loaded, loadedpn))
            continue;
        strcat(loaded, loadedpn);

        int oType = getI(pBase + offset.oType); //Otype Offsets

        if (oType == 0x1d85400 || oType == 0x1d85000)
        { ///PLayer

            if (getI(pBase + offset.bDead))
                continue;

            pvm(pBase + offset.health, healthbuff, sizeof(healthbuff));
            if (healthbuff[1] > 200.0f || healthbuff[1] < 50.0f || healthbuff[0] > healthbuff[1] || healthbuff[0] < 0.0f)
                continue;

            Health = healthbuff[0] / healthbuff[1] * 100;

            TeamID = getI(pBase + offset.teamID);
            if (TeamID < 1 || TeamID > 0x1000)
                continue;
            //meeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
            uintptr_t me = getI(pBase + offset.me);

            if (me == 258)
            {

                if (aimbot)
                {
                    yawPitch = getA(pBase + offset.Controller /*Class: Pawn.Actor.Object to Controller* Controller Update 1.4 0x2ec*/) + offset.Rotator /*Class: Controller.Actor.Object to Rotator ControlRotation update 1.4 0x2e8*/;
                    if (aimWhen == 3 || aimWhen == 2)
                        pvm(pBase + offset.isGunFiring, &firing, 1); //bool bIsWeaponFiring; update 0xdf0
                    if (aimWhen == 3 || aimWhen == 1)
                        pvm(pBase + offset.isGunADS, &ads, 1); //bool bIsGunADS; update 0xa89
                }
                myteamID = TeamID;
                continue;
            }
            else if (me != 257)
                continue;

            if (TeamID == myteamID && myteamID <= 100)
                continue;
            pvm(getA(pBase + 0x3050) + 0xfc, &exyz, sizeof(exyz));
            HeadLocation = World2Screen(vMat, exyz);
            Distance = getDistance(xyz, exyz);
            if (Distance > 600.0f)
                continue;
            pvm(pBase + 0x6e8, &isBot, sizeof(isBot));
            strcpy(PlayerNameByte, "66:111:116:");
            if (HeadLocation.Z != 1.0f && HeadLocation.X < width + 100 && HeadLocation.X > -50)
            {
                if (!isBot)
                {
                    Bone = getPlayerBone(pBase, vMat);
                    Weapon = getPlayerWeapon(pBase);
                    strcpy(PlayerNameByte, getNameByte(getA(pBase + 0x648)));
                    if (strlen(PlayerNameByte) < 4)
                        continue;
                }
            }
            if (HeadLocation.Z != 1.0f && (aimKnoced || Health > 0) && aimbot)
            {
                float centerDist = sqrt((HeadLocation.X - width / 2) * (HeadLocation.X - width / 2) + (HeadLocation.Y - height / 2) * (HeadLocation.Y - height / 2));
                if (centerDist < aimRadius)
                {
                    if (aimBy != 1)
                        centerDist = Distance;
                    if (nearest > centerDist || nearest < 0)
                    {

                        nearest = centerDist;
                        if (aimFor == 1)
                            pointingAngle = getPointingAngle(xyz, exyz, Distance);
                        else if (aimFor == 2)
                        {

                            uintptr_t boneAddr = getA(pBase + offset.boneStruct); //SkeletalMeshComponent*
                            struct D3DMatrix baseMatrix = getOMatrix(boneAddr + offset.boneMatrix);
                            boneAddr = getA(boneAddr + offset.bonePntr);
                            struct D3DMatrix oMatrix = getOMatrix(boneAddr + 4 * 48);
                            pointingAngle = getPointingAngle(xyz, mat2Cord(oMatrix, baseMatrix), Distance);
                        }
                        else
                        {
                            uintptr_t boneAddr = getA(pBase + offset.boneStruct); //SkeletalMeshComponent*
                            struct D3DMatrix baseMatrix = getOMatrix(boneAddr + offset.boneMatrix);
                            boneAddr = getA(boneAddr + offset.bonePntr);
                            struct D3DMatrix oMatrix = getOMatrix(boneAddr + 2 * 48);
                            pointingAngle = getPointingAngle(xyz, mat2Cord(oMatrix, baseMatrix), Distance);
                        }
                        if (aimFor == 3)
                        {
                            uintptr_t boneAddr = getA(pBase + offset.boneStruct); //SkeletalMeshComponent*
                            struct D3DMatrix baseMatrix = getOMatrix(boneAddr + offset.boneMatrix);
                            boneAddr = getA(boneAddr + offset.bonePntr);
                            struct D3DMatrix oMatrix = getOMatrix(boneAddr + 12 * 48);
                            pointingAngle = getPointingAngle(xyz, mat2Cord(oMatrix, baseMatrix), Distance);
                        }
                        else if (aimFor == 4)
                        {
                            uintptr_t boneAddr = getA(pBase + offset.boneStruct); //SkeletalMeshComponent*
                            struct D3DMatrix baseMatrix = getOMatrix(boneAddr + offset.boneMatrix);
                            boneAddr = getA(boneAddr + offset.bonePntr);
                            struct D3DMatrix oMatrix = getOMatrix(boneAddr + 59 * 48);
                            pointingAngle = getPointingAngle(xyz, mat2Cord(oMatrix, baseMatrix), Distance);
                        }
                    }
                }
            }

            if ((firing || ads) && nearest > 0)
            {
                p_write(yawPitch, &pointingAngle, 8); //8
            }

            if (isBot)
            {
                _colorByDistance;
            }
            else
            {
                _colorByDistance;
            }

            if (isBot)
            {
                botCount++;
            }
            else
            {
                playerCount++;
                clr.r = 0;
                clr.g = 232;
                clr.b = 0;
                clr.a = 255;
            }
            if (options.openState == 0)
                sViewDrawing.CanvasDrawCircle(Color(255, 100, 0, 255),
                                              Vector22(screenWidth / 2, screenHeight / 2), options.aimingRange, screenHeight / 500);
            x = HeadLocation.X;
            y = HeadLocation.Y;
            Color _colorByDistance = colorByDistance((int)Distance, 255);
            float magic_number = (Distance);
            float mx = (screenWidth / 4) / magic_number;
            float my = (screenWidth / 1.38) / magic_number;
            float top = y - my + (screenWidth / 1.7) / magic_number;
            float bottom = y + my + screenHeight / 4 / magic_number;

            if (HeadLocation.Z != 1)
            {
                if (x > -50 && x < screenWidth + 50)
                { //onScreen
                    if (isSkelton1)
                    { //Skelton
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(x, y), Vector22(Bone.neck.X, Bone.neck.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.neck.X, Bone.neck.Y), Vector22(Bone.cheast.X, Bone.cheast.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.cheast.X, Bone.cheast.Y), Vector22(Bone.pelvis.X, Bone.pelvis.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.neck.X, Bone.neck.Y), Vector22(Bone.lSh.X, Bone.lSh.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.neck.X, Bone.neck.Y), Vector22(Bone.rSh.X, Bone.rSh.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.lSh.X, Bone.lSh.Y), Vector22(Bone.lElb.X, Bone.lElb.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.rSh.X, Bone.rSh.Y), Vector22(Bone.rElb.X, Bone.rElb.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.lElb.X, Bone.lElb.Y), Vector22(Bone.lWr.X, Bone.lWr.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.rElb.X, Bone.rElb.Y), Vector22(Bone.rWr.X, Bone.rWr.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.pelvis.X, Bone.pelvis.Y), Vector22(Bone.lTh.X, Bone.lTh.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.pelvis.X, Bone.pelvis.Y), Vector22(Bone.rTh.X, Bone.rTh.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.lTh.X, Bone.lTh.Y), Vector22(Bone.lKn.X, Bone.lKn.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.rTh.X, Bone.rTh.Y), Vector22(Bone.rKn.X, Bone.rKn.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.lKn.X, Bone.lKn.Y), Vector22(Bone.lAn.X, Bone.lAn.Y));
                        sViewDrawing.CanvasDrawLine(Color().White(), 2.3, Vector22(Bone.rKn.X, Bone.rKn.Y), Vector22(Bone.rAn.X, Bone.rAn.Y));
                    }
                    if (isPlayerBox)
                        sViewDrawing.CanvasDrawRect(_colorByDistance, screenHeight / 500,
                                                    Vector22(x - mx, top), Vector22(x + mx, bottom));

                    if (isPlayerHealth)
                    {
                        float healthLength = screenWidth / 50; //60
                        if (healthLength < mx)
                            healthLength = mx;
                        if (Health < 25)
                            clrHealth = Color(200, 0, 0);
                        else if (Health < 50)
                            clrHealth = Color(200, 150, 0);
                        else if (Health < 75)
                            clrHealth = Color(0, 200, 0);
                        else
                            clrHealth = Color(0, 200, 0);
                        if (Health == 0)
                            sViewDrawing.CanvasDrawRect2(Color(0, 0, 0, 0), screenHeight / 660,
                                                         Vector22(x - healthLength, top - screenHeight / 20),
                                                         Vector22(x + healthLength, top - screenHeight / 40));
                        else
                        {
                            sViewDrawing.CanvasDrawRect2(Color(0, 0, 0, 0), screenHeight / 660,
                                                         Vector22(x - healthLength, top - screenHeight / 100),
                                                         Vector22(x + healthLength + 2, top - screenHeight / 40));

                            sViewDrawing.CanvasDrawFilledRect3(clrHealth,
                                                               Vector22(x - healthLength, top - screenHeight / 100),
                                                               Vector22(x - healthLength + (2 * healthLength) * Health / 100,
                                                                        top - screenHeight / 40));

                            sViewDrawing.CanvasDrawRect2(Color(0, 0, 0, 0), screenHeight / 660,
                                                         Vector22(x - healthLength, top - screenHeight / 20),
                                                         Vector22(x + healthLength, top - screenHeight / 40));
                        }
                    }

                    if (isPlayerHead)
                        sViewDrawing.CanvasDrawHead(Color(255, 255, 255, 255),
                                                    Vector22(HeadLocation.X, HeadLocation.Y),
                                                    screenHeight / 5 / magic_number);

                    if (isPlayerName)
                        if (isBot)
                        {

                            sViewDrawing.CanvasDrawTextNormal(Color(255, 255, 255), "🤖 Robot",
                                                              Vector22(x - 60, top - 50), 13);
                            sViewDrawing.CanvasDrawName(Color(255, 255, 0), PlayerNameByte, TeamID,
                                                        Vector22(x - 35, top - 25), textsize);
                            //	sViewDrawing.CanvasDrawName2(Color().White(),PlayerNation, TeamID,
                            //                    Vector22(x, top - 28), textsize);
                            //	sViewDrawing.CanvasDrawName3(Color().White(),PlayerUID,
                            //                    Vector22(x, top - 28), textsize);
                        }
                        else
                        {
                            sViewDrawing.CanvasDrawTextNormal(Color(255, 255, 255), "⛑ Players",
                                                              Vector22(x - 60, top - 50), 13);
                            sViewDrawing.CanvasDrawName(Color(255, 255, 0), PlayerNameByte, TeamID,
                                                        Vector22(x - 35, top - 25), textsize);
                            //sViewDrawing.CanvasDrawName2(Color().White(),PlayerNation, TeamID,
                            //                   Vector22(x, top - 28), textsize);
                            //sViewDrawing.CanvasDrawName3(Color().White(),PlayerUID,
                            //            Vector22(x, top - 28), textsize);
                        }

                    if (isPlayerDist)
                    {
                        sprintf(extra, "%0.0fM", Distance);
                        sViewDrawing.CanvasDrawTextDistance(Color(255, 255, 255), extra,
                                                            Vector22(x + 140, top - 25), textsize);
                    }
                    if (isEnemyWeapon && Weapon.isWeapon)
                        sViewDrawing.CanvasDrawWeapon(Color(247, 244, 200), Weapon.id,
                                                      Weapon.ammo,
                                                      Vector22(x, bottom + screenHeight / 27), textsize);
                }
            }
            if (HeadLocation.Z == 1.0f)
            {
                if (!isr360Alert)
                    continue;
                if (y > screenHeight - screenHeight / 12)
                    y = screenHeight - screenHeight / 12;
                else if (y < screenHeight / 12)
                    y = screenHeight / 12;
                if (x < screenWidth / 2)
                {
                    sViewDrawing.CanvasDrawTextAltert(RGBBoy(), "⇛ ",
                                                      Vector22(screenWidth - screenWidth / 80, y), alertSize);
                }
                else
                {
                    sViewDrawing.CanvasDrawTextAltert(RGBBoy(), " ⇚",
                                                      Vector22(screenWidth / 80, y), alertSize);
                }
            }
            else if (x < -screenWidth / 10 || x > screenWidth + screenWidth / 10)
            {
                if (!isr360Alert)
                    continue;
                if (y > screenHeight - screenHeight / 12)
                    y = screenHeight - screenHeight / 12;
                else if (y < screenHeight / 12)
                    y = screenHeight / 12;
                if (x > screenWidth / 2)
                {
                    sViewDrawing.CanvasDrawTextAltert(RGBBoy(), "⇛ ",
                                                      Vector22(screenWidth - screenWidth / 80, y), alertSize);
                }
                else
                {
                    sViewDrawing.CanvasDrawTextAltert(RGBBoy(), " ⇚",
                                                      Vector22(screenWidth / 80, y), alertSize);
                }
            }
            else if (isPlayerLine)
                sViewDrawing.CanvasDrawLine(_colorByDistance, screenHeight / 800,
                                            Vector22(screenWidth / 2, screenHeight / 500.5 + 0), Vector22(x, top));
        }
        if (oType == 0x1d85060) {
            int ItemID = getI(getA(getA(pBase + 0xC) + 0xA8) + 0x3C4);
            bool isID = true;
            if (!isValidItem(ItemID))
                continue;
            pvm(getA(pBase + 0x144) + 0x150, &exyz, sizeof(exyz));
            Location = World2Screen(vMat, exyz);
            if (Location.Z == 1.0f  || Location.X > width + 100 || Location.X < -50)
            continue;
            Distance = getDistance(xyz, exyz);
            if (Distance > 200.0f)
                continue;
            if (Location.Z!=1.0f) {
                sViewDrawing.CanvasDrawItemByID(ItemID, Distance, Vector22(Location.X, Location.Y), textsize);
            }
        }
    }
    if (botCount + playerCount > 0)
    {
        sprintf(extra, "Enemies Around: %d", playerCount + botCount);
        sViewDrawing.CanvasDrawText(RGBBoy2(), extra, Vector22(screenWidth / 2, 120), enemySize);
    }
    else
    {
        sprintf(extra, "Enemies Around: %d", playerCount + botCount);
        sViewDrawing.CanvasDrawText(Color(255, 100, 0, 255), extra, Vector22(screenWidth / 2, 120), enemySize);
    }

}

#endif
