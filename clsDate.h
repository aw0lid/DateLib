#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <vector>
using namespace std;



class clsDate {


	short _Year;
	short _Month;
	short _Day;

	enum eCompare {

		Before = -1,
		Equal = 0,
		After = 1
	};


public:

	clsDate() {

		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}


	clsDate(string Date) {

		vector <string> vDate = Split(Date, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}


	clsDate(short day, short month, short year) {

		_Day = day;
		_Month = month;
		_Year = year;
	}


	clsDate(short Days, short year) {

		clsDate Date = DateFromDayOrderInYear(year, Days);

		_Year = Date._Year;
		_Month = Date._Month;
		_Day = Date._Day;
	}



	short Day() {
		return _Day;
	}

	short Month() {
		return _Month;
	}

	short Year() {
		return _Year;
	}



	void setDay(short day) {
		_Day = day;
	}

	void setMonth(short month) {
		_Month = month;
	}

	void setYear(short year) {
		_Year = year;
	}





	void Print() {
		cout << _Day << "/" << _Month << "/" << _Year;
	}


	static void Print(clsDate Date) {
		cout << Date.Day() << "/" << Date.Month() << "/" << Date.Year();
	}



	static bool LeapYear(short Year) {
		return (Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0;
	}

	bool LeapYear() {
		LeapYear(_Year);
	}




	static short DaysInFeb(short year) {
		return (LeapYear(year)) ? 29 : 28;
	}


	short DaysInFeb() {
		return DaysInFeb(_Year);
	}




	static short NumbersOfDaysInYear(short year) {
		return (LeapYear(year)) ? 366 : 365;
	}

	short NumbersOfDaysInYear() {
		return NumbersOfDaysInYear(_Year);
	}




	static int NumbersOfHoursInYear(short year) {
		return NumbersOfDaysInYear(year) * 24;
	}

	int NumbersOfHoursInYear() {
		return NumbersOfHoursInYear(_Year);
	}




	static int NumbersOfMinInYear(short year) {
		return NumbersOfHoursInYear(year) * 60;
	}

	int NumbersOfMinInYear() {
		return NumbersOfMinInYear(_Year);
	}




	static int NumbersOfSecInYear(short year) {
		return NumbersOfMinInYear(year);
	}

	int NumbersOfSecInYear() {
		return NumbersOfSecInYear(_Year);
	}








	static short NumbersOfDaysInMonth(short year, short month) {
		return (month == 2) ? DaysInFeb(year) : (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ? 31 : 30;
	}

	short NumbersOfDaysInMonth() {
		return NumbersOfDaysInMonth(_Year, _Month);
	}



	static short NumbersOfHoursInMonth(short year, short month) {
		return NumbersOfDaysInMonth(year, month) * 24;
	}

	short NumbersOfHoursInMonth() {
		return NumbersOfHoursInMonth(_Year, _Month);
	}



	static short NumbersOfMinInMonth(short year, short month) {
		return NumbersOfHoursInMonth(year, month) * 60;
	}

	short NumbersOfMinInMonth() {
		return NumbersOfMinInMonth(_Year, _Month);
	}



	static short NumbersOfSecInMonth(short year, short month) {
		return NumbersOfMinInMonth(year, month) * 60;
	}

	short NumbersOfSecInMonth() {
		return NumbersOfSecInMonth(_Year, _Month);
	}





	static string DayNameOfWeek(short num) {

		string Days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return Days[num];
	}





	static short DayOfWeekOrder(short day, short month, short year)
	{
		short a, y, m, d;

		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;

		d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	short DayOfWeekOrder() {
		return DayOfWeekOrder(_Day, _Month, _Year);
	}





	static void MonthCalendar(short year, short month) {

		string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec" };
		short FirstDayInMonth = DayOfWeekOrder(1, month, year);
		short line = 0;


		cout << "________________________" << Months[month - 1] << "_______________________\n\n";

		cout << "Sun\t" << "Mon\t" << "Tue\t" << "Wed\t" << "Thu\t" << "Fri\t" << "Sat\n\n";

		for (short i = 0; i < FirstDayInMonth; i++) {

			if (line == 7) {
				cout << endl << endl;
				line = 0;
			}

			cout << "" << "\t";
			line++;
		}


		for (short i = 1; i <= NumbersOfDaysInMonth(year, month); i++) {

			if (line == 7) {
				cout << endl << endl;
				line = 0;
			}

			cout << i << "\t";
			line++;
		}

		cout << "\n__________________________________________________\n\n";
	}


	void MonthCalendar() {
		MonthCalendar(_Year, _Month);
	}




	void YearCalendar(short year) {

		cout << "\n\t=====================================\n";
		cout << "\t Calendar - " << year;
		cout << "\n\t=====================================\n\n";

		for (short i = 1; i <= 12; i++) {

			MonthCalendar(year, i);
			cout << "\n\n";
		}
	}


	void YearCalendar() {
		YearCalendar(_Year);
	}






	static short DaysFromBeginningOfYear(short year, short month, short day) {

		short TotalDays = 0;

		for (short i = 1; i < month; i++) {

			TotalDays += NumbersOfDaysInMonth(year, i);
		}

		return TotalDays + day;
	}

	short DaysFromBeginningOfYear() {
		return DaysFromBeginningOfYear(_Year, _Month, _Day);
	}




	static clsDate DateFromDayOrderInYear(short year, short Days) {

		clsDate Date;
		Date._Month = 1;
		Date._Year = year;

		while (Days > NumbersOfDaysInMonth(Date._Year, Date._Month)) {

			Days -= NumbersOfDaysInMonth(Date._Year, Date._Month);
			Date._Month++;
		}

		Date._Day = Days;

		return Date;
	}


	void AddDaysOnDate(short Days) {

		short TotalDays = Days + DaysFromBeginningOfYear(_Year, _Month, _Day);
		_Month = 1;


		while (TotalDays > NumbersOfDaysInMonth(_Year, _Month)) {

			TotalDays -= NumbersOfDaysInMonth(_Year, _Month);
			_Month++;



			if (_Month > 12) {

				_Month = 1;
				_Year++;
				_Day = 1;
			}
		}

		_Day = TotalDays;
	}






	static bool Date1LessThanDate2(clsDate Date1, clsDate Date2) {
		return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}


	bool Date1LessThanDate2(clsDate Date) {
		return Date1LessThanDate2(*this, Date);
	}





	static bool Date1EqualDate2(clsDate Date1, clsDate Date2) {
		return (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day) ? true : false;
	}

	bool Date1EqualDate2(clsDate Date) {
		return Date1EqualDate2(*this, Date);
	}





	static bool Date1AfterDate2(clsDate Date1, clsDate Date2) {
		return (!Date1EqualDate2(Date1, Date2) && !Date1LessThanDate2(Date1, Date2)) ? true : false;
	}

	bool Date1AfterDate2(clsDate Date) {
		return Date1AfterDate2(*this, Date);
	}


	eCompare compareDates(clsDate Date1, clsDate Date2) {

		return (Date1LessThanDate2(Date1, Date2)) ? eCompare::Before : Date1EqualDate2(Date1, Date2) ? eCompare::Equal : eCompare::After;
	}


	static bool LastDayInMonth(short year, short month, short day) {
		return (day == NumbersOfDaysInMonth(year, month)) ? true : false;
	}


	static bool LastMonthInYear(short day) {
		return (day == 12) ? true : false;
	}



	bool LastDayInMonth(clsDate Date) {
		return (Date._Day == NumbersOfDaysInMonth(Date._Year, Date._Month)) ? true : false;
	}




	bool LastDayInMonth() {
		return LastDayInMonth(*this);
	}

	bool LastMonthInYear() {
		return LastMonthInYear(_Day);
	}




	static clsDate AddOneDayOnDate(clsDate Date) {

		if (LastDayInMonth(Date._Year, Date._Month, Date._Day)) {


			if (LastMonthInYear(Date._Month)) {

				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}


			else {
				Date._Day = 1;
				Date._Month++;
			}

		}
		else {
			Date._Day++;
		}

		return Date;
	}


	void AddOneDayOnDate() {
		*this = AddOneDayOnDate(*this);
	}








	static short DiffDaysBetweenDate1AndDate2(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {

		short counter = 0;

		while (!Date1EqualDate2(Date1, Date2)) {

			Date1 = AddOneDayOnDate(Date1);
			counter++;
		}

		return (IncludeEndDay) ? counter + 1 : counter;
	}


	short DiffDaysBetweenDate1AndDate2(clsDate Date, bool IncludeEndDay = false) {
		return DiffDaysBetweenDate1AndDate2(*this, Date, IncludeEndDay);
	}




	static void SwapDates(clsDate& Date1, clsDate& Date2) {

		clsDate temp;

		temp._Year = Date1._Year;
		temp._Month = Date1._Month;
		temp._Day = Date1._Day;

		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;


		Date2._Year = temp._Year;
		Date2._Month = temp._Month;
		Date2._Day = temp._Day;
	}


	void SwapDates(clsDate& Date) {
		SwapDates(*this, Date);
	}




	static int UpdatedDiffDaysBetweenDate1AndDate2(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {

		short flage = 1;
		short counter = 0;

		if (Date1LessThanDate2(Date2, Date1)) {
			SwapDates(Date1, Date2);
			flage = -1;
		}

		while (!Date1EqualDate2(Date1, Date2)) {

			Date1 = AddOneDayOnDate(Date1);
			counter++;
		}

		return (IncludeEndDay) ? counter + 1 * flage : counter * flage;

	}


	int UpdatedDiffDaysBetweenDate1AndDate2(clsDate Date) {
		return UpdatedDiffDaysBetweenDate1AndDate2(*this, Date);
	}



	static clsDate GetSystemDate() {

		clsDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date._Year = now->tm_year + 1900;
		Date._Month = now->tm_mon + 1;
		Date._Day = now->tm_mday;

		return Date;
	}

	static string getSystemTimeAndDate() {

		string T;

		time_t t = time(0);
		tm* now = localtime(&t);

		T += to_string(now->tm_year + 1900) + "/";
		T += to_string(now->tm_mon + 1) + "/";
		T += to_string(now->tm_mday) + "-";

		T += to_string(now->tm_hour) + ":";
		T += to_string(now->tm_min) + ":";
		T += to_string(now->tm_sec);

		return T;
	}


	static int AgeInDays(clsDate Date) {

		clsDate toDay = GetSystemDate();

		return DiffDaysBetweenDate1AndDate2(Date, toDay);
	}

	int AgeInDays() {
		return AgeInDays(*this);
	}





	static clsDate AddXDaysOnDate(clsDate Date, int days) {

		for (int i = 1; i <= days; i++) {

			AddOneDayOnDate(Date);
		}

		return Date;
	}

	clsDate AddXDaysOnDate(int days) {
		return AddXDaysOnDate(*this, days);
	}




	static clsDate AddOneWeekOnDate(clsDate Date) {

		for (short i = 1; i <= 7; i++) {

			AddOneDayOnDate(Date);
		}

		return Date;
	}

	clsDate AddOneWeekOnDate() {
		return AddOneWeekOnDate(*this);
	}




	static clsDate AddXWeekOnDate(clsDate Date, int weeks) {

		for (short i = 1; i <= weeks; i++) {

			AddOneWeekOnDate(Date);
		}

		return Date;
	}

	clsDate AddXWeekOnDate(int weeks) {
		return AddXWeekOnDate(*this, weeks);
	}



	static clsDate AddOneMonthOnDate(clsDate Date) {

		Date._Month++;

		if (Date._Month > 12) {

			Date._Month = 1;
			Date._Year++;
			Date._Day = 1;
		}
		else {

			if (Date._Day > NumbersOfDaysInMonth(Date._Year, Date._Month))
				Date._Day = NumbersOfDaysInMonth(Date._Year, Date._Month);
		}

		return Date;
	}

	clsDate AddOneMonthOnDate() {
		return AddOneMonthOnDate(*this);
	}




	static clsDate AddXMonthOnDate(clsDate Date, int month) {

		for (int i = 1; i <= month; i++) {

			AddOneMonthOnDate(Date);
		}

		return Date;
	}

	clsDate AddXMonthOnDate(int month) {
		return AddXMonthOnDate(*this, month);
	}




	static clsDate AddOneYearOnDate(clsDate Date) {

		for (short i = 1; i <= 12; i++) {

			AddOneMonthOnDate(Date);
		}

		return Date;
	}

	clsDate AddOneYearOnDate() {
		return AddOneYearOnDate(*this);
	}





	static clsDate AddXYearOnDate(clsDate Date, int year) {

		for (int i = 1; i <= year; i++) {

			AddOneYearOnDate(Date);
		}

		return Date;
	}


	clsDate AddXYearOnDate(int year) {
		return AddXYearOnDate(*this, year);
	}





	static clsDate AddOneDecadeOnDate(clsDate Date) {

		return 	AddXYearOnDate(Date, 10);
	}


	clsDate AddOneDecadeOnDate() {
		return AddOneDecadeOnDate(*this);
	}




	static clsDate AddXDecadeOnDate(clsDate Date, int decade) {

		for (int i = 1; i <= decade; i++) {

			AddOneDecadeOnDate(Date);
		}

		return Date;
	}


	clsDate AddXDecadeOnDate(int decade) {
		return AddXDecadeOnDate(*this, decade);
	}





	static clsDate AddOneCenturyOnDate(clsDate Date) {
		return AddXDecadeOnDate(Date, 10);
	}

	clsDate AddOneCenturyOnDate() {
		return AddOneCenturyOnDate(*this);
	}



	static clsDate AddXCenturyOnDate(clsDate Date, int century) {

		for (int i = 1; i <= century; i++) {

			AddOneCenturyOnDate(Date);
		}
		return Date;
	}

	clsDate AddXCenturyOnDate(int century) {
		return AddXCenturyOnDate(*this, century);
	}




	static clsDate AddOneMilinumOnDate(clsDate Date) {

		return AddXCenturyOnDate(Date, 10);
	}

	clsDate AddOneMilinumOnDate() {
		return AddOneMilinumOnDate(*this);
	}


	static clsDate MulOneDayFromDate(clsDate Date) {

		if (Date._Day == 1) {

			if (Date._Month == 1) {

				Date._Month = 12;
				Date._Year--;
			}
			else {
				Date._Month--;
			}

			Date._Day = NumbersOfDaysInMonth(Date._Year, Date._Month);
		}
		else {
			Date._Day--;
		}

		return Date;
	}

	clsDate MulOneDayFromDate() {
		return MulOneDayFromDate(*this);
	}





	static clsDate MullXDaysFromDate(clsDate Date, int days) {

		for (int i = 1; i <= days; i++) {

			MulOneDayFromDate(Date);
		}

		return Date;
	}

	clsDate MullXDaysFromDate(int days) {
		return MullXDaysFromDate(*this, days);
	}





	static clsDate MullOneWeekFromDate(clsDate Date) {

		return MullXDaysFromDate(Date, 7);
	}


	clsDate MullOneWeekFromDate() {
		return MullOneWeekFromDate(*this);
	}




	static clsDate MullXWeekFromDate(clsDate Date, int week) {

		for (int i = 1; i <= week; i++) {

			MullOneWeekFromDate(Date);
		}

		return Date;
	}

	clsDate MullXWeekFromDate(int week) {
		return MullXWeekFromDate(*this, week);
	}


	static clsDate MullOneMonthFromDate(clsDate Date) {//6/1/2022

		if (Date._Month == 1) {

			Date._Month = 12;
			Date._Year--;
		}

		else {

			Date._Month--;
		}

		if (Date._Day > NumbersOfDaysInMonth(Date._Year, Date._Month))
			Date._Day = NumbersOfDaysInMonth(Date._Year, Date._Month);

		return Date;
	}

	clsDate MullOneMonthFromDate() {
		return MullOneMonthFromDate(*this);
	}



	static clsDate MullXMonthFromDate(clsDate Date, int month) {

		for (int i = 1; i <= month; i++) {

			MullOneMonthFromDate(Date);
		}

		return Date;
	}

	clsDate MullXMonthFromDate(int month) {
		return MullXMonthFromDate(*this, month);
	}



	static clsDate MullOneYearFromDate(clsDate Date) {

		return MullXMonthFromDate(Date, 12);
	}

	clsDate MullOneYearFromDate() {
		return MullOneYearFromDate(*this);
	}



	static clsDate MullXYearFromDate(clsDate Date, int year) {

		for (int i = 1; i <= year; i++) {

			MullOneYearFromDate(Date);
		}

		return Date;
	}

	clsDate MullXYearFromDate(int year) {
		return MullXYearFromDate(*this, year);
	}




	static clsDate MullOneDecadeFromDate(clsDate Date) {
		return MullXYearFromDate(Date, 10);
	}

	clsDate MullOneDecadeFromDate() {
		return MullOneDecadeFromDate(*this);
	}




	static clsDate MullXDecadeFromDate(clsDate Date, int decade) {

		for (int i = 1; i <= decade; i++) {

			MullOneDecadeFromDate(Date);
		}

		return Date;
	}


	clsDate MullXDecadeFromDate(int decade) {
		return MullXDecadeFromDate(*this, decade);
	}






	static clsDate MullOneCenturyFromDate(clsDate Date) {

		return MullXDecadeFromDate(Date, 10);
	}


	clsDate MullOneCenturyFromDate() {
		return MullOneCenturyFromDate(*this);
	}




	static clsDate MullXCenturyFromDate(clsDate Date, int century) {

		for (int i = 1; i <= century; i++) {

			MullOneCenturyFromDate(Date);
		}

		return Date;
	}

	clsDate MullXCenturyFromDate(int century) {
		return MullXCenturyFromDate(*this, century);
	}



	static clsDate MullMilinumFromDate(clsDate Date) {

		return MullXCenturyFromDate(Date, 10);
	}

	clsDate MullMilinumFromDate() {
		return MullMilinumFromDate(*this);
	}





	static bool Weekend(clsDate Date) {
		return (DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 5 || DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6);
	}

	bool Weekend() {
		return Weekend(*this);
	}




	static bool endOfWeek(clsDate Date) {
		return (DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 0) ? true : false;
	}

	bool endOfWeek() {
		return endOfWeek(*this);
	}




	static bool BusinessDay(clsDate Date) {
		return (Weekend(Date)) ? false : true;
	}

	bool BusinessDay() {
		return BusinessDay(*this);
	}



	static short NumberDaysUntilWeekend(clsDate Date) {

		short counter = 0;

		while (!endOfWeek(Date)) {

			counter++;
			Date = AddOneDayOnDate(Date);
		}
		return counter;
	}

	short NumberDaysUntilWeekend() {
		return NumberDaysUntilWeekend(*this);
	}





	static short NumberDaysUntilEndMonth(clsDate Date) {

		short counter = 0;

		while (!LastDayInMonth(Date._Year, Date._Month, Date._Day)) {

			counter++;
			Date = AddOneDayOnDate(Date);
		}

		return counter;
	}

	short NumberDaysUntilEndMonth() {
		return NumberDaysUntilEndMonth(*this);
	}





	static short NumbersOfDaysUntilEndYear(clsDate Date) {

		short daysFromStartYear = DaysFromBeginningOfYear(Date._Year, Date._Month, Date._Day) - 1;
		short NumbersDaysInYear = NumbersOfDaysInYear(Date._Year);

		return NumbersDaysInYear - daysFromStartYear;
	}

	short NumbersOfDaysUntilEndYear() {
		return NumbersOfDaysUntilEndYear(*this);
	}





	static short NumbersDaysOfVacation(clsDate Date1, clsDate Date2) {

		short counter = 0;

		while (Date1LessThanDate2(Date1, Date2)) {

			if (BusinessDay(Date1))
				counter++;

			Date1 = AddOneDayOnDate(Date1);
		}

		return counter;
	}

	short NumbersDaysOfVacation(clsDate Date) {
		return NumbersDaysOfVacation(*this, Date);
	}





	static clsDate ReturnVacationDate(clsDate Date, short days) {

		short counter = 0;

		for (short i = 1; i <= days; i++) {

			if (Weekend(Date))
				days++;

			Date = AddOneDayOnDate(Date);
		}

		return Date;
	}

	clsDate ReturnVacationDate(short days) {
		return ReturnVacationDate(*this, days);
	}




	static bool ValidDate(clsDate Date) {
		return (Date._Month <= 12) ? (Date._Day <= NumbersOfDaysInMonth(Date._Year, Date._Month) && Date._Day > 0) ? true : false : false;
	}

	bool ValidDate() {
		return ValidDate(*this);
	}





	static vector <string> Split(string text, string del = " ") {

		vector <string> vText;
		string word;
		short pos;


		while ((pos = text.find(del)) != string::npos) {

			word = text.substr(0, pos);

			if (!word.empty())
				vText.push_back(word);

			text.erase(0, pos + del.length());
		}

		if (!text.empty())
			vText.push_back(text);

		return vText;
	}




	static string ReplaceString(string text, string word, string newWord) {

		short pos = 0;

		while ((pos = text.find(word)) != string::npos) {

			text = text.replace(pos, word.length(), newWord);
		}

		return text;
	}


	static string convertDateToString(clsDate Date) {

		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string convertDateToString() {
		return convertDateToString(*this);
	}




	static string DateFormating(clsDate Date, string format = "dd/mm/yyyy") {

		string result = format;

		result = ReplaceString(result, "dd", to_string(Date._Day));
		result = ReplaceString(result, "mm", to_string(Date._Month));
		result = ReplaceString(result, "yyyy", to_string(Date._Year));

		return result;
	}


	string DateFormating(string format = "dd/mm/yyyy") {
		return DateFormating(*this, format);
	}
};