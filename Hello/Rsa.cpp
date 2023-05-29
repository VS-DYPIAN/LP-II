#include <bits/stdtr1c++.h>
using namespace std;
int gcd(int a,int h){
    int temp;
    temp=a%h;
    if(temp==0){
        return h;
    }
    a=h;
    h=temp;
    return 0;
}
int main(){
    double p=3;
    double q=11;
    double n=p*q;
    double phi=(p-1)*(q-1);
    double e=2;
    while(e<phi&&e!=p&&e!=q){
        if(gcd(e,phi)==1){
            break;
        }
        e++;
    }
    cout<<"e= "<<e<<endl;;
    double m=2;
    double k=1;
    double d=(1+phi*k)/e;
    cout<<"d="<<d<<endl;
    double t=pow(m,e);
    double c=fmod(t,n);
    cout<<"c: "<<c<<endl;
    t=pow(c,d);
    double pl=fmod(t,n);
    cout<<"plain= "<<pl<<endl;
return 0;
}