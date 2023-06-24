#include<bits/stdc++.h>
#include"geometry.hpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);

    int q;
    cin >> q;

    while(q--){
        Point a,b,c,d;
        cin >> a >> b >> c >> d;
        Segment s(a,b),t(c,d);

        cout << crossPoint(s,t) << endl;
    }
}