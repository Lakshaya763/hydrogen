# ⚙️ Hydrogen - A Minimal Toy Compiler in C++

Hydrogen is a lightweight expression compiler designed to parse and evaluate a tiny programming language. Built from scratch in modern C++20, it features a custom memory allocator, lexer, parser, and basic code generation.

---

## 🚀 Features

- 🔤 Tokenizer (Lexer) with support for single-line and multi-line comments
- 🌳 Recursive Descent Parser with AST construction
- 🧠 Expression evaluation with precedence rules
- 🔠 Statement parsing (`let`, `exit`, empty statements)
- 🧹 Arena Allocator for efficient memory management
- 🛑 Basic error reporting with position tracking

---

## 📁 Folder Structure

hydrogen/
├── CMakeLists.txt
├── test.hy # Sample input
├── src/
│ ├── arena.hpp
│ ├── generation.hpp
│ ├── main.cpp
│ ├── parser.hpp
│ ├── tokenization.hpp
├── cmake-build-* # Auto-generated build folders (WSL)

---

## 🔧 Build Instructions

### 📌 Requirements:
- C++20 compiler (e.g., `g++`, `clang++`)
- [CMake](https://cmake.org/) 3.15+

### 🧱 Build (Linux/macOS/WSL)

bash
mkdir build && cd build
cmake ..
cmake --build .
./hydrogen ../test.hy

### Direct Run
g++ -std=c++20 src/main.cpp -o hydrogen
./hydrogen test.hy

### Sample test.hy
//single line comment
let x = 5 + 3 * 2;
exit(x);
