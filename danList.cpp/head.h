#include<stdio.h>
#pragma once

typedef int DataType;

struct strNode
{
	DataType  data;
	struct strNode* pNext;
};

typedef struct strNode Node;//�ṹ��ڵ�
typedef struct strNode *PNode;//�ṹ��ڵ�ָ��


//���򣺷��Ǹı��˵��������ݻ����Ǹı���ͷ�ڵ�ָ��Ķ�������ָ�룬����һ��ָ��

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

//////������Ŀǰ����̫�����ǣ�ʵ��һ��Լɪ�򻷺�������ɻ��Ļ�����ڵ�

