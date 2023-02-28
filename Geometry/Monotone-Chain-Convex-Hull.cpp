#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// note that this point implementation behaves like a pair<int, int> which is recommended if speed and/or memory is in question
struct Point {

    int x, y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator<(Point b) {
        if (x < b.x) {
            return true;
        }
        return y < b.y;
    }
};

int cross(const Point o, const Point a, const Point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<Point> convexHull(vector<Point> points) {
    sort(points.begin(), points.end());
    vector<Point> u, l;
    for (int i = 0; i < points.size(); i++) {
        while (l.size() >= 2 && cross(l[l.size() - 2], l[l.size() - 1], points[i]) <= 0) {
            l.pop_back();
        }
        l.push_back(points[i]);
    }
    for (int i = points.size() - 1; i >= 0; i--) {
        while (u.size() >= 2 && cross(u[u.size() - 2], u[u.size() - 1], points[i]) <= 0) {
            u.pop_back();
        }
        u.push_back(points[i]);
    }
    l.pop_back();
    u.pop_back();
    l.insert(l.begin(), u.begin(), u.end());
    return l;
}

int main() {
    vector<Point> points;
    points.push_back(Point(1, 1));
    points.push_back(Point(1, 4));
    points.push_back(Point(4, 1));
    points.push_back(Point(2, 2));
    vector<Point> hull = convexHull(points);
    for (Point p : hull) {
        printf("%d %d\n", p.x, p.y);
    }
    return 0;
}
