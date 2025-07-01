#include <iostream>
#include <vector>
#include <random>
#include "grid.hpp"
#include "dijkstra.hpp"
#include "utils.hpp"

using namespace std;

int main()
{
        const int rows = 15;
        const int cols = 30;
        Grid grid(rows, cols);

        int startRow, startCol, endRow, endCol;

        cout << "Enter source (row col): ";
        cin >> startRow >> startCol;

        cout << "Enter destination (row col): ";
        cin >> endRow >> endCol;

        Cell *source = &grid.cells[startRow][startCol];
        Cell *destination = &grid.cells[endRow][endCol];

        int minRow = min(startRow, endRow);
        int maxRow = max(startRow, endRow);
        int minCol = min(startCol, endCol);
        int maxCol = max(startCol, endCol);

        int rectArea = (maxRow - minRow + 1) * (maxCol - minCol + 1);
        int wallCount = rectArea * 0.2;

        mt19937 gen(random_device{}());
        uniform_int_distribution<> randRow(minRow, maxRow);
        uniform_int_distribution<> randCol(minCol, maxCol);

        int placedWalls = 0;
        while (placedWalls < wallCount)
        {
                int r = randRow(gen);
                int c = randCol(gen);

                if ((r == startRow && c == startCol) || (r == endRow && c == endCol))
                        continue;

                if (!grid.cells[r][c].isWall)
                {
                        grid.setWall(r, c);
                        placedWalls++;
                }
        }

        vector<Cell *> path;

        auto showVisitedStep = [&](Grid &g, Cell *current)
        {
                g.print(source, destination, path, [](const Cell &cell)
                        { return cell.visited; });
                delay(50);
        };

        path = dijkstra(grid, source, destination, showVisitedStep);

        cout << "\nFinal Path:";
        for (Cell *cell : path)
        {
                cout << " (" << cell->r << "," << cell->c << ")";
        }
        cout << "\n\n";

        grid.print(source, destination, path);

        return 0;
}
