#include <stdio.h>
#include <locale.h>


// Структура для хранения даты
struct Date 
{
    int year, month, day;
};

// Функция для определения високосного года
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// Функция для возвращения количества недель с начала года для структуры Date
int weeksInYear(struct Date date) 
{
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int weeks = 0;
    for (int i = 1; i < date.month; i++) 
    {
        weeks += daysInMonth[i];
    }
    weeks += date.day;
    if (isLeapYear(date.year)) 
    {
        weeks += 1;
    }
    return weeks / 7;
}

// Перегрузка функции для трех целочисленных параметров: год, месяц, день
int weeksInYear1(int year, int month, int day) 
{
    struct Date date = { year, month, day };
    return weeksInYear(date);
}

// Перегрузка функции для двух целочисленных параметров: месяц, день
int weeksInYear2(int month, int day) 
{
    struct Date currentDate; // текущий год
    currentDate.year = 2023;
    currentDate.month = month;
    currentDate.day = day;
    return weeksInYear(currentDate);
}

int main() 
{
    setlocale(LC_ALL, "rus");
    struct Date date1 = { 2023, 11, 22 };
    printf("Прошло недель с начала года: %d\n", weeksInYear(date1));

    printf("Прошло недель с начала года: %d\n", weeksInYear1(2023, 11, 22));

    printf("Прошло недель с начала года: %d\n", weeksInYear2(11, 22));

    return 0;
}