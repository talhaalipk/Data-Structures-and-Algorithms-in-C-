#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct MinHeapNode
{
    int element;
    int i;
};

void swap(MinHeapNode *x, MinHeapNode *y);

class MinHeap
{
    MinHeapNode *harr;
    int heap_size;

public:
    MinHeap(MinHeapNode a[], int size);
    void MinHeapify(int);
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    MinHeapNode getMin()
    {
        return harr[0];
    }
    void replaceMin(MinHeapNode x)
    {
        harr[0] = x;
        MinHeapify(0);
    }
};

MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

ifstream openFileRead(const string &fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cerr << "Error while opening the file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    return file;
}

ofstream openFileWrite(const string &fileName)
{
    ofstream file(fileName);
    if (!file.is_open())
    {
        cerr << "Error while opening the file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    return file;
}

void mergeData(const string &opFile, int n, int k)
{
    vector<ifstream> in;
    for (int i = 0; i < k; i++)
    {
        string fileName = to_string(i);
        in.push_back(openFileRead(fileName));
    }
    ofstream out = openFileWrite(opFile);
    MinHeapNode *harr = new MinHeapNode[k];
    int i;
    for (i = 0; i < k; i++)
    {
        if (!(in[i] >> harr[i].element))
            break;
        harr[i].i = i;
    }
    MinHeap hp(harr, i);
    int count = 0;
    while (count != i)
    {
        MinHeapNode root = hp.getMin();
        out << root.element << ' ';
        if (!(in[root.i] >> root.element))
        {
            root.element = INT_MAX;
            count++;
        }
        hp.replaceMin(root);
    }
    for (int i = 0; i < k; i++)
        in[i].close();
    out.close();
}

void initialiseData(const string &ipFile, int memory, int num_ways)
{
    ifstream in = openFileRead(ipFile);
    vector<ofstream> out;
    for (int i = 0; i < num_ways; i++)
    {
        string fileName = to_string(i);
        out.push_back(openFileWrite(fileName));
    }
    vector<int> arr(memory);
    bool more_input = true;
    int next_opFile = 0;
    int i;
    while (more_input)
    {
        for (i = 0; i < memory; i++)
        {
            if (!(in >> arr[i]))
            {
                more_input = false;
                break;
            }
        }
        mergeSort(arr.data(), 0, i - 1);
        for (int j = 0; j < i; j++)
            out[next_opFile] << arr[j] << ' ';
        next_opFile++;
    }
    for (int i = 0; i < num_ways; i++)
        out[i].close();
    in.close();
}

void externalSort(const string &ipFile, const string &opFile, int num_ways, int memory)
{
    initialiseData(ipFile, memory, num_ways);
    mergeData(opFile, memory, num_ways);
}

void intro()
{
    system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t{}{}     {}     {}{}  {}{}{}{}{}  {}{}        {}{}{}{}{} {}{}{}{}{}  {}{}{}{}{}{}{}{}{}  {}{}{}{}{}" << endl;
    cout << "\t{}{}     {}     {}{}  {}{}{}{}{}  {}{}        {}{}{}{}{} {}{}{}{}{}  {}{}{}{}{}{}{}{}{}  {}{}{}{}{}" << endl;
    cout << "\t{}{}     {}     {}{}  {}{}        {}{}        {}{}       {}      {}  {}{}    {}    {}{}  {}{}      " << endl;
    cout << "\t{}{}     {}     {}{}  {}{}        {}{}        {}{}       {}      {}  {}{}    {}    {}{}  {}{}      " << endl;
    cout << "\t{}{}     {}     {}{}  {}{}{}{}{}  {}{}        {}{}       {}      {}  {}{}    {}    {}{}  {}{}{}{}{}" << endl;
    cout << "\t{}{}     {}     {}{}  {}{}        {}{}        {}{}       {}      {}  {}{}    {}    {}{}  {}{}      " << endl;
    cout << "\t{}{}     {}     {}{}  {}{}        {}{}        {}{}       {}      {}  {}{}    {}    {}{}  {}{}      " << endl;
    cout << "\t{}{}{}{}{}{}{}{}{}{}  {}{}{}{}{}  {}{}{}{}{}  {}{}{}{}{} {}{}{}{}{}  {}{}          {}{}  {}{}{}{}{}" << endl;
    cout << "\t{}{}{}{}{}{}{}{}{}{}  {}{}{}{}{}  {}{}{}{}{}  {}{}{}{}{} {}{}{}{}{}  {}{}          {}{}  {}{}{}{}{}" << endl;
    _sleep(1000);
    system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t{}{}{}{}{}{}{}{}{}{}{}     {}{}{}{}{}" << endl;
    cout << "\t\t\t\t\t{}{}{}{}{}{}{}{}{}{}{}     {}{}{}{}{}" << endl;
    cout << "\t\t\t\t\t        {}{}               {}      {}" << endl;
    cout << "\t\t\t\t\t        {}{}               {}      {}" << endl;
    cout << "\t\t\t\t\t        {}{}               {}      {}" << endl;
    cout << "\t\t\t\t\t        {}{}               {}      {}" << endl;
    cout << "\t\t\t\t\t        {}{}               {}      {}" << endl;
    cout << "\t\t\t\t\t        {}{}               {}{}{}{}{}" << endl;
    cout << "\t\t\t\t\t        {}{}               {}{}{}{}{}" << endl;
    _sleep(500);
    system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t ######                         #####                      " << endl;
    cout << "\t\t\t\t\t #     # #  ####  #    #       #     #  ####  #####  ##### " << endl;
    cout << "\t\t\t\t\t #     # # #      #   #        #       #    # #    #   #  " << endl;
    cout << "\t\t\t\t\t #     # #  ####  ####          #####  #    # #    #   #   " << endl;
    cout << "\t\t\t\t\t #     # #      # #  #               # #    # #####    #  " << endl;
    cout << "\t\t\t\t\t #     # # #    # #   #        #     # #    # #   #    #   " << endl;
    cout << "\t\t\t\t\t ######  #  ####  #    #        #####   ####  #    #   #   " << endl;
    _sleep(1500);
    system("cls");
}

void complete()
{
    system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t ######     #             #           #####                                    " << endl;
    cout << "\t\t\t\t\t #     #   # #   #####   # #         #     #  ####  #####  ##### ###### #####  " << endl;
    cout << "\t\t\t\t\t #     #  #   #    #    #   #        #       #    # #    #   #   #      #    # " << endl;
    cout << "\t\t\t\t\t #     # #     #   #   #     #        #####  #    # #    #   #   #####  #    # " << endl;
    cout << "\t\t\t\t\t #     # #######   #   #######             # #    # #####    #   #      #    # " << endl;
    cout << "\t\t\t\t\t #     # #     #   #   #     #       #     # #    # #   #    #   #      #    # " << endl;
    cout << "\t\t\t\t\t ######  #     #   #   #     #        #####   ####  #    #   #   ###### #####  " << endl;
    _sleep(1500);
    system("cls");
}

int main()
{
    // Call ing intro
    intro();

    string ipFile;
    string opFile;

    cout << "Please Enter the Name of Input File (want to sort - like input.txt) : ";
    cin >> ipFile;

    cout << endl
         << endl
         << endl
         << endl;

    cout << "Please Enter the Name of Output File (sorted file - like output.txt) : ";
    cin >> opFile;

    cout << endl
         << endl
         << endl
         << endl;

    int ram;
    int data_size;

    cout << "Enter the size of date in " << ipFile << " File {1 for INT (4byte)}  : ";
    cin >> data_size;

    cout << endl
         << endl
         << endl
         << endl;

    cout << "Enter the size of Ram you want to Use {1 for INT (4byte)} ";
    cin >> ram;

    cout << endl
         << endl
         << endl
         << endl;

    int no_oF_Files = data_size / ram + 1;

    _sleep(10);
    system("cls");

    cout << "Processing ." << endl;
    cout << "Processing .." << endl;
    cout << "Processing ..." << endl;
    cout << "Processing ...." << endl;
    cout << "Processing ....." << endl;
    _sleep(1000);

    externalSort(ipFile, opFile, no_oF_Files, ram);
    complete();

    cout << endl
         << endl
         << endl
         << endl;

    cout << "GO And Get SOrted Data in " << opFile << " File. " << endl;
    return 0;
}