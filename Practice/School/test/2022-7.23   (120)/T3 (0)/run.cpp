#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
    int s;  // speed
    int n;  // number
} d[11000];

struct n2{
    int n;
    bool s=0;  // selected
} a[11000];

int maxD=0;
int n,m,ti=0,br=0;
int di=0;

bool cmp(node a,node b){
    return a.s>b.s;
}

void save(int,int);

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>d[i].s;
        d[i].n=i;
    }
    int runTime=floor(n/2);
    for(int i=0;i<n;i++){
        a[i].n=d[i].s;
    }
    sort(d, d+n, cmp);
    for(int i=0;i<runTime;i++){
        a[d[i].n].s=1;
    }
    di=runTime;
    int con=0;  // continue selected number
    for(int i=0;i<n;i++){
        if(a[i].s)
            con++,maxD+=a[i].n;
        else
            if(con>m){  // Bessie dying
                // save(i-con+1, con);
                // :(
                con=0;
            }
            else
                con=0;
    }
    cout<<maxD;
}


void save(int s,int con){
    int want=con-m;
    int b[con];
    for(int i=s;i<s+con;i++){
        b[i-s]=a[i].n;
    }
    sort(b, b+con);
    // :(
}