#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
int main() {
    mciSendString("open F:\\C\\music\\background.mp3 alias aa", NULL,0,NULL);
    mciSendString("play aa", NULL, 0, NULL);
    return 0;
}
