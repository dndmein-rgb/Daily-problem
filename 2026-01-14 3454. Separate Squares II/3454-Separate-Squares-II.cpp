/* Pattern: Sweep Line + Segment Tree (Area of Union of Rectangles)
   Time Complexity: O(N log N) - Due to sorting and segment tree updates
   Space Complexity: O(N) - For storing events and segment tree nodes
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

struct Event {
    double y;
    int type; // +1 for square start (bottom), -1 for square end (top)
    double x1, x2;
    bool operator<(const Event& other) const {
        if (y != other.y) return y < other.y;
        return type > other.type; // Process additions before subtractions
    }
};

class SegmentTree {
    int n;
    vector<double>& coords;
    vector<int> count;
    vector<double> length;

public:
    SegmentTree(vector<double>& x_coords) : coords(x_coords) {
        n = coords.size();
        count.assign(4 * n, 0);
        length.assign(4 * n, 0.0);
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l >= end || r <= start) return;
        if (l <= start && end <= r) {
            count[node] += val;
        } else {
            int mid = (start + end) / 2;
            update(2 * node, start, mid, l, r, val);
            update(2 * node + 1, mid, end, l, r, val);
        }

        // Logic to maintain the union length of active x-intervals
        if (count[node] > 0) {
            length[node] = coords[end] - coords[start];
        } else if (end - start > 1) {
            length[node] = length[2 * node] + length[2 * node + 1];
        } else {
            length[node] = 0;
        }
    }

    double get_length() { return length[1]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<double> x_coords;
        vector<Event> events;
        
        for (auto& s : squares) {
            double x = s[0], y = s[1], l = s[2];
            x_coords.push_back(x);
            x_coords.push_back(x + l);
            events.push_back({y, 1, (double)x, (double)x + l});
            events.push_back({y + l, -1, (double)x, (double)x + l});
        }

        // Coordinate Compression for X
        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
        sort(events.begin(), events.end());

        // Pass 1: Calculate Total Union Area
        SegmentTree st(x_coords);
        double total_area = 0;
        
        for (int i = 0; i < (int)events.size() - 1; ++i) {
            int l = lower_bound(x_coords.begin(), x_coords.end(), events[i].x1) - x_coords.begin();
            int r = lower_bound(x_coords.begin(), x_coords.end(), events[i].x2) - x_coords.begin();
            st.update(1, 0, x_coords.size() - 1, l, r, events[i].type);
            
            double h = events[i+1].y - events[i].y;
            total_area += st.get_length() * h;
        }

        double target = total_area / 2.0;
        
        // Pass 2: Sweep again to find the y-coordinate that splits the area exactly
        SegmentTree st2(x_coords);
        double current_area = 0;
        
        for (int i = 0; i < (int)events.size() - 1; ++i) {
            int l = lower_bound(x_coords.begin(), x_coords.end(), events[i].x1) - x_coords.begin();
            int r = lower_bound(x_coords.begin(), x_coords.end(), events[i].x2) - x_coords.begin();
            st2.update(1, 0, x_coords.size() - 1, l, r, events[i].type);
            
            double width = st2.get_length();
            double h = events[i+1].y - events[i].y;
            
            if (current_area + width * h >= target - 1e-9) {
                double needed = target - current_area;
                return events[i].y + (needed / width);
            }
            current_area += width * h;
        }

        return events.back().y;
    }
};
