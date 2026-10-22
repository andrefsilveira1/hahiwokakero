#include "board.hpp"

#include <algorithm>
#include <iostream>

namespace new_base {

int n, m, qi;
board_t board;
std::map<cell, std::vector<cell>> adj_list;
std::vector<std::pair<cell, cell>> edg_list;

bool are_same_line(cell c1, cell c2) {
    return c1.cd.x == c2.cd.x;
}

bool are_same_collum(cell c1, cell c2) {
    return c1.cd.y == c2.cd.y;
}

void connect_cells(cell& c1, cell& c2) {
    if (!((are_same_line(c1, c2) || are_same_collum(c1, c2)) &&
          c1.check_adj(&c2) && c2.check_adj(&c1))) {
        return;
    }

    // adj_list[c1].push_back(c2);
    // adj_list[c2].push_back(c1);
    edg_list.push_back({c1, c2});

    c1.decrease_val();
    c2.decrease_val();
    bool full = false;
    if (are_same_line(c1, c2)) {
        int min_y = std::min(c1.cd.y, c2.cd.y);
        int max_y = std::max(c1.cd.y, c2.cd.y);
        int my_x = c1.cd.x;
        for (int j = min_y + 1; j <= max_y - 1; j++) {
            full = board[my_x][j].add_line(HORIZONTAL);
        }
        if (board[my_x][min_y].rgt_value > 0) board[my_x][min_y].rgt_value--;
        if (board[my_x][max_y].lft_value > 0) board[my_x][max_y].lft_value--;
        if (full) {
            if (c1.cd.y < c2.cd.y) {
                c1.rgt = nullptr;
                c2.lft = nullptr;
            } else {
                c2.rgt = nullptr;
                c1.lft = nullptr;
            }
        }
    } else {
        int min_x = std::min(c1.cd.x, c2.cd.x);
        int max_x = std::max(c1.cd.x, c2.cd.x);
        int my_y = c1.cd.y;
        for (int i = min_x + 1; i <= max_x - 1; i++) {
            full = board[i][my_y].add_line(VERTICAL);
        }
        if (board[min_x][my_y].bot_value > 0) board[min_x][my_y].bot_value--;
        if (board[max_x][my_y].top_value > 0) board[max_x][my_y].top_value--;
        if (full) {
            if (c1.cd.x < c2.cd.x) {
                c1.bot = nullptr;
                c2.top = nullptr;
            } else {
                c2.bot = nullptr;
                c1.top = nullptr;
            }
        }
    }
}

void initialize_board(std::istream& input) {
    std::vector<cell*> last_island_r(n, nullptr), last_island_c(m, nullptr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cell& c = board[i][j];
            input >> c.val;
            std::cout << c.val << " ";

            c.init_val = c.val;
            c.cd.x = i;
            c.cd.y = j;

            c.lft = last_island_r[i];
            c.top = last_island_c[j];

            if (c.is_island()) {
                qi++;
                last_island_c[j] = &c;
                last_island_r[i] = &c;
            }
        }
        std::cout << std::endl;
    }

    last_island_r = std::vector<cell*>(n, nullptr);
    last_island_c = std::vector<cell*>(m, nullptr);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            cell& c = board[i][j];
            c.rgt = last_island_r[i];
            c.bot = last_island_c[j];

            if (c.is_island()) {
                last_island_c[j] = &c;
                last_island_r[i] = &c;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cell& c = board[i][j];
            if (c.top != nullptr) c.top_value = std::min(c.top->val, 2);
            if (c.bot != nullptr) c.bot_value = std::min(c.bot->val, 2);
            if (c.rgt != nullptr) c.rgt_value = std::min(c.rgt->val, 2);
            if (c.lft != nullptr) c.lft_value = std::min(c.lft->val, 2);
        }
    }
}

} // namespace new_base
