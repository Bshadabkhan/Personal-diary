#ifndef PERSONALDIARY_H
#define PERSONALDIARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct DiaryEntry {
    std::string date;
    std::string content;
};

class PersonalDiary {
private:
    std::vector<DiaryEntry> entries;
    const std::string filename = "diary.txt";

    void loadEntries();
    void saveEntries();

public:
    PersonalDiary();
    ~PersonalDiary();

    void addEntry(const std::string& date, const std::string& content);
    void viewEntries();
    void editEntry(const std::string& date);
    void deleteEntry(const std::string& date);
};

#endif
