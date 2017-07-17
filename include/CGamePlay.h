#ifndef CGAMEPLAY_H
#define CGAMEPLAY_H
#include "highgui.h"

class CGamePlay
{
    public:
        IplImage *m_play_background,*m_minercar,*m_character[6],*m_objectsrc[10],*m_objecton[12];//背景、矿车、人物、物体
        IplImage *m_hook[20],*m_realhook;  //钩子
        CvPoint m_pos_car,m_pos_character;  //定义矿车位置、人物位置
        CvPoint m_start,m_end;  //绳索的起点、终点
        CvPoint m_pos_object[10];  //金子，石头，袋子
        int m_time;  //时间60秒
        int m_timeadd;  //时间增量
        int m_playerID;  //角色编号
        int m_level;  //关卡
        int m_plus;  //大力，更快拉钩
        int m_lable;  //钩子下标
        int m_score;  //分数
        int m_goalscore[10];  //目标分数
        int m_increase;  //绳索摆动增量
        bool m_flag,objectflag[10];  //控制钩子方向、物体是否已被抓到
        void InitPlayPage(int lev,int playerID);
        void Play(IplImage *player,int level);
        void RollLine();  //钩子摆动，抓物体（主体）
        void Get(IplImage *play_backgound);  //是否碰到物体
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
