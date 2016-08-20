#pragma once
#include<stdio.h>
#include"head.h"
//#include"danList.hpp"

PNode danList;

void Test()
{
	PushBack(&danList, 1);
	PushBack(&danList, 2);
	PushBack(&danList, 3);
	PushBack(&danList, 4);
	PushBack(&danList, 5);
	//ReservedanList(&danList);

    //PNode Nolist = FindLastKNode(danList, 2);
	JosephCircle(&danList, 2);
}
int main()
{
	Test();
	return 0;
}