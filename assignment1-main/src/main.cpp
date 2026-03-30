#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

// Umur dalam tahun
int yearsOld(tm* inputTgl, tm* currentTgl);
// Umur dalam bulan
int monthsOld(tm* inputTgl, tm* currentTgl);
// Hari dalam seminggu
string dayOfDate(tm* inputTgl);

int main(int argc, char ** argv) 
{
    time_t currentTime;
    time(&currentTime);

    tm* currentTgl = localtime(&currentTime);

    int yearinput, monthinput, dayinput;
    string inputstr;
    char ch;

    cin >> inputstr;
    stringstream ss(inputstr);
    ss >> dayinput >> ch >> monthinput >> ch >> yearinput;

    tm* inputTgl = new tm();
    inputTgl->tm_year = yearinput - 1900;
    inputTgl->tm_mon = monthinput - 1;
    inputTgl->tm_mday = dayinput;

    int ageOfYear = yearsOld(inputTgl, currentTgl);
    int ageOfMonth = monthsOld(inputTgl, currentTgl);
    string dayName = dayOfDate(inputTgl);

    cout << ageOfYear << " " << ageOfMonth << " " << dayName;

    return 0;
}

// ================= FUNCTION =================

int yearsOld(tm* inputTgl, tm* currentTgl)
{
    int year = currentTgl->tm_year - inputTgl->tm_year;

    if (currentTgl->tm_mon < inputTgl->tm_mon ||
       (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday))
    {
        year--;
    }

    return year;
}

int monthsOld(tm* inputTgl, tm* currentTgl)
{
    int yearDiff = currentTgl->tm_year - inputTgl->tm_year;
    int monthDiff = currentTgl->tm_mon - inputTgl->tm_mon;

    int totalMonth = yearDiff * 12 + monthDiff;

    if (currentTgl->tm_mday < inputTgl->tm_mday)
    {
        totalMonth--;
    }

    return totalMonth;
}

string dayOfDate(tm* inputTgl)
{
    mktime(inputTgl);

    string hari[] = {
        "Minggu", "Senin", "Selasa", "Rabu",
        "Kamis", "Jumat", "Sabtu"
    };

    return hari[inputTgl->tm_wday];
}