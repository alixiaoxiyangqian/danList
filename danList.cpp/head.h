#include<stdio.h>
#pragma once

typedef int DataType;

struct strNode
{
	DataType  data;
	struct strNode* pNext;
};

typedef struct strNode Node;//结构体节点
typedef struct strNode *PNode;//结构体节点指针


//规则：凡是改变了单链表内容或者是改变了头节点指向的都传二级指针，否则传一级指针

void InitList(PNode* pHead);
void PopFront(PNode* pHead);
void PopBack(PNode* pHead);
void PushFront(PNode *pHead, DataType data);
PNode _ByeNode(DataType data);
void PushBack(PNode* pHead, DataType data);
int Length(PNode pHead);
PNode Find(PNode pHead, DataType data);
void Insert(PNode* pHead, PNode pos, DataType data);
void Erase(PNode* pHead, PNode pos);
void PrinitdanList(PNode pHead);
void Remove(PNode* pHead, DataType data);
void RemoveAll(PNode* pHead, DataType data);
void DeleteNotTailNode(PNode pos);
void PrinitdanListFromTailToHead(PNode pHead);
void InsertNotHeadNode(PNode pos, DataType data);
PNode FindMidNode(PNode pHead);
void ReservedanList(PNode* pHead);
void BubbleSort(PNode pHead);
void Destroy(PNode* pHead);
PNode MergeList(PNode pHead1, PNode pHead2);
int IsCross(PNode pHead1, PNode pHead2);
PNode GetCrossNode(PNode pHead1, PNode pHead2);
PNode FindLastKNode(PNode pHead, int K);
void DeleteLastKNode(PNode* pHead, int K);
void JosephCircle(PNode* pHead, int M);
bool IsCircle(PNode pHead);
int GetCircleLength(PNode pMeetNode);
PNode GetCircleEnterNode(PNode pHead, PNode pMeetNode);

//////——到目前都不太理解的是：实现一个约瑟夫环和求链表成环的环的入口点

