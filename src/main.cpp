#include <iostream>
#include <utility>
#include <vector>
#include "grid.hpp"

constexpr bool DEBUG = false;

int main() {
    using namespace hashiwokakero;
    
    // Coordinates are zero-based: a 5x5 board spans x,y = 0..4.
    std::vector<Island> islands;
    islands.emplace_back(0, Position{0, 1}, 2);
    islands.emplace_back(1, Position{3, 1}, 2);
    
    Grid grid(5, std::move(islands));

    if (DEBUG) {
        grid.printGridInfo();
    } else {
        grid.printGrid();
    }
}
