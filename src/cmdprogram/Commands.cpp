#include "Commands.h"

#include <filesystem>
#include <print>

const std::filesystem::path versionsDir = ".versions";

void handleInit()
{
    if (std::filesystem::exists(versionsDir) && std::filesystem::is_directory(versionsDir)) {
        std::println("The versioning system is already initialized for this folder.");
    }
    else {
        // Attempt to create the directory
        try {
            if (std::filesystem::create_directory(versionsDir)) {
                std::println("Successfully initialized versioning system in current folder.");
            }
            else {
                std::println("Error: Could not create directory.");
            }
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::println("Filesystem error: {}", e.what());
        }
    }
}
