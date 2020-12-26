#include <iostream>
#include <ctime>
#include <stdexcept>

using namespace std;

class ChArr
{
    char* Ch;
    size_t S;
public:
    ChArr(size_t size)
    {
        if (size == 0)
            throw out_of_range("Size is incorrect\n");
        Ch = new char[size];
        S = size;

        srand(time(NULL));
        for (int i = 0;i < S;i++)
        {
            Ch[i] = rand() % S;
            Ch[i] *= pow(-1, rand() % 2);
        }
    }

    bool sorted()
    {
        for (int i = 0;i < (S - 1);i++)
        {
            if (Ch[i] > Ch[i + 1])
                return false;
        }
        return true;
    }
    void CountingSort()
    {
        int i;
        int max = Ch[0];
        int min = Ch[0];
        int* PArr = nullptr;
        int* MArr = nullptr;
        for (i = 1;i < S;i++)
        {
            if (Ch[i] > max)
                max = Ch[i];
            else if (Ch[i] < min)
                min = Ch[i];
        }
        if (max >= 0)
        {
            PArr = new int[max + 1];
            for (i = 0;i <= max;i++)
                PArr[i] = 0;
        }
        if (min < 0)
        {
            MArr = new int[min * (-1) + 1];
            for (i = 0;i <= (min * (-1));i++)
                MArr[i] = 0;
        }
        for (i = 0;i < S;i++)
        {
            if (Ch[i] < 0)
                MArr[Ch[i] * (-1)]++;
            else
                PArr[Ch[i]]++;
        }
        int j = 0;
        if (min < 0)
        {
            for (i = (min * (-1));i > 0;i--)
            {
                while (MArr[i] != 0)
                {
                    Ch[j] = i * (-1);
                    j++;
                    MArr[i]--;
                }
            }
            delete[] MArr;
        }
        if (max >= 0)
        {
            for (i = 0;i <= max;i++)
            {
                while (PArr[i] != 0)
                {
                    Ch[j] = i;
                    j++;
                    PArr[i]--;
                }
            }
            delete[] PArr;
        }
    }
    void print_to_console()
    {
        for (int i = 0;i < S;i++)
        {
            cout << Ch[i] << ' ';
        }
        cout << endl;
    }

    ~ChArr()
    {
        delete[] Ch;
    }
};

class IntArr
{
    int* Int;
    size_t S;

    void QSort(int first, int last)
    {
        int pivot = last;
        int temp, i, j;
        for (i = first; i < pivot;i++)
        {
            if (Int[i] > Int[pivot])
            {
                for (j = i;j < pivot;j++)
                {
                    temp = Int[j];
                    Int[j] = Int[j + 1];
                    Int[j + 1] = temp;
                }
                pivot--;
                i--;
            }
        }
        if (first < (pivot - 1))
            QSort(first, pivot - 1);
        if ((pivot + 1) < last)
            QSort(pivot + 1, last);
    }
    int BSearch(int left, int right, int elem)
    {
        if (left > right)
            return -1;
        size_t mid = ((right - left) / 2) + left;
        size_t ans;
        if (Int[mid] == elem)
            ans = mid;
        else if (Int[mid] < elem)
            ans = BSearch(mid + 1, right, elem);
        else
            ans = BSearch(left, mid - 1, elem);
        return ans;
    }

public:
    IntArr(size_t size)
    {
        if (size == 0)
            throw out_of_range("Size is incorrect\n");
        Int = new int[size];
        S = size;
        
        srand(time(NULL));
        for (int i = 0;i < S;i++)
        {
            Int[i] = rand() % S;
            Int[i] *= pow(-1, rand() % 2);
        }
    }
    int getelem(size_t index)
    {
        if (index >= S)
            throw out_of_range("index must be less than size of array\n");
        return Int[index];
    }
    bool sorted()
    {
        for (int i = 0;i < (S - 1);i++)
        {
            if (Int[i] > Int[i + 1])
                return false;
        }
        return true;
    }
    size_t BiniarySearch(int search)
    {
        if (!sorted())
            throw runtime_error("Array must be sorted\n");
        if (search<Int[0] || search>Int[S - 1])
            throw runtime_error("There is no element\n");
        int index = BSearch(0, S - 1, search);
        if (index < 0)
            throw runtime_error("There is no element\n");
        return index;
    }
    void QuickSort()
    {
        QSort(0, S - 1);
    }
    void InsertionSort()
    {
        int key;
        for (int i = 0;i < S - 1;i++)
        {
            key = Int[i + 1];
            for (int j = i;j >= 0;j--)
            {
                if (key < Int[j])
                {
                    Int[j + 1] = Int[j];
                    Int[j] = key;
                }
                else
                {
                    break;
                }
            }
        }
    }
    void BogoSort()
    {
        int temp;
        int index;
        for (int i = 0;i < S;i++)
        {
            temp = Int[i];
            srand(time(NULL));
            index = rand() % S;
            Int[i] = Int[index];
            Int[index] = temp;
        }
        if (!sorted())
        {
            BogoSort();
        }
    }
    void print_to_console()
    {
        for (int i = 0;i < S;i++)
        {
            cout << Int[i] << ' ';
        }
        cout << endl;
    }

    ~IntArr()
    {
        delete[] Int;
    }
};

int main()
{
  //  IntArr Arr(5);
  //  Arr.print_to_console();
  //  Arr.InsertionSort();
  //  Arr.print_to_console();

    IntArr* Arr = nullptr;
    long double start, end, res;
    long double mid1, mid2;
    for (int i = 10;i <= 100000;i *= 10)
    {
        cout << "Size of data: " << i << endl;
        mid1 = 0;
        mid2 = 0;
        for (int j = 1;j <= 10;j++)
        {
            cout << "Sort " << j << ": ";

            Arr = new IntArr(i);
            start = clock();
            Arr->QuickSort();
            end = clock();
            delete Arr;
            res = end - start;
            mid1 += res;
            cout << "QSort: " << res / CLOCKS_PER_SEC << " sec. ";

            Arr = new IntArr(i);
            start = clock();
            Arr->InsertionSort();
            end = clock();
            delete Arr;
            res = end - start;
            mid2 += res;
            cout << "ISort: " << res / CLOCKS_PER_SEC << " sec.\n";
        }
        mid1 /= 10;
        mid2 /= 10;
        cout << "Middle time: QSort: " << mid1 / CLOCKS_PER_SEC << " ISort: " << mid2 / CLOCKS_PER_SEC << endl << endl;
    }

}