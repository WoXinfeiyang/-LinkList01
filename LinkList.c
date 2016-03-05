#include<stdio.h>
#include<malloc.h>
#include"LinkList.h"

/*定义一个带头结点的链表类型*/
typedef struct _TLinkList
{
	LinkListNode head;
	int length;
}TLinkList;

/*初始化一个带头结点的单链表*/
LinkList *LinkListInit()
{
	TLinkList *slist=(TLinkList*)malloc(sizeof(TLinkList));/*强制类型转换*，产生一个带头结点的单链表*/
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
	
	/*第一种方法*/
	/*
	return slist->length;
	*/
	
	/**第二种方法*/
	
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
		printf("\n当前链表不存在\n");
		return False;	
	}
	else
	{
		if(!LinkListLength(list))/*当链表的长度为0时返回True*/
			return True;	
		else 
			return False;
	}
}
/*对链表进行情况操作*/
void LinkListClear(LinkList *list)
{
	TLinkList *slist=(TLinkList*)list;
	if(slist!=NULL)
	{
		slist->head.next=NULL;
		slist->length=0;		
	}
}
/*从内存中销毁一个链表*/
void LinkListDestory(LinkList *list)
{
	free(list);
}

/*
函数名称：LinkListGet(LinkList *list,int pos)
函数参数：list------指向链表的指针
		  pos-------要获取链表元素的位置，从0开始，范围：0<=pos<LinkListLength(list);
函数说明：获取链表list中第pos个元素，注意pos从0开始计算 
*/
LinkListNode*LinkListGet(LinkList *list,int pos)
{
	LinkListNode *ret=NULL;
	
	TLinkList *slist=(TLinkList*)list;
	
	int i=0;
	
	if((slist!=NULL)&&(pos>0)&&(pos<=LinkListLength(list)))/*先进行合法性检查*/ 
	{
		LinkListNode* currentNode=(LinkListNode*)slist;
		for(i=0;(i<pos)/*&&(currentNode!=NULL)*/;i++) 
		{
			currentNode=currentNode->next;/*currentNode指针移动到要获取元素的前一个位置*/	
		}
		ret=currentNode->next;/*ret指向要获取元素的位置*/
	}
	
	return ret;
} 
/*
函数名称：LinkListInsert(LinkList *list,LinkListNode *node,int pos)
函数参数：list-------------指向单链表list的指针
		  node-------------指向待插入结点的指针
		  pose-------------待插入链表中的位置，从0开始，插入的位置前面有pose个元素，即前面的元素下标是从0~pos-1 

*/
void LinkListInsert(LinkList *list,LinkListNode *node,int pos)
{
	TLinkList *slist=(TLinkList*)list;
	int flag=((slist!=NULL)&&(node!=NULL)&&(pos>=0));/*合法性检查标志*/
	int i=0;
	if(flag)
	{
		LinkListNode*currentNode=(LinkListNode*)slist;
		for(i=0;(i<pos)&&(currentNode->next!=NULL);i++)/*此循环从下标为0的元素开始遍历直到遍历到下标为[pos-2]的元素停止遍历,待插入结点的位置下标为[pos-1]，即第pos个元素，注意:当遍历到最后一个结点的时候就不再遍历*/
		{
			currentNode=currentNode->next;/*currentNode遍历到带插入结点位置的前一个位置*/	
		}
		node->next=currentNode->next;
		currentNode->next=node;
		slist->length++;			
	}	
 	
}
/*
函数名称：LinkListDelete(LinkList*list,int pos)
函数参数：list------指向链表的指针
		  pos-------待删除结点的位置，从0开始，范围：0~LinkListLength(l)-1 
函数说明：删除链表中指定位置的元素，pos的范围：0~LinkListLength(l)-1 
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
			currentNode=currentNode->next;/*将currentNode指针移动到待删除结点的前一个结点的位置*/	
		}
		ret=currentNode->next;/*指向待删除结点*/
		deleteNode=currentNode->next;/*指向待删除结点*/
		currentNode->next=ret->next;
		
		slist->length--;
		free(deleteNode);/*释放待删除结点*/
	} 
	return ret;
	
}
