class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordFind(wordList.begin(), wordList.end());
        if (wordFind.find(endWord) == wordFind.end()) {
            return 0;
        }
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        while (!q.empty()) {
            auto word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord){
                return steps;
            }
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i]=ch;
                    if (wordFind.find(word) != wordFind.end() &&
                        visited.find(word) == visited.end()) {
                        visited.insert(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
