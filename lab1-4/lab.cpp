#include <iostream>
using namespace std;
long long lcm(int a, int b)
{
	long long r = a*b;
	while(b) { int t = a%b; a = b; b = t; }
	return r/a;
}
int main(){
	int n, a, b;
	cin >> n >> a >> b;
	long long c = lcm(a, b);
	int na = n/a;
	int nb = n/b;
	int nc = n/c;
	long long sum = (long long)a*na*(na+1)/2 +
		(long long)b*nb*(nb+1)/2 -
		(long long)c*nc*(nc+1)/2;
	cout << sum;
}
