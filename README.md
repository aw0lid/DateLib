# 📅 clsDate – Comprehensive C++ Date Utility Class

`clsDate` is a powerful, high-level C++ library designed for sophisticated date management and time calculations. It provides an extensive set of tools for date manipulation, comparison, formatting, and calendar operations, demonstrating advanced **Object-Oriented Programming (OOP)** and manual logic implementation.

---

## 🛠 Features & Services

The library is organized into logical categories to handle all date-time requirements:

| Category | Features |
| :--- | :--- |
| **Date Creation** | Current system date, from string "dd/mm/yyyy", from day/month/year, from day-of-year order. |
| **Access & Modification** | Get/Set Day, Month, and Year. |
| **Date Analysis** | Leap year check, days in month/year, day of the week, weekend & business day check, age in days. |
| **Date Manipulation** | Add/Subtract days, weeks, months, years, decades, centuries, and millennia. |
| **Date Comparison** | Less than, equal, greater than, precise difference in days. |
| **Formatting & Display** | Convert to string, custom formatting (dd/mm/yyyy), split & replace logic. |
| **Calendar Display** | Full monthly and yearly calendars printed to console. |
| **Vacation & Work** | Count vacation days, calculate vacation end date, days until end of month/year/week. |

---

## 📊 Commonly Used Methods

### ⚙️ Creation & Access
`clsDate()`, `clsDate(day, month, year)`, `clsDate("dd/mm/yyyy")`, `Day()`, `Month()`, `Year()`, `setDay()`.

### 🔍 Analysis & Comparison
`LeapYear()`, `Weekend()`, `BusinessDay()`, `AgeInDays()`, `Date1LessThanDate2()`, `Date1EqualDate2()`, `Date1AfterDate2()`.

### 🔄 Manipulation & Formatting
`AddOneDayOnDate()`, `AddXDaysOnDate()`, `MulOneDayFromDate()`, `convertDateToString()`, `DateFormating()`.

### 🗓 Calendar & Vacation
`MonthCalendar()`, `YearCalendar()`, `NumbersDaysOfVacation()`, `ReturnVacationDate()`.

---

## 💻 Example Usage

### 1️⃣ Basic Operations & Printing
```cpp
clsDate today;
today.Print(); // Output: 21/12/2025
```
### 2️⃣ Handling Leap Years & Adding Days
```cpp
clsDate myDate(28, 2, 2024); // Leap Year
myDate.AddXDaysOnDate(3);
cout << myDate.DateFormating(); // Output: 2/3/2024
```
### 3️⃣ Difference Between Dates
```cpp
clsDate start(1, 1, 2025);
clsDate end(10, 1, 2025);
cout << start.DiffDaysBetweenDate1AndDate2(end); // Output: 9
```
### 4️⃣ Calendar & Vacation Logic
```cpp
clsDate vacationStart(20, 12, 2025);
// Calculate return date after 10 business days
clsDate vacationEnd = clsDate::ReturnVacationDate(vacationStart, 10);
cout << vacationEnd.DateFormating(); // Output: 2/1/2026

// Print monthly calendar
vacationStart.MonthCalendar();
```
---

## 🎯 Project Purpose
- The main goal of this project is hands-on practice and demonstrating:

- Full OOP Implementation: Mastering objects, static methods, encapsulation, and class relationships.

- Advanced Manual Logic: Implementing leap years, month-end detection, and date differences without external libraries.

- Problem-Solving: Handling complex time intervals and edge cases.
---

## 📜 License
This project is provided for educational and experimental purposes only.
