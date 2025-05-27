# 🧾 Employee Management System (C++ with JSON)

This is a console-based Employee Management System written in C++ with persistent storage using the [nlohmann/json](https://github.com/nlohmann/json) library.

## ✅ Features

- Add employee
- Show all employees
- Search employee by ID
- Update employee by ID
- Delete specific employee
- Delete all employee records
- Persistent data storage using `employees.json`

---

## 📦 Requirements

- C++ compiler (e.g., `g++`)
- `nlohmann/json` single-header file library

Download `json.hpp` from the [GitHub repo](https://github.com/nlohmann/json/releases) and place it in your project folder.

---

## 🛠️ Setup & Compile

1. **Clone the repository** or copy the `.cpp` and `json.hpp` files.
2. Open terminal in the project directory.
3. Compile the project:

```bash
g++ employee_manager.cpp -o employee_manager
```

4. Run the program:

```bash
./employee_manager
```

---

## 📂 File Structure

```
.
├── employee_manager.cpp   # Main C++ source code
├── json.hpp               # JSON library (you add this manually)
└── employees.json         # Auto-generated file with saved data
```

---

## 💡 How it Works

- On start, the system loads all employee data from `employees.json`.
- You interact with the system through a numeric menu.
- All changes are automatically saved to the JSON file.

---

## 🔐 Example Actions

- Add new employees and their details
- View a list of all employee records
- Update or remove employees by ID
- Clear all employee data from the system

---

