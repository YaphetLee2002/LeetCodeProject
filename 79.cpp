#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool dfs(int x, int y, int i, vector<vector<char>>& board, string word, int stat) {
        bool ans = false;
        if (board[x][y] != word[i]) {
            return false;
        }
        else {
            if (i + 1 == word.size())
                return true;
            if (x < board.size() - 1 && stat != 2) {
                board[x][y] = 0;
                ans = dfs(x + 1, y, i + 1, board, word, 1);
                board[x][y] = word[i];
            }
            if (x > 0 & stat != 1) {
                board[x][y] = 0;
                ans = ans || dfs(x - 1, y, i + 1, board, word, 2);
                board[x][y] = word[i];
            }
            if (y < board[0].size() - 1 && stat != 4) {
                board[x][y] = 0;
                ans = ans || dfs(x, y + 1, i + 1, board, word, 3);
                board[x][y] = word[i];
            }
            if (y > 0 && stat != 3) {
                board[x][y] = 0;
                ans = ans || dfs(x, y - 1, i + 1, board, word, 4);
                board[x][y] = word[i];
            }

        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        size_t m = board.size();
        size_t n = board[0].size();
        vector<pair<int, int>> begin;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    begin.emplace_back(make_pair(i, j));
                }
            }
        }
        for (auto [i, j] : begin) {
            if (dfs(i, j, 0, board, word, 0)) {
                return true;
            }
        }
        return false;
    }
};