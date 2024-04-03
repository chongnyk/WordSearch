class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        function<bool(int, int, int)> backtrack = [&](int i, int j, int k){
            if(k == word.length()) return true;
            if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) return false;
            char temp = board[i][j];
            board[i][j] = '\0';
            bool result = backtrack(i + 1, j, k + 1);
            result |= backtrack(i - 1, j, k + 1);
            result |= backtrack(i, j + 1, k + 1);
            result |= backtrack(i, j - 1, k + 1);
            board[i][j] = temp;
            return result;
        };

        unordered_map<char, int> freq; //addition of freq checker improved from 639ms to 96ms
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                freq[board[i][j]]++;
        
        for(int i = 0; i < word.size(); i++)
            if(freq.find(word[i]) == freq.end()) return false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(backtrack(i, j, 0)) return true;
            }
        }

        return false;
    }
};
