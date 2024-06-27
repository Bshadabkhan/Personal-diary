#include "PersonalDiary.h"

PersonalDiary::PersonalDiary() {
    loadEntries();
}

PersonalDiary::~PersonalDiary() {
    saveEntries();
}

void PersonalDiary::loadEntries() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    std::string date, content;
    while (getline(file, date)) {
        getline(file, content);
        entries.push_back({date, content});
    }
    file.close();
}

void PersonalDiary::saveEntries() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for saving entries.\n";
        return;
    }

    for (const auto& entry : entries) {
        file << entry.date << "\n" << entry.content << "\n";
    }
    file.close();
}

void PersonalDiary::addEntry(const std::string& date, const std::string& content) {
    entries.push_back({date, content});
    saveEntries();
}

void PersonalDiary::viewEntries() {
    for (const auto& entry : entries) {
        std::cout << "Date: " << entry.date << "\n";
        std::cout << "Content: " << entry.content << "\n";
        std::cout << "-------------------------------------\n";
    }
}

void PersonalDiary::editEntry(const std::string& date) {
    for (auto& entry : entries) {
        if (entry.date == date) {
            std::cout << "Current content: " << entry.content << "\n";
            std::cout << "Enter new content: ";
            std::cin.ignore();
            getline(std::cin, entry.content);
            saveEntries();
            return;
        }
    }
    std::cout << "Entry not found.\n";
}

void PersonalDiary::deleteEntry(const std::string& date) {
    for (auto it = entries.begin(); it != entries.end(); ++it) {
        if (it->date == date) {
            entries.erase(it);
            saveEntries();
            return;
        }
    }
    std::cout << "Entry not found.\n";
}
