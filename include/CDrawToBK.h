#ifndef CDRAWTOBK_H
#define CDRAWTOBK_H
#include "highgui.h"
#include "CGamePlay.h"
class CDrawToBK
{
    public:
        void DrawCar(IplImage *m_play_background,IplImage *m_minercar,CvPoint m_pos_car);
        void DrawPlayer(IplImage *m_play_background,IplImage *player,CvPoint m_pos_character);
        void DrawHook(IplImage *background,IplImage *m_hook,CvPoint m_end,int lable);
        void DrawObject(IplImage *background,IplImage *object,int x,int y);
        void ShowScore(IplImage *background,int s);
        void ShowGoal(IplImage *background,int n);
        void ShowTime(IplImage *background,int timeleft);
        void ShowLevel(IplImage *background,int n);
        CDrawToBK();
        virtual ~CDrawToBK();
    protected:
    private:
};

#endif // CDRAWTOBK_H
