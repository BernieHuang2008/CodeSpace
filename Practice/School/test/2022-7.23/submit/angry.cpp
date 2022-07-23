#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct block{
    float s;
    float e;
    int f;
} b[110000], info;

int n,k,r;
int a[110000];
int bi=2;

bool in(int s, int e){
    for(int i=0;i<bi;i++){
        if(b[i].s<=s and e<=b[i].e){
            info=b[i];
            cout<<"in: "<<b[i].s<<","<<b[i].e;
            cout<<"|"<<s<<','<<e<<endl;
            return true;
        }
    }
    return false;
}

bool cmp(block x,block y){
    return x.s<y.s;
}

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n);

    b[0]={(float)a[0], (float)a[0], 1};
    b[1]={(float)a[n-1], (float)a[n-1], n};

    float len=a[n-1]-a[0], boom=k, d;
    while(1){
        d=len*1.0/boom;
        int flg=0;
        int bii=bi;
        int bb=boom;
        for(int i=0;i<bb;i++){
            float bs=a[0]+d*i;
            float be=bs+d;
            if(in(bs, be)){
                bb++;
                flg=info.f;
                continue;
            }
            int flag=0;
            for(flg;a[flg]<be;flg++){
                flag=1;
            }
            if(!flag){
                b[i].s=bs;
                b[i].e=be;
                b[i].f=flg;
                bi++;
            }
        }
        if(bii==bi)
            break;
        len-=(bi-bii)*d;
    }
    sort(b, b+bi, cmp);
    int fl=0;
    float cmin=110000;
    for(int i=0;i<=bi;i++){
        float s=b[i].e;
        float e=b[i+1].s;
        if(e-s<=0){
            continue;
        }
        for(int j=0;j<(e-s)/d;j++){
            float ss=s+j*d;
            float ee=ss+d;
            float tmp=a[fl]-ss;
            for(fl;a[fl]<ee;fl++);
            cmin=min((float)cmin, tmp+ee-a[fl-1]);
        }
    }
    d-=cmin;
    r=ceil(d/2);
    cout<<r;

}