#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // log(n) solution
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return *(nums.begin());
        long largest = INT_MIN;
        long sum = 0;
        for(auto i=nums.begin();i!=nums.end();++i){
            sum += *i;
            if(sum > largest) largest = sum;
            if(sum < 0) sum = 0;
        }
        return largest;
    }
};

int main(){
    Solution s;
    vector<int> numArray = {-2,-1};
    cout << s.maxSubArray(numArray) << endl;
}