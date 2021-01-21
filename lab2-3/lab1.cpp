#include <stdio.h>
int main()
{
	long long n;
	scanf("%lld", &n);

	//	약수의 개수를 1로 초기화한다.
	int nodiv=1;
	//	2의 배수인지 검사한다.
	if(n%2==0)
	{
		int s = 1;
		while(n%2==0) n/=2, s++;
		nodiv *= s;
	}
	//	3이상의 홀수에 대해서
	for(long long i=3; i*i <= n; i+=2)
	{
		if(n%i) continue;
		int s = 1;
		while(n%i==0) n/=i, s++;
		nodiv *= s;
	}
	if(n > 1) nodiv*=2;

	printf("%d\n", nodiv);
}
