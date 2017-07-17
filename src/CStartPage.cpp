#include "CStartPage.h"
CStartPage::CStartPage()
{
    //ctor
}

CStartPage::~CStartPage()
{
    //dtor
}

void CStartPage::InitStartPage()
{
    m_home_background=cvLoadImage(".\\GoldMinerIMG\\homepage.jpg",1);
    m_home_Haruhi=cvLoadImage(".\\GoldMinerIMG\\home_Haruhi.jpg",1);
    m_home_Kyon=cvLoadImage(".\\GoldMinerIMG\\home_Kyon.jpg",1);
    m_home_Yuki=cvLoadImage(".\\GoldMinerIMG\\home_Yuki.jpg",1);
    m_home_Mikuru=cvLoadImage(".\\GoldMinerIMG\\home_Mikuru.jpg",1);
    m_home_Itsuki=cvLoadImage(".\\GoldMinerIMG\\home_Itsuki.jpg",1);
    m_helppage=cvLoadImage(".\\GoldMinerIMG\\helppage.jpg",1);
    m_xK=100;m_yK=180;
    m_xH=220;m_yH=170;
    m_xM=320;m_yM=160;
    m_xY=400;m_yY=170;
    m_xI=490;m_yI=180;
}

void CStartPage::DrawCharacter(IplImage *character,int x,int y)
{
    int i,j;
    for(i=1;i<character->width;i++)
        for(j=1;j<character->height;j++)
    {
        if(CV_IMAGE_ELEM(character,uchar,j,i*3)<10&&CV_IMAGE_ELEM(character,uchar,j,i*3+1)<10&&CV_IMAGE_ELEM(character,uchar,j,i*3+2)<10)
        continue;
        CV_IMAGE_ELEM(m_home_background,uchar,j+y,(i+x)*3)=CV_IMAGE_ELEM(character,uchar,j,i*3);
        CV_IMAGE_ELEM(m_home_background,uchar,j+y,(i+x)*3+1)=CV_IMAGE_ELEM(character,uchar,j,i*3+1);
        CV_IMAGE_ELEM(m_home_background,uchar,j+y,(i+x)*3+2)=CV_IMAGE_ELEM(character,uchar,j,i*3+2);
    }
    cvNamedWindow("GoldMiner of Haruhi",1);
    cvShowImage("GoldMiner of Haruhi",m_home_background);
    cvWaitKey(350);  //人物显示间隔0.35秒

}
void CStartPage::ShowStartPage()
{
    DrawCharacter(m_home_Kyon,m_xK,m_yK);
    DrawCharacter(m_home_Haruhi,m_xH,m_yH);
    DrawCharacter(m_home_Mikuru,m_xM,m_yM);
    DrawCharacter(m_home_Yuki,m_xY,m_yY);
    DrawCharacter(m_home_Itsuki,m_xI,m_yI);

    CvFont font,fonthelp;  //显示文字 开始游戏
    //初始化字体结构，（字体初始化，字体名称标识符，字体宽度，字体高度，字体倾斜度，字体笔画粗细，字体笔画类型）
    cvInitFont(&font,CV_FONT_HERSHEY_DUPLEX,2,2,0.2,2,8);
    //在图像中显示文本，（原图像，要显示的字符串，第一个字符左下角坐标，字体结构初始化，文本颜色）
    cvPutText(m_home_background,"Press 1~5 to start",cvPoint(70,380),&font,CV_RGB(250,250,10));
    cvInitFont(&fonthelp,CV_FONT_HERSHEY_DUPLEX,1,1,0,1,8);
    cvPutText(m_home_background,"Help(H)",cvPoint(500,430),&fonthelp,CV_RGB(250,250,10));
    cvNamedWindow("GoldMiner of Haruhi",1);
    cvShowImage("GoldMiner of Haruhi",m_home_background);
    cvWaitKey(0);
}
void CStartPage::ReleaseStartPage()
{
    cvReleaseImage(&m_home_background);
    cvReleaseImage(&m_home_Haruhi);
    cvReleaseImage(&m_home_Kyon);
    cvReleaseImage(&m_home_Yuki);
    cvReleaseImage(&m_home_Itsuki);
    cvReleaseImage(&m_helppage);
}
