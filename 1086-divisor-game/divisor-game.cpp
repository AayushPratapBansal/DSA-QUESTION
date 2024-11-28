


//Alice just has to choose 1 each time (n/2 can work if n/2 is odd) 
//to force Bob into the base case situation (n=2).
//it is all about making n odd for Bob
//so that no matter what move he makes, it will make n even again
//because odd only has odd factors (odd-odd = even)
//and eventually you repeat till it gets to n=2 (base case)
class Solution {
public:
    bool divisorGame(int n) {
        if (n%2 == 0){return true;}
        return false;
    }
};