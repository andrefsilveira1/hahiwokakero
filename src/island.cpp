#include "island.hpp"

#include <stdexcept>

namespace hashiwokakero {

Island::Island(int id, Position position, int requiredBridges)
    : id_(id), position_(position), requiredBridges_(requiredBridges) {
    if (id_ < 0) {
        throw std::invalid_argument("Island ID cannot be negative.");
    }
    if (requiredBridges_ < 0 || requiredBridges_ > 8) {
        throw std::invalid_argument("Required bridges must be between 0 and 8.");
    }
}

Position Island::getPosition() const { return position_; }
int Island::getId() const { return id_; }
int Island::getRequiredBridges() const { return requiredBridges_; }
int Island::getCurrentBridges() const { return currentBridges_; }
bool Island::isEnabled() const { return enabled; }

bool Island::addBridges(int quantity) {
    if (quantity <= 0 || currentBridges_ + quantity > requiredBridges_) {
        return false;
    }
    currentBridges_ += quantity;
    return true;
}

bool Island::isSatisfied() const {
    return currentBridges_ == requiredBridges_;
}

void Island::setEnabled() { enabled = true; }

} // namespace hashiwokakero
