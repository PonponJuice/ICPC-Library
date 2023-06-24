#include<bits/stdc++.h>
#include"geometry.hpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);

    int q;
    cin >> q;

    while(q--){
        Point a,b,c,d;
        cin >> a >> b >> c >> d;
        Line s(a,b),t(c,d);

        if(isParallel(s,t)){
            cout << 2 << endl;
        }
        else if(isOrthogonal(s,t)){
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}