# 📚 Library Management System  

A **simple yet efficient** C++ library management system that allows users to **borrow, return, and manage books** with ease. This project is built with **object-oriented programming (OOP) principles** and includes a **command-line interface** for user interaction.  
This project provides a **search functions**,  **error handling** and **user authentication system** for every roll in the system 
I make this project in one week (1 hour per day) since i steel a beginner 😅  

## 🚀 Features  

✔️ **Borrow Books** – Users can borrow books if they are available.  
✔️ **Return Books** – Return borrowed books to the system.  
✔️ **Show Borrowed Books** – View all borrowed books.  
✔️ **Manage Books** – Add, remove, or update book details.  
✔️ **File Storage** – Books data is stored in `libraryData.txt`.  
✔️ **Show Members** - Admins can Show the available members `membersData.txt`.  
✔️ **Manage Members** - Admins can modify any member.  

## 🛠 Technologies Used  

- **C++** – Core programming language  
- **OOP (Object-Oriented Programming)** – Used to structure the system  
- **File Handling (`fstream`)** – To store and retrieve book data  
- **CMake** – For project build configuration
- **CLion** - For Devolopment
- **Obsidian** - For taking notes and make the flowcharts for algorithme

## 📂 Project Structure  

```
📦 LibraryManagementSystem  
 ┣ 📂 src/                 # Source files  
 ┃ ┣ 📄 cBook.cpp          # Book class implementation  
 ┃ ┣ 📄 cLibrary.cpp       # Library system logic  
 ┃ ┣ 📄 cMember.cpp        # Member-related operations  
 ┃ ┣ 📄 cData.cpp          # Data handling (saving/loading books)  
 ┃ ┣ 📄 cUserInterface.cpp # Command-line user interface  
 ┃ ┗ 📄 main.cpp           # Entry point of the program  
 ┣ 📄 CMakeLists.txt       # CMake configuration  
 ┣ 📄 README.md            # Project documentation  
┗ 📄 libraryData.txt       # Data storage for books  
```

## 🚀 Getting Started  

### 1️⃣ Clone the Repository  
```sh
git clone https://github.com/rajehfed/LibraryManagementSystem.git
cd LibraryManagementSystem
```

### 2️⃣ Build the Project  
```sh
mkdir build && cd build
cmake ..
make
```

### 3️⃣ Run the Application  
```sh
./LibraryManagementSystem
```

## 📌 How It Works  

- 📚 **Adding Books**: Books can be added to the system via `cBook` class.  
- 🎯 **Borrowing a Book**: The system checks if a book is available before allowing it to be borrowed.  
- 🔄 **Returning a Book**: If the book exists in the borrowed list, it is returned successfully.  
- 💜 **Viewing Borrowed Books**: Displays a list of all currently borrowed books.  
- ➕ **Adding/Remove/Modifying Users** this extension is only for the admins of the system.

## 🛠 Future Improvements  

- ✅ Add an other **Rolls** to make the project more efficient.  
- ✅ Make **GUI** for better experiance.  

## 📌 Contributing  

Contributions are **welcome!** If you want to improve the project, feel free to fork the repo and submit a pull request.  

## 📄 License  

This project is **open-source** and available under the **MIT License**.  

