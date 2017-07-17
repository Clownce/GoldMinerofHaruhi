#include "CEndPage.h"
#include "highgui.h"
#include <stdio.h>

CEndPage::CEndPage()
{
    //ctor
}

CEndPage::~CEndPage()
{
    //dtor
}
void CEndPage::InitEndPage()  //初始化背景图片
{
    m_end_background=cvLoadImage(".\\GoldMinerIMG\\endpage.jpg",1);
}
void CEndPage::ShowEndPage(int s)  //显示结束界面
{
    char score[50];
    sprintf(score,"%d",s);
    CvFont font_score1,font_score2,font_restart,font_quit;
    cvInitFont(&font_score1,CV_FONT_HERSHEY_DUPLEX,2,2,0,2,8);
    cvPutText(m_end_background,"Your Score:",cvPoint(180,280),&font_score1,CV_RGB(250,250,250));
    cvInitFont(&font_score2,CV_FONT_HERSHEY_SIMPLEX,2,2,0,2.5,8);
    cvPutText(m_end_background,score,cvPoint(300,370),&font_score2,CV_RGB(34,139,34));
    cvInitFont(&font_restart,CV_FONT_HERSHEY_DUPLEX,2,2,0,3,8);
    cvPutText(m_end_background,"Restart",cvPoint(400,520),&font_restart,CV_RGB(250,250,250));
    cvInitFont(&font_quit,CV_FONT_HERSHEY_DUPLEX,2,2,0,3,8);
    cvPutText(m_end_background,"Quit",cvPoint(100,520),&font_quit,CV_RGB(250,250,250));
    cvNamedWindow("GoldMiner of Haruhi",1);
    cvShowImage("GoldMiner of Haruhi",m_end_background);
    cvWaitKey(0);
}
void CEndPage::ReleaseEndPage()  //释放
{
    cvReleaseImage(&m_end_background);
}
