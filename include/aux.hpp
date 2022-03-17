/*===========================================================
# Author:       Eiki Yamashiro
# Github:       github.com/Eikinho/smith_waterman
# FileName:     aux.hpp
# Email:        eikisantos@outlook.com
# Version:      0.0.1
===========================================================*/

#ifndef __AUX_HPP_
#define __AUX_HPP_

// INCLUDES
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// DEFINES
#define MATCH 2
#define MISMATCH -1
#define GAP -1

// STRUCTS
struct Sequency
{
    int id;
    int size;
    vector<char> sequency;
};

struct SmithWaterman
{
    int score;
    vector<vector<int>> matrix;
};

struct Cursor
{
    Sequency one;
    Sequency two;
    SmithWaterman smith_waterman;
};

// PROTOTYPES
Cursor init();
void cout_sequency_init(Sequency sequency);
void cout_sequency(Sequency sequency);
vector<vector<int>> create_matrix(Sequency seqOne, Sequency seqTwo);
void cout_matrix(Cursor cursor);
int mini_score(Cursor cursor, int i, int j);
vector<vector<int>> smith_waterman(Cursor cursor);
int score(Cursor cursor);

#endif