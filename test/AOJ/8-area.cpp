#include<bits/stdc++.h>
#include"geometry.hpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(1);

    int n;
    cin >> n;

    vector<Point> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    cout << area(p) << endl;
}