#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int partition (vector<int>& arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 // The main function that implements QuickSort
 // arr[] --> Array to be sorted,
 //  low  --> Starting index,
 //  high  --> Ending index
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now
        //    at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void moveZeroes(vector<int>& nums) {
  // set contains indices of 0s
  // set count determines how many zeroes
  set<int> s;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]==0)
        {
          s.insert(i);
        }
    }

    for(set<int>::iterator it = s.begin(); it!=s.end(); it++)
    {
      cout<<(*it)<<" ";
    }
    cout<<endl;
    // don't need to move if all are 0s
    // or none are 0s
    if(s.size()>0 && s.size()<=nums.size())
    {
      // so loop only as many as 0s
      // instead of every element
      int j = nums.size()-1;
      for(set<int>::iterator it = s.begin(); it!=s.end(); it++)
      {
        int temp = nums[j];
        nums[j] = 0;
        nums[(*it)] = temp;
        j--;
      }
      // j is now index to sort till
      quickSort(nums, 0, j);
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
  return 0;
}
