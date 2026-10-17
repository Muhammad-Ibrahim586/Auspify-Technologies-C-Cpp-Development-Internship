# Auspify Technologies — C/C++ Development Internship

A collection of four C++ console applications developed as part of the **C/C++ Development Internship at Auspify Technologies**. These projects demonstrate practical programming skills, object-oriented design, file handling, input validation, and algorithm implementation.

## Projects Overview

| Task | Project | Description |
|---|---|---|
| 3 | Student Management System | Manage student records with file persistence. |
| 4 | Library Management System | Manage books, availability, and issue/return operations. |
| 5 | Banking Management System | Manage accounts, deposits, withdrawals, and transaction history. |
| 6 | Expression Evaluator | Evaluate arithmetic expressions with operator precedence and nested brackets. |

## Technologies Used

- **Language:** C++
- **Code Editor:** Visual Studio Code (VS Code)
- **Compiler:** GCC/MinGW (`g++`)
- **Libraries:** C++ Standard Library
- **Core Concepts:** Object-Oriented Programming (OOP), file handling, data management, input validation, and error handling

## Project Details

### Task 3 — Student Management System

A console-based application for maintaining student records.

**Features**
- Add new student records
- Display student information
- Search for students
- Update existing records
- Delete student records
- Save and load records using file handling

**Concepts Demonstrated**
- Classes and objects
- Data encapsulation
- CRUD operations (Create, Read, Update, Delete)
- File input/output
- Input validation

**Source Files**
- `main.cpp`
- `Student.h`
- `Student.cpp`

**Data File:** `data/students.txt`

### Task 4 — Library Management System

A console-based application for managing books and their availability in a library.

**Features**
- Add and remove books
- Search for books
- Display available books
- Issue books
- Return books
- Persist book records using file handling

**Concepts Demonstrated**
- Object-oriented programming
- Class-based data management
- Book availability tracking
- File input/output
- Input validation

**Source Files**
- `main.cpp`
- `Book.h`
- `Book.cpp`
- `Library.h`
- `Library.cpp`

**Data File:** `data/books.txt`

### Task 5 — Banking Management System

A console-based application for managing bank accounts and performing basic transactions.

**Features**
- Create and manage accounts
- Deposit money
- Withdraw money
- Validate transaction amounts and account balances
- View transaction history
- Delete accounts
- Save and load account records using file handling

**Concepts Demonstrated**
- Object-oriented programming
- Encapsulation
- Transaction processing
- Balance validation
- File persistence
- Error handling

**Source Files**
- `main.cpp`
- `Account.h`
- `Account.cpp`
- `Bank.h`
- `Bank.cpp`

**Data File:** `data/accounts.txt`

### Task 6 — Expression Evaluator

A console-based arithmetic expression evaluator that processes mathematical expressions and calculates their results.

**Features**
- Addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`)
- Operator precedence
- Parentheses (`()`), square brackets (`[]`), and curly braces (`{}`)
- Nested bracket expressions
- Decimal number support
- Invalid-expression handling
- Division-by-zero handling

**Concepts Demonstrated**
- Arithmetic expression parsing
- Operator precedence
- Stack-based or equivalent expression evaluation techniques
- Input validation
- Error handling

**Source Files**
- `main.cpp`
- `ExpressionEvaluator.h`
- `ExpressionEvaluator.cpp`

## Repository Structure

```text
Auspify_Technologies_C_C++_Development_Internship/
│   .gitignore
│   README.md
│
├───docs
│       Internship Presentation Slides.pptx
│       Internship Report.pdf
│
├───Task_3_Student_Management
│   ├───data
│   │       students.txt
│   │
│   ├───screenshots
│   │       Add Student.PNG
│   │       Delete Student.PNG
│   │       Display All Students.PNG
│   │       Main Menu.PNG
│   │       Search Student.PNG
│   │       Update Student.PNG
│   │
│   └───src
│           main.cpp
│           Student.cpp
│           Student.h
│           StudentManagement.exe
│
├───Task_4_Library_Management
│   ├───data
│   │       books.txt
│   │
│   ├───screenshots
│   │       Add Book.PNG
│   │       Display all Books.PNG
│   │       Display Available Books.PNG
│   │       Issue Book.PNG
│   │       Main Menu.PNG
│   │       Remove Book.PNG
│   │       Return Book.PNG
│   │       Search Book.PNG
│   │
│   └───src
│           Book.cpp
│           Book.h
│           Library.cpp
│           Library.h
│           LibraryManagement.exe
│           main.cpp
│
├───Task_5_Banking_Management
│   ├───data
│   │       accounts.txt
│   │
│   ├───screenshots
│   │       Create Account.PNG
│   │       Delete Account.PNG
│   │       Deposit Money.PNG
│   │       Display Account Details.PNG
│   │       Display All Accounts.PNG
│   │       Main Menu.PNG
│   │       Transaction History.PNG
│   │       Withdraw Money.PNG
│   │
│   └───src
│           Account.cpp
│           Account.h
│           Bank.cpp
│           Bank.h
│           BankingManagement.exe
│           main.cpp
│
└───Task_6_Expression_Evaluator
    ├───screenshots
    │       Evaluation.PNG
    │       Main Menu.PNG
    │
    └───src
            ExpressionEvaluator.cpp
            ExpressionEvaluator.exe
            ExpressionEvaluator.h
            main.cpp
```

## Compilation and Execution

These projects can be compiled using GCC/MinGW from the integrated terminal in VS Code.

### Prerequisites

- Visual Studio Code
- GCC/MinGW C++ compiler
- A working terminal with `g++` available in the system PATH

Verify the compiler installation:

```bash
g++ --version
```

### Task 3 — Student Management System

Open a terminal in `Task_3_Student_Management/src`:

```bash
g++ main.cpp Student.cpp -o StudentManagement.exe
```

Run on Windows:

```bat
StudentManagement.exe
```

### Task 4 — Library Management System

Open a terminal in `Task_4_Library_Management/src`:

```bash
g++ main.cpp Book.cpp Library.cpp -o LibraryManagement.exe
```

Run on Windows:

```bat
LibraryManagement.exe
```

### Task 5 — Banking Management System

Open a terminal in `Task_5_Banking_Management/src`:

```bash
g++ main.cpp Account.cpp Bank.cpp -o BankingManagement.exe
```

Run on Windows:

```bat
BankingManagement.exe
```

### Task 6 — Expression Evaluator

Open a terminal in `Task_6_Expression_Evaluator/src`:

```bash
g++ main.cpp ExpressionEvaluator.cpp -o ExpressionEvaluator.exe
```

Run on Windows:

```bat
ExpressionEvaluator.exe
```

**Note:** The commands assume that the listed source files are sufficient to build each application. If the implementation requires additional source files or libraries, include them in the compilation command. For the first three projects, ensure the application's working directory matches the relative paths used to access its data files.

## Data Persistence

The Student Management, Library Management, and Banking Management applications use text files to store application data.

- Student records: `Task_3_Student_Management/data/students.txt`
- Book records: `Task_4_Library_Management/data/books.txt`
- Banking records: `Task_5_Banking_Management/data/accounts.txt`

Use fictional sample records when demonstrating these applications. Do not publish real personal information, account details, or sensitive transaction data.

## Screenshots

The `screenshots/` directory in each project is reserved for images demonstrating its main features.

Screenshots will be added to document application execution, important operations, and validation behavior.

## Learning Outcomes

Through these projects, the following programming skills are practiced:

- Designing and implementing classes in C++
- Organizing programs into header and implementation files
- Performing file-based data persistence
- Implementing CRUD operations
- Validating user input and handling errors
- Managing state and transactions
- Evaluating arithmetic expressions with operator precedence
- Compiling and running C++ applications using GCC/MinGW

## Internship Information

- **Organization:** Auspify Technologies
- **Program:** C/C++ Development Internship
- **Project Type:** Console-based C++ applications

---

*Developed as part of the Auspify Technologies C/C++ Development Internship.*