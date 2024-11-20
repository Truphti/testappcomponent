#include "DSTestApp.h"
#include <iostream>
#include <string>
void DisplayMenu() {
    std::cout << "\n=== MENU ===" << std::endl;
    std::cout << " 1: setVolumeLevel" << std::endl;
    std::cout << " 2: getVolumeLevel" << std::endl;
    std::cout << " 3: setMuted" << std::endl;
    std::cout << " 4: getMuted" << std::endl;
    std::cout << " 5: getVideoFormat" << std::endl;
    std::cout << " 6: setDRCMode" << std::endl;
}

int setVolumeLevel() {
    JsonObject params;
    JsonObject result;
    std::string res;
    // Prompt the user to input the audio port (optional)
    std::string audioPort;
    std::cout << "Enter Audio Port (optional, e.g., HDMI0, SPEAKER0, SPDIF0):\n";
    std::getline(std::cin, audioPort);
    // Prompt the user to input the volume level
    int volumeLevel;
    std::cout << "Enter Volume Level (0-100): ";
    std::cin >> volumeLevel;
    // Validate the volume level
    if (volumeLevel < 0 || volumeLevel > 100) {
        std::cerr << "Volume level must be between 0 and 100." << std::endl;
        return -1; // Exit with an error code
    }
    // Store audio port and volume level in params
    result.params["success"] = "true"; // Store success as a string
    result.params["volumeLevel"] = std::to_string(volumeLevel); // Store the volume level as a string
    // Prepare result string
    result.ToString(res);
    std::cout << "DisplaySettings setVolumeLevel: success\n";
    std::cout << "Result: " << res << "\n";
    return 0;
}
int getVolumeLevel() {
    JsonObject result;
    std::string res;
    // Simulated response
    result.params["success"] = "true"; // Store success as a string
    result.params["volumeLevel"] = "75"; // Simulated volume level as string for demonstration
    result.ToString(res);
    std::cout << "DisplaySettings getVolumeLevel call - Success!\n";
    int volumeLevel = result.Number(); // This will now correctly convert the string to int
    std::cout << "Current Volume Level: " << volumeLevel << " (0 = Min, 100 = Max)\n";
    std::cout << "Result: " << res << "\n";
    return 0;
}
int setMuted() {
    JsonObject params;
    JsonObject result;
    std::string res;
    std::cout << "Enter Mute Status (0 for Unmute, 1 for Mute) --> ";
    int value;
    std::cin >> value;
    // Simulated response
    result.params["success"] = true;
    result.ToString(res);
    std::cout << "DisplaySettings setMuted: success\n";
    std::cout << "Result: " << res << "\n";
    return 0;
}
int getMuted() {
    JsonObject result;
    std::string res;
    // Simulated response
    result.params["success"] = true;
    result.ToString(res);
    std::cout << "DisplaySettings getMuted call - Success!\n";
    std::cout << "Result: " << res << "\n";
    return 0;
}
int getVideoFormat() {
    JsonObject result;
    std::string res;
    // Simulated response
    result.params["success"] = "true"; // Changed to string to match the expected format
    result.params["currentVideoFormat"] = "1080p"; // Simulated video format
    result.ToString(res);
    std::cout << "DisplaySettings getVideoFormat call - Success!\n";
    std::cout << "Current Video Format: " << result.String() << "\n";
    std::cout << "Result: " << res << "\n";
    return 0;
}
int setDRCMode() {
    JsonObject params;
    JsonObject result;
    std::string res;
    std::cout << "Enter value (e.g., 0 thru 100) --> ";
    int value;
    std::cin >> value;
    // Simulated response
    result.params["success"] = true;
    result.ToString(res);
    std::cout << "DisplaySettings setDRCMode: success\n";
    std::cout << "Result: " << res << "\n";
    return 0;
}
int main() {
    int choice;
    do {
        DisplayMenu();
        std::cout << "Enter your choice (1-6, or 0 to exit): ";
        std::cin >> choice;
        switch (choice) {
            case 0:
                std::cout << "Exiting program. Goodbye!" << std::endl; break;
            case 1:
                setVolumeLevel();  break;
            case 2:
                getVolumeLevel();break;
            case 3:
                setMuted();break;
            case 4:
                getMuted();break;
            case 5:
                getVideoFormat();
                break;
            case 6:
                setDRCMode();break;
            default:
                std::cout << "Invalid choice. Please enter a number between 0 and 6." << std::endl;
        }
    } while (choice != 0);
    return 0;
}
