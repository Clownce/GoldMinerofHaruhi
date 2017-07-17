#ifndef CGAMEPLAY_H
#define CGAMEPLAY_H
#include "highgui.h"

class CGamePlay
{
    public:
        IplImage *m_play_background,*m_minercar,*m_character[6],*m_objectsrc[10],*m_objecton[12];//�������󳵡��������
        IplImage *m_hook[20],*m_realhook;  //����
        CvPoint m_pos_car,m_pos_character;  //�����λ�á�����λ��
        CvPoint m_start,m_end;  //��������㡢�յ�
        CvPoint m_pos_object[10];  //���ӣ�ʯͷ������
        int m_time;  //ʱ��60��
        int m_timeadd;  //ʱ������
        int m_playerID;  //��ɫ���
        int m_level;  //�ؿ�
        int m_plus;  //��������������
        int m_lable;  //�����±�
        int m_score;  //����
        int m_goalscore[10];  //Ŀ�����
        int m_increase;  //�����ڶ�����
        bool m_flag,objectflag[10];  //���ƹ��ӷ��������Ƿ��ѱ�ץ��
        void InitPlayPage(int lev,int playerID);
        void Play(IplImage *player,int level);
        void RollLine();  //���Ӱڶ���ץ���壨���壩
        void Get(IplImage *play_backgound);  //�Ƿ���������
        void FindHook(CvPoint m_end);
        void LoadObjectIMG(int level);
        void ReleaseObjectIMG(int lev);
        void ReleasePlayPage();
        CGamePlay();
        virtual ~CGamePlay();
    protected:
    private:
};

#endif // CGAMEPLAY_H
