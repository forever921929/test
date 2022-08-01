#include"address_list.h"
extern Person *g_info[MAX];//数组用来存储学生信息的地址
extern int g_count;
void menu()
{
    system("clear");
    printf("----------------------------------------------------------------------------\n\n");
    printf("\t\t1. 添加信息          2. 显示信息\n\n");
    printf("\t\t3. 搜素信息          4. 删除信息\n\n");
    printf("\t\t5. 修改信息          6. 退出系统\n\n");  
    printf("-----------------------------------------------------------------------------\n\n");
}
void welcome()
{
    printf("**********************************************************************\n\n");
    printf("**********************************************************************\n\n");
    printf("**************************欢迎使用本通讯录系统*************************\n\n");
    printf("*****************welcome using the address_list syste*****************\n\n");
    printf("**********************************************************************\n\n");
    printf("**********************************************************************\n\n");
    
}
int AddInfo()//添加模块
{
    g_info[g_count]=(Person*)malloc(sizeof(Person)*1);
    if(NULL ==g_info)
    {
         printf("apply filed !\n");
         exit(1);
    }
        int flag=1;
        if(g_count>1024)
        {
            printf("对不起,人数已满\n");
        }
        else
        {
            while(flag)
            {
                printf("请输入ID   姓名  年龄  电话:\n");
                scanf("%s%s%d%s",g_info[g_count]->id,g_info[g_count]->name, &g_info[g_count]->age,g_info[g_count]->telephone);
            
                if(strlen(g_info[g_count]->telephone)!=11)
                {
                    printf("电话号码格式输入错误,请重新输入");
                    flag=1;
                    continue;
                }
                int i;
                for(i=0;i<g_count;i++)
                {
                    if(strcmp(g_info[i]->telephone,g_info[g_count]->telephone)==0)
                    {
                        printf("电话重复,请重新输入!\n");
                        break;

                    }
                }
                g_count++;
                free(g_info[g_count]);
                break;

            }
        }

    return 0;
}
void display()//显示模块
{
     if (g_count == 0)
        {
		    printf("通讯录为空,请先添加!!!\n");
		    return;
	    }

        for(int m=0;m<g_count;m++)
        {
           for(int n=0;n<g_count-m-1;n++)
           {
              int ret=strcmp(g_info[n]->name,g_info[n+1]->name);
              if(ret>0)
              {
                  Person *tamp;
                  tamp=g_info[n];
                  g_info[n]=g_info[n+1];
                  g_info[n+1]=tamp;
                  printf("ok\n");

              }
           }


        }
    for(int j=0;j<g_count;j++)
    {
        printf("************************************************\n");
        printf("*****************第%d位联系人********************\n",j+1);
        printf("ID: %s  姓名:%s  年龄:%d  电话: %s \n",g_info[j]->id,g_info[j]->name, g_info[j]->age,g_info[j]->telephone);
        printf("************************************************\n");
    }

}
void search()
{
    printf("请选择搜索方式:1.ID搜索  2.用户名搜索\n");
    int a;
    scanf("%d\n",&a);
    switch (a)
    {
        case 1:   
        search_ID();
        break;
        case 2:
        search_name();
        break;
        default:
        break;
    }
}
void search_ID()
{
    char ch[20];
    char abc;
    int b;
    
    scanf("%s",ch);
    for(b=0;b<g_count;b++)
    {
        if(strcmp(g_info[b]->id,ch)==0)
        {
            printf("ID: %s  姓名:%s  年龄:%d  电话: %s \n",g_info[b]->id,g_info[b]->name, g_info[b]->age,g_info[b]->telephone);
            break;
        }
        else if (b==(g_count-1))
        {
            printf("无\n");
            getchar();
            while(!scanf("%c",&abc))
            {
                sleep(1);
            }
            break;
        }
    }
    /*if(strcmp(g_info[g_count-1]->id,ch)==0)
    {
         printf("ID: %s  姓名:%s  年龄:%d  电话: %s \n",g_info[b]->id,g_info[b]->name, g_info[b]->age,g_info[b]->telephone);
    }
    if(strcmp(g_info[g_count-1]->id,ch)!=0)
    {
         printf("没有该联系人");
    }*/
    
}
void search_name()

{
    printf("请输入你要搜索的姓名\n");
    char nam[20];
    char ab;
    int c;
    scanf("%s",nam);
    for(c=0;c<g_count;c++)
    {
        if(strcmp(g_info[c]->name,nam)==0)
        {
            printf("ID: %s  姓名:%s  年龄:%d  电话: %s \n",g_info[c]->id,g_info[c]->name, g_info[c]->age,g_info[c]->telephone);
            break;
        }
        else if (c==(g_count-1))
        {
            printf("无\n");
            break;
        }
    }
}

void delete()
{
    char user[20];
	int c = 0;
	printf("删除用户!\n");
	printf("请输入要删除的用户姓名:\n");
	scanf("%s", user);
	for (c = 0;c<g_count; c++)
	{
		if (strcmp(user,g_info[c]->name ) == 0)
		{
			for(int j=c;j<g_count;j++)
            {
                printf("%s", g_info[c]->name);
		        g_info[j] = g_info[j+1];
       
            }
            g_count--;
		}
	}
	printf("删除成功!\n");
}
void change()
{
    char name[20];
    int c=0;
	printf("请输入要修改的用户姓名:\n");
	scanf("%s", name);
    for (c = 0;c<g_count; c++)
	{
		if (strcmp(name,g_info[c]->name ) == 0)
		{
			 printf("请输入修改的: ID, 姓名, 年龄, 电话\n\n");
             scanf("%s%s%d%s",g_info[c]->id,g_info[c]->name, &g_info[c]->age,g_info[c]->telephone);
             break;
		}
	}

}