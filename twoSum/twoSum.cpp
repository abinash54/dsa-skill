#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> solution;
        for(auto i=nums.begin(); i!=nums.end();++i){
            int complement = target - *i;
            if(numMap.find(complement) != numMap.end()){
                solution.push_back(numMap[complement]);
                solution.push_back((i - nums.begin()));
                return solution;
            }
            numMap[*i] = i - nums.begin();
        }
        return solution;
    }
};

void displayVector(vector<int>& nums){
    for(auto i=nums.begin(); i!=nums.end();++i){
        cout<<*i<<"\t";
    }
    cout<<endl;
}

int main(){
    Solution s;
    // vector<int> problem = {3, 11, 7, 9, 5, 17, 4, 4, 9};
    vector<int> problem = {3,3};
    problem = s.twoSum(problem, 6);
    displayVector(problem);
    return 0;
}