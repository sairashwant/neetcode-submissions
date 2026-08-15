class MedianFinder {
public:
    vector<int> nums;
    int size;
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        nums.push_back(num);
        size++;
        sort(nums.begin(), nums.end());
    }
    
    double findMedian() {

        if(size == 0)
            return 0;
        if(size%2 == 0)
            {
                int mid1 = (size/2)-1;
                int mid2 = (size/2);
                double median = ((double)nums[mid1]+(double)nums[mid2])/2;
                return median;
            }
        if(size%2 != 0)
            {
                int mid2 = (size/2);
                double median = nums[mid2];
                return median;
            }
        

        return 0;
    }
};
