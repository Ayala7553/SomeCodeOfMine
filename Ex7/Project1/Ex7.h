#pragma once

typedef struct node
{
	int val;
	struct  node* next;

}node, * ptrNode;
void CreateList(ptrNode* head, int n);
void printList(const char* title, ptrNode list);
void chang(ptrNode* header);