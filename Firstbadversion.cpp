// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int left = 1;
        long int right = n;
        long int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(isBadVersion(mid))
                right = mid-1;
            else 
                left = mid+1;
            if(isBadVersion(mid) && !(isBadVersion(mid-1)))
                return mid;
        }
        return 1;
    }
};
