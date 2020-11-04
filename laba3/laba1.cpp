#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
bool proverka(int x)
{
	if (x == 1 || x == 2) 
	{
		return true;
	}
	else
	{
		puts("повторите ввод:");
		return false;	
	}
}
int fib(int x)
{
	if (x < 1)return 0;
	if (x == 1) return 1;
	return fib(x - 1) + fib(x - 2);
}
int main()
{
	system("chcp 1251>nul");
	printf("\tЧисла Фибоначчи определяются следующим образом: Fb(0)=0; Fb(1)=1; Fb(n) = Fb(n–1) + Fb(n–2). \n\tОпределить Fb(n).\n\n");
	printf("\t1 - рекурсия\n");
	printf("\t2 - другой способ\n\n");
	int option;
	int n;
	do {
		scanf_s("%d", &option);
	} while (proverka(option) != 1);
	switch (option)
	{
	case 1:
		printf("введите n: ");
	    scanf_s("%d", &n);
		printf("Число Фибоначчи: %d", fib(n));
		break;
	case 2:
		printf("введите n: ");
		scanf_s("%d", &n);
		if (n > 0) 
		{   
			vector<int> fib(n);
			for (int i = 0; i < n; i++)
			{
				if (i <= 1)
				{
					fib[i] = 1;
				}
				if (i > 1)
				{
					fib[i] = fib[i - 1] + fib[i - 2];
				}
			}
			printf("Число Фибоначчи: %d", fib[n - 1]);
		}
		else
		{
			printf("Число Фибоначчи: 0");
		}
		break;
	}
	system("pause>nul");
	return 0;
}