#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

double getDistance(double x1, double y1, double x2, double y2){
  double xdif = x1 - x2;
  double ydif = y1 - y2;
  return sqrt(xdif * xdif + ydif * ydif);
}
int main() {

  ifstream pointSet("points.txt");

  typedef pair<double, double> Point;

  double x, y;
  set<Point> s;
  vector<Point> v;
  while (pointSet >> x >> y) {
    v.push_back(Point(x, y));
  }

  sort(v.begin(), v.end());

  double d = 2;
  int i = 0, j = 0;
  for (int j = 0; j < v.size(); j++){

    s.insert(Point(v[j].second, v[j].first));// maybe swap order with next while

    set<Point>::iterator it;
    it = s.find(Point(v[j].second, v[j].first));
    it++;

    while (it != s.end() && (it->first - v[j].second < d)){
      if (getDistance(v[j].first, v[j].second, it->second, it->first) < d){
        d = getDistance(v[j].first, v[j].second, it->second, it->first);
      }
      it++;
    }
    it = s.find(Point(v[j].second, v[j].first));
    it--;
    while (it != s.begin() && (v[j].second - it->first < d)) {
      if (getDistance(v[j].first, v[j].second, it->second, it->first) < d){
        d = getDistance(v[j].first, v[j].second, it->second, it->first);
      }
      it--;
    }
    while (v[j].first - v[i].first > d){
      i++;
      s.erase(Point(v[i-1]));
    }
  }

  cout << d << endl;
  return 0;
}
