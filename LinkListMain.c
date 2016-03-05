#include <stdio.h>
#include <stdlib.h>
#include"LinkList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Value
{
	LinkListNode pointer;
	int data;
}Value;


int main(int argc, char *argv[]) 
{
	LinkList *l=LinkListInit();
	LinkList*m;
	int i=0;
	
	Value v1,v2,v3,v4,v5,v6;
	Value *temp;
	v1.data=1;
	v2.data=2;
	v3.data=3;
	v4.data=4;
	v5.data=5;
	
	printf("\n��ǰ����ĳ���Ϊ:%d\n",LinkListLength(l));
	
	if(LinkListIsEmpty(l)==True)
	{
		printf("\n��ǰ����Ϊ��!\n");
	}
	
	LinkListInsert(l,(LinkListNode*)&v1,0);
	LinkListInsert(l,(LinkListNode*)&v2,1);
	LinkListInsert(l,(LinkListNode*)&v3,2);
	LinkListInsert(l,(LinkListNode*)&v4,3);
	LinkListInsert(l,(LinkListNode*)&v5,4);
	printf("\n��ǰ����ĳ���Ϊ:%d\n",LinkListLength(l));
	
	if(LinkListIsEmpty(l)==True)
	{
		printf("\n��ǰ����Ϊ��!\n");
	}	

	temp=(Value*)LinkListGet(l,0);
	printf("\n�����е�%d�����������Ϊ:%d\n",0,temp->data);
	
	temp=(Value*)LinkListGet(l,1);
	printf("\n�����е�%d�����������Ϊ:%d\n",1,temp->data);
	
	temp=(Value*)LinkListGet(l,2);
	printf("\n�����е�%d�����������Ϊ:%d\n",2,temp->data);

	temp=(Value*)LinkListGet(l,3);
	printf("\n�����е�%d�����������Ϊ:%d\n",3,temp->data);
	/*	
	for(i=0;i<LinkListLength(l);i++)
	{
		temp=(Value*)LinkListGet(l,i);
		printf("\n�����е�%d�����������Ϊ:%d\n",i,temp->data);			
	}*/
	
	LinkListDelete(l,2);
	printf("\n��ǰ����ĳ���Ϊ:%d\n",LinkListLength(l));
	
	temp=(Value*)LinkListGet(l,2);
	printf("\n�����е�%d�����������Ϊ:%d\n",2,temp->data);
	return 0;
}
