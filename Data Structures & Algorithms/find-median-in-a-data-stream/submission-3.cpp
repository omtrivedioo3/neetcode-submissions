class MedianFinder {
   public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<>> mini;
    MedianFinder() {}

    void addNum(int num) {
        maxi.push(num);

        // Step 2: Ensure max of maxi <= min of mini
        mini.push(maxi.top());
        maxi.pop();

        // Step 3: Maintain size property (maxi can have at most 1 more element than mini)
        if (mini.size() > maxi.size()) {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        if (!mini.empty() and mini.size() == maxi.size()) {
            return (mini.top() + maxi.top()) / 2.0;
        }
        return maxi.top();
    }
};
