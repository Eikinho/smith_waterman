#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>

using namespace std;

struct Cursor {
    int n;
    int m;
    vector<char> seq_one;
    vector<char> seq_two;
};

Cursor init()
{
    int m, n;
    cin >> n >> m;
    cout << "n: " << n << endl;
    cout << "m: " << m << endl;

    vector<char> seqOne;
    vector<char> seqTwo;

    for (int i=0; i < n; i++)
    {
        char base;
        cin >> base;
        seqOne.push_back(base);
    }

    for (int i=0; i < m; i++)
    {
        char base;
        cin >> base;
        seqTwo.push_back(base);
    }

    Cursor return_cursor;
    return_cursor.n = n;
    return_cursor.m = m;
    return_cursor.seq_one = seqOne;
    return_cursor.seq_two = seqTwo;

    return return_cursor;
}

int main()
{
    cout << "----SMITH--WATERMAN----" << endl;

    Cursor cursor = init();

    for (int i=0; i < cursor.n; i++)
    {
        cout << cursor.seq_one[i] << endl;
    }

    return 0;
}