#include <iostream>

using namespace std;

template <typename T, typename Cmp=less<T>> struct Heap {

    T* data; size_t size;
    Heap(size_t N = 63) { data = new T[N+1], size = 0; }

    void heap_down(size_t parent) 
    {
        size_t lchild = 2*parent, rchild = lchild+1,
            smallest_node = parent;

        if (lchild <= size &&  Cmp()(data[lchild], data[smallest_node])) 
            smallest_node = lchild;

        if (rchild <= size &&  Cmp()(data[rchild], data[smallest_node])) 
            smallest_node = rchild;

        if (smallest_node != parent) {
            swap(data[smallest_node], data[parent]);
            heap_down(smallest_node);
        }
    }

    T pop()
    {
        swap(data[1], data[size--]);
        heap_down(1);
        return data[size+1];
    }

    void push(const T& val) 
    {
        data[++size] = val;

        int pos = size;
        while (pos > 1 && Cmp()(data[pos], data[pos/2]) ) 
            swap(data[pos/2], data[pos]), pos /= 2;
    }

};



int main()
{
    int N; long long val;
    cin >> N;

    Heap<long long> heap(N);
    for (int i=1; i<=N; ++i) cin >> val, heap.push(val);

    long long ans = 0, min1, min2, cost;
    while (heap.size >= 2)
    {
        min1 = heap.pop(); min2 = heap.pop();
        cost = min1 + min2; ans += cost;
        heap.push(cost);
    }
    
    cout << ans;

    return 0;
}
