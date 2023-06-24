#include<bits/stdc++.h>
#include"geometry.hpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);
    Point a,b;
    cin >> a >> b;
    int q;
    cin >> q;
    while (q--) {
        Point p;
        cin >> p;
        int t = ccw(a, b, p);
        if(t == -2) cout << "ONLINE_BACK" << endl;
        if(t == -1) cout << "CLOCKWISE" << endl;
        if(t == 0) cout << "ON_SEGMENT" << endl;
        if(t == 1) cout << "COUNTER_CLOCKWISE" << endl;
        if(t == 2) cout << "ONLINE_FRONT" << endl;
    }
}