#include <iostream>

using namespace std;

int main()
{
    long long n, sum, hlaf_sum, current_sum, i;

    cin >> n;

    sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0 || n == 1 || n == 2)
    {
        cout << "No" << endl;
        return 0;
    }

    hlaf_sum = sum / 2;
    bool* used = new bool[n + 1]();

    current_sum = 0;
    for (i = n; i >= 1; i--)
    {
        if (current_sum + i <= hlaf_sum)
        {
            current_sum += i;
            used[i] = true;

            if (current_sum == hlaf_sum)
                break;
        }
    }

    if (current_sum != hlaf_sum)
    {
        cout << "No" << endl;
        delete[] used;
        return 0;
    }

    cout << "Yes" << endl;
    int countPetya = 0;
    for (i = 1; i <= n; i++)
    {
        if (used[i])
            countPetya++;
    }

    cout << countPetya << endl;
    for (i = 1; i <= n; i++)
    {
        if (used[i])
            cout << i << " ";
    }

    cout << endl;

    cout << n - countPetya << endl;
    for (i = 1; i <= n; i++)
    {
        if (!used[i])
            cout << i << " ";
    }

    cout << endl;

    delete[] used;
    return 0;
}