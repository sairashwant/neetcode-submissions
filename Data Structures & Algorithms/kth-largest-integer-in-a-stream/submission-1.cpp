class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kVal;

    KthLargest(int k, vector<int>& nums) {

        kVal = k;

        for(auto num : nums)
        {
            minHeap.push(num);
            
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if(minHeap.size() > kVal)
            minHeap.pop();

        return minHeap.top();
    }
};
