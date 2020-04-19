#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
using namespace std;

#include <curl/curl.h>
#include <jsoncpp/json/json.h>

namespace
{
    std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}

