class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(ratings.size(),1);

        // left pass
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }

        // right pass
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        int total=0;
        for(int candie: candies){
            total+=candie;
        }
        return total;
    }
};