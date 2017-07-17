#include <iostream>
#include "CStartPage.h"
#include "CGamePlay.h"
#include "CEndPage.h"
#include "CRegulate.h"
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int main()
{
    CRegulate on;
    on.GameOn();
    return 0;
}
