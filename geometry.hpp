#include<complex>
#include<vector>
#include<iostream>
using namespace std;

using Real = double;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

// 多分いらない入出力
istream &operator>>(istream &is, Point& p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}
ostream &operator<<(ostream &os, Point p) {
  return os << fixed << p.real() << " " << p.imag();
}
//////////////////

Point operator*(Point p, Real d) {
  return Point(real(p) * d, imag(p) * d);
}

inline bool equal(Real a, Real b){
    return fabs(a - b) < EPS;
}

Point unit(Point a) {
    return a / abs(a);
}

Point normal(Point a) {
    return a * Point(0, 1);
}

Point normalUnit(Point a) {
    return unit(normal(a));
}

Real dot(Point a, Point b){
    return a.real() * b.real() + a.imag() * b.imag(); 
}

Real cross(Point a, Point b){
    return (a.real() * b.imag() - a.imag() * b.real());
}

Point rotate(Point a, double theta){
    return Point(cos(theta) * a.real() - sin(theta) * a.imag(),
                 sin(theta) * a.real() + cos(theta) * a.imag());
}

Real radianToDegree(Real r) {
    return r * 180 / PI;
}

Real degreeToRadian(Real d) {
    return d * PI / 180;
}

Real getAngle(Point a, Point b, Point c){
    const Point ab(b - a), bc(c - b);
    Real s = atan2(ab.imag(), ab.real()), t = atan2(bc.imag(), bc.real());
    if(s > t) swap(s,t);
    Real theta = t - s;
    return min(theta, 2 * PI - theta);
}

struct Line{
    Point a,b;

    Line() = default;

    Line(Point A, Point B) : a(A), b(B) {}

    // ax + by = c
    Line(Real A, Real B, Real C){
        if(equal(A, 0)) a = Point(0, C / B), b = Point(1, C / B);
        else if(equal(B, 0)) b = Point(C / A, 0), b = Point(C / A, 1);
        else a = Point(0, C / B), b = Point(C / A, 0);
    }

    friend ostream &operator<<(ostream &os, Line &p) {
        return os << p.a << " to " << p.b;
    }

    friend istream &operator>>(istream &is, Line &a) {
        return is >> a.a >> a.b;
    }
};

using Segment = Line;

struct Circle{
    Point p;
    Real r;

    Circle() = default;

    Circle(Point p, Real r) : p(p), r(r) {}
};

// 点pから線lに垂線を下ろした時の交点
Point projection(Line l, Point p){
    Real t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + (l.b - l.a) * t;
}

int ccw(Point a, Point b, Point c){
    b -= a;
    c -= a;
    // 反時計回り
    if(cross(b, c) > EPS) return 1;
    // 時計回り
    if(cross(b, c) < -EPS) return -1;
    // c-a-bの順番で点がある
    if(dot(b, c) < 0) return -2;
    // a-b-cの順番で点がある
    if(norm(b) < norm(c)) return 2;
    // a-b の間にcがある
    return 0;
}

bool isParallel(Line a, Line b){
    return equal(cross(a.b - a.a, b.b - b.a), 0);
}

bool isOrthogonal(Line a, Line b){
    return equal(dot(a.b - a.a, b.b - b.a), 0);
}

bool IsIntersect(Segment s, Segment t){
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Point crossPoint(Line s, Line t){
    Real d1 = cross(s.b - s.a, t.b - t.a);
    Real d2 = cross(s.b - s.a, s.b - t.a);
    if(equal(d1, 0) && equal(d2, 0)){
        if( ccw(t.a, t.b, s.a) == 0) return s.a;
        if( ccw(t.a, t.b, s.b) == 0) return s.b;
        if( ccw(s.a, s.b, t.a) == 0) return t.a;
        if( ccw(s.a, s.b, t.b) == 0) return t.b;
    }

    return t.a + (t.b - t.a) * (d2 / d1);
}

Real distance(Segment l, Point p){
    if(dot(l.b - l.a, p - l.a) < EPS) return abs(p - l.a);
    if(dot(l.a - l.b, p - l.b) < EPS) return abs(p - l.b);
    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}

Real distance(Segment s, Segment t){
    if(IsIntersect(s,t)) return 0;
    Real res = distance(s,t.a);
    res = min(res, distance(s, t.b));
    res = min(res, distance(t, s.a));
    res = min(res, distance(t, s.b));
    return res;
}

Real area(vector<Point>& p){
    Real res = 0;
    int n = p.size();
    for(int i = 0; i < n - 1; i++){
        res += cross(p[i], p[i+1]);
    }
    res += cross(p[n-1],p[0]);

    return res * 0.5;
}

bool isConvex(vector<Point>& p){
    bool res = true;
    int n = p.size();
    for(int i = 0; i < n; i++) {
        if(cross(p[(i+1)%n]-p[i], p[(i+2)%n] - p[(i+1)%n]) < -EPS){
            res = false;
        }
    }
    return res;
}