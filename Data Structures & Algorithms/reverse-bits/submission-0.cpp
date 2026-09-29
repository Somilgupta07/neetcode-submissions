class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;

        for(int i=0;i<32;i++){
            int bit=n&1; //get the last bit
            ans=ans<<1;  //make space for next bit
            ans=ans|bit; //put bit into ans
            n=n>>1;      //remove the last bit
        }
        return ans;
    }
};
