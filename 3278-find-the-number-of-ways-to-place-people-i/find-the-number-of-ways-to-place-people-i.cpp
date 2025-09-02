#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInside(vector<int>& A, vector<int>& B, vector<int>& P) {
        int x1 = min(A[0], B[0]), x2 = max(A[0], B[0]);
        int y1 = min(A[1], B[1]), y2 = max(A[1], B[1]);
        return (P[0] >= x1 && P[0] <= x2 && P[1] >= y1 && P[1] <= y2);
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                auto &A = points[i];
                auto &B = points[j];

                // A should be on the upper-left side of B
                if (A[0] <= B[0] && A[1] >= B[1] && !(A[0] == B[0] && A[1] == B[1])) {
                    bool ok = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        if (isInside(A, B, points[k])) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) count++;
                }
            }
        }
        return count;
    }
};
