#include <iostream>
#include <vector>

using namespace std;
//better
// o(n*logm)
// sc = o(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
};

// optimal
// tc = o(log(n*m))
// sc = o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
           int low = 0 ;
           int high = n*m - 1 ;
           

            while (low <= high){
                
                int mid = low + (high-low)/2;

                int row = mid/m;
           int col = mid%m;
                if (matrix[row][col]== target) return true;
                if (matrix[row][col] < target) low = mid + 1 ;
                if (matrix[row][col] > target) high = mid - 1 ;
            }
            return false;
            
        
        
        
    }
};