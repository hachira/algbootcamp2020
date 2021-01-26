#include <stdio.h>
#include <memory.h>

void inverse(char a[])
{
	int n=0;
	while(a[n]) n++;
	//	배열을 거꾸로 만듭니다.
	for(int i = 0; i < n/2; i++)
	{
		int t = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = t;
	}
}

int main()
{
	char a[128], b[128], c[256];

	//	결과를 저장할 c 배열 초기화
	memset(c, 0, sizeof(c));

	//	입력부
	scanf("%s%s", a, b);

	//	입력 배열을 거꾸로 배열하도록 한다.
	inverse(a);
	inverse(b);

	//	곱하기 처리부
	int carry = 0, max = 1, j;
	for(int i = 0; a[i]; i++)
	{
		carry = 0;
		for(j = 0; b[j]; j++)
		{
			carry += c[i+j] + (int)(a[i]-'0')*(b[j]-'0');
			c[i+j] = carry%10;
			carry /= 10;
		}
		if(carry)
		{
			c[i+j] = carry;
			max = i+j;
		}
		else max = i+j-1;
	}
	for(int i = max; i >= 0; i--) putchar(c[i]+'0');
	putchar('\n');
}
