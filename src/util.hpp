#ifndef UTIL_HPP
#define UTIL_HPP

#include <fstream>
#include <string>

std::uint32_t read_chunk(std::basic_ifstream<char> &ifs)
{
    std::uint32_t value;
    ifs.read(reinterpret_cast<char*>(&value), 4);

    return value;
}

std::wstring read_chunk(std::basic_ifstream<char> &ifs, uint32_t length)
{
    ifs.read
#endif
