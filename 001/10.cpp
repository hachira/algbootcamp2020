#include <iostream>
using namespace std;
int main(){
        int n;   //입력
        cin >> n ;
        bool right[n+1];
        for(int i=0;i<n+1;i++) // 일단 모두 맞다고 한다. 
            right[i]=true;
        for(int i=2;i*i<=n;i++) // 제곱을 해서 입력받은 수보다 작을 때까지 
        {
            if(right[i]==true)   
            {
                for(int j=i*i;j<=n;j=j+i)  // i의 제곱과 그 이후 i의 배수들은 모두 false 
                    right[j]=false;
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
            if(right[i]==true)
                count++;

        cout<<count<<endl;
}
