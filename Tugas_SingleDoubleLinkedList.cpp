//SINGLE LINKED LIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct numbers{
    int value;
    struct numbers *next;
} *head = NULL, *node, *tail, *temp;



void nambah_data(int x)
{
 node = (struct numbers*)malloc(sizeof(struct numbers));
    node->value = x;

    if(head == NULL){
        head = tail = node;
        node -> next = NULL;
    } else if (node -> value <= head -> value){
        node -> next = head;
        head = node;
    } else if (node -> value >= tail -> value){
        tail -> next = node;
        tail = node;
        tail -> next = NULL;
    } else {
        temp = head;
        while(node -> value > temp -> next -> value)
            temp = temp -> next;

        node -> next = temp -> next;
        temp -> next = node;
    }
}	



void lihat_data()
{
 node = head;
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}



int main()
{

	int pilihan,data;
	do
	{
		fflush(stdin);
		printf("\n 1. Menambahkan data\n");
		printf(" 2. Lihat data\n");
		printf(" 3. Exit\n");
		printf("\n Masukkan pilihan anda [1..3] : ");
		scanf("%d",&pilihan);
		
		switch(pilihan)
		{
			case 1:
				do
				{
					printf("\nMasukkan angka yang ingin di input ke dalam list [1..100] : ");
					scanf("%d",&data);	
				}while(data < 1 || data>100);
				
				nambah_data(data);
				break;
				
			case 2:
				printf("\nData dalam list :\n");
				lihat_data();
				break;
				
			case 3:
				printf("selesai\n");
				break;
				
			default:
				break;
		}
		
	}while(pilihan != 3);
	
	return 0;
	
}


//DOUBLE LINKED LIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct numbers{
    int value;
    struct numbers *next;
    struct numbers *prev;
} *head = NULL, *node, *tail;



void nambah_data(int x)
{
  node = (struct numbers*)malloc(sizeof(struct numbers));
    node->value = x;
    node->next = NULL;
    node->prev = NULL;
    if (head == NULL)
    {
        head = node;
        tail = node;
    } else if (head->value > x)
    {
        node->next = head;
        head->prev = node;
        head = node;
        head -> prev = NULL;
    } else if (tail->value < x)
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
        tail->next = NULL;
    } else
    {
        struct numbers *temp = head;
        while (temp->next != NULL && temp->next->value < x)
        {
            temp = temp->next;
        }
        node->next = temp->next;
        node->prev = temp;
        temp->next = node;
        node->next->prev = node;
    }
}



void lihat_data()
{
 node = head;
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
}



int main()
{

	int pilihan,data;
	do
	{
		fflush(stdin);
		printf("\n 1. Menambahkan data\n");
		printf(" 2. Lihat data\n");
		printf(" 3. Exit\n");
		printf("\n Masukkan pilihan anda [1..3] : ");
		scanf("%d",&pilihan);
		
		switch(pilihan)
		{
			case 1:
				do
				{
					printf("\nMasukkan angka yang ingin di input ke dalam list [1..100] : ");
					scanf("%d",&data);	
				}while(data < 1 || data>100);
				
				nambah_data(data);
				break;
				
			case 2:
				printf("\nData dalam list :\n");
				lihat_data();
				break;
				
			case 3:
				printf("selesai\n");
				break;
				
			default:
				break;
		}
		
	}while(pilihan != 3);
	
	return 0;
	
}



