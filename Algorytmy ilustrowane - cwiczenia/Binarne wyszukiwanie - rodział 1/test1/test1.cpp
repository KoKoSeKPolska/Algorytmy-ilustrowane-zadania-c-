#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

//wyszukiwanie binarne
int binary(vector<int>tab, int x)
{

    int low = 0;
    int high = tab.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int guess = tab[mid];
        if (guess == x)
        {
            return mid;
        }
        if(guess > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
// wyszukiwanie prsote / liniowe
int basic(vector<int>tab, int x)
{
    for (int i = 0; i < tab.size(); i++)
    {
        if (tab[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int x = 4543;
    vector <int> tab = { 1,2,};
    sort(tab.begin(), tab.end());
    cout << binary(tab, x) << endl;



// czas wykonania algorytmu
    int repeats = 100000;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < repeats; i++)
    {
        binary(tab, x);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    double seconds = duration.count() / 1000000000.0;

    cout << "Czas wykonania: " << seconds << " ns" << endl;

}
