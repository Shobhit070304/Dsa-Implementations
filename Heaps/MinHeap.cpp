#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> heap;

public:
    MinHeap(vector<int> &v)
    {
        heap = v;
        int n = heap.size();
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void heapifyUp(int idx)
    {
        int parent = (idx - 1) / 2;
        if (idx > 0 && heap[idx] < heap[parent])
        {
            swap(heap[idx], heap[parent]);
            heapifyUp(parent);
        }
        return;
    }

    void heapify(int idx)
    {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < heap.size() && heap[smallest] > heap[left])
        {
            smallest = left;
        }

        if (right < heap.size() && heap[smallest] > heap[right])
        {
            smallest = right;
        }

        if (smallest != idx)
        {
            swap(heap[smallest], heap[idx]);
            heapify(smallest);
        }
        return;
    }

    void insertInHeap(int x)
    {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return;
    }

    void printHeap()
    {
        cout << "The heap is: ";
        for (auto i : heap)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    // MinHeap h;
    // h.insertInHeap(50);
    // h.insertInHeap(40);
    // h.insertInHeap(30);
    // h.insertInHeap(20);
    // h.insertInHeap(10);
    // h.printHeap(); // 10 20 30 40 50
    // h.deleteRoot();
    // h.printHeap(); // 20 30 40 50

    vector<int> v = {4, 7, 1, 3, 8, 5};
    MinHeap h(v);

    h.printHeap(); // 1 3 4 7 8 5
    return 0;
}