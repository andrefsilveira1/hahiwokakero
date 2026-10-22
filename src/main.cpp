#include "board.hpp"
#include "render.hpp"

#include <iostream>
#include <sstream>
#include <vector>

int main() {
    using namespace new_base;

    std::istringstream quick_example("3 1 0\n1 0 1\n");
    std::istream* input = &std::cin;
    if (!(std::cin >> m >> n >> qi)) {
        input = &quick_example;
        *input >> m >> n >> qi;
    }
    qi = 0;
    std::cout << m << " " << n << std::endl;

    board = board_t(n, std::vector<cell>(m));
    initialize_board(*input);
}
