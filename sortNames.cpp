/*
 Task 2- C++
 Created By Mohamad Ainur Imal
 UGlobal Solutions
*/
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <fstream>   // For file handling

// Function to read names from the user
std::vector<std::string> getNamesFromUser(int numNames) {
    std::vector<std::string> names;
    std::string name;

    std::cout << "Please enter " << numNames << " names:\n";
    for (int i = 0; i < numNames; ++i) {
        std::cout << "Name " << (i + 1) << ": ";
        std::getline(std::cin, name); // Use getline to handle spaces in names
        names.push_back(name);
    }

    return names;
}

// Function to load names from a text file
std::vector<std::string> loadNamesFromFile(const std::string& filename) {
    std::vector<std::string> names;
    std::ifstream file(filename); // Open the file for reading
    std::string name;

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "'.\n";
        return names; // Return an empty vector if the file cannot be opened
    }

    while (std::getline(file, name)) { // Read each line as a name
        names.push_back(name);
    }

    file.close(); // Close the file
    return names;
}

// Function to sort names alphabetically
void sortNamesAlphabetically(std::vector<std::string>& names) {
    std::sort(names.begin(), names.end()); // Uses std::sort from <algorithm>
}

// Function to display the sorted list of names with numbering
void displaySortedNames(const std::vector<std::string>& names) {
    std::cout << "\nSorted Names:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        std::cout << (i + 1) << ". " << names[i] << "\n"; // Add numbering
    }
}

int main() {
    int choice;
    std::vector<std::string> names;

    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Enter names manually\n";
        std::cout << "2. Append names from a text file\n";
        std::cout << "3. Exit program\n";
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        if (choice == 1) {
            int numNames;
            std::cout << "Enter the number of names you want to sort: ";
            std::cin >> numNames;
            std::cin.ignore(); // Clear the newline character from the input buffer

            if (numNames <= 0) {
                std::cerr << "Error: The number of names must be greater than zero.\n";
                char retry;
                std::cout << "Do you want to go back to the selection menu? (y/n): ";
                std::cin >> retry;
                std::cin.ignore(); // Clear the newline character from the input buffer
                if (retry != 'y' && retry != 'Y') {
                    std::cout << "Exiting program.\n";
                    return 0;
                }
                continue; // Go back to the selection menu
            }

            // Get names from the user
            names = getNamesFromUser(numNames);
            break; // Proceed to sorting and displaying names
        } else if (choice == 2) {
            // Append names from a text file
            std::string filename;
            std::cout << "Enter the filename containing the names (e.g., names.txt):\n";
            std::getline(std::cin, filename);

            // Load names from the file
            names = loadNamesFromFile(filename);

            if (names.empty()) {
                char retry;
                std::cout << "Do you want to go back to the selection menu? (y/n): ";
                std::cin >> retry;
                std::cin.ignore(); // Clear the newline character from the input buffer
                if (retry != 'y' && retry != 'Y') {
                    std::cout << "Exiting program.\n";
                    return 0;
                }
                continue; // Go back to the selection menu
            }
            break; // Proceed to sorting and displaying names
        } else if (choice == 3) {
            std::cout << "Exiting program.\n";
            return 0;
        } else {
            std::cerr << "Invalid choice. Please try again.\n";
            continue; // Go back to the selection menu
        }
    }

    // Sort the names alphabetically
    sortNamesAlphabetically(names);

    // Display the sorted names with numbering
    displaySortedNames(names);

    return 0; // Successful execution
}
