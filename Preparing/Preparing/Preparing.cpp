#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<iostream>
#include <conio.h>
#include<string.h>
#include<math.h>
typedef unsigned long long int uli;
using namespace std;
union aaa {
	int num,num2;
	char name[20];
};
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
		printf("%s->", print->a.age);
		print = print->next;
	}
	printf("NULL\n");
}
int main()
{
	List* begin;
	begin = new List;
	begin->a.age = 10;
	cout << begin->a.age << endl;
	strcpy(begin->a.name, "yegor");
	begin->next = NULL;
	List* end = begin;
	for (int i = 0; i < 5; ++i)
	{
		end->next = new List;
		end = end->next;
		end->a.age = rand() % 60;
		cout << end->a.age << endl;
		for (int j = 0; j < 5; ++j)
		{
			end->a.name[j] = 97 + rand() % 24;
		}
		end->next = NULL;
	}
	_getch();
	end = begin;
	end = end->next;// 1
	List* sort = begin;// 0
	List* swap;
	for (int i = 0; i < 6-1; ++i)
	{
		for (int j = 0; j < 6 - i - 1; ++j)
		{
			swap = end;
			if (end->a.age > sort->a.age)
			{
				end = end->next;
				sort->next = swap;
			}
			end = end->next;
			sort = sort->next;
		}
	}
	
	printList(begin);
	/*aaa item1;
	item1.num = 20;
	item1.num2 = 30;
	cout << ++item1.num;

	int m;
	cout << "Enter m";
	cin >> m;
	int* dim = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; ++i)
	{
		dim[i] = 1 + rand() % 9;
		cout << dim[i] << endl;
	}
	cout << endl << endl << endl;
	_getch();
	int** s = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; ++i)
	{
		s[i] = (int*)malloc(dim[i] * sizeof(int));
		for (int j = 0; j < dim[i]; ++j)
		{
			s[i][j] = 1 + rand() % 100;
			if(i==0)
			cout << s[i][j] << endl;
			else cout << "\t"<<s[i][j]<<endl;

		}

	}
	int sumdiv = 0;
	
	for (int i = 0; i < m; ++i)
	{
		sumdiv += dim[i];
	}
	cout <<"Sumdiv"<< sumdiv<<endl;
	int* masyv = (int*)malloc(sumdiv * sizeof(int));
	for (int i = 0,k=0,j=0; i < m; ++k,++j)
	{
		if (k == dim[i])
		{
			k = 0;
			i++;
		}
		if (i == m)
			break;
		masyv[j] = s[i][k];
	}
	
	for (int i = 0; i < sumdiv; ++i)
	{
		cout << masyv[i] << endl;
	}
	*/


	return 0;
}

