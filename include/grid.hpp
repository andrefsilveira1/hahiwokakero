#pragma once
#include <vector>
#include "island.hpp"

namespace hashiwokakero {

class Grid {
public:
    // The caller supplies the puzzle's islands; Grid owns a copy of them.
    Grid(int size, std::vector<Island> islands);

    int getSize() const;
    int getVerticesCount() const;

    int getMaxConnections() const;
    void printGrid() const;

private:
    int size_;
    std::vector<Island> grid_;

    void initializeGrid();
};

} // namespace hashiwokakero
