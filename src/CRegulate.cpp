#include "CRegulate.h"
#include "CStartPage.h"
#include "CGamePlay.h"
#include "CEndPage.h"
#include <windows.h>
#include <iostream>
using namespace std;
CRegulate::CRegulate()
{
    //ctor
}

CRegulate::~CRegulate()
{
    //dtor
}
void CRegulate::GameOn()
{
    int lev=1;
    CStartPage start;  //��ʼ����
    CGamePlay play;
    CEndPage over;
    start.InitStartPage();
    start.ShowStartPage();
    char key=cvWaitKey(0);
    if(key=='H')  //��������
    {
        cvDestroyAllWindows();
        cvNamedWindow("Help",1);
        cvShowImage("Help",start.m_helppage);
        cvWaitKey(0);
        cvDestroyWindow("Help");
        start.ShowStartPage();
        key=cvWaitKey(0);
    }
    start.ReleaseStartPage();
    if(key>='1'&&key<='5')
    {
        int i=key-'0'-1;  //ѡ������
        while(1)
        {
           PlaySound (".\\GoldMinerIMG\\back.wav",NULL,SND_ASYNC|SND_LOOP);
           play.InitPlayPage(lev,i);  //��Ϸ��ʼ
           play.LoadObjectIMG(lev);
           play.Play(play.m_character[i],lev);
           play.ReleaseObjectIMG(lev);
           if(play.m_score>=play.m_goalscore[lev-1]&&lev<5)  //������һ��
           {
               lev++;
               continue;
           }
           over.InitEndPage();  //δ�ﵽĿ�꣬��Ϸ����
           over.ShowEndPage(play.m_score);
           cvWaitKey(0);
           if(::GetAsyncKeyState('R')&&0x8000)  //������˳�
           {
               lev=1;
               continue;
           }
           if(::GetAsyncKeyState(VK_ESCAPE)&&0x8000) exit(0);
           over.ReleaseEndPage();
        }
        play.ReleasePlayPage();
        cvDestroyAllWindows();
    }
}
