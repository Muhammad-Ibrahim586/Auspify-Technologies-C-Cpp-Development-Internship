# Auspify Technologies — C/C++ Development Internship

A collection of four C++ console applications developed as part of the **C/C++ Development Internship at Auspify Technologies**.

The projects demonstrate practical C++ programming, object-oriented design, modular source-code organization, file handling, input validation, and problem-solving.

## Projects Overview

| Task | Project | Description |
|---|---|---|
| 3 | Student Management System | Manage student records through a console interface. |
| 4 | Library Management System | Manage book records, availability, and issue/return operations. |
| 5 | Banking Management System | Manage accounts and perform basic balance-related transactions. |
| 6 | Expression Evaluator | Evaluate arithmetic expressions using expression-processing logic. |

## Technologies Used

- **Programming Language:** C++
- **Editor:** Visual Studio Code (VS Code)
- **Compiler:** GCC/MinGW (`g++`)
- **Libraries:** C++ Standard Library
- **Development Concepts:** Object-oriented programming (OOP), classes, functions, modular design, file handling, input validation, and error handling
- **Interface:** Console-based user interfaces

## Project Details

### Task 3 — Student Management System

A console-based application for managing student records.

**Implemented functionality may include:**
- Adding student records
- Displaying student information
- Searching for students
- Updating existing records
- Deleting student records
- Saving and loading records using a text file

**Source files**
- `main.cpp`
- `Student.h`
- `Student.cpp`

**Data file:** `data/students.txt`

**Screenshot directory:** `screenshots/`

### Task 4 — Library Management System

A console-based application for managing library books and their availability.

**Implemented functionality may include:**
- Adding and removing books
- Searching for books
- Displaying book records and available books
- Issuing books
- Returning books
- Saving and loading book records

**Source files**
- `main.cpp`
- `Book.h`
- `Book.cpp`
- `Library.h`
- `Library.cpp`

**Data file:** `data/books.txt`

**Screenshot directory:** `screenshots/`

### Task 5 — Banking Management System

A console-based educational application for basic account management and balance-related operations. It is not a production banking system and does not connect to real banking services.

**Implemented functionality may include:**
- Creating and managing accounts
- Displaying account information
- Depositing money
- Withdrawing money
- Viewing transaction history
- Deleting accounts
- Saving and loading account records

**Source files**
- `main.cpp`
- `Account.h`
- `Account.cpp`
- `Bank.h`
- `Bank.cpp`

**Data file:** `data/accounts.txt`

**Screenshot directory:** `screenshots/`

### Task 6 — Expression Evaluator

A console-based C++ application for evaluating arithmetic expressions.

Depending on the final implementation, its functionality may include:
- Basic arithmetic operations
- Operator precedence
- Parenthesized or grouped expressions
- Nested expressions
- Decimal numbers
- Invalid-expression handling
- Division-by-zero handling

The supported operators, bracket types, and error-handling behavior should be confirmed against the final source code.

**Source files**
- `main.cpp`
- `ExpressionEvaluator.h`
- `ExpressionEvaluator.cpp`

**Screenshot directory:** `screenshots/`

## Repository Structure

```text
Auspify-Technologies-C-CPP-Internship/
├── .gitignore
├── README.md
├── docs/
│   ├── Internship Report.pdf
│   └── Internship Presentation Slides.pptx
├── Task_3_Student_Management/
│   ├── data/
│   │   └── students.txt
│   ├── screenshots/
│   └── src/
│       ├── main.cpp
│       ├── Student.h
│       └── Student.cpp
├── Task_4_Library_Management/
│   ├── data/
│   │   └── books.txt
│   ├── screenshots/
│   └── src/
│       ├── main.cpp
│       ├── Book.h
│       ├── Book.cpp
│       ├── Library.h
│       └── Library.cpp
├── Task_5_Banking_Management/
│   ├── data/
│   │   └── accounts.txt
│   ├── screenshots/
│   └── src/
│       ├── main.cpp
│       ├── Account.h
│       ├── Account.cpp
│       ├── Bank.h
│       └── Bank.cpp
└── Task_6_Expression_Evaluator/
    ├── screenshots/
    └── src/
        ├── main.cpp
        ├── ExpressionEvaluator.h
        └── ExpressionEvaluator.cpp
```

## Prerequisites

To compile the projects on Windows, install:

- Visual Studio Code or another C++ editor
- GCC/MinGW C++ compiler
- A terminal where `g++` is available in the system `PATH`

Verify the compiler installation:

```bash
g++ --version
```

## Compilation and Execution

Run the following commands from the corresponding project's `src` directory.

### Task 3 — Student Management System

Compile:

```bash
g++ main.cpp Student.cpp -o StudentManagement.exe
```

Run in Windows CMD:

```cmd
StudentManagement.exe
```

### Task 4 — Library Management System

Compile:

```bash
g++ main.cpp Book.cpp Library.cpp -o LibraryManagement.exe
```

Run:

```cmd
LibraryManagement.exe
```

### Task 5 — Banking Management System

Compile:

```bash
g++ main.cpp Account.cpp Bank.cpp -o BankingManagement.exe
```

Run:

```cmd
BankingManagement.exe
```

### Task 6 — Expression Evaluator

Compile:

```bash
g++ main.cpp ExpressionEvaluator.cpp -o ExpressionEvaluator.exe
```

Run:

```cmd
ExpressionEvaluator.exe
```

**Build note:** These commands assume that the listed source files are sufficient to compile each application and that no additional libraries are required.

**Working-directory note:** The Student Management, Library Management, and Banking Management applications use data files. Ensure the working directory matches the relative file paths expected by the code. If the programs expect a `data` directory relative to the working directory, running them from `src` may require adjusting the paths or running them from the project directory.

## Data Persistence

The first three applications use text files for application data, where implemented:

- Student records: `Task_3_Student_Management/data/students.txt`
- Book records: `Task_4_Library_Management/data/books.txt`
- Account records: `Task_5_Banking_Management/data/accounts.txt`

Use fictional sample records when demonstrating the applications. Do not publish real personal information, account details, or sensitive transaction data.

## Screenshots

Each project's `screenshots/` directory contains images demonstrating the console interface and selected application operations.

The screenshots provide visual evidence of the applications' behavior and support the accompanying internship report and presentation.

## Internship Documentation

- **Internship Report:** [`docs/Internship Report.pdf`](docs/Internship%20Report.pdf)
- **Internship Presentation:** [`docs/Internship Presentation Slides.pptx`](docs/Internship%20Presentation%20Slides.pptx)

## Learning Outcomes

The projects provided practical opportunities to work with:

- C++ programming fundamentals
- Classes, objects, and encapsulation
- Object-oriented programming
- Modular code using header and implementation files
- File input/output and data persistence
- Record management and CRUD operations
- Input validation and error handling
- Arithmetic expression processing
- Compilation, debugging, and testing
- Technical documentation and project organization

## Internship Information

- **Organization:** Auspify Technologies
- **Program:** C/C++ Development Internship
- **Duration:** 4 weeks
- **Project Type:** Console-based C++ applications
- **Tasks Covered:** Tasks 3, 4, 5, and 6

## Repository

**GitHub Repository:** https://github.com/Muhammad-Ibrahim586/Auspify-Technologies-C-Cpp-Development-Internship.

---

*Developed as part of the Auspify Technologies C/C++ Development Internship.*