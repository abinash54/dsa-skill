#include<bits/stdc++.h>
using namespace std;

/*
    function(A[]){
        output = []
        for i from 0 to A.len:
            if(i==0 || (i > 0 and (A[i]!=A[i-1]))):
                start = i+1
                end = A.len()-1
                target = 0 - A[i]
                while(start < end):
                    if(target = A[start] + A[end]):
                        output.push(A[i], A[start], A[end])
                        while(start < end && A[start] == A[start+1])
                            ++start;
                        while(start < end && A[end] == A[end-1])
                            --end;
                    else if(target < A[start] + A[end]):
                        --end;
                    else:
                        ++start 
                    
        return output[];
    }
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector <int>> solution;
        for(auto i=nums.begin();i!=nums.end()-2;i++){
            if(i==nums.begin() || (i>nums.begin() && (*i != *(i+1)))){
                auto start = i+1;
                auto end = nums.end();
                int target = 0 - *i;
                while(start < end){
                    if(target = *start + *end){
                        vector<int> temp = {*i, *start, *end};
                        solution.push_back(temp);
                        while(start < end && *start == *(start+1))  ++start;
                        while(start < end && *end == *(end-1))  --end;
                    }else if(target < *start + *end)
                        --end;
                    else ++start;
                } 
            }
        }
        return solution;
    }
};

void displayVector(vector<vector<int>>& vec){
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<endl;
}

int main(){
    vector<int> prob = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> sol = s.threeSum(prob);
    cout<<"solution: "<<endl;
    displayVector(sol);
}