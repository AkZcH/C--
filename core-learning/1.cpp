#include<iostream>
#include<vector>
using namespace std;

int floorSqrt(int n)  {
      int low = 0;
      int high = n;
      int ans = 0;

      while(low<=high){
        int mid = low + (high - low)/2;
        
        if(mid <= n/mid){
            low = mid + 1;
            ans = mid;
        }
        else{
          high = mid - 1;
        }
      }
      return ans;
    }

int main(){
    int n = 520;
    cout<<floorSqrt(n);
    return 0;
}
