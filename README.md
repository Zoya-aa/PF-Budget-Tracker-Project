
# Budget-Tracker
* **Course:** Programming Fundamentals  
* **Team:** Omaima Siddique (26K-2517), Zoya Shahid (26K-2515)  

A personal budget tracker application designed for managing monthly budgets, income sources, and home expenses.The backend logic is written in **C/C++** using a modular header-and-source file architecture, accompanied by an interactive **HTML, CSS, and JavaScript** web dashboard.



---

## Features

* **User & Budget Setup:** Saves the user's profile name and sets a monthly spending budget limit.
* **Expense Tracking:** Logs expenses with descriptions, amounts, categories (`Housing`, `Food`, `Transport`, `Fun`), and months.
* **Income Management:** Records multiple income sources and dynamically computes net balances.
* **Search & Filter:** Searches through recorded transactions by category, description, or month.
* **Budget Alerts:** Automatically alerts the user when spending approaches or exceeds the configured monthly budget limit.
* **Report Export:** Generates a formatted financial summary and exports it to a `.txt` report file.
* **Data Persistence:** Saves records locally so financial data remains intact across sessions.

## Project Structure

| File | Description |
| :--- | :--- |
| `main function.c` | Entry point of the C/C++ console application; integrates the budget and expense modules via header files. |
| `expenses.h` / `expenses.c` | **Member 1:** Handles expense logging, category/month searching, total expense calculations, and file storage. |
| `budget.h` / `budget.c` | **Member 2:** Handles user setup, income tracking, monthly budget limits, balance calculations, alerts, and report generation. |
| `index.html` | Structure and layout of the web-based GUI dashboard. |
| `style.css` | Black and electric-blue dark theme styling for the dashboard. |
| `app.js` | Frontend logic, live chart rendering, local storage persistence, and `.txt` report export. |

## How to Run

### 1. C/C++ Console Application
Ensure you have a C/C++ compiler installed (such as `g++` via MinGW on Windows, or GCC/Clang on Linux/macOS).

Open your terminal in the project folder and compile all source files together:
```bash
g++ "main function.cpp" expenses.cpp budget.cpp -o tracker
./tracker

### 2. **Web Dashboard GUI**
1. Navigate to the project folder on your computer.
2. Double-click `index.html` to open the dashboard directly in any web browser (Chrome, Edge, Firefox, etc.).

