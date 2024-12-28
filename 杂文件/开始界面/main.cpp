#include<iostream>
#include<easyx.h>
using namespace std;

int main()
{
    initgraph(1365 ,658);

    IMAGE bk;

    loadimage(&bk, _T("IMAGE"), _T("bk"), 1365 , 658);//从资源文件载入图片到bk

    putimage(0, 0, &bk);

    system("pause");
    return 0;
}
