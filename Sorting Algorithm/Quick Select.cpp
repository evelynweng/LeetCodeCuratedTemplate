#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

/* 
find the "kth largest" number in an array
result of this will have nums[i] > num[nth] on the left side
|---------kth-----------------|
<--left--->|<-------right----->
quicksort(nums, k , 0, nums.size() - 1);
*/

void quicksort(vector<int>& nums, int k, int l, int r){
    if( l >= r ) return;
    int pivot = l; // choose left most as piviot
    int sortidx = pivot;
    
    // partition:
    for(int i = l; i <= r; i++){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[++sortidx]);
        }
    }
    swap(nums[pivot], nums[sortidx]);
    int nth = sortidx + 1;
    if(nth > k) return quicksort(nums, k, l ,sortidx - 1); // if current number too small, sort left part
    if(nth < k) return quicksort(nums, k, sortidx + 1 , r); // if current number too large, sort right part
}