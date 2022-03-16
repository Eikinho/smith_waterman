#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>

using namespace std;

struct Sequency {
    int id;
    int size;
    vector<char> sequency;
};

struct Cursor {
    Sequency one;
    Sequency two;
    vector<vector<int>> matrix;
};

Cursor init()
{
    cout << "----SMITH--WATERMAN----" << endl;
    cout << "--by--eiki--yamashiro--" << endl;
    cout << endl;

    int m, n;
    cin >> n >> m;

    vector<char> seqOne;
    vector<char> seqTwo;
    seqOne.push_back(' ');
    seqTwo.push_back(' ');

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
    Sequency _one;
    Sequency _two;
    _one.id = 1;
    _one.size = n;
    _one.sequency = seqOne;
    _two.id = 2;
    _two.size = m;
    _two.sequency = seqTwo;
    return_cursor.one = _one;
    return_cursor.two = _two;

    return return_cursor;
}

void cout_sequency(Sequency sequency)
{
    cout << "Sequency " << sequency.id << ": "; 

    for (int i=0; i < sequency.size; i++)
    {
        cout << sequency.sequency[i];
    }

    cout << endl;
}

vector<vector<int>> create_matrix(Sequency seqOne, Sequency seqTwo)
{
    vector<vector<int>> matrix;
    matrix.resize(seqOne.size);

    for (int i=0; i < seqOne.size; i++)
    {
        matrix[i].resize(seqTwo.size);
    }


    for (int i=0; i < seqOne.size; i++)
    {
        for (int j=0; j < seqTwo.size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void cout_matrix(vector<vector<int>> matrix, int i_, int j_)
{
    for (int i=0; i < i_; i++)
    {
        for (int j=0; j < j_; j++)
        {
            matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    // reading .txt file that contains the both sequencies. Create the cursor. 
    Cursor cursor = init();
    
    cursor.matrix = create_matrix(cursor.one, cursor.two);



    cout_sequency(cursor.one);
    cout_sequency(cursor.two);
    cout_matrix(cursor.matrix, cursor.one.size, cursor.two.size);
    

    return 0;
}