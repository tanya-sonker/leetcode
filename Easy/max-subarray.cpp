#include <iostream>
#include <vector>

using namespace std;


int maxSubArray(vector<int>& nums) {
   int max_so_far = nums[0];
   int curr_max = nums[0];

   for (int i = 1; i < nums.size(); i++)
   {
        curr_max = max(nums[i], curr_max+nums[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

// attempt #1: not accepted b/c runtime error
// works tho
// had the right idea but maybe didn't have to split around max
int maxSubArray_try(vector<int>& nums) {
  int max_index = 0; // index of max in array
  int max = nums[0]; // local max
  int max_number = nums[0]; // max in array
  for(int i=1; i<nums.size(); i++)
  {
      if(nums[i]>max)
      {
        max = nums[i];
        max_number = nums[i];
        max_index = i;
      }
  }

  // reset
  max = nums[max_index-1];

  // largest sum between elements other than max
  int max_return = nums[max_index-1];

  for(int i=max_index-2; i>=0; i--)
  {
      max += nums[i];
      if(max>max_return)
      {
        max_return = max;
      }
  }

  // reset
  max = nums[max_index+1];
  for(int i=max_index+2; i<nums.size(); i++)
  {
      max +=  nums[i];
      if(max>max_return)
      {
        max_return = max;
      }
  }
  return max_number+max_return;
}

int main()
{
  vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int b = maxSubArray(a);
  cout<<b<<endl;
  return 0;
}
