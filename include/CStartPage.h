#ifndef CSTARTPAGE_H
#define CSTARTPAGE_H
#include "highgui.h"

class CStartPage
{
    public:
        IplImage *m_home_Haruhi,*m_home_Kyon,*m_home_Mikuru,*m_home_Yuki,*m_home_Itsuki;  //���������ɫ
        IplImage *m_home_background;  //���忪ʼ���汳��
        IplImage *m_helppage;
        int m_xK,m_yK;  //Kyon��ʾ����
        int m_xH,m_yH;  //Haruhi��ʾ����
        int m_xM,m_yM;  //Mikuru��ʾ����
        int m_xY,m_yY;  //Yuki��ʾ����
        int m_xI,m_yI;  //Itsuki��ʾ����
        void InitStartPage();  //��ʼ��
        void ShowStartPage();  //��ʾ��ʼ����
        void DrawCharacter(IplImage *character,int x,int y);  //�����ﻭ������
        void ReleaseStartPage();  //�ͷ�ͼƬ�ռ�
        CStartPage();
        virtual ~CStartPage();
    protected:
    private:
};

#endif // CSTARTPAGE_H
