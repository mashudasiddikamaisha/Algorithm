//id: 231-115-119
#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n, int i)
{
    int mx=i;
    int l = 2*i+1;
    int r= 2*i+2;
    if(l<n && a[i]<a[l])
        mx=l;
    if(r<n && a[mx]<a[r])
        mx=r;
    if(mx!=i)
    {
        swap(a[i],a[mx]);
        heapify(a,n,mx);
    }
}
void heapsort(int a[],int n)
{
    for(int i= n/2 -1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
