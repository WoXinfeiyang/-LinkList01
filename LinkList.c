#include<stdio.h>
#include<malloc.h>
#include"LinkList.h"

/*����һ����ͷ������������*/
typedef struct _TLinkList
{
	LinkListNode head;
	int length;
}TLinkList;

/*��ʼ��һ����ͷ���ĵ�����*/
LinkList *LinkListInit()
{
	TLinkList *slist=(TLinkList*)malloc(sizeof(TLinkList));/*ǿ������ת��*������һ����ͷ���ĵ�����*/
	if(slist!=NULL)
	{
	slist->head.next=NULL;
	slist->length=0;
	}
	return slist;
	
}

int LinkListLength(LinkList *list)
{
	TLinkList *slist=(TLinkList*)list;
	int length=0;
	
	/*��һ�ַ���*/
	/*
	return slist->length;
	*/
	
	/**�ڶ��ַ���*/
	
	LinkListNode *r;
	r=slist->head.next;
	while(r!=NULL)
	{
		r=r->next;
		length++;	
	}
	return length;
	
	
	
}
Bool LinkListIsEmpty(LinkList *list)
{
	if(list==NULL)
	{
		printf("\n��ǰ��������\n");
		return False;	
	}
	else
	{
		if(!LinkListLength(list))/*������ĳ���Ϊ0ʱ����True*/
			return True;	
		else 
			return False;
	}
}
/*����������������*/
void LinkListClear(LinkList *list)
{
	TLinkList *slist=(TLinkList*)list;
	if(slist!=NULL)
	{
		slist->head.next=NULL;
		slist->length=0;		
	}
}
/*���ڴ�������һ������*/
void LinkListDestory(LinkList *list)
{
	free(list);
}

/*
�������ƣ�LinkListGet(LinkList *list,int pos)
����������list------ָ�������ָ��
		  pos-------Ҫ��ȡ����Ԫ�ص�λ�ã���0��ʼ����Χ��0<=pos<LinkListLength(list);
����˵������ȡ����list�е�pos��Ԫ�أ�ע��pos��0��ʼ���� 
*/
LinkListNode*LinkListGet(LinkList *list,int pos)
{
	LinkListNode *ret=NULL;
	
	TLinkList *slist=(TLinkList*)list;
	
	int i=0;
	
	if((slist!=NULL)&&(pos>0)&&(pos<=LinkListLength(list)))/*�Ƚ��кϷ��Լ��*/ 
	{
		LinkListNode* currentNode=(LinkListNode*)slist;
		for(i=0;(i<pos)/*&&(currentNode!=NULL)*/;i++) 
		{
			currentNode=currentNode->next;/*currentNodeָ���ƶ���Ҫ��ȡԪ�ص�ǰһ��λ��*/	
		}
		ret=currentNode->next;/*retָ��Ҫ��ȡԪ�ص�λ��*/
	}
	
	return ret;
} 
/*
�������ƣ�LinkListInsert(LinkList *list,LinkListNode *node,int pos)
����������list-------------ָ������list��ָ��
		  node-------------ָ����������ָ��
		  pose-------------�����������е�λ�ã���0��ʼ�������λ��ǰ����pose��Ԫ�أ���ǰ���Ԫ���±��Ǵ�0~pos-1 

*/
void LinkListInsert(LinkList *list,LinkListNode *node,int pos)
{
	TLinkList *slist=(TLinkList*)list;
	int flag=((slist!=NULL)&&(node!=NULL)&&(pos>=0));/*�Ϸ��Լ���־*/
	int i=0;
	if(flag)
	{
		LinkListNode*currentNode=(LinkListNode*)slist;
		for(i=0;(i<pos)&&(currentNode->next!=NULL);i++)/*��ѭ�����±�Ϊ0��Ԫ�ؿ�ʼ����ֱ���������±�Ϊ[pos-2]��Ԫ��ֹͣ����,���������λ���±�Ϊ[pos-1]������pos��Ԫ�أ�ע��:�����������һ������ʱ��Ͳ��ٱ���*/
		{
			currentNode=currentNode->next;/*currentNode��������������λ�õ�ǰһ��λ��*/	
		}
		node->next=currentNode->next;
		currentNode->next=node;
		slist->length++;			
	}	
 	
}
/*
�������ƣ�LinkListDelete(LinkList*list,int pos)
����������list------ָ�������ָ��
		  pos-------��ɾ������λ�ã���0��ʼ����Χ��0~LinkListLength(l)-1 
����˵����ɾ��������ָ��λ�õ�Ԫ�أ�pos�ķ�Χ��0~LinkListLength(l)-1 
*/ 
LinkListNode* LinkListDelete(LinkList*list,int pos)
{
	TLinkList*slist=(TLinkList*)list; 
	LinkListNode *ret=NULL;
	LinkListNode*deleteNode=NULL;
	int i=0;
	if((slist!=NULL)&&(pos>=0)&&(pos<slist->length))
	{
		LinkListNode *currentNode=(LinkListNode*)slist;
		for(i=0;(i<pos)&&(currentNode->next!=NULL);i++)
		{
			currentNode=currentNode->next;/*��currentNodeָ���ƶ�����ɾ������ǰһ������λ��*/	
		}
		ret=currentNode->next;/*ָ���ɾ�����*/
		deleteNode=currentNode->next;/*ָ���ɾ�����*/
		currentNode->next=ret->next;
		
		slist->length--;
		free(deleteNode);/*�ͷŴ�ɾ�����*/
	} 
	return ret;
	
}
