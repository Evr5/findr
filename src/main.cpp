#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <string>

namespace fs = std::filesystem;

std::string toLowerCopy(const std::string& str) {
    std::string result;
    result.reserve(str.size());
    std::transform(str.begin(), str.end(), std::back_inserter(result), ::tolower);
    return result;
}

std::string joinArgs(int argc, const char* argv[], int start = 1) {
    std::string result;
    for (int i = start; i < argc; ++i) {
        if (i > start) result += ' ';
        result += argv[i];
    }
    return result;
}

int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <name_to_find>" << std::endl;
        std::cerr << "Example: " << argv[0] << " myfile.txt" << std::endl;
        std::cerr << "This program will search for files and directories containing the specified name in the current directory and its subdirectories." << std::endl;
        return 1;
    }

    std::string nameTofind = joinArgs(argc, argv, 1);
    std::string nameToFindLower = toLowerCopy(nameTofind);
    std::cout << "Searching for: " << nameTofind << "\n" << std::endl;

    std::vector<std::string> result;
    fs::path current_path = fs::current_path();
    for (const fs::directory_entry& entry : fs::recursive_directory_iterator(current_path, fs::directory_options::skip_permission_denied)) {
        const std::string pathStr = entry.path().string();
        const std::string pathStrLower = toLowerCopy(pathStr);

        if (pathStrLower.find(nameToFindLower) != std::string::npos) {
            result.push_back(pathStr);
        }
    }

    if (result.empty()) {
        std::cout << "No files or directories found containing : " << nameTofind << std::endl;
        return 0;
    }

    std::cout << "Found " << result.size() << " match(es):\n" << std::endl;
    for (const std::string &entry : result) {
        std::cout << entry << std::endl;
    }

    return 0;
}
