#include "grid.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

namespace hashiwokakero {

Grid::Grid(int size, std::vector<Island> islands)
    : size_(size), grid_(std::move(islands)) {
    if (size_ <= 0) {
        throw std::invalid_argument("Grid size must be positive.");
    }
    initializeGrid();
}

int Grid::getSize() const {
    return size_;
}

int Grid::getVerticesCount() const {
    return static_cast<int>(grid_.size());
}

void Grid::initializeGrid() {
    for (std::size_t i = 0; i < grid_.size(); ++i) {
        const Position position = grid_[i].getPosition();
        if (position.x < 0 || position.x >= size_ ||
            position.y < 0 || position.y >= size_) {
            throw std::invalid_argument("Island position is outside the grid.");
        }
        for (std::size_t j = 0; j < i; ++j) {
            const Position other = grid_[j].getPosition();
            if (position.x == other.x && position.y == other.y) {
                throw std::invalid_argument("Two islands cannot occupy the same cell.");
            }
            if (grid_[i].getId() == grid_[j].getId()) {
                throw std::invalid_argument("Island IDs must be unique.");
            }
        }
    }
}

int Grid::getMaxConnections() const {
    int maxConnections = 0;
    for (const auto& island : grid_) {
        if (island.isEnabled()) {
            maxConnections += island.getRequiredBridges();
        }
    }
    return maxConnections / 2;
}

void Grid::printGrid() const {
    for (const auto& island : grid_) {
        std::cout << "Island ID: " << island.getId() 
                  << ", Position: (" << island.getPosition().x 
                  << ", " << island.getPosition().y << ")"
                  << ", Required Bridges: " << island.getRequiredBridges()
                  << ", Current Bridges: " << island.getCurrentBridges()
                  << std::endl;
    }
}

} // namespace hashiwokakero
