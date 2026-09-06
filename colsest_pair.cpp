#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double closestPair(vector<Point>& p, int left, int right) {
    
    if (right - left <= 3) {
        double ans = DBL_MAX;

        for (int i = left; i <= right; i++) {
            for (int j = i + 1; j <= right; j++) {
                ans = min(ans, dist(p[i], p[j]));
            }
        }

        return ans;
    }

    int mid = left + (right - left) / 2;
    double midX = p[mid].x;

    
    double dLeft = closestPair(p, left, mid);

    
    double dRight = closestPair(p, mid + 1, right);

    double d = min(dLeft, dRight);

    
    vector<Point> strip;

    for (int i = left; i <= right; i++) {
        if (abs(p[i].x - midX) < d) {
            strip.push_back(p[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1;
             j < strip.size() && strip[j].y - strip[i].y < d;
             j++) {

            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

int main() {
    vector<Point> points = {
        {2, 3},
        {12, 30},
        {40, 50},
        {5, 1},
        {12, 10},
        {3, 4}
    };

    sort(points.begin(), points.end(), compareX);

    double ans = closestPair(points, 0, points.size() - 1);

    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}
