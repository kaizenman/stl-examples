#include <iostream>
#include <memory>
#include <cstdio>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

int fclose_and_log(std::FILE* fp)
{
    std::cout << "fclose(" << fp << ")\n";
    return fclose(fp);
}

int main()
{
    using evil = std::unique_ptr<FILE, int(*)(FILE*)>;

    evil ptr{fopen("foo.txt", "w"), &fclose};
    ptr = evil{fopen("bar.txt", "w"), &fclose_and_log};

    std::vector<evil> files;
    files.reserve(64);
    std::generate_n(std::back_inserter(files), 64, [n = 1]()mutable {
        auto name = std::to_string(n++) + ".txt";
        return evil{fopen(name.c_str(), "w"), &fclose};
    });
}