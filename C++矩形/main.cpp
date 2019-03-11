#include <iostream>
using namespace std;
int main()
{
    int m,n,t=1;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0)
                cout<<t;
            else
                cout<<" "<<t;
            t++;
        }
        cout<<endl;
    }
}
