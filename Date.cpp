#include <iostream>

struct WrongDayException
{
    int day;
};

struct WrongMonthException
{
    int month;
};

struct WrongYearException
{
    int year;
};

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int day, int month, int year)
    {
        this->day = day;
        this->year = year; 
        this->month = month;
        
        int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth[2] = 29;
        }

        if (day > daysInMonth[month] || day <= 0)
        {
            throw WrongDayException(day);
        }

        if (month > 12 || month <= 0)
        {
            throw WrongMonthException(month);
        }

        if (year <= 0)
        {
            throw WrongYearException(year);
        }

    }

    Date(int day)
    {
        this->day = day;
        month = 1;
        year = 1;

        int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (day > daysInMonth[month] || day <= 0)
        {
            throw WrongDayException(day);
        }
    }

    int GetYear()const
    {
        return year;
    }

    int GetMonth()const
    {
        return month;
    }

    int GetDay()const
    {
        return day;
    }

    Date operator+ (int d) const 
    {
        int newDay = day + d;
        
        return Date(newDay, month, year);
    }
    
    Date operator- (int d) const
    {
        int newDay = day - d;
       
        return Date(newDay, month, year);
    }

    Date& operator+= (int d)
    {
        day += d;

        Date(day, month, year);
        
        return *this;
    }
   
};


std::ostream& operator << (std::ostream& out, const Date& d) 
{
    out << d.GetDay() << " . " << d.GetMonth() << " . " << d.GetYear();

    return out;
}

std::istream& operator >> (std::istream& in, Date& date) 
{
    std::cin.exceptions(std::istream::failbit);

    int y, m, d;
    char c;
    
    in >> d >> c;
    in >> m >> c;
    in >> y;

    date = Date(d, m, y);

    return in;

}


int main()
{
    try {
        Date date(10,9,2005);
       /* date.operator+=(30);*/
       /* date = date + 25;*/
        /*date = date - 30;*/
       /* std::cin >> date;*/
        /*Date date1(-100);*/
    }

    catch (const WrongDayException& d) {
        std::cerr << "Wrong day" << std::endl;
        return 1;
    }

    catch (const WrongMonthException& m) {
        std::cerr << "Wrong month" << std::endl;
        return 1;
    }

    catch (const WrongYearException& y) {
        std::cerr << "Wrong year" << std::endl;
        return 1;
    }

    catch (const std::istream::failure& ex)
    {
        std::cerr << "Data could not be read " << ex.what() << "\n";
        return 2;
    }

    catch (...)
    {
        std::cerr << "other failure " << "\n";
        return -1;
    }


    return 0;
}
