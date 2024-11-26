#include <iostream>
using namespace std;

int main() 
{
    int n = 4;
    int wt[n+1] = {0, 2, 4, 8, 10};
    int v[n+1] = {0, 10, 20, 30, 40};
    int c = 12;
    int dp[n+1][c+1];
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=c;j++)
      {
        if(i==0 || j==0) dp[i][j] = 0;
        else if(wt[i] <= j)
        {
          dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-wt[i]]);
        }
        else
        {
          dp[i][j] = dp[i-1][j];
        }
        cout<<dp[i][j]<<" ";
      }
      cout<<'\n';
    }
    int i = n, j = c;
    while(i>=0 && j>=0)
    {
      if(dp[i][j]==dp[i-1][j])
      {
        cout<<0<<'\n';
        i--;
      }
      else
      {
        cout<<1<<'\n';
        j-=wt[i];
        i--;
      }
    }
    return 0;
}
