#include <iostream>
#include <string>
using namespace std;

bool isValidDate(const std::string& dateStr)
{
    int day, month, year;

    // Extract day, month, and year from the date string
    if (sscanf(dateStr.c_str(), "%d/%d/%d", &day, &month, &year) != 3)
        return false;

    // Check if the year is valid
    if (year < 1 || year > 9999)
        return false;

    // Check if the month is valid
    if (month < 1 || month > 12)
        return false;

    // Get the maximum number of days in the month
    int daysInMonth = 31;
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        daysInMonth = 30;
    }

    // Check if the day is valid
    if (day < 1 || day > daysInMonth)
        return false;

    return true;
}

int main()
{
    std::string date;

    while (true)
    {
        std::cout << "Enter a date (DD/MM/YYYY): ";
        std::getline(std::cin, date);

        if (isValidDate(date))
        {
            std::cout << "Date is valid: " << date << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid date entered!" << std::endl;
        }
    }

    return 0;
}
