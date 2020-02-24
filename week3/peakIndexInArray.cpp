class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low=0, high=A.size()-1;
        if(high+1 < 3) return -1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(A[mid-1] < A[mid] && A[mid]> A[mid+1]) return mid;
            else if(A[mid-1] > A[mid]) high=mid;
            else if(A[mid] < A[mid+1]) low=mid;
        }
        return -1;
    }
};
