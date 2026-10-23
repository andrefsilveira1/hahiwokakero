#pragma once

#include "cell.hpp"

#include <utility>
#include <vector>

namespace new_base {

using board_t = std::vector<std::vector<cell>>;

class Board {
public:
    explicit Board(const std::vector<std::vector<int>>& values);

    int rows() const;
    int columns() const;
    int island_count() const;

    cell& at(int row, int column);
    const cell& at(int row, int column) const;
    const std::vector<std::pair<cell, cell>>& edges() const;

    void connect_cells(cell& first, cell& second);

private:
    board_t cells_;
    int island_count_ = 0;
    std::vector<std::pair<cell, cell>> edges_;

    void initialize();
};

bool are_same_line(cell first, cell second);
bool are_same_collum(cell first, cell second);

} // namespace new_base
