#include <bits/stdc++.h>
using namespace std;
struct Activity
{
  char name;
  int start, finish;
};

bool cmp(Activity a, Activity b)
{
  return a.finish < b.finish;
}
int main()
{
    int n;
    cin>>n;
    if(n<=0)
    {
      cout<<"No Activity to select\n";
      return 0;
    }
    Activity arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i].name>>arr[i].start>>arr[i].finish;
    }
    sort(arr, arr+n, cmp);
    
    int activity[n], j=0;
    int last_finish = arr[0].finish;
    activity[j++] = 0;
    for(int i=1;i<n;i++)
    {
      if(arr[i].start >= last_finish)
      {
        last_finish = arr[i].finish;
        activity[j++] = i;
      }
    }
    for(int i=0;i<j;i++)
    {
      cout<<arr[activity[i]].name<<" ";
    }
    return 0;
}
