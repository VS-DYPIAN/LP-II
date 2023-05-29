#include <iostream>
using namespace std;

void selection(int a[],int n)
{
    int minindex;
    for(int i=0;i<n-1;i++)
    {
        minindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minindex])
            {
                minindex=j;
            }
        }
        swap(a[minindex],a[i]);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements :: ";
    cin>>n;
    int a[n];
    
    cout<<"Enter the elements :: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<"Sorted array :: "<<" ";
    selection(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}  