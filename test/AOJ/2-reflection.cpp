#include<bits/stdc++.h>
#include"geometry.hpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);
    Point a,b;
    cin >> a >> b;
    Line l(a,b);
    int q;
    cin >> q;
    while (q--) {
        Point p;
        cin >> p;
        cout << p + (projection(l, p) - p) * 2 << endl;
    }
}