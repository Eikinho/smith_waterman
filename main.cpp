#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>

#define MATCH 2
#define MISMATCH -1
#define GAP -1

using namespace std;

struct Sequency {
    int id;
    int size;
    vector<char> sequency;
};

struct SmithWaterman {
    int score;
    vector<vector<int>> matrix;
};

struct Cursor {
    Sequency one;
    Sequency two;
    SmithWaterman smith_waterman;
};

Cursor init()
{
    cout << "---------SMITH--WATERMAN---------" << endl;
    cout << "-------by--eiki--yamashiro-------" << endl;
    cout << endl;
    cout << "Match: " << MATCH << " | " << "Mismatch: " << MISMATCH << " | " "Gap: " << GAP << endl;
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

void cout_sequency_init(Sequency sequency)
{
    cout << "Sequency " << sequency.id << ": "; 

    for (int i=0; i <= sequency.size; i++)
    {
        cout << sequency.sequency[i];
    }

    cout << endl;
}

void cout_sequency(Sequency sequency)
{

    for (int i=0; i <= sequency.size; i++)
    {
        cout << sequency.sequency[i] << " ";
    }

    cout << endl;
}

vector<vector<int>> create_matrix(Sequency seqOne, Sequency seqTwo)
{
    vector<vector<int>> matrix;
    matrix.resize(seqOne.size + 1);

    for (int i=0; i <= seqOne.size; i++)
    {
        matrix[i].resize(seqTwo.size + 1);
    }


    for (int i=0; i <= seqOne.size; i++)
    {
        for (int j=0; j < seqTwo.size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void cout_matrix(Cursor cursor)
{
    cout << "S ";
    cout_sequency(cursor.two);

    for (int i=0; i <= cursor.one.size; i++)
    {
        cout << cursor.one.sequency[i] << " ";
        for (int j=0; j <= cursor.two.size; j++)
        {
            cout << cursor.smith_waterman.matrix[i][j] << " ";
        }
        
        cout << endl;
        
        
    }
}

int mini_score(Cursor cursor, int i, int j)
{
    if (cursor.one.sequency[i] == cursor.two.sequency[j])
    {
        return MATCH;
    }
    
    else if (cursor.one.sequency[i] != cursor.two.sequency[j])
    {
        return MISMATCH;
    } 
    else if (cursor.one.sequency[i] == '-')
    {
        return GAP;
    }
    else if (cursor.two.sequency[j] == '-')
    {
        return GAP;
    }
    return 0;
}

vector<vector<int>> smith_waterman(Cursor cursor)
{
    int diagonal = 0;
    int deletion = 0;
    int insertion = 0;
    int temp_max = 0;

    for (int i = 1; i <= cursor.one.size; i++)
    {
        for (int j = 1; j <= cursor.two.size; j++)
        {
            diagonal = cursor.smith_waterman.matrix[i-1][j-1] + mini_score(cursor, i,  j);
            deletion = cursor.smith_waterman.matrix[i-1][j] - 1;
            insertion = cursor.smith_waterman.matrix[i][j-1] - 1;
            temp_max = max(deletion, max(diagonal, insertion));
            if (temp_max < 0)
             {
                 temp_max = 0;
             }
             cursor.smith_waterman.matrix[i][j] = temp_max;
        }
    }
    
    return cursor.smith_waterman.matrix;
}

int score(Cursor cursor)
{
    int max = 0;
    for (int i=0; i <= cursor.one.size; i++)
    {
        for (int j=0; j <= cursor.two.size; j++)
        {   
            if (cursor.smith_waterman.matrix[i][j] > max)
            {
                max = cursor.smith_waterman.matrix[i][j];
            }
        }
    }
    return max;
}

int main()
{
    // reading .txt file that contains the both sequencies. Create the cursor. 
    Cursor cursor = init();
    
    cursor.smith_waterman.matrix = create_matrix(cursor.one, cursor.two);
    cout_sequency_init(cursor.one);
    cout_sequency_init(cursor.two);
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << endl;

    cout << "Matrix Output:" << endl;
    cout << endl;

    cursor.smith_waterman.matrix = smith_waterman(cursor);
    cout_matrix(cursor);
    
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << endl;

    cursor.smith_waterman.score = score(cursor);

    cout << "Score: " << cursor.smith_waterman.score << endl;
    return 0;
} 