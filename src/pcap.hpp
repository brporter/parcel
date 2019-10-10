#ifndef PCAP_HPP
#define PCAP_HPP

#include <string>

namespace parcel
{
    class PCap
    {
        public:
            PCap() = delete; // default
            PCap(const std::wstring&); // standard
            PCap(const PCap&); // copy
            PCap(PCap&&); // move


            PCap& operator=(const PCap&); // copy assignment
            PCap& operator=(PCap&&); // move assignment
            

            std::wstring captureHardware();
            std::wstring captureOs();
            std::wstring captureApp();

            uint16_t majorVersion();
            uint16_t minorVersion();


        private:
            uint16_t readChunk(std::basic_ifstream<char>&);


std::uint32_t read_chunk(std::basic_ifstream<char> &ifs)
{
    std::uint32_t value;
    ifs.read(reinterpret_cast<char*>(&value), 4);

    return value;
}

            uint16_t _majorVersion;
            uint16_t _minorVersion;
            std::wstring _captureHardware;
            std::wstring _captureOs;
            std::wstring _captureApp;
    };

} // namespace parcel
#endif
