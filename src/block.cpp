#include "block.hpp"

using namespace parcel;

Block::Block(const Block&) {}

Block::Block(Block&&) {}

Block::~Block() {}

Block& Block::operator=(const Block&) noexcept {}
Block& Block::operator=(Block&&) noexcept {}

enum BlockType Block::type() const {}
std::uint32_t Block::length() const {}
std::shared_ptr<std::uint8_t> Block::body() const {}

