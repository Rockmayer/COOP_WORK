#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<iostream>
#include <conio.h>
#include<string.h>
#include<math.h>
typedef unsigned long long int uli;
using namespace std;

struct nages
{	
	char name[20];
	uli age;
};
struct List
{
	nages a;
	List* next;
};

int isum = 1;
/*Написати програму для об'єднання декількох масивів, m – кількість масивів, що
підлягають об'єднанню; s -масив вказівників на масиви; масив dim -містить розміри даних
масивів. Пам'ять під масиви виділити динамічно; masyv – результуючий масив.*/
void printList(List* begin)
{
	List* print = begin;
	
	while (print)
	{
		printf("%d->", print->a.age);
		print = print->next;
	}
	printf("NULL\n");
}
int main()
{
	srand(time(NULL));
	List* begin = new List;
	begin->next = NULL;
	List* end = begin;
	for (int i = 0; i < 5; ++i)
	{
		end->next = new List;
		end = end->next;
		end->a.age = rand() % 60;
		cout << end->a.age << endl;
		end->next=NULL;
	}
	end = begin;
	end = end->next;
	List* sort = end;
	sort = sort->next;
	List* temp=begin;
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			if (end->a.age > sort->a.age)
			{
				sort = end;
				end = end->next;
			}
			end = sort;
			sort = sort->next;
		}
	}
	_getch();
	printList(begin->next);
	return 0;
}

