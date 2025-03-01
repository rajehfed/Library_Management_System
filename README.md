# 📚 Library Management System

## 🔹 About the Project
The **Library Management System** is a **C++ console application** designed to efficiently manage books and members in a library. It allows users to add, modify, search, and manage books and members while ensuring data persistence using file handling.

## 🚀 Features
- 📖 **Book Management**: Add, modify, search, and display books.
- 👤 **Member Management**: Register members, authenticate users, and assign admin roles.
- 🔍 **Search Functionality**: Find books by name and check availability.
- 📂 **Data Persistence**: Uses text files to store books and members data.
- 🔒 **Authentication System**: Validates users and admin access.

## 🛠️ Technologies Used
- **C++** (Object-Oriented Programming)
- **File Handling (fstream)** for data storage
- **CLion IDE** for development

## 📂 Project Structure
```
📦 LibraryManagementSystem
 ┣ 📂 src
 ┃ ┣ 📜 cLibrary.cpp
 ┃ ┣ 📜 cBook.cpp
 ┃ ┣ 📜 cMember.cpp
 ┃ ┣ 📜 cData.cpp
 ┃ ┗ 📜 main.cpp
 ┣ 📂 include
 ┃ ┣ 📜 cLibrary.h
 ┃ ┣ 📜 cBook.h
 ┃ ┣ 📜 cMember.h
 ┃ ┗ 📜 cData.h
 ┣ 📜 libraryData.txt  (Stores books data)
 ┣ 📜 membersData.txt  (Stores members data)
 ┗ 📜 README.md
```

## 🏗️ Installation & Usage
### 🔹 Prerequisites
Ensure you have the following installed:
- **C++ Compiler** (g++, clang++, or MSVC)
- **CLion IDE** (or any C++ IDE)

### 🔹 Clone the Repository
```sh
git clone https://github.com/RFedili/LibraryManagementSystem.git
cd LibraryManagementSystem
```

### 🔹 Compile & Run
If using **g++ (GCC)**:
```sh
g++ -o librarySystem src/*.cpp -I include && ./librarySystem
```

If using **CLion**:
1. Open the project in CLion.
2. Configure **CMakeLists.txt** if needed.
3. Click **Run** or use `Shift + F10`.

## 🖥️ Usage Guide
1. **Run the application**
2. **Choose an option** from the main menu
3. **Follow the prompts** to manage books or members

## 🛠️ Contributing
Contributions are welcome! Feel free to fork the repo and submit a pull request.

## 📬 Contact & Socials
📷 [Instagram](https://www.instagram.com/rajeh23f/)  
💼 [LinkedIn](https://www.linkedin.com/in/rajeh-fedili-a737ab230/)  
✖️ [X (Twitter)](https://x.com/RFedili)  

## 📜 License
This project is **open-source** and licensed under the MIT License.

