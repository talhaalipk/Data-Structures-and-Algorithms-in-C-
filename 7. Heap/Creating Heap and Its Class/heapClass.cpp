#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Heap
{
    vector<T> v;

public:
    Heap() {}

    // -- GET CHLID FUNCTIONS -- //
    // -- GET CHLID FUNCTIONS -- //

    int get_left_child_index(int ind) // ind = index
    {
        return (ind * 2) + 1;
    }

    int get_right_child_index(int ind) // ind = index
    {
        return (ind * 2) + 2;
    }

    // -- GET PARENT FUNCTION -- //
    // -- GET PARENT FUNCTION -- //

    int get_parrent_index(int ind)
    {
        // agar old node ha
        if (ind % 2 != 0)
        {
            return (ind / 2);
        }
        // agar even node ha
        else
        {
            return (ind / 2) - 1;
        }
    }

    // -- IS MAX HEAP OR NOT FUNCTION -- //
    // -- IS MAX HEAP OR NOT FUNCTION -- //

    bool isMaxHeap()
    {
        int size = v.size();

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > v[get_parrent_index(i)])
            {
                return false;
            }
        }

        return true;
    }

    // -- IS MIN HEAP OR NOT FUNCTION -- //
    // -- IS MIN HEAP OR NOT FUNCTION -- //

    bool isMinHeap()
    {
        int size = v.size();

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < v[get_parrent_index(i)])
            {
                return false;
            }
        }

        return true;
    }

    // -- HEAPIFY UP ^ FUNCTIONS -- //
    // -- HEAPIFY UP ^ FUNCTIONS -- //

    void heapifyup_forMaxHeap(int ind)
    {
        // base case
        int parent = get_parrent_index(ind);
        if (ind <= 0 || v[ind] < v[parent])
        {
            return;
        }

        swap(v[ind], v[parent]);
        heapifyup_forMaxHeap(parent);
    }

    void heapifyup_forMinHeap(int ind)
    {
        // base case
        int parent = get_parrent_index(ind);
        if (ind <= 0 || v[ind] > v[parent])
        {
            return;
        }

        swap(v[ind], v[parent]);
        heapifyup_forMinHeap(parent);
    }

    // -- INSERT IN HEAP FUNCTIONS -- //
    // -- INSERT IN HEAP FUNCTIONS -- //

    void insert_forMaxheap(T value)
    {
        v.push_back(value);

        heapifyup_forMaxHeap(v.size() - 1);
    }

    void insert_forMinheap(T value)
    {
        v.push_back(value);

        heapifyup_forMinHeap(v.size() - 1);
    }

    // -- HEAPITY DOWN  -- //
    // -- HEAPITY DOWN  -- //

    void heapifyDown_forMaxHeap(int ind)
    {
        int l_child = get_left_child_index(ind);
        int r_child = get_right_child_index(ind);

        // BASE CONDITION
        if (ind >= v.size() || (l_child >= v.size() && r_child >= v.size()))
        {
            return;
        }

        int right_ind;
        // agar bono child ha
        if (l_child < v.size() && r_child < v.size())
        {
            if (v[l_child] > v[r_child])
            {
                right_ind = l_child;
            }
            else
            {
                right_ind = r_child;
            }
        }
        // agar koi ak child ha
        else
        {
            if (l_child < v.size())
            {
                right_ind = l_child;
            }
            else
            {
                right_ind = r_child;
            }
        }

        if (v[ind] < v[right_ind])
        {
            swap(v[ind], v[right_ind]);
            heapifyDown_forMaxHeap(right_ind);
        }
    }

    void heapifyDown_forMinHeap(int ind)
    {
        int l_child = get_left_child_index(ind);
        int r_child = get_right_child_index(ind);

        // BASE CONDITION
        if (ind >= v.size() || (l_child >= v.size() && r_child >= v.size()))
        {
            return;
        }

        int right_ind;
        // agar bono child ha
        if (l_child < v.size() && r_child < v.size())
        {
            if (v[l_child] < v[r_child])
            {
                right_ind = l_child;
            }
            else
            {
                right_ind = r_child;
            }
        }
        // agar koi ak child ha
        else
        {
            if (l_child < v.size())
            {
                right_ind = l_child;
            }
            else
            {
                right_ind = r_child;
            }
        }

        if (v[ind] > v[right_ind])
        {
            swap(v[ind], v[right_ind]);
            heapifyDown_forMinHeap(right_ind);
        }
    }

    // -- DELETE FIRST -- //
    // -- DELETE FIRST -- //

    void deleteFirst_maxHeap()
    {
        if (v.size() == 0)
        {
            cout << "heap empty..." << endl;
            return;
        }

        int endIndex = v.size() - 1;
        v[0] = v[endIndex];

        v.pop_back();

        heapifyDown_forMaxHeap(0);
    }

    void deleteFirst_minHeap()
    {
        if (v.size() == 0)
        {
            cout << "heap empty..." << endl;
            return;
        }

        int endIndex = v.size() - 1;
        v[0] = v[endIndex];

        v.pop_back();

        heapifyDown_forMinHeap(0);
    }

    // -- GET MINIMUM ()  -- //
    // -- GET MINIMUM ()  -- //

    T getMaximum_maxHeap_andRemoveFirst()
    {
        T hold = v[0];

        deleteFirst_maxHeap();

        return hold;
    }

    T getMinimum_minHeap_andRemoveFirst()
    {
        T hold = v[0];

        deleteFirst_minHeap();

        return hold;
    }

    // -- Heap Sort -- //
    // -- Heap Sort -- //

    void heapsort()
    {   

        if (isMaxHeap() == 0)
        {
            cout << "not heap" << endl;
            return;
        }

        vector <int> vec1;

        int s = v.size();
        int Heap_size = v.size();
        T max;

        for (int i = 0; i < s; i++)
        {
            max = getMaximum_maxHeap_andRemoveFirst();
            vec1.push_back(max);
        }

        v = vec1 ;
    }

    // -- PRINT -- //
    // -- PRINT -- //

    void print()
    {
        int size = v.size();

        if (size == 0)
        {
            cout << "Heap Empty.. " << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << v[i] << "  ";
        }

        cout << endl;
    }
};

int main()
{
    Heap<int> h;

    h.print();

    h.insert_forMaxheap(100);
    h.insert_forMaxheap(90);
    h.insert_forMaxheap(80);
    h.insert_forMaxheap(70);
    h.insert_forMaxheap(60);
    h.insert_forMaxheap(455);
    h.insert_forMaxheap(6845);
    h.insert_forMaxheap(894);
    h.insert_forMaxheap(256);
    h.insert_forMaxheap(102);
    h.print();

    h.heapsort();
    h.print();
}