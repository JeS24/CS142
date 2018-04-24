/**
 * WORKS - Check "mainForBH.cpp"
 */

#ifndef BHeapArr_h
#define BHeapArr_h
#endif

class BHeapArr {
    public:
        long SIZE, hArr[1000];

        BHeapArr(): SIZE(0) {}

        long parent(long i);
        long lChild(long i);
        long rChild(long i);
        void insert(long val);
        void delRoot();
        void heapify(long arr[], long i, long size);
        void disp();
};

// Utility function
void swap(long* i, long* j) {
    long temp = *i;
    *i = *j;
    *j = temp;
}
