#include "PersonalDiary.h"

int main() {
    PersonalDiary diary;
    int choice;
    std::string date, content;

    do {
        std::cout << "1. Add Entry\n";
        std::cout << "2. View Entries\n";
        std::cout << "3. Edit Entry\n";
        std::cout << "4. Delete Entry\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;
                std::cin.ignore();
                std::cout << "Enter content: ";
                getline(std::cin, content);
                diary.addEntry(date, content);
                break;
            case 2:
                diary.viewEntries();
                break;
            case 3:
                std::cout << "Enter date of entry to edit (YYYY-MM-DD): ";
                std::cin >> date;
                diary.editEntry(date);
                break;
            case 4:
                std::cout << "Enter date of entry to delete (YYYY-MM-DD): ";
                std::cin >> date;
                diary.deleteEntry(date);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
