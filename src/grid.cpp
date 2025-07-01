#include "grid.hpp"
#include "utils.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

Grid::Grid(int r, int c) : rows(r), cols(c)
{
    cells.resize(r);
    for (int i = 0; i < r; ++i)
    {
        cells[i].resize(c);
        for (int j = 0; j < c; ++j)
        {
            cells[i][j].r = i;
            cells[i][j].c = j;
        }
    }
}

void Grid::setWall(int r, int c)
{
    if (r >= 0 && r < rows && c >= 0 && c < cols)
    {
        cells[r][c].isWall = true;
    }
}

void Grid::resetState()
{
    for (auto &row : cells)
    {
        for (auto &cell : row)
        {
            cell.visited = false;
            cell.dist = INT_MAX;
            cell.parent = nullptr;
        }
    }
}

void Grid::print(Cell *src, Cell *dest, vector<Cell *> &path, function<bool(Cell &)> frontier)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            Cell &c = cells[i][j];
            if (&c == src)
            {
                cout << "S ";
            }
            else if (&c == dest)
            {
                cout << "D ";
            }
            else if (c.isWall)
            {
                cout << "# ";
            }
            else if (find(path.begin(), path.end(), &c) != path.end())
            {

                cout << "* ";
            }
            else if (frontier && frontier(c))
            {
                cout << "· ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << '\n';
    }
}
