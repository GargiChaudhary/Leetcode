"""
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int guess(int num), which returns three possible results:
-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.  
"""
  
class Solution {
public:
    int guessNumber(int n) {
        int s = 1, e = n;
        while(s<=e){
            int m = s + (e-s)/2;
            if(guess(m) == 0){
                return m;
            }
            else if(guess(m) == 1){
                s = m+1;
            }else if(guess(m) == -1){
                e = m-1;
            }
        }
        return 0;
    }
};
