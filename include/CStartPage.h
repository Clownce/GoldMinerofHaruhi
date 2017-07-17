#ifndef CSTARTPAGE_H
#define CSTARTPAGE_H
#include "highgui.h"

class CStartPage
{
    public:
        IplImage *m_home_Haruhi,*m_home_Kyon,*m_home_Mikuru,*m_home_Yuki,*m_home_Itsuki;  //定义五个角色
        IplImage *m_home_background;  //定义开始界面背景
        IplImage *m_helppage;
        int m_xK,m_yK;  //Kyon显示坐标
        int m_xH,m_yH;  //Haruhi显示坐标
        int m_xM,m_yM;  //Mikuru显示坐标
        int m_xY,m_yY;  //Yuki显示坐标
        int m_xI,m_yI;  //Itsuki显示坐标
        void InitStartPage();  //初始化
        void ShowStartPage();  //显示开始界面
        void DrawCharacter(IplImage *character,int x,int y);  //将人物画到背景
        void ReleaseStartPage();  //释放图片空间
        CStartPage();
        virtual ~CStartPage();
    protected:
    private:
};

#endif // CSTARTPAGE_H
