#pragma once
#include "grid.hpp"
#include <bits/stdc++.h>
using namespace std;


vector<Cell *> dijkstra(Grid &grid, Cell *src, Cell *dest, function<void(Grid &, Cell *)> onVisit = NULL);
