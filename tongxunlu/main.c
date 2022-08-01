#include<stdio.h>
#include"address_list.h"
Person *g_info[MAX]={0};//数组用来存储学生信息的地址
int g_count=0;//代表当前人数
int main()
{
    welcome();

    int choice;
    sleep(2);
    while(1)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                AddInfo();
                break;
            case 2:
                display();
                sleep(5);
                break;
            case 3:
                search();
                sleep(5);
                break;
            case 4:
                delete();
                break;
            case 5:
                change();
                break;
            case 6:
                exit(0);
                break;
            default:
                break;
        }
    }    
    return 0;
}