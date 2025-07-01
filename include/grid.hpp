#pragma once
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

struct Cell
{
    int r, c;
    bool isWall = false;
    bool visited = false;
    int dist = INF;
    Cell *parent = NULL;
};

class Grid
{
public:
    int rows, cols;
    vector<vector<Cell>> cells;

    Grid(int r, int c);

    void setWall(int r, int c);
    void resetState();

    void print(Cell *src, Cell *dest,  vector<Cell *> &path, function<bool( Cell &)> frontier = NULL);
};