#ifndef _DSTESTAPP_H_
#define _DSTESTAPP_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>
class JsonObject {
public:
    std::unordered_map<std::string, std::string> params;
    std::vector<std::string> supportedVideoFormats; // Added member to store supported formats
    std::string& operator[](const std::string& key) {
        return params[key]; // Corrected return type
    }
    std::string String() const {
        auto it = params.find("currentVideoFormat");
        if (it != params.end()) {
            return it->second; // Ensure we're returning a string
        }
        return ""; // Default return if not found
    }
    bool Boolean() const {
        return params.find("success") != params.end() && params.at("success") == "true"; // Checking success flag
    }
    int Number() const {
        auto it = params.find("volumeLevel");
        if (it != params.end()) {
            return std::stoi(it->second); // Convert string to int
        }
        return 0; // Default return if not found
    }
void ToString(std::string& res) const {
    res = ""; // Clear the result string
    for (const auto& pair : params) {
        res += pair.first + ": " + pair.second + "\n"; // Convert params to string
    }
    // Only add supported video formats if there are any
    if (!supportedVideoFormats.empty()) {
        res += "Supported Video Formats: ";
        for (const auto& format : supportedVideoFormats) {
            res += format + " "; // Add supported formats to the string representation
        }
        res += "\n"; // New line at the end
    }
}
};
#endif
