
class MedianFinder {
    multiset<int> mst;
    multiset<int>::iterator it;
public:
    MedianFinder() {
        it = mst.end();
    }
    
    void addNum(int num) {
        mst.insert(num);
        if(it == mst.end()) {
            it = mst.begin();
        } else if(num >= *it and mst.size() % 2 == 1) {
            it++;
        } else if(num < *it and mst.size() % 2 == 0) {
            it--;
        }
    }
    
    double findMedian() {
        if(mst.size() % 2 == 1)
            return *it;
        return ((double)*(++it) + *(--it)) / 2;
    }
};
