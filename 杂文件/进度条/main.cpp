#define _CRT_SECURE_NO_DEPRECATE
#include"title_check_string.h"
#include"title_check_graph.h"
#include"title_check_file.h"
//#include <conio.h>

//#include <math.h>






int main()
{
   
    // ��ʼ��ͼ�ν���
    initgraph(640, 480);
    File_data* oldtitle = (File_data*)malloc(sizeof(File_data));
    Inint_File_data(oldtitle);
    if (oldtitle != NULL)
    {
        printf("�ڴ�����ɹ�\n");
    }
    else
    {
        printf("�ڴ�����ʧ�ܣ��˳�����\n");
        exit(1);
    }
    //char print_new_tile_flag = 0;//���ڱ������Ŀ�Ƿ񱻴�ӡ����
    //char reset_arry[2] = "\n";//�ĵ�����
    FILE* old_pi = fopen(Old_File_Address, "r");
    if (old_pi == NULL)
    {
        MessageBox
        (
            GetForegroundWindow(),
            L"δ�ҵ�����Ŀ,�뽫����Ŀ�ļ��ŵ��ŵ���ǰ�ļ����£���������Ϊ����Ŀ.txt���������г���",
            L"�����ж�",
            MB_ICONEXCLAMATION
        );
        exit(1);
    }
    else
    {
        printf("����Ŀ�ļ��򿪳ɹ�����ʼ��ȡ��......\n");
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
    // �ر�ͼ�ν���
    closegraph();
    return 0;
}