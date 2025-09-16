#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// brute force 

class Solution {
public:
    // Check if we can make at least m bouquets on given day
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++; // this flower has bloomed
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0; // break in adjacent flowers
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long totalRequired = 1LL * m * k;
        if (totalRequired > n) return -1;

        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        for (int day = minDay; day <= maxDay; day++) {
            if (canMake(bloomDay, m, k, day)) {
                return day;
            }
        }

        return -1;
    }
};

// optimal approach 
// tc = O(N * log(max bloom day))
// sc = O(1)
class Solution {
public:

    bool canMakeBouquets(vector <int> & bloomDay ,int m , int k , int day){
        int bouquets = 0 ;
        int flowers = 0 ;

        for (int bloom : bloomDay){
            if (bloom <= day){
                flowers++;

                if (flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            }else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long totalRequired = 1LL * m * k;
        if (totalRequired > bloomDay.size()) return -1;

        int left = *min_element(bloomDay.begin() , bloomDay.end());
        int right = *max_element(bloomDay.begin() , bloomDay.end());
        int answer = -1;

        while (left <= right ){
            int mid = left + (right - left)/2;

            if (canMakeBouquets(bloomDay , m , k , mid)){
                answer = mid ;
                right = mid - 1;
            }else {
                left = mid +1 ;

            }
        }
        return answer ;
        
    }
};
