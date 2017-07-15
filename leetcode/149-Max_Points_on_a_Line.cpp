/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int size = points.size();
		if (size < 2) {
			return size;
		}

		int result = 0;
		for(int i = 0; i < size; ++i) {
			map<pair<int,int>, int> mappingList;
			int lineMax = 0, samePoint = 0;

			for (int j = i + 1; j < size; ++j) {
				int dX, dY, gcdValue;

				if (points[i].x == points[j].x && points[i].y == points[j].y) {
					samePoint++;
					continue;
				} else if (points[i].x == points[j].x) {
					dX = 0;
					dY = 1;
				} else if (points[i].y == points[j].y) {
					dX = 1;
					dY = 0;
				} else {
					dX = points[i].x - points[j].x;
					dY = points[i].y - points[j].y;
					gcdValue = gcd(dX, dY);
					dX /= gcdValue;
					dY /= gcdValue;
				}
				lineMax = max(++mappingList[make_pair(dX, dY)], lineMax);
				// cout << i << ":" << j << " " << r << " " << lineMax << endl;
			}

			result = max(lineMax+samePoint+1, result);
		}
		return result;
	}

	int gcd(int x, int y) {
		if (y == 0) {
			return x;
		} else {
			return gcd(y, x%y);
		}
	}
};