#ifndef UTILS_H
#define UTILS_H

#include <regex>

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

#endif