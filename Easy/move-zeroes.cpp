#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// attempt #2: no vector
// runtime: 16ms (61.61%)
// memory: 9.3 MB (100%)
// time complexity: O(n)
// space complexity: O(1)
void moveZeroes(vector<int>& nums)
{
  int zero_index = 0;
  for(int i=0; i<nums.size(); i++)
  {
    if(nums[i]!=0)
    {
      swap(nums[i],nums[zero_index]);
      zero_index++; // want 1st 0 for in-place
    }
  }
}
/*
// run time: 12 ms (96.98%)
//memory: 9.6MB (63.89%)
void moveZeroes(vector<int>& nums)
{
  int zero_index = 0;
  for(int i=0; i<nums.size(); i++)
  {
    if(nums[i]!=0)
    {
      int temp = nums[i];
      nums[i] = 0;
      nums[zero_index] = temp;
      zero_index++; // want 1st 0 for in-place
    }
  }
}
*/

// attempt #1: used another vector
// runtime: 12 ms (96.98%)
// space: 9.5 MB (81.94%)
// time complexity: O(n)
// space complexity: O(n)
void moveZeroes_vec(vector<int>& nums) {
  // set contains indices of 0s
  // set count determines how many zeroes
  int count  = 0;
  vector<int> o;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]==0)
        {
          count++;
        }
        else
        {
          o.push_back(nums[i]);
        }
    }
    // don't need to move if all are 0s
    // or none are 0s
    if(count>0 && count<=nums.size())
    {
      // so loop only as many as 0s
      // instead of every element
      int i = 0;
      int j = o.size();
      int k = nums.size();
      // copy over non 0s
      while(i<j)
      {
          nums[i] = o[i];
          i++;
      }
      // copy over 0s
      while(i<k)
      {
          nums[i] = 0;
          i++;
      }
    }
}

int main()
{
  vector<int> a{0,1,0,3,12};
  cout<<"before: ";
  for(auto e:a)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  cout<<"after: ";
  moveZeroes(a);
  for(auto e:a)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  vector<int> b{0,0,0,3,12};
  cout<<"before: ";
  for(auto e:b)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  cout<<"after: ";
  moveZeroes(b);
  for(auto e:b)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  vector<int> c{2,3,0,0,12};
  cout<<"before: ";
  for(auto e:c)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  cout<<"after: ";
  moveZeroes(c);
  for(auto e:c)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  return 0;
}
