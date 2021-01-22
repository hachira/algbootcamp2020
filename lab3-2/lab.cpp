#include <stdio.h>

void hanoi(int n, char a, char b, char c)
{
	if(n == 0) return;
	hanoi(n-1, a, c, b);
	printf("%d : %c -> %c\n", n, a, b);
	hanoi(n-1, c, b, a);
}

int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');
}
