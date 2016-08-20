#pragma once
#include<stdio.h>
#include"head.h"
#include<assert.h>
#include<new>

//#include<math.h>

//传一级指针还是二级指针，取决于是否可能改变头指针的指向，传二级指针也可以传一级指针的引用；

//1、初始化单链表
void InitList(PNode* pHead)//传进去头结点指针
{
	assert(NULL != pHead);//断言一级指针
	*pHead = NULL;//真正做题的时候用传进来的二级指针
}


//2、头删
void PopFront(PNode* pHead)
{
	assert(NULL != pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else if (NULL == (*pHead)->pNext)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pNode = *pHead;
		*pHead = (*pHead)->pNext;
		free(pNode);
	}
}


//3、尾删
void PopBack(PNode* pHead)
{
	assert(pHead != NULL);
	if (NULL == *pHead)
	{
		return;
	}
	else if (NULL == (*pHead)->pNext)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pNode = *pHead;
		PNode pPreNode = pNode;
		while (pNode->pNext)//while循环里面的条件是真的才能进入循环
		{
			pPreNode = pNode;
			pNode = pNode->pNext;
		}

		free(pNode);
		pPreNode->pNext = NULL;
	}
}


//4、头插
void PushFront(PNode *pHead, DataType data)
{
	//方法一：
	assert(NULL != pHead);
	PNode pNewNode = _ByeNode(data);
	if (NULL != pNewNode)
	{
		pNewNode->pNext = *pHead;
		*pHead = pNewNode;
	}

	//方法二：
   /*assert(NULL != pHead);
	PNode pNewNode = _ByeNode(data);

	if (NULL == *pHead)
	{
	    *pHead = pNode;
	    rerurn;
	}
	else 
	{
	    pNewNode->pNext=*pHead;
	   (*pHead)=pNewNode;
	}
	*/

}

//5、根据data创建一个新的节点
PNode _ByeNode(DataType data)
{
	PNode pNewNode;
	pNewNode =(PNode)malloc(sizeof(Node));

	if (NULL == pNewNode)//检测是否开辟成功
	{
		return NULL;
	}

	pNewNode->data = data;
	pNewNode->pNext = NULL;

	return pNewNode;
}


//6、尾插
void PushBack(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	PNode pNode = NULL;

	assert(NULL != pHead);
    pNewNode = _ByeNode(data);
	if (NULL == *pHead)
	{
		*pHead = pNewNode;
		return;
	}
	else
	{
	    pNode = *pHead;
		//找最后一个节点
		while (pNode->pNext)
		{
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
	}
}

//7、求单链表的长度
int Length(PNode pHead)
{
	PNode pNode = NULL;
	int iCount = 0;
	if (NULL == pHead)
	{
		return 0;
	}
	pNode = pHead;
	while (pNode)
	{
		iCount++;
		pNode = pNode->pNext;
	}
	return iCount;
}


//8、查找：根据数据在单链表中找节点
PNode Find(PNode pHead, DataType data)
{
	PNode pNode = pHead;
	//if (NULL == pHead)
	//{
	//	return NULL;
	//}//注释掉这一部分也是可以的，否则冗余
	while (pNode)
	{
		if (pNode->data == data)
		{
			return pNode;
		}
		pNode = pNode->pNext;
	}
	return NULL;
}


//9、在单链表中某个节点后面插入数据
void Insert(PNode* pHead,PNode pos, DataType data)
{
	assert(NULL != pHead);
	PNode pNewNode = _ByeNode(data);

	if (NULL == *pHead && NULL == pos)
	{
		return;
	}
	 //找pos是否在单链表中存在
	PNode pNode = *pHead;
	while (pNode != pos && NULL != pNode)
	{
		pNode = pNode->pNext;
	}
	if (pNode == pos)
	{
		pNewNode->pNext = pos->pNext;
		pos->pNext = pNewNode; 
	}
	if (NULL == pNode)
	{
		return;
	}

}


//10、在单链表中删除某个节点
void Erase(PNode* pHead, PNode pos)
{
	assert(NULL!=pHead);
	if (NULL == *pHead && NULL==pos)
	{
		return;
	}
	if (pos == *pHead)
	{
		*pHead = (*pHead)->pNext;//直接删除头结点，在改变新的头结点
		free(pos);
		return;
	}
	else
	{
		//找pos的位置
		PNode pNode = *pHead;
		PNode pPreNode = pNode;
		while (pNode != pos && NULL != pNode)
		{
			pPreNode = pNode;
			pNode = pNode->pNext;
		}
		if (pNode == pos)
		{
			pPreNode->pNext = pNode->pNext;
			free(pos);
		}
		if (NULL == pNode)
		{
			return;
		}
	}
}


//11、打印链表
void PrinitdanList(PNode pHead)
{
	if (NULL == pHead)
	{
		return;
	}
	PNode pNode = pHead;
	while (NULL!=pNode)
	{
		printf("%d->",pNode->data);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
}


//12、移除某个数据——删除
void Remove(PNode* pHead,DataType data)
{
	assert(pHead);
	PNode pNode = NULL;
	if (NULL == *pHead)
	{
		return;
	}
	if ((*pHead)->data == data)
	{
		*pHead = (*pHead)->pNext;
		free(pNode);
		return;
	}
	while (NULL != pNode->pNext)
	{
		PNode pPreNode = pNode;
		pNode = pNode->pNext;

		if (pNode->data == data)
		{
			pPreNode->pNext = pNode->pNext;
			free(pNode);
			return;//重点：此时已经找到要删除的节点，需要直接返回，否则继续循环
		}
	}
}


//13、删除单链表中data相等的所有数据
void RemoveAll(PNode* pHead, DataType data)
{
	assert(NULL!=pHead);
	if (NULL == *pHead)
	{
		return;
	}

	PNode pNode = *pHead;
	int iCount = 0;
	while (NULL != pNode)
	{
		if (pNode->data == data)
		{
			iCount++;
		}
		pNode = pNode->pNext;
	}
	for (int idx = 0; idx < iCount; idx++)
	{
		Remove(pHead, data);
	}
}


//14、删除一个无头单链表的非尾节点
void DeleteNotTailNode(PNode pos)
{
	//无头单链表在删除操作的时候，只能删它后面的节点，data互换
	PNode pDeleteNode = NULL;
	if (NULL == pos || NULL == pos->pNext)//尾节点
	{
		return;
	}
	pDeleteNode = pos->pNext;//此时需要一个节点保存pos之后的链
	pos->data = pDeleteNode->data;
	pos->pNext = pDeleteNode->pNext;
	free(pDeleteNode);
}

//15、从尾到头打印单链表（也就是逆序输出每个节点的值）
void PrinitdanListFromTailToHead(PNode pHead)
{
	if (NULL != pHead)
	{
		PrinitdanListFromTailToHead(pHead->pNext);
		printf("%d  ",pHead->data);
	}
}


//16、在无头单链表的一个非头节点前插入一个节点
void InsertNotHeadNode(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)
	{
		return;
	}
	pNewNode = _ByeNode(data);

	pNewNode->pNext = pos->pNext;
	pos->pNext = pNewNode;

	DataType dataTemp=pNewNode->data;
	pNewNode->data = pos->data;
	pos->data = dataTemp;
	
}


//17、查找单链表的中间节点，要求只能遍历一次链表
//————-采用快慢指针
PNode FindMidNode(PNode pHead)
{
	PNode pFastNode = NULL;
	PNode pSlowNode = NULL;
	if (NULL == pHead)
	{
		return NULL;
	}
	pFastNode = pHead;
	pSlowNode = pHead;
	while (NULL != pFastNode && NULL != pFastNode->pNext)//节点个数分奇数个和偶数个
	{
		pFastNode = pFastNode->pNext->pNext;
		pSlowNode = pSlowNode->pNext;
	}
	return pSlowNode;
}


//18、链表的逆置(三个指针的移动)
void ReservedanList(PNode* pHead)
{
	PNode pPreNode = NULL;
	PNode pCurNode = NULL;
	PNode pNextNode = NULL;
	assert(NULL != pHead);
	if (NULL == *pHead||NULL==(*pHead)->pNext)
	{
		return;
	}
	pPreNode = *pHead;
	pCurNode = pPreNode->pNext;
	pNextNode = pCurNode->pNext;
	while (NULL != pNextNode)
	{
		pCurNode->pNext = pPreNode;

		pPreNode = pCurNode;
		pCurNode = pNextNode;
		pNextNode = pNextNode->pNext;
	}
	pCurNode->pNext = pPreNode;

	*pHead = NULL;//把原来的头结点指向空
	*pHead = pCurNode;//把新的头结点指向原来的尾节点
}


//19、冒泡排序单链表——这里传一级指针耐人寻味（升序）
void BubbleSort(PNode pHead)
{
	PNode pTailNode = NULL;
	PNode pCurNode = NULL;
	PNode pNextNode = NULL;
	int flag = 0;

	if (NULL == pHead || NULL == (pHead)->pNext)
	{
		return;
	}

	while (pHead->pNext!= pTailNode)//尾节点每次回退一个位置（因为一趟排序下来，找到一个节点的正确位置放在最后——最大的）//为什么是pHead的pNext呢？因为当N个数中N-1个数都找到它正确的位置后，剩下的最后一个的位置自动固定了，无须再排
	{
		pCurNode = pHead;
		pNextNode = pCurNode->pNext;
		flag = 0;//这里再次恢复到0，是因为几次冒泡之后已经有序了，就不用一定非要走完接下去的冒泡
		
		while (pNextNode!=pTailNode )//真正的一趟排序
		{
			if (pCurNode->data > pNextNode->data)
			{
				DataType dataTemp=pCurNode->data;
				pCurNode->data = pNextNode->data;
				pNextNode->data = dataTemp;
				flag = 1;
            }
			pCurNode = pNextNode;
			pNextNode = pNextNode->pNext;
		}
		if (flag != 1)
		{
			return;
		}
	    pTailNode = pCurNode;//恢复尾节点的位置(也可以说它是在给初始化的pTailNode一个参与冒泡的非空的真正的值)
	}
}



//20、释放单链表的节点
void Destroy(PNode* pHead)
{
	PNode pNode = NULL;
	PNode pPreNode = NULL;
	assert(NULL != pHead);
	if (NULL == *pHead)
	{
		return;
	}
	pNode = *pHead;
	while (pNode)
	{
		pPreNode = pNode;
		pNode = pNode->pNext;
		free(pPreNode);
	}
	*pHead = NULL;
}



//21、合并两个已序链表——保证新的链表也是有序的（均为升序）
PNode MergeList(PNode pHead1, PNode pHead2)//——这里也是传一级指针——耐人寻味
{
	PNode pNewHead = NULL;
	PNode pNode1 = NULL;
	PNode pNode2 = NULL;
	PNode pTailNode = NULL;

	if (NULL == pHead1)
	{
		return pHead2;
	}
	if (NULL == pHead2)
	{
		return pHead1;
	}
	pNode1 = pHead1;
	pNode2 = pHead2;

	if (pNode1->data < pNode2->data)//找到一个开头，也就是找到新的头结点的位置
	{
		pNewHead= pNode1;
		pTailNode = pNode1;
		pNode1 = pNode1->pNext;
	}
	else
	{
		pNewHead = pNode2;
		pTailNode = pNode2;
		pNode2 = pNode2->pNext;
	}

	//真正的合并开始了(S形的循环)
	while (NULL != pNode1&&NULL != pNode2)
	{
		if (pNode1->data > pNode2->data)
		{
			pTailNode->pNext = pNode2; //不能用pTailNode = pNode2;因为这样的话并没有将链表链起来，都是独立的一个一个节点，明显错误的么
			pNode2 = pNode2->pNext;
		}
		else
		{
			pTailNode->pNext = pNode1;
			pNode1 = pNode1->pNext;
		}
		pTailNode = pTailNode->pNext;//每次都要移动尾节点，否则就完全错误了
	}

	if (NULL == pNode1)
	{
		pTailNode->pNext = pNode2;
	}
	else
	{
		pTailNode->pNext = pNode1;
    }
	return pNewHead;//返回排序后新链表的头结点
}




//22、找到链表的倒数第K个节点(快慢指针)（要求只能遍历一次链表）
PNode FindLastKNode(PNode pHead, int K)
{
	PNode pFast = NULL;
	PNode pSlow = NULL;
	if (NULL == pHead || K<= 0)
	{
		return NULL;
	}
    pFast = pHead;
    pSlow = pHead;
	
	while (--K)
	{
		if (NULL == pFast->pNext)
	    {
		   return NULL;
	    }
		pFast = pFast->pNext;
	}

	while (NULL != pFast)
	{
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}
	return pSlow;
}


//23、删除链表中的倒数第K个节点
void DeleteLastKNode(PNode* pHead, int K)
{
	PNode pFast = NULL;
	PNode pSlow = NULL;//最后要删除的节点就是pSlow
	PNode pPreNode = NULL;
	assert(NULL!=pHead);
	if (NULL == *pHead || K <= 0)
	{
		return ;
	}
	pFast = *pHead;
	pSlow = *pHead;
	while (--K)
	{
		if (NULL == pFast->pNext)
		{
			return ;
		}
		pFast = pFast->pNext;
	}
	while (NULL != pFast)
	{
		pFast = pFast->pNext;
		pPreNode = pSlow;
		pSlow = pSlow->pNext;
	}
	if (pSlow == *pHead)//这个判断条件很重要
	{
		*pHead = (*pHead)->pNext;
	}
	else
	{
		pPreNode->pNext = pSlow->pNext;
	}

	free(pSlow);
}


//24、单链表实现一个约瑟夫环：
//已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。
//从编号为k的人开始报数，数到m的那个人出列；
//他的下一个人又从1开始报数，数到m的那个人又出列；
//依此规律重复下去，直到圆桌周围的人全部出列

PNode JosephCircle(PNode pHead, int M)
{
	PNode pPreNode = NULL;
	PNode pNode = NULL;
	if (NULL == pHead || M <= 0)
	{
		return NULL;
	}
	pPreNode = pHead;
	pNode = pHead;
	while (pNode!=pNode->pNext)//直到最后只剩下一个节点
	{
		while (--M)
		{
			pPreNode = pNode;
			pNode = pNode->pNext;
		}
		pPreNode->pNext = pNode->pNext;///为什么它们用的是替换法删除
		free(pPreNode);
     }	
	return pNode;
}


//25、判断一个单链表是否带环？若带环，求环的长度，求环的入口点，并计算每个算法的时间复杂度

//判断是否带环：用快慢指针，快慢指针如果能追上，则一定是环
bool IsCircle(PNode pHead)
{
	PNode pFast = NULL;
	PNode pSlow = NULL;
	if (NULL == pHead)
	{
		return false;
	}
	pFast = pHead;
	pSlow = pHead;
	while (NULL!=pFast&&NULL!=pFast->pNext)
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;
		if (pFast == pSlow)
		{
			return true;
		}
	}
	return false;
}


//带环，求环的长度(把相遇点给了)
int GetCircleLength(PNode pMeetNode)
{
	PNode pNode = NULL;
	int iCount = 1;
	if (NULL ==pMeetNode)
	{
		return 0;
	}
	pNode = pMeetNode;
	while (pMeetNode!=pNode->pNext)
	{
		pNode = pNode->pNext;
		iCount++;
	}
	return iCount;
}



//若带环，求环的入口点——“6”形
/////这里有一个数学推导，可以确定条件
//头结点、入口点、快慢指针的相遇点（慢指针先从头结点走到入口点处，快指针才开始从头结点处走）
//则有：L+X=2*(L+X)+nr;——L+X=nr;——L=nr-X;(环越大，n越小；环越小，n越大)(r是环的周长，也就是把环一圈的长度)
//当n=1时，L=r-X;
PNode GetCircleEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode pNode = NULL;
	PNode pM = NULL;
	if (NULL==pHead || NULL == pMeetNode)
	{
		return NULL;
	}
	pNode = pHead;
	pM = pMeetNode;
	while (pNode != pM)
	{
		pNode = pNode->pNext;
		pM = pM->pNext;
	}
	return pNode;
}



//26、判断两个链表是否相交，若相交，求交点。（假设这两个链表都不带环）
//(相交的概念：相交之后两条链表变成一条，方向一致)
//首先：判断两个链表是否相交，返回值应该是0、1(相交的概念：相交之后两条链表变成一条，方向一致)
//求交点，返回的是节点


//两种形式：V形和Y形（V形也包括在了Y形里面，所以不用考虑V形的情况）


//判断是否相交
int IsCross(PNode pHead1, PNode pHead2)
{
	PNode pNode1 = NULL;
	PNode pNode2 = NULL;
	if (NULL == pHead1 || NULL == pHead2)
	{
		return 0;
	}
	pNode1 = pHead1;
	pNode2 = pHead2;
	while (NULL != pNode1->pNext)
	{
		pNode1 = pNode1->pNext;
	}
	while (NULL != pNode2->pNext)
	{
		pNode2 = pNode2->pNext;
	}
	if (pNode1 == pNode2)
	{
		return 1;
	}
	return 0;
}



//求链表的长度（这个函数一开始就已经实现好了）


//求交点
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int len1 = 0;
	int len2 = 0;
	int iStep = 0;
	PNode pNode1 = NULL;
	PNode pNode2 = NULL;
	if (!IsCross(pHead1, pHead2))//它两没有相交,无交点
	{
		return NULL;
	}
	//下面这种情况是它俩肯定相交，一定能找到相交的交点
	len1 = Length(pHead1);
	len2 = Length(pHead2);
	iStep = len1 - len2;
	if (iStep > 0)
	{
		while (iStep--)
		{
			pNode1 = pNode1->pNext;
		}
	}
	else
	{
		iStep = 0 - iStep;
		while (iStep--)
		{
			pNode2 = pNode2->pNext;
		}
	}
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->pNext;
		pNode2 = pNode2->pNext;
	}
	return pNode1;
}



//27、判断两个链表是否相交，若相交，求交点（这两个链表可能带环）
//两个链表有三种情况：可能都带环；可能都不带环；可能一个带环，一个不带环（不可能相交）。
//相交也有三种情况：环内相交；环外相交；不相交
//(相交之后方向一致，变成一条链表)
//判断两个带环链表是否相交？
PNode TwoCircleListIsCross(PNode pHead1, PNode pHead2)
{
	PNode pNode1 = NULL;
	PNode pNode2 = NULL;
	if (NULL == pHead1&&NULL == pHead2)
	{
		return NULL;
	}
	//如果两个链表都不带环（“Y”形）
	pNode1 = pHead1;
	pNode2 = pHead2;
	while (NULL != pNode1&&NULL != pNode2)
	{
		pNode1 = pNode1->pNext;
		pNode2 = pNode2->pNext;
		if (pNode1 == pNode2)
		{
			 return ;
		}
	}
	return false;
    //如果两个链表都带环("6和y"形——你懂得)
	

}


