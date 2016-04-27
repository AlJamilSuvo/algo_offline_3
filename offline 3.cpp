#include <iostream>
#include <cstring>
#include <algorithm>
#define LOOP(a,b,c) for(int c=a;c<b;c++)
using namespace std;

int mini(int a,int b){ return a<b?a:b;}
int maxi(int a,int b){return a>b?a:b;}





struct res{
    int max,min;
    bool checkEmpty(){
        return (max==-99999 && min==99999);
    }
};

res demo[1000][1000];

int num[1000];//={-2,-3,-6,-7,6,-9,-8,-9};
char ope[1000];//={'+','*','+','*','*','+','+'};


res solve(int l,int r){
    if (l==r){
        res ans;
        ans.max=num[l];
        ans.min=num[l];
        return ans;
    }
    int max=-99999;
    int min=999999;
    int t[4];
    int temp;
    if (!demo[l][r].checkEmpty()) return demo[l][r];
    LOOP(l,r,i){
        res t1=solve(l,i);
        res t2=solve(i+1,r);
        if (ope[i]=='+'){
            t[0]=t1.max+t2.max;
            t[1]=t1.max+t2.min;
            t[2]=t1.min+t2.max;
            t[3]=t1.min+t2.min;
        }
        else{
            t[0]=t1.max*t2.max;
            t[1]=t1.max*t2.min;
            t[2]=t1.min*t2.max;
            t[3]=t1.min*t2.min;
        }
        LOOP(0,4,j) min=mini(min,t[j]);
        LOOP(0,4,j) max=maxi(max,t[j]);
    }
    res ans;
    ans.max=max;
    ans.min=min;
    demo[l][r]=ans;
    return ans;
}




int main(){
    int N;
    cin>>N;
    LOOP(0,N,i) cin>>num[i];
    LOOP(0,N-1,i) cin>>ope[i];



    LOOP(0,900,i) LOOP(0,900,j){
        demo[i][j].max=-99999;
        demo[i][j].min=99999;
    }
    res a=solve(0,N-1);
    cout<<a.max<<endl;
}







