#include<bits/stdc++.h>
#include"geometry.hpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(10);

    int n;
    cin >> n;

    vector<Point> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    bool convex = 1;
    for(int i = 0; i < n; i++) {
        if(cross(p[(i+1)%n]-p[i], p[(i+2)%n] - p[(i+1)%n]) < -EPS){
            convex = 0;
        }
    }
    cout << convex << endl;
}