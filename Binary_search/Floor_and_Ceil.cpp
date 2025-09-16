#include <iostream>
#include <vector>

using namespace std ;
// tc =  
class Solution{
public:
    int floor(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0 , high = n-1;
        int ans = -1;
        while (low<=high){
            int mid = (low + high) /2;
            if (nums[mid]<=x){
                ans=nums[mid];
                low = mid+1;
            }else {
                high = mid - 1;
            }
        }
        return ans;
        
    }
};

class Solution{
public:
    int ceil(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0 , high = n-1;
        int ans = -1 ;
        while (low<=high){
            int mid = (low + high) /2;
            if (nums[mid]>=x){
                ans=nums[mid];
                high = mid-1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
        
    }
};




//stl

#include <iostream>
#include <vector>
#include <algorithm>  // for lower_bound, upper_bound
using namespace std;

int main() {
    vector<int> nums = {2, 4, 6, 8, 10};
    int x;
    cout << "Enter x: ";
    cin >> x;

    // Lower Bound
    auto lb = lower_bound(nums.begin(), nums.end(), x);
    if (lb != nums.end())
        cout << "Lower Bound (>= " << x << ") = " << *lb << endl;
    else
        cout << "No Lower Bound exists\n";

    // Upper Bound
    auto ub = upper_bound(nums.begin(), nums.end(), x);
    if (ub != nums.end())
        cout << "Upper Bound (> " << x << ") = " << *ub << endl;
    else
        cout << "No Upper Bound exists\n";

    // Ceil = Lower Bound
    if (lb != nums.end())
        cout << "Ceil = " << *lb << endl;
    else
        cout << "No Ceil exists\n";

    // Floor = (Upper Bound - 1)
    if (ub != nums.begin()) {
        ub--;
        cout << "Floor = " << *ub << endl;
    } else
        cout << "No Floor exists\n";

    // Search Insert Position = Lower Bound index
    cout << "Insert Position = " << (lb - nums.begin()) << endl;

    return 0;
}
// all have the time complexity is o(log n)
// sc= o(1)