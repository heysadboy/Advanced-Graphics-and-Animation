/*Number of points using bressenham algorithm*/

#include<bits/stdc++.h>

using namespace std;

void bressenham(int xa,int ya,int xb,int yb)
{
    int dx=abs(xb-xa);
    int dy=abs(yb-ya);
    int k = 2*dy - dx,steps=dx-1;
    int num = steps;
    cout<<xa<<" "<<yb<<endl;

    while(steps--)
    {
        if(k<0)
        {
            cout<<xa+1<<" "<<ya<<endl;
            k = k+(2*dy);
        }
        else
        {
            cout<<xa+1<<" "<<ya+1<<endl;
            ya++;
            k = k+(2*dy)-(2*dx);
        }
        xa++;
    }
    cout<<"Number of points: "<<num;
}

int main()
{
    int xa,ya,xb,yb;

    cin>>xa>>ya>>xb>>yb;
    bressenham(xa,ya,xb,yb);
    return 0;
}
