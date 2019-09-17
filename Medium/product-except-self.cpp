#include <iostream>
#include <vector>

using namespace std;
// problem: "Product of Array Except Self"
// solve w/o divisiomn & in O(n)
/*
input: [ 1 2 3 4 ]
output: [ 24 12 8 6]
--
in attempt #1:
left = [ 1 1 2 6 ]
right = [ 24 12 4 1 ]

*/

// Attempt #2: Constant Space Complexity
// How could you solve this in constant space complexity?
// I had the right idea to have variables to keep track
// those variables help me remove the additional vectors
// treat left as initial ans
// update ans as you figure right

// runtime: 40 ms --> faster than 81.74% submissions
// memory: 12.8 MB --> less than 39.39% submissions
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;

// constructing left array
    // left of 1st element is nothing
    // multiplying by 1 does nothing
    int l = 1;
    for(int i=0; i<nums.size(); i++)
    {
        ans.push_back(l);
        l *= nums[i]; // reset
    }

// constructing right array
  // right of last element is nothing
  // so start out with one
    int r = 1;
    for(int j=nums.size()-1; j>=0; j--)
    {
        ans[j] *= r;
        r *= nums[j]; // reset
    }
    return ans;
}



// Attempt #1: left & right lists
// runtime: 40ms --> faster than 81.74%
// memory: 14MB --> less than 6.06%
// time complexity: O(n) --> actually 3n
// space complexity: O(n) --> 3 vectors
vector<int> productExceptSelf_lists(vector<int>& nums) {
    vector<int> ans;
    vector<int> left, right;

// constructing left array
    // left of 1st element is nothing
    // multiplying by 1 does nothing
    int l = 1;
    for(int i=0; i<nums.size(); i++)
    {
        left.push_back(l);
        l *= nums[i]; // reset
    }

// constructing right array
    int r = 1;
    for(int j=nums.size()-1; j>=0; j--)
    {
        right.push_back(r);
        r *= nums[j]; // reset
    }
    reverse(right.begin(), right.end());

    for(int i=0; i<nums.size(); i++)
    {
      ans.push_back(left[i]*right[i]);
    }

    return ans;
}

int main()
{
  vector<int> a{1,2,3,4};
  vector<int> prod = productExceptSelf(a);
  for(auto e: prod)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  return 0;
}
