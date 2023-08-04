#pragma once
#include<stdlib.h>
#include <iostream>
#include <vector>


void swap(int a, int b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
	//이러면 내부만 

}

void ptrswap(int* a, int* b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap2(void* x, void* y, int size)
{
	void* tmp;
	if ((tmp = malloc(size)) == NULL) {
		return;
	}

	memcpy(tmp, x, size); memcpy(x, y, size); memcpy(y, tmp, size);
	free(tmp);


}


int fect(int n)
{
	if (n < 0) {
		return 0;
	}
	else if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		std::cout << n << "\n";
		return n * fect(n - 1);
	}
}

int facttail(int n, int a)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	else
		return facttail(n - 1, n * a);
}

int issort(char* data, int size, int esize, int (*compare) (const void* key1, const void* key2))
{
	char* a = data;
	void* key;
	int i, j;

	if ((key = (char*)malloc(esize)) == NULL)
		return -1;

	for (j = 1; j < size; j++) {
		memcpy(key, &a[j * esize], esize);
		i = j - 1;
	

		while (i >= 0 && compare(&a[i * esize], key) > 0) 
		{
			memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
			i--;
		}

		memcpy(&a[(i + 1) * esize], key, esize);
	}
	free(key)
		;
	return 0;
}

