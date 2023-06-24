#include<bits/stdc++.h>
#include"geometry.hpp"

int main(){
    Point a(1,1);
    Point b(1,0);

    cout << dot(a, b) << endl;
    cout << cross(a, b) << endl;
    cout << cross(b, a) << endl;
    cout << a << endl;
    cout << unit(a) << endl;
    cout << normal(a) << endl;
    cout << normalUnit(a) << endl;
    cout << rotate(b, PI/4) << endl;
    cout << a * 10 << endl;
    cout << norm(a) << endl;
}