#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <sstream>
#include <iomanip>

void clearTerminal(void)
{
    std::system("cls||clear");
    return;
}

string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string year = to_string(1900 + ltm->tm_year);
    string month;
    if (1 + ltm->tm_mon < 10)
    {
        month = "0" + to_string(1 + ltm->tm_mon);
    }
    else
    {
        month = to_string(1 + ltm->tm_mon);
    }

    string day = to_string(ltm->tm_mday);

    return year + "-" + month + "-" + day;
}

bool dateFormatValidation(string date)
{
    std::regex pattern("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(date, pattern);
}

int generate3RandomNumber()
{
    srand(time(0));
    return rand() % 1000;
}

void enterToContinue()
{
    cout << "\nTekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    return;
}

string getRegexpDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    char date[11];
    snprintf(date, sizeof(date), "%04d-%02d-%02d", year, month, day);
    return string(date);
}

int kalkulasiPerbedaanTanggal(string date1, string date2)
{
    // mengambil tahun, bulan, dan hari dari string
    int year1, month1, day1;
    sscanf(date1.c_str(), "%d-%d-%d", &year1, &month1, &day1);

    // mengambil tahun, bulan, dan hari dari string
    int year2,
        month2, day2;
    sscanf(date2.c_str(), "%d-%d-%d", &year2, &month2, &day2);

    // membuat struct tm
    tm tm1 = {0}, tm2 = {0};
    tm1.tm_year = year1 - 1900;
    tm1.tm_mon = month1 - 1;
    tm1.tm_mday = day1;

    tm2.tm_year = year2 - 1900;
    tm2.tm_mon = month2 - 1;
    tm2.tm_mday = day2;

    // konversi string ke time
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    double difference = difftime(time1, time2) / (60 * 60 * 24);

    return static_cast<int>(difference);
}

#endif