#define _CRT_SECURE_NO_DEPRECATE
#include"title_check_string.h"
#include"title_check_graph.h"
#include"title_check_file.h"
//#include <conio.h>

//#include <math.h>






int main()
{
   
    // 初始化图形界面
    initgraph(640, 480);
    File_data* oldtitle = (File_data*)malloc(sizeof(File_data));
    Inint_File_data(oldtitle);
    if (oldtitle != NULL)
    {
        printf("内存申请成功\n");
    }
    else
    {
        printf("内存申请失败，退出程序\n");
        exit(1);
    }
    //char print_new_tile_flag = 0;//用于标记新题目是否被打印过。
    //char reset_arry[2] = "\n";//文档空行
    FILE* old_pi = fopen(Old_File_Address, "r");
    if (old_pi == NULL)
    {
        MessageBox
        (
            GetForegroundWindow(),
            L"未找到旧题目,请将旧题目文件放到放到当前文件夹下，并重命名为旧题目.txt后重新运行程序",
            L"程序中断",
            MB_ICONEXCLAMATION
        );
        exit(1);
    }
    else
    {
        printf("旧题目文件打开成功，开始读取中......\n");
    }
    int old_line_count = 0;
    old_line_count = Write_File_To_Array(old_pi, oldtitle);

   /* for (int i = 0; i < 500; i++)
    {
        printf("%s\n", (oldtitle->_titles)[i]);
    }*/
    //free(old_pi);
    draw_progress_bar(640, 480);
    //destroyAllWindows();
    // 关闭图形界面
    closegraph();
    return 0;
}