#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* origin = NULL;

struct _Node
{
	int a;
};

typedef struct _Node Node;

// 포인터가 가르키고있는 값이 상수
// 포인터 주소값이 상수
const Node* const Process()
{
	Node* a = (Node*)malloc(sizeof(Node));
	if (a != NULL)
	{
		a->a = 10;
		return a;
	}
	return NULL;
}

void Set(const char* p)
{
	size_t pSize = strlen(p) + 1;
	origin = (char*)malloc(pSize);
	if (origin != NULL)
		memcpy(origin, p, pSize);
}

int main()
{
	int num1 = 3;   
	int num2 = 24;

	num1 <<= 3;

	return 0;
}