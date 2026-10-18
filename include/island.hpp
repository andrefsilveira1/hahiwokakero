#pragma once

namespace hashiwokakero {

struct Position {
    int x;
    int y;
};

class Island {
public:
    Island(int id, Position position, int requiredBridges);

    Position getPosition() const;
    
    int getId() const;
    int getRequiredBridges() const;
    int getCurrentBridges() const;
    
    bool isEnabled() const;
    bool addBridges(int quantity);
    bool isSatisfied() const;

    void setEnabled();

private:
    int id_;
    Position position_;
    bool enabled = false;

    int requiredBridges_;
    int currentBridges_ = 0;
};

} // namespace hashiwokakero
