#pragma once
#include <vector>

namespace hashiwokakero {
using Id = std::size_t;

struct Bridge {
    Id from;
    Id to;
    int count;
};

class Bridge {
public:
    Bridge(Id from, Id to);
};

class BridgesList {
public: 
    BridgesList(int total);
    std::vector<Bridge> createList();

private:
    std::vector<Bridge> MatrixBridgeList;
};


} // namespace hashiwokakero