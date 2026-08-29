class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int>mp;
        for(int card: hand){
            mp[card]++;
        }
        for(auto&[card,frequency]:mp){
            int cnt = frequency;
            if(cnt==0)continue;
            for(int i=0;i<groupSize;i++){
                int nextCard=i+card;
                if(mp[nextCard]<cnt){
                    return false;
                }
                mp[nextCard]-=cnt;
            }
        }
        return true;
    }
};
