#include<bits/stdc++.h>
#define ull unsigned long long
#define fi first
#define se second

using namespace std;

int main(){
    //freopen("output/contestant_out000.out","w",stdout);
    vector<pair<int,int> >a;
    for(int i=0; i<3; i++){
        int x;
        cin>>x;
        a.push_back(make_pair(x,i));
    }
    int d;
    cin>>d;
    int res[5];
    memset(res,0,sizeof(res));
    sort(a.begin(),a.end());
    for(int i=0; i<3; i++){
        if(d<=0) break;
        int id = a[i].se;
        int val = a[i].fi;
        if(d-val>=0){
            d-=val;
            res[id]=val;
        } else{
            res[id] = d;
            d=0;
        }
    }
    for(int i=0; i<3; i++){
        cout << res[i] << " ";
    }
    return 0;
}
