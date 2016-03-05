#ifndef _LinkList_H
#define _LinkList_H


#define Bool int
#define True (1)
#define False (0)
typedef void LinkList;/*Ϊ�˱�������κ��������͵Ľ�㣬���������Ͷ���Ϊvoid*/




typedef struct _LinkListNode
{
	struct _LinkListNode* next;
}LinkListNode;

LinkList *LinkListInit();

int LinkListLength(LinkList *list);
Bool LinkListIsEmpty(LinkList *list);
void LinkListClear(LinkList *list);
void LinkListDestory(LinkList *list);

LinkListNode*LinkListGet(LinkList *list,int pos);

void LinkListInsert(LinkList *list,LinkListNode *node,int pos);
LinkListNode* LinkListDelete(LinkList*list,int pos);





#endif
