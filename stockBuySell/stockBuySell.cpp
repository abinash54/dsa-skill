#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
    - first sort the array and get the minimum element (min)
    - find the index of min
    - sort the vector again for the range from the index to the end
    - get the max element
    - return the difference if not -ve, else 0
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long profit = 0;
        long minPrice = *prices.begin();
        
        for(auto i=(prices.begin()+1);i!=prices.end();++i){
            if(profit < *i - minPrice) profit = *i - minPrice;
            if(minPrice < *i) minPrice = *i;            
        }
        
        return profit;
    }
};

int main(){
    vector<int> prob = {7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(prob) << endl;
    return 0;
}