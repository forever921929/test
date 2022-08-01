#ifndef _ADDRESS_LIST
#define _ADDRESS_LIST
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>
#define MAX 1024
typedef struct ContactPerson{
char id[10];
char name[32];
int age;
char telephone[12];
}Person;
void welcome();
void menu();
int AddInfo();
void display();
void search();
void search_ID();
void search_name();
void delete();
void change();
#endif 