class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return std::max(maxChar(answerKey, k, 'T'), maxChar(answerKey, k, 'F'));
    }   

private:
     int maxChar(string answerKey, int k, char target){
        int len = answerKey.size();

        int left = 0, right = 0, max_len = 0, flip_num = 0;
    
        while(right < len){
            // If rigth ok, then right++
            if(answerKey[right] != target){
                flip_num++;
            }


            // if flip_num is so large
            while(flip_num > k){
                if(answerKey[left] != target){
                    flip_num--;
                }
                left++;
            }
            

            max_len = std::max(max_len, right - left + 1);     
            right++;       
        }
        
        return max_len;
        
     }
};