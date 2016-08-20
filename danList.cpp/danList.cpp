#pragma once
#include<stdio.h>
#include"head.h"
#include<assert.h>
#include<new>

//#include<math.h>

//��һ��ָ�뻹�Ƕ���ָ�룬ȡ�����Ƿ���ܸı�ͷָ���ָ�򣬴�����ָ��Ҳ���Դ�һ��ָ������ã�

//1����ʼ��������
void InitList(PNode* pHead)//����ȥͷ���ָ��
{
	assert(NULL != pHead);//����һ��ָ��
	*pHead = NULL;//���������ʱ���ô������Ķ���ָ��
}


//2��ͷɾ
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


//3��βɾ
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
		while (pNode->pNext)//whileѭ���������������Ĳ��ܽ���ѭ��
		{
			pPreNode = pNode;
			pNode = pNode->pNext;
		}

		free(pNode);
		pPreNode->pNext = NULL;
	}
}


//4��ͷ��
void PushFront(PNode *pHead, DataType data)
{
	//����һ��
	assert(NULL != pHead);
	PNode pNewNode = _ByeNode(data);
	if (NULL != pNewNode)
	{
		pNewNode->pNext = *pHead;
		*pHead = pNewNode;
	}

	//��������
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

//5������data����һ���µĽڵ�
PNode _ByeNode(DataType data)
{
	PNode pNewNode;
	pNewNode =(PNode)malloc(sizeof(Node));

	if (NULL == pNewNode)//����Ƿ񿪱ٳɹ�
	{
		return NULL;
	}

	pNewNode->data = data;
	pNewNode->pNext = NULL;

	return pNewNode;
}


//6��β��
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
		//�����һ���ڵ�
		while (pNode->pNext)
		{
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
	}
}

//7��������ĳ���
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


//8�����ң����������ڵ��������ҽڵ�
PNode Find(PNode pHead, DataType data)
{
	PNode pNode = pHead;
	//if (NULL == pHead)
	//{
	//	return NULL;
	//}//ע�͵���һ����Ҳ�ǿ��Եģ���������
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


//9���ڵ�������ĳ���ڵ�����������
void Insert(PNode* pHead,PNode pos, DataType data)
{
	assert(NULL != pHead);
	PNode pNewNode = _ByeNode(data);

	if (NULL == *pHead && NULL == pos)
	{
		return;
	}
	 //��pos�Ƿ��ڵ������д���
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


//10���ڵ�������ɾ��ĳ���ڵ�
void Erase(PNode* pHead, PNode pos)
{
	assert(NULL!=pHead);
	if (NULL == *pHead && NULL==pos)
	{
		return;
	}
	if (pos == *pHead)
	{
		*pHead = (*pHead)->pNext;//ֱ��ɾ��ͷ��㣬�ڸı��µ�ͷ���
		free(pos);
		return;
	}
	else
	{
		//��pos��λ��
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


//11����ӡ����
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


//12���Ƴ�ĳ�����ݡ���ɾ��
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
			return;//�ص㣺��ʱ�Ѿ��ҵ�Ҫɾ���Ľڵ㣬��Ҫֱ�ӷ��أ��������ѭ��
		}
	}
}


//13��ɾ����������data��ȵ���������
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


//14��ɾ��һ����ͷ������ķ�β�ڵ�
void DeleteNotTailNode(PNode pos)
{
	//��ͷ��������ɾ��������ʱ��ֻ��ɾ������Ľڵ㣬data����
	PNode pDeleteNode = NULL;
	if (NULL == pos || NULL == pos->pNext)//β�ڵ�
	{
		return;
	}
	pDeleteNode = pos->pNext;//��ʱ��Ҫһ���ڵ㱣��pos֮�����
	pos->data = pDeleteNode->data;
	pos->pNext = pDeleteNode->pNext;
	free(pDeleteNode);
}

//15����β��ͷ��ӡ������Ҳ�����������ÿ���ڵ��ֵ��
void PrinitdanListFromTailToHead(PNode pHead)
{
	if (NULL != pHead)
	{
		PrinitdanListFromTailToHead(pHead->pNext);
		printf("%d  ",pHead->data);
	}
}


//16������ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
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


//17�����ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
//��������-���ÿ���ָ��
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
	while (NULL != pFastNode && NULL != pFastNode->pNext)//�ڵ��������������ż����
	{
		pFastNode = pFastNode->pNext->pNext;
		pSlowNode = pSlowNode->pNext;
	}
	return pSlowNode;
}


//18�����������(����ָ����ƶ�)
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

	*pHead = NULL;//��ԭ����ͷ���ָ���
	*pHead = pCurNode;//���µ�ͷ���ָ��ԭ����β�ڵ�
}


//19��ð���������������ﴫһ��ָ������Ѱζ������
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

	while (pHead->pNext!= pTailNode)//β�ڵ�ÿ�λ���һ��λ�ã���Ϊһ�������������ҵ�һ���ڵ����ȷλ�÷�����󡪡����ģ�//Ϊʲô��pHead��pNext�أ���Ϊ��N������N-1�������ҵ�����ȷ��λ�ú�ʣ�µ����һ����λ���Զ��̶��ˣ���������
	{
		pCurNode = pHead;
		pNextNode = pCurNode->pNext;
		flag = 0;//�����ٴλָ���0������Ϊ����ð��֮���Ѿ������ˣ��Ͳ���һ����Ҫ�������ȥ��ð��
		
		while (pNextNode!=pTailNode )//������һ������
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
	    pTailNode = pCurNode;//�ָ�β�ڵ��λ��(Ҳ����˵�����ڸ���ʼ����pTailNodeһ������ð�ݵķǿյ�������ֵ)
	}
}



//20���ͷŵ�����Ľڵ�
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



//21���ϲ�����������������֤�µ�����Ҳ������ģ���Ϊ����
PNode MergeList(PNode pHead1, PNode pHead2)//��������Ҳ�Ǵ�һ��ָ�롪������Ѱζ
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

	if (pNode1->data < pNode2->data)//�ҵ�һ����ͷ��Ҳ�����ҵ��µ�ͷ����λ��
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

	//�����ĺϲ���ʼ��(S�ε�ѭ��)
	while (NULL != pNode1&&NULL != pNode2)
	{
		if (pNode1->data > pNode2->data)
		{
			pTailNode->pNext = pNode2; //������pTailNode = pNode2;��Ϊ�����Ļ���û�н����������������Ƕ�����һ��һ���ڵ㣬���Դ����ô
			pNode2 = pNode2->pNext;
		}
		else
		{
			pTailNode->pNext = pNode1;
			pNode1 = pNode1->pNext;
		}
		pTailNode = pTailNode->pNext;//ÿ�ζ�Ҫ�ƶ�β�ڵ㣬�������ȫ������
	}

	if (NULL == pNode1)
	{
		pTailNode->pNext = pNode2;
	}
	else
	{
		pTailNode->pNext = pNode1;
    }
	return pNewHead;//����������������ͷ���
}




//22���ҵ�����ĵ�����K���ڵ�(����ָ��)��Ҫ��ֻ�ܱ���һ������
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


//23��ɾ�������еĵ�����K���ڵ�
void DeleteLastKNode(PNode* pHead, int K)
{
	PNode pFast = NULL;
	PNode pSlow = NULL;//���Ҫɾ���Ľڵ����pSlow
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
	if (pSlow == *pHead)//����ж���������Ҫ
	{
		*pHead = (*pHead)->pNext;
	}
	else
	{
		pPreNode->pNext = pSlow->pNext;
	}

	free(pSlow);
}


//24��������ʵ��һ��Լɪ�򻷣�
//��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ��
//�ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳��У�
//������һ�����ִ�1��ʼ����������m���Ǹ����ֳ��У�
//���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ������

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
	while (pNode!=pNode->pNext)//ֱ�����ֻʣ��һ���ڵ�
	{
		while (--M)
		{
			pPreNode = pNode;
			pNode = pNode->pNext;
		}
		pPreNode->pNext = pNode->pNext;///Ϊʲô�����õ����滻��ɾ��
		free(pPreNode);
     }	
	return pNode;
}


//25���ж�һ���������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣬������ÿ���㷨��ʱ�临�Ӷ�

//�ж��Ƿ�������ÿ���ָ�룬����ָ�������׷�ϣ���һ���ǻ�
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


//�������󻷵ĳ���(�����������)
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



//���������󻷵���ڵ㡪����6����
/////������һ����ѧ�Ƶ�������ȷ������
//ͷ��㡢��ڵ㡢����ָ��������㣨��ָ���ȴ�ͷ����ߵ���ڵ㴦����ָ��ſ�ʼ��ͷ��㴦�ߣ�
//���У�L+X=2*(L+X)+nr;����L+X=nr;����L=nr-X;(��Խ��nԽС����ԽС��nԽ��)(r�ǻ����ܳ���Ҳ���ǰѻ�һȦ�ĳ���)
//��n=1ʱ��L=r-X;
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



//26���ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������������������
//(�ཻ�ĸ���ཻ֮������������һ��������һ��)
//���ȣ��ж����������Ƿ��ཻ������ֵӦ����0��1(�ཻ�ĸ���ཻ֮������������һ��������һ��)
//�󽻵㣬���ص��ǽڵ�


//������ʽ��V�κ�Y�Σ�V��Ҳ��������Y�����棬���Բ��ÿ���V�ε������


//�ж��Ƿ��ཻ
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



//������ĳ��ȣ��������һ��ʼ���Ѿ�ʵ�ֺ��ˣ�


//�󽻵�
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int len1 = 0;
	int len2 = 0;
	int iStep = 0;
	PNode pNode1 = NULL;
	PNode pNode2 = NULL;
	if (!IsCross(pHead1, pHead2))//����û���ཻ,�޽���
	{
		return NULL;
	}
	//������������������϶��ཻ��һ�����ҵ��ཻ�Ľ���
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



//27���ж����������Ƿ��ཻ�����ཻ���󽻵㣨������������ܴ�����
//����������������������ܶ����������ܶ�������������һ��������һ�����������������ཻ����
//�ཻҲ����������������ཻ�������ཻ�����ཻ
//(�ཻ֮����һ�£����һ������)
//�ж��������������Ƿ��ཻ��
PNode TwoCircleListIsCross(PNode pHead1, PNode pHead2)
{
	PNode pNode1 = NULL;
	PNode pNode2 = NULL;
	if (NULL == pHead1&&NULL == pHead2)
	{
		return NULL;
	}
	//���������������������Y���Σ�
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
    //���������������("6��y"�Ρ����㶮��)
	

}


