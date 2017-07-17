#ifndef CENDPAGE_H
#define CENDPAGE_H
#include "highgui.h"

class CEndPage
{
    public:
        IplImage *m_end_background;
        void InitEndPage();
        void ShowEndPage(int s);
        void ReleaseEndPage();
        CEndPage();
        virtual ~CEndPage();
    protected:
    private:
};

#endif // CENDPAGE_H
