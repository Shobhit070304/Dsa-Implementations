#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<int> heap;

public:
    MaxHeap(vector<int> &v)
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
        if (idx > 0 && heap[idx] > heap[parent])
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
        int largest = idx;

        if (left < heap.size() && heap[largest] < heap[left])
        {
            largest = left;
        }

        if (right < heap.size() && heap[largest] < heap[right])
        {
            largest = right;
        }

        if (largest != idx)
        {
            swap(heap[largest], heap[idx]);
            heapify(largest);
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
    // MaxHeap h;
    // h.insertInHeap(50);
    // h.insertInHeap(40);
    // h.insertInHeap(30);
    // h.insertInHeap(20);
    // h.insertInHeap(10);

    // cout << "Heap before deletion: ";
    // h.printHeap(); // 50 40 30 20 10

    // h.deleteRoot();

    // cout << "Heap after deletion: ";
    // h.printHeap(); // 40 20 30 10

    vector<int> v = {4, 7, 1, 3, 8, 5};
    MaxHeap h(v);

    h.printHeap(); // 8 7 5 4 3 1
    return 0;
}