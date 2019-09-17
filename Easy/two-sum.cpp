#include <iostream>
#include <vector>
#include <map>

using namespace std;

// #1: brute force
vector<int> twoSum_brute(vector<int>& nums, int target) {
    vector<int> result;
    for(int i=0; i<nums.size()-1; i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i]+nums[j]==target)
            {
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }
    return result;
}

// #2: two pass map
vector<int> twoSum_map(vector<int>& nums, int target) {
    map<int, int> m;
    // populating map
    for(int i=0; i<nums.size(); i++)
    {
        m.insert(pair<int, int>(nums[i], i));
    }
    for(int i=0; i<nums.size(); i++)
    {
        // compute complement
        int complement = target - nums[i];
        // first part checks if complement exists
        // second part checks if numbers are distinct
        // so, cannot do [0, 0]
        if(m.find(complement)!=m.end() && m[complement]!=i)
        {
            // cut down on space complexity
            // remember vector
            return vector<int>{i, m[complement]};
        }
    }
    throw domain_error("no such pair found!");
}

// #3 : one pass (hash) map
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    // while inserting elements in map, look back
    // check if complement exists
    // if it does, return right away
    for(int i=0; i<nums.size(); i++)
    {
        int complement = target - nums[i];
        // no need to check if distinct, will always be!
        if(m.find(complement)!=m.end())
        {
            return vector<int>{m[complement], i}; // looking back so, flip order
        }
        m.insert(pair<int, int>(nums[i], i));
    }
    throw domain_error("no such pair found!");
}

int main(){
  vector<int> v{2, 7, 11, 15};
  vector<int> ans = twoSum(v, 9);
  cout<<"[ "<<ans[0]<<", "<<ans[1]<<" ]"<<endl;
}
