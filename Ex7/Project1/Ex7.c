#include "Ex7.h"
#include <stdlib.h>
#include <stdio.h>

void CreateList(ptrNode* head, int n)
{
	ptrNode tmp;
	tmp = *head = (ptrNode)malloc(sizeof(node));
	if (!tmp)
	{
		exit(1);
	}
	tmp->val = abs(rand() % 100-50);
	for (int i = 0; i < n - 1; i++)
	{
		tmp->next = (ptrNode)malloc(sizeof(node));
		if (!tmp->next)
		{
			exit(1);
		}
		tmp = tmp->next;
		tmp->val = abs(rand() % 100 - 50);
	}
	tmp->next = NULL;
}
void printList(const char* title, ptrNode list)
{
	puts(title);
	while (list)
	{
		printf("%d ,", list->val);
		list = list->next;
	}
	puts("");
}
void change(ptrNode* header)
{
	ptrNode tmp = *header;
	*header = (*header) ->next;
	tmp->next = NULL;
	ptrNode tmp2;
	while ((* header)->next)
	{
		tmp2 = (*header);
		(*header) = (*header)->next;
		tmp2->next = tmp;
		tmp = tmp2;
	}
	(*header)->next = tmp;
}
void main()
{
	ptrNode head;
	CreateList(&head, 10);
	printList("List:", head);
	change(&head);
	printList("New List:", head);
}
/*
List:
-9 ,17 ,-16 ,-50 ,19 ,-26 ,28 ,8 ,12 ,14 ,
New List:
14 ,12 ,8 ,28 ,-26 ,19 ,-50 ,-16 ,17 ,-9 ,
*/