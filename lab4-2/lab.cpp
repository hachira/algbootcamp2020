#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int judge(int a, int b)
{
	int flag = 0, r = a, sb = 0;
	while(r > 0) 
	{
		flag |= 1<<(r%10);
		r /= 10;
	}
	while(a > 0)
	{
		if(flag & (1<<(b%10)))
		{
			if(a%10 == b%10) sb += 16;
			else sb++;
		}
		a /= 10; b /= 10;
	}
	return sb;
}

int main()
{
	srand(time(0));

	//	Make a candidate list
	int cand[504];
	int t = 0;
	for(int i = 1; i < 10; i++ )
	{
		for(int j = 1; j < 10; j++ )
		{
			if(i==j) continue;
			for(int k = 1; k < 10; k++ )
			{
				if(i==k || j==k) continue;
				cand[t++] = i*100+j*10+k;
			}
		}
	}

	//	Shuffle candidate list
	for(int i = 0; i < 504*504*10; i++)
	{
		int a = rand()%504;
		int b = rand()%504;
		int t = cand[a];
		cand[a] = cand[b];
		cand[b] = t;
	}

	//	Guess and write history
	int h[100][2];
	int hc = 0;
	for(int i = 0; i < 504; i++)
	{
		bool isValid = true;
		for(int j = 0; j < hc; j++)
		{
			int r = judge(cand[i], h[j][0]);
			if(r != h[j][1]) { isValid=false; break; }
		}
		if(!isValid) continue;
		printf("Guess : %d\n", cand[i]);
		int s, b;
		scanf("%d%d", &s, &b);
		if(s == 3) break;
		h[hc][0] = cand[i]; h[hc][1] = (s<<4)|b; hc++;
	}
}
