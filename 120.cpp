#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        for (int i = 1; i < size; ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < i - 1; ++j) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        return *min_element(triangle[size - 1].begin(), triangle[size - 1].end());
    }
};