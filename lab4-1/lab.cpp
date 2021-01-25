#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void judge(int *think, int *guess, int *strike, int *ball)
{
	int s = 0, b = 0, flag = 0;
	for(int i = 0; i < 3; i++) flag |= 1<<think[i];
	for(int i = 0; i < 3; i++)
	{
		if(!(flag & (1<<guess[i]))) continue;
		if(think[i] == guess[i]) s++;
		else b++;
	}
	*strike = s; *ball = b;
}

int main()
{
	srand(time(0));

	int think[3], guess[3];
	int strike = 0, ball;

	//	Computer Think
	think[0] = rand()%9+1;
	think[1] = rand()%8+1;
	if(think[0] <= think[1]) think[1]++;
	think[2] = rand()%7+1;
	if(think[0] <= think[2]) think[2]++;
	if(think[1] <= think[2]) think[2]++;

	int t;
	for(t = 0; strike != 3; t++)
	{
		char str[100];
		printf("Guess : ");
		scanf("%s", str);
		for(int i = 0; i < 3; i++) guess[i] = str[i]-'0';
		judge(think, guess, &strike, &ball);
		printf("%dS%dB\n", strike, ball);
	}
	printf("Score : %d\n", t);
}
