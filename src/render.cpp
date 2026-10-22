#include "render.hpp"

#include "board.hpp"

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

namespace new_base {

void print_cell_info(cell c) {
    std::cout << "{ val: " << c.val << ", ";
    std::cout << "lft: " << c.lft_value << ", ";
    std::cout << "rgt: " << c.rgt_value << ", ";
    std::cout << "top: " << c.top_value << ", ";
    std::cout << "bot: " << c.bot_value;
    std::cout << " } ";
}

void print_cell(cell c) {
    if (c.is_island()) {
        std::cout << board[c.cd.x][c.cd.y].init_val << " ";
    } else {
        std::vector<std::string> switch_line(6);
        switch_line[NO_LINE] = " ";
        switch_line[HORIZONTAL] = "-";
        switch_line[D_HORIZONTAL] = "=";
        switch_line[VERTICAL] = "|";
        switch_line[D_VERTICAL] = "ǁ";

        if (c.line > D_VERTICAL) std::cout << "? ";
        else std::cout << switch_line[c.line] << " ";
    }
}

void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            print_cell(board[i][j]);
        }
        std::cout << std::endl;
    }
}

void print_edg_list() {
    std::cout << qi << " " << static_cast<int>(edg_list.size()) << std::endl;
    for (auto e : edg_list) {
        std::printf("%d %d %d %d\n", e.first.cd.x, e.first.cd.y,
                    e.second.cd.x, e.second.cd.y);
    }
}

} // namespace new_base
