#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct node
{
	int data;
	struct node* next;
}Liste;

Liste* getNode()
{
	Liste* node;
	node = (Liste*)malloc(sizeof(Liste)); //Liste* türünde node tanýmlamýþtýk
	return node;
}

Liste* insert(Liste* head, int data)
{
	if (head == NULL) 
	{
		head = getNode();
		head->data = data;
		head->next = NULL;
		return head;
	}
	Liste* temp = getNode();
	temp->data = data;
	temp->next = NULL;

	Liste* list = head; 
	


	while (head->next != NULL)
	{
		head = head->next; 
	}

	head->next = temp; 
	return list;
}
void printlist(Liste* head)
{
	if (head == NULL)
	{
		printf("Listede eleman yoktur \n");
	}
	else
	{
		while (head != NULL)
		{
			printf("%d ", head->data);
			head = head->next;
		}
	}
}
bool search(Liste* head, int x)
{
	Liste* current = head; 
	while (current != NULL)
	{
		if (current->data == x)
			return true;
		current = current->next;
	}
	return false;
}

void sayRakam(Liste* head, int elemanSayisi) {
	Liste* temp = head;
	Liste* count = head;
	int rakam[100];
	int sonuc[100];
	int dizi[100];

	for (int i = 0; i < elemanSayisi; i++) {
		rakam[i] = head->data;
		head = head->next;
	}
	for (int i = 0; i < elemanSayisi; i++) {
		if (rakam[i] == count->data) {
			break;
		}
		else {
			sonuc[i] = count->data;
		}
	
		count = count->next;
	}
	for (int i = 0; i < elemanSayisi; i++) {
		int say = 0;
		for (int j = 0; j < elemanSayisi; j++) {
			if (temp->data == rakam[j]) {
				say++;
			}
		}
		dizi[i] = temp->data;
		for (int a = 0; a < i; a++) {
			
			if (dizi[i] == rakam[a]) {
				printf("%d sayisindan %d tane vardir.\n", temp->data, say);
			}
			
		}
		temp = temp->next;
	}
}


int main()
{
	Liste* list = NULL;
	srand(time(NULL));
	int b;
	for (int i = 0; i < 11; i++) {
		list = insert(list, rand()%10);
	}
	
	printf("Liste:");
	printlist(list);
	printf("\n");
	printf("\n");
	printf("Tekrar edenler:");
	printf("\n");
	sayRakam(list, 10);
	
	

	
	return 0;
}