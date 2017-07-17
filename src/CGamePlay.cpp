#include "CGamePlay.h"
#include "CDrawToBK.h"
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include "highgui.h"

CGamePlay::CGamePlay()
{
    //ctor
}

CGamePlay::~CGamePlay()
{
    //dtor
}

void CGamePlay::InitPlayPage(int lev,int playerID)  //初始化游戏主体
{
    m_play_background=cvLoadImage(".\\GoldMinerIMG\\play_background.jpg",1);
    m_minercar=cvLoadImage(".\\GoldMinerIMG\\mine_car.jpg",1);
    m_character[0]=cvLoadImage(".\\GoldMinerIMG\\play_Kyon.jpg",1);
    m_character[1]=cvLoadImage(".\\GoldMinerIMG\\play_Haruhi.jpg",1);
    m_character[2]=cvLoadImage(".\\GoldMinerIMG\\play_Mikuru.jpg",1);
    m_character[3]=cvLoadImage(".\\GoldMinerIMG\\play_Yuki.jpg",1);
    m_character[4]=cvLoadImage(".\\GoldMinerIMG\\play_Itsuki.jpg",1);
    m_objectsrc[0]=cvLoadImage(".\\GoldMinerIMG\\bag.jpg",1);
    m_objectsrc[1]=cvLoadImage(".\\GoldMinerIMG\\gold1.jpg",1);
    m_objectsrc[2]=cvLoadImage(".\\GoldMinerIMG\\gold2.jpg",1);
    m_objectsrc[3]=cvLoadImage(".\\GoldMinerIMG\\gold3.jpg",1);
    m_objectsrc[4]=cvLoadImage(".\\GoldMinerIMG\\stone1.jpg",1);
    m_objectsrc[5]=cvLoadImage(".\\GoldMinerIMG\\stone2.jpg",1);
    m_objectsrc[6]=cvLoadImage(".\\GoldMinerIMG\\crystal.jpg",1);
    m_objectsrc[7]=cvLoadImage(".\\GoldMinerIMG\\sandglass.png",1);
    m_hook[0]=cvLoadImage(".\\GoldMinerIMG\\hook.png",1);
    m_hook[1]=cvLoadImage(".\\GoldMinerIMG\\hook-1.png",1);
    m_hook[2]=cvLoadImage(".\\GoldMinerIMG\\hook-2.png",1);
    m_hook[3]=cvLoadImage(".\\GoldMinerIMG\\hook-3.png",1);
    m_hook[4]=cvLoadImage(".\\GoldMinerIMG\\hook-4.png",1);
    m_hook[5]=cvLoadImage(".\\GoldMinerIMG\\hook-5.png",1);
    m_hook[6]=cvLoadImage(".\\GoldMinerIMG\\hook-6.png",1);
    m_hook[7]=cvLoadImage(".\\GoldMinerIMG\\hook+1.png",1);
    m_hook[8]=cvLoadImage(".\\GoldMinerIMG\\hook+2.png",1);
    m_hook[9]=cvLoadImage(".\\GoldMinerIMG\\hook+3.png",1);
    m_hook[10]=cvLoadImage(".\\GoldMinerIMG\\hook+4.png",1);
    m_hook[11]=cvLoadImage(".\\GoldMinerIMG\\hook+5.png",1);
    m_hook[12]=cvLoadImage(".\\GoldMinerIMG\\hook+6.png",1);
    m_pos_car=cvPoint(386,55);
    m_pos_character=cvPoint(387,10);
    m_start=cvPoint(417,75);
    m_end=cvPoint(327,118);
    if(lev==1)  //不同关卡，物体位置不同
    {
        m_pos_object[0]=cvPoint(130,300);
        m_pos_object[1]=cvPoint(200,450);
        m_pos_object[2]=cvPoint(400,350);
        m_pos_object[3]=cvPoint(450,400);
        m_pos_object[4]=cvPoint(700,500);
        m_pos_object[5]=cvPoint(600,400);
    }
    else if(lev==2)
    {
        m_pos_object[0]=cvPoint(230,400);
        m_pos_object[1]=cvPoint(100,450);
        m_pos_object[2]=cvPoint(700,350);
        m_pos_object[3]=cvPoint(450,190);
        m_pos_object[4]=cvPoint(700,500);
        m_pos_object[6]=cvPoint(200,280);
    }
    else if(lev==3)
    {
        m_pos_object[0]=cvPoint(180,300);
        m_pos_object[1]=cvPoint(300,460);
        m_pos_object[2]=cvPoint(500,350);
        m_pos_object[3]=cvPoint(450,470);
        m_pos_object[4]=cvPoint(700,500);
        m_pos_object[6]=cvPoint(600,300);
        m_pos_object[7]=cvPoint(270,390);
    }
    else if(lev==4)
    {
        m_pos_object[0]=cvPoint(200,300);
        m_pos_object[1]=cvPoint(200,150);
        m_pos_object[2]=cvPoint(470,350);
        m_pos_object[3]=cvPoint(620,210);
        m_pos_object[4]=cvPoint(500,200);
        m_pos_object[6]=cvPoint(460,340);
        m_pos_object[7]=cvPoint(370,500);
        m_pos_object[8]=cvPoint(280,390);
    }
    else if(lev==5)
    {
        m_pos_object[0]=cvPoint(260,500);
        m_pos_object[1]=cvPoint(200,250);
        m_pos_object[2]=cvPoint(600,250);
        m_pos_object[3]=cvPoint(450,420);
        m_pos_object[4]=cvPoint(700,530);
        m_pos_object[6]=cvPoint(510,390);
        m_pos_object[7]=cvPoint(170,440);
        m_pos_object[8]=cvPoint(270,310);
        m_pos_object[9]=cvPoint(450,320);
    }
    m_flag=true;
    for(int i=0;i<10;i++)
    objectflag[i]=true;
    m_increase=1;
    if(lev==1) m_score=0;
    m_time=60;
    m_level=lev;
    m_playerID=playerID;
    m_timeadd=0;
    m_plus=2;
    m_goalscore[0]=600;
    m_goalscore[1]=1500;
    m_goalscore[2]=2300;
    m_goalscore[3]=3100;
    m_goalscore[4]=4200;
}
void CGamePlay::LoadObjectIMG(int level)  //加载物体，每关不同
{
        m_objecton[0]=cvCloneImage(m_objectsrc[0]);
        m_objecton[1]=cvCloneImage(m_objectsrc[1]);
        m_objecton[2]=cvCloneImage(m_objectsrc[2]);
        m_objecton[3]=cvCloneImage(m_objectsrc[4]);
        m_objecton[4]=cvCloneImage(m_objectsrc[5]);
        m_objecton[5]=cvCloneImage(m_objectsrc[3]);
        if(level==2) m_objecton[6]=cvCloneImage(m_objectsrc[7]);
        else if(level==3)
        {
            m_objecton[6]=cvCloneImage(m_objectsrc[7]);
            m_objecton[7]=cvCloneImage(m_objectsrc[6]);
        }
        else if(level==4)
        {
            m_objecton[6]=cvCloneImage(m_objectsrc[1]);
            m_objecton[7]=cvCloneImage(m_objectsrc[6]);
            m_objecton[8]=cvCloneImage(m_objectsrc[6]);
        }
        else if(level==5)
        {
            m_objecton[6]=cvCloneImage(m_objectsrc[7]);
            m_objecton[7]=cvCloneImage(m_objectsrc[6]);
            m_objecton[8]=cvCloneImage(m_objectsrc[2]);
            m_objecton[9]=cvCloneImage(m_objectsrc[1]);
        }

}
void CGamePlay::ReleaseObjectIMG(int lev)  //释放物体
{
    for(int i=0;i<5+lev;i++)
    cvReleaseImage(&m_objecton[i]);
}
void CGamePlay::RollLine()  //绳索控制、游戏主体
{
    CDrawToBK draw;
    IplImage *background=cvCreateImage(cvGetSize(m_play_background),m_play_background->depth,m_play_background->nChannels);
    while(1)
    {
        cvCopy(m_play_background,background);
        if(m_flag==true)  //绳索右摆
        {
            m_end.x+=m_increase;
            m_end.y=75+sqrt(10000-(m_end.x-417)*(m_end.x-417));
            cvLine(background,m_start,m_end,cvScalar(10,50,70),2,8,0);
        }
        if(m_flag==false)  //绳索左摆
        {
            m_end.x-=m_increase;
            m_end.y=75+sqrt(10000-(m_end.x-417)*(m_end.x-417));
            cvLine(background,m_start,m_end,cvScalar(0,50,50),2,8,0);
        }
        for(int i=0;i<5+m_level;i++)  //画物体
        {
            if(objectflag[i]==true)
            draw.DrawObject(background,m_objecton[i],m_pos_object[i].x,m_pos_object[i].y);
        }
        FindHook(m_end);
        draw.DrawHook(background,m_realhook,m_end,m_lable);  //加载钩子
        if(m_end.x>=507) m_flag=false;  //钩子左右边界
        if(m_end.x<=327) m_flag=true;
        draw.ShowScore(background,m_score);
        draw.ShowTime(background,m_time-(m_timeadd++)/68);
        if(m_time-(m_timeadd)/68==0) break;
        cvNamedWindow("GoldMiner of Haruhi",1);
        cvShowImage("GoldMiner of Haruhi",background);
        if(::GetAsyncKeyState(VK_ESCAPE)&&0x8000) exit(0);
        if(::GetAsyncKeyState(VK_DOWN)&&0x8000)
            {
                cvCopy(m_play_background,background);  //去掉已画的线
                Get(background);  //线的伸缩
                m_end=cvPoint(327,118);
            }
        else cvWaitKey(10);
    }
}

void CGamePlay::Get(IplImage *play_background)  //碰到物体
{
    CDrawToBK draw;
    bool ifget=false;
    IplImage *background=cvCreateImage(cvGetSize(play_background),play_background->depth,play_background->nChannels);
    while(m_end.x<background->width&&m_end.x>0&&m_end.y>75&&m_end.y<background->height)  //放出绳索
    {
        cvCopy(play_background,background);
        for(int i=0;i<5+m_level;i++)  //重画物体
        {
            if(objectflag[i]==true)
            draw.DrawObject(background,m_objecton[i],m_pos_object[i].x,m_pos_object[i].y);
        }
        m_end.y+=2;
        if(m_end.x>417)
            m_end.x+=2*abs(m_end.x-m_start.x)/(m_end.y-m_start.y-2);
        else if(m_end.x<417)
            m_end.x-=2*abs(m_end.x-m_start.x)/(m_end.y-m_start.y-2);
        cvLine(background,m_start,m_end,cvScalar(10,50,70),2,8,0);
        FindHook(m_end);
        draw.DrawHook(background,m_realhook,m_end,m_lable);
        draw.ShowScore(background,m_score);
        draw.ShowTime(background,m_time-(m_timeadd++)/68);
        if(m_time-(m_timeadd)/68==0) break;
        cvNamedWindow("GoldMiner of Haruhi",1);
        cvShowImage("GoldMiner of Haruhi",background);
        cvWaitKey(1);
        for(int i=0;i<5+m_level;i++)  //判断是否碰到物体
        {
            if(sqrt((m_end.x-(m_pos_object[i].x+m_objecton[i]->width/2))*(m_end.x-(m_pos_object[i].x+m_objecton[i]->width/2))+
                    (m_end.y-(m_pos_object[i].y+m_objecton[i]->height/2))*(m_end.y-(m_pos_object[i].y+m_objecton[i]->height/2)))<25&&objectflag[i]==true)
            {
                objectflag[i]=false;
                bool bomb=false;
                for(int j=m_pos_object[i].x;j<m_pos_object[i].x+m_objecton[i]->width;j++)  //删去碰到的物体
                    for(int k=m_pos_object[i].y;k<m_pos_object[i].y+m_objecton[i]->height;k++)
                {
                    CV_IMAGE_ELEM(background,uchar,k,j*3)=CV_IMAGE_ELEM(m_play_background,uchar,k,j*3);
                    CV_IMAGE_ELEM(background,uchar,k,j*3+1)=CV_IMAGE_ELEM(m_play_background,uchar,k,j*3+1);
                    CV_IMAGE_ELEM(background,uchar,k,j*3+2)=CV_IMAGE_ELEM(m_play_background,uchar,k,j*3+2);
                }
                while(sqrt((m_end.x-m_start.x)*(m_end.x-m_start.x)+(m_end.y-m_start.y)*(m_end.y-m_start.y))>8) //将碰到的物体拉回
                        {
                            cvCopy(play_background,background);
                            for(int n=0;n<5+m_level;n++)
                              {
                                 if(objectflag[n]==true)
                                 draw.DrawObject(background,m_objecton[n],m_pos_object[n].x,m_pos_object[n].y);  //画物体
                              }
                            draw.DrawObject(background,m_objecton[i],m_end.x-m_objecton[i]->width/2,m_end.y+2);
                            if(m_playerID==1) m_plus=3;
                            m_end.y-=m_plus;
                            if(m_end.x>=417)
                            m_end.x-=m_plus*abs(m_end.x-m_start.x)/(m_end.y-m_start.y+m_plus);
                            else if(m_end.x<417)
                            m_end.x+=m_plus*abs(m_end.x-m_start.x)/(m_end.y-m_start.y+m_plus);
                            cvLine(background,m_start,m_end,cvScalar(10,50,70),2,8,0);
                            FindHook(m_end);
                            draw.DrawHook(background,m_realhook,m_end,m_lable);
                            draw.ShowScore(background,m_score);
                            draw.ShowTime(background,m_time-(m_timeadd++)/68);
                            if(m_time-(m_timeadd)/68==0) break;
                            cvNamedWindow("GoldMiner of Haruhi",1);
                            cvShowImage("GoldMiner of Haruhi",background);
                            cvWaitKey(1);
                            if(::GetAsyncKeyState(VK_UP)&&0x8000)
                                if(m_playerID==4)
                            {
                                bomb=true;
                                break;
                            }
                         }
                if(bomb==true&&m_playerID==4) break;
                if(i==0)
                {
                    m_score+=200;
                    if(m_playerID==2) m_score+=600;
                }
                if(i==1) m_score+=200;
                if(i==2) m_score+=400;
                if(i==3||i==4)
                {
                    m_score+=50;
                    if(m_playerID==3) m_score+=400;
                }
                if(i==5) m_score+=600;
                if(m_level==2)
                {
                    if(i==6) m_time+=10;
                }
                else if(m_level==3)
                {
                    if(i==6) m_time+=10;
                    if(i==7) m_score+=800;
                }
                else if(m_level==4)
                {
                    if(i==6) m_score+=200;
                    if(i==7||i==8) m_score+=800;
                }
                else if(m_level==5)
                {
                    if(i==6) m_time+=10;
                    if(i==7) m_score+=800;
                    if(i==8) m_score+=400;
                    if(i==9) m_score+=200;
                }
                ifget=true;
                break;
            }
        }
    }
    if(ifget==false)
    while(sqrt((m_end.x-m_start.x)*(m_end.x-m_start.x)+(m_end.y-m_start.y)*(m_end.y-m_start.y))>8&&m_end.y>8)  //没碰到物体时
    {
        cvCopy(play_background,background);
        for(int i=0;i<5+m_level;i++)
        {
            if(objectflag[i]==true)
            draw.DrawObject(background,m_objecton[i],m_pos_object[i].x,m_pos_object[i].y);  //重画物体
        }
        m_end.y-=2;
        if(m_end.x>417)
            m_end.x-=2*abs(m_end.x-m_start.x)/(m_end.y-m_start.y+2);
        else if(m_end.x<417)
            m_end.x+=2*abs(m_end.x-m_start.x)/(m_end.y-m_start.y+2);
        cvLine(background,m_start,m_end,cvScalar(10,50,70),2,8,0);
        FindHook(m_end);
        draw.DrawHook(background,m_realhook,m_end,m_lable);
        draw.ShowScore(background,m_score);
        draw.ShowTime(background,m_time-(m_timeadd++)/68);
        if(m_time-(m_timeadd)/68==0) break;
        cvNamedWindow("GoldMiner of Haruhi",1);
        cvShowImage("GoldMiner of Haruhi",background);
        cvWaitKey(1);
    }
}
void CGamePlay::FindHook(CvPoint m_end)  //判断钩子角度
{
    float angle=100*abs(m_end.x-417)/(m_end.y-75);
    if(m_end.x<=417)
    {
        if(angle<5) m_lable=0;
        else if(angle<30) m_lable=1;
        else if(angle<70) m_lable=2;
        else if(angle<105) m_lable=3;
        else if(angle<140) m_lable=4;
        else if(angle<175) m_lable=5;
        else if(angle<210) m_lable=6;
    }
    else
    {
        if(angle<5) m_lable=0;
        else if(angle<30) m_lable=7;
        else if(angle<70) m_lable=8;
        else if(angle<105) m_lable=9;
        else if(angle<140) m_lable=10;
        else if(angle<175) m_lable=11;
        else if(angle<210) m_lable=12;
    }
    m_realhook=cvCloneImage(m_hook[m_lable]);
}

void CGamePlay::Play(IplImage *player,int level)  //加载游戏
{
    CDrawToBK draw;
    draw.DrawPlayer(m_play_background,player,m_pos_character);
    draw.DrawCar(m_play_background,m_minercar,m_pos_car);
    draw.ShowGoal(m_play_background,level);
    draw.ShowLevel(m_play_background,level);
    RollLine();
}
void CGamePlay::ReleasePlayPage()  //释放空间
{
    cvReleaseImage(&m_play_background);
    cvReleaseImage(&m_minercar);
    for(int i=0;i<8;i++)
        cvReleaseImage(&m_objectsrc[i]);
    for(int i=0;i<13;i++)
        cvReleaseImage(&m_hook[i]);
    for(int i=0;i<5;i++)
        cvReleaseImage(&m_character[i]);
}
