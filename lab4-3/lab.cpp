#include <stdio.h>
int pelindrome(int n)
{
	int r = 0;
	while(n > 0) r=r*10+n%10, n/=10;
	return r;
}
int main()
{
	int k;
	scanf("%d", &k);
	if(k <= 9) { printf("%d", k); return 0; }
	k -= 10;
	int iv, is, tv;
	for(is = 2, iv = 9, tv = 1; ; is++)
	{
		if(k < iv) break;
		k -= iv;
		if(is%2 == 1) tv *= 10;
		else iv *= 10;
	}
	if(is%2 == 1)
	{
		int f = k/10 + tv;
		printf("%d%d%0*d\n", f, k%10, is/2, pelindrome(f));
	}
	else
	{
		k += tv;
		printf("%d%0*d\n", k, is/2, pelindrome(k));
	}
}
