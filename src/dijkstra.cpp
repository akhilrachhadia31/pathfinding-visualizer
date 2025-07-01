#include "dijkstra.hpp"
#include <queue>
using namespace std;

struct Compare
{
    bool operator()(const Cell *a, const Cell *b) const
    {
        return a->dist > b->dist;
    }
};

vector<Cell *> dijkstra(Grid &grid, Cell *src, Cell *dest, function<void(Grid &, Cell *)> onVisit)
{
    grid.resetState();
    src->dist = 0;

    priority_queue<Cell *, vector<Cell *>, Compare> pq;
    pq.push(src);

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!pq.empty())
    {
        Cell *u = pq.top();
        pq.pop();
        if (u->visited)
        {
            continue;
        }
        u->visited = true;

        if (onVisit)
        {
            onVisit(grid, u);
        }
        if (u == dest)
        {
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nr = u->r + dr[i], nc = u->c + dc[i];
            if (nr < 0 || nc < 0 || nr >= grid.rows || nc >= grid.cols)
            {
                continue;
            }
            Cell *v = &grid.cells[nr][nc];
            if (v->isWall || v->visited)
                continue;

            int weight = 1;
            if (u->dist + weight < v->dist)
            {
                v->dist = u->dist + weight;
                v->parent = u;
                pq.push(v);
            }
        }
    }

    vector<Cell *> path;
    for (Cell *cur = dest; cur; cur = cur->parent)
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    if (!path.empty() && path[0] == src)
    {
        return path;
    }
    else
    {
        return {};
    }
}
