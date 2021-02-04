#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int hist[n];
	for(int i = 0; i < n; i++) scanf("%d", hist+i);

	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if(i > 0 && hist[i-1] >= hist[i]) continue;
		int min = hist[i];
		for(int j = i+1; j < n; j++)
		{
			if(min > hist[j]) min = hist[j];
			int area = min*(j-i+1);
			if(max < area) max = area;
		}
	}
	printf("%d\n", max);
}
