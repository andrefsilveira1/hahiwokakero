#pragma once

#include "cell.hpp"

#include <map>
#include <iosfwd>
#include <utility>
#include <vector>

namespace new_base {

using board_t = std::vector<std::vector<cell>>;

extern int n, m, qi;
extern board_t board;
extern std::map<cell, std::vector<cell>> adj_list;
extern std::vector<std::pair<cell, cell>> edg_list;

bool are_same_line(cell c1, cell c2);
bool are_same_collum(cell c1, cell c2);
void connect_cells(cell& c1, cell& c2);
void initialize_board(std::istream& input);

} // namespace new_base
