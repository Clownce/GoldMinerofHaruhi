#include "CDrawToBK.h"
#include "CGamePlay.h"
#include <stdio.h>
#include <math.h>

CDrawToBK::CDrawToBK()
{
    //ctor
}

CDrawToBK::~CDrawToBK()
{
    //dtor
}

void CDrawToBK::DrawCar(IplImage *m_play_background,IplImage *m_minercar,CvPoint m_pos_car)  //加载小矿车
{
    int i,j;
    for(i=0;i<m_minercar->width;i++)
        for(j=0;j<m_minercar->height;j++)
    {
        if(CV_IMAGE_ELEM(m_minercar,uchar,j,i*3)<20&&CV_IMAGE_ELEM(m_minercar,uchar,j,i*3+1)<20&&CV_IMAGE_ELEM(m_minercar,uchar,j,i*3+2)<20)
            continue;
        CV_IMAGE_ELEM(m_play_background,uchar,j+m_pos_car.y,(i+m_pos_car.x)*3)=CV_IMAGE_ELEM(m_minercar,uchar,j,i*3);
        CV_IMAGE_ELEM(m_play_background,uchar,j+m_pos_car.y,(i+m_pos_car.x)*3+1)=CV_IMAGE_ELEM(m_minercar,uchar,j,i*3+1);
        CV_IMAGE_ELEM(m_play_background,uchar,j+m_pos_car.y,(i+m_pos_car.x)*3+2)=CV_IMAGE_ELEM(m_minercar,uchar,j,i*3+2);
    }
}
void CDrawToBK::DrawPlayer(IplImage *m_play_background,IplImage *player,CvPoint m_pos_character)  //加载角色
{
    int i,j;
    for(i=0;i<player->width;i++)
        for(j=0;j<player->height;j++)
    {
        if(CV_IMAGE_ELEM(player,uchar,j,i*3)<20&&CV_IMAGE_ELEM(player,uchar,j,i*3+1)<20&&CV_IMAGE_ELEM(player,uchar,j,i*3+2)<20)
            continue;
        CV_IMAGE_ELEM(m_play_background,uchar,j+m_pos_character.y,(i+m_pos_character.x)*3)=CV_IMAGE_ELEM(player,uchar,j,i*3);
        CV_IMAGE_ELEM(m_play_background,uchar,j+m_pos_character.y,(i+m_pos_character.x)*3+1)=CV_IMAGE_ELEM(player,uchar,j,i*3+1);
        CV_IMAGE_ELEM(m_play_background,uchar,j+m_pos_character.y,(i+m_pos_character.x)*3+2)=CV_IMAGE_ELEM(player,uchar,j,i*3+2);
    }
}
void CDrawToBK::DrawHook(IplImage *background,IplImage *m_hook,CvPoint m_end,int lable)  //加载钩子
{
    CvPoint m_pos_hook;
    if(lable==0)  //不同角度的钩子
    {
       m_pos_hook.x=m_end.x-20;
       m_pos_hook.y=m_end.y;
    }
    else if(lable==1)
    {
       m_pos_hook.x=m_end.x-23;
       m_pos_hook.y=m_end.y-5;
    }
    else if(lable==2)
    {
       m_pos_hook.x=m_end.x-25;
       m_pos_hook.y=m_end.y-7;
    }
    else if(lable==3)
    {
       m_pos_hook.x=m_end.x-30;
       m_pos_hook.y=m_end.y-9;
    }
    else if(lable==4)
    {
       m_pos_hook.x=m_end.x-31;
       m_pos_hook.y=m_end.y-12;
    }
    else if(lable==5)
    {
       m_pos_hook.x=m_end.x-30;
       m_pos_hook.y=m_end.y-15;
    }
    else if(lable==6)
    {
       m_pos_hook.x=m_end.x-31;
       m_pos_hook.y=m_end.y-16;
    }
    else if(lable==7)
    {
       m_pos_hook.x=m_end.x-20;
       m_pos_hook.y=m_end.y-5;
    }
    else if(lable==8)
    {
       m_pos_hook.x=m_end.x-20;
       m_pos_hook.y=m_end.y-8;
    }
    else if(lable==9)
    {
       m_pos_hook.x=m_end.x-19;
       m_pos_hook.y=m_end.y-10;
    }
    else if(lable==10)
    {
       m_pos_hook.x=m_end.x-15;
       m_pos_hook.y=m_end.y-12;
    }
    else if(lable==11)
    {
       m_pos_hook.x=m_end.x-14;
       m_pos_hook.y=m_end.y-13;
    }
    else if(lable==12)
    {
       m_pos_hook.x=m_end.x-11;
       m_pos_hook.y=m_end.y-15;
    }
    int i,j;
    for(i=0;i<m_hook->width&&(i+m_pos_hook.x)<background->width;i++)  //注意避免钩子越界
        for(j=0;j<m_hook->height&&(j+m_pos_hook.y)<background->height;j++)
    {
        if(CV_IMAGE_ELEM(m_hook,uchar,j,i*3)<20&&CV_IMAGE_ELEM(m_hook,uchar,j,i*3+1)<20&&CV_IMAGE_ELEM(m_hook,uchar,j,i*3+2)<20)
            continue;
        CV_IMAGE_ELEM(background,uchar,j+m_pos_hook.y,(i+m_pos_hook.x)*3)=CV_IMAGE_ELEM(m_hook,uchar,j,i*3);
        CV_IMAGE_ELEM(background,uchar,j+m_pos_hook.y,(i+m_pos_hook.x)*3+1)=CV_IMAGE_ELEM(m_hook,uchar,j,i*3+1);
        CV_IMAGE_ELEM(background,uchar,j+m_pos_hook.y,(i+m_pos_hook.x)*3+2)=CV_IMAGE_ELEM(m_hook,uchar,j,i*3+2);
    }
}
void CDrawToBK::DrawObject(IplImage *background,IplImage *object,int x,int y)  //加载物体
{
    int i,j;
    for(i=0;i<object->width&&(i+x)<background->width;i++)
        for(j=0;j<object->height&&(j+y)<background->height;j++)
    {
        if(CV_IMAGE_ELEM(object,uchar,j,i*3)<50&&CV_IMAGE_ELEM(object,uchar,j,i*3+1)<50&&CV_IMAGE_ELEM(object,uchar,j,i*3+2)<50)
        continue;
        CV_IMAGE_ELEM(background,uchar,j+y,(i+x)*3)=CV_IMAGE_ELEM(object,uchar,j,i*3);
        CV_IMAGE_ELEM(background,uchar,j+y,(i+x)*3+1)=CV_IMAGE_ELEM(object,uchar,j,i*3+1);
        CV_IMAGE_ELEM(background,uchar,j+y,(i+x)*3+2)=CV_IMAGE_ELEM(object,uchar,j,i*3+2);
    }
}
void CDrawToBK::ShowScore(IplImage *background,int s)  //显示分数
{
    char score[50];
    sprintf(score,"%d",s);
    CvFont font;
    //初始化字体结构，（字体初始化，字体名称标识符，字体宽度，字体高度，字体倾斜度，字体笔画粗细，字体笔画类型）
    cvInitFont(&font,CV_FONT_HERSHEY_DUPLEX,1,1,0,2,8);
    //在图像中显示文本，（原图像，要显示的字符串，第一个字符左下角坐标，字体结构初始化，文本颜色）
    cvPutText(background,"Score:",cvPoint(10,77),&font,CV_RGB(250,250,250));
    CvFont font1;
    cvInitFont(&font1,CV_FONT_HERSHEY_SIMPLEX,1,1,0,2,8);
    cvPutText(background,score,cvPoint(150,80),&font1,CV_RGB(173,255,47));
}
void CDrawToBK::ShowLevel(IplImage *background,int n)  //显示关卡
{
    char level[22];
    sprintf(level,"%d",n);
    CvFont level1,level2;
    cvInitFont(&level1,CV_FONT_HERSHEY_DUPLEX,1,1,0,2,8);
    cvInitFont(&level2,CV_FONT_HERSHEY_TRIPLEX,1,1,0,2,8);
    cvPutText(background,"Level:",cvPoint(15,38),&level1,CV_RGB(250,250,250));
    cvPutText(background,level,cvPoint(150,38),&level2,CV_RGB(176,196,222));
}
void CDrawToBK::ShowGoal(IplImage *background,int level)  //显示目标分数
{
    int s;
    CvFont fontgoal;
    if(level==1) s=600;
    else if(level==2) s=1500;
    else if(level==3) s=2300;
    else if(level==4) s=3100;
    else if(level==5) s=4200;
    char goal[22];
    sprintf(goal,"%d",s);
    cvInitFont(&fontgoal,CV_FONT_HERSHEY_DUPLEX,1,1,0,2,8);
    cvPutText(background,"Goal Score:",cvPoint(600,75),&fontgoal,CV_RGB(250,250,250));
    cvPutText(background,goal,cvPoint(800,75),&fontgoal,CV_RGB(107,142,35));
    cvPutText(background,"TimeLeft:",cvPoint(600,30),&fontgoal,CV_RGB(250,250,250));
    cvPutText(background,"S",cvPoint(850,33),&fontgoal,CV_RGB(250,250,250));
}
void CDrawToBK::ShowTime(IplImage *background,int timeleft)  //显示倒计时
{
    char time[52];
    sprintf(time,"%d",timeleft);
    CvFont font;
    cvInitFont(&font,CV_FONT_HERSHEY_DUPLEX,1,1,0,2,8);
    if(timeleft>10)
    cvPutText(background,time,cvPoint(775,33),&font,CV_RGB(255,127,0));
    else
    cvPutText(background,time,cvPoint(775,33),&font,CV_RGB(255,0,0));
}
