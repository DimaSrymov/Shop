# Blyzenko Grocery Store 🛒

A simple and elegant C++ console application that simulates a shopping experience at the "Blyzenko" grocery store. It allows users to select products, apply custom discounts, and generate detailed receipts in both plain text and JSON formats.

## ✨ Features
* **Interactive Shopping Cart:** Users can add items to their cart from a predefined list of products (e.g., Bread, Milk, Eggs, Cheese, Apples).
* **Discount System:** Supports custom percentage-based discounts applied to the total order before checkout.
* **Multi-Format Receipt Generation:**
  * `receipt.json`: A structured JSON file containing item details, subtotal, discount amount, and final price.
  * `Text.txt`: A clean, human-readable text receipt formatted for printing.

## 🚀 Getting Started

### Prerequisites
* A C++11 (or higher) compatible compiler (GCC, Clang, MSVC).
* [nlohmann/json](https://github.com/nlohmann/json) library (included in the project structure).

### Building the Project
1. Clone the repository to your local machine.
2. Ensure `Header.h`, `Source.cpp`, and the `nlohmann/json` headers are properly set up in your environment.
3. Compile the code using your preferred compiler. For example, using GCC:
   ```bash
   g++ Source.cpp -o blyzenko_store -std=c++11
   
   Run the executable:

Bash
./blyzenko_store
📂 Project Structure
Source.cpp: Contains the main application loop, user input handling, and cart management.

Header.h: Defines the Product structure, the store's inventory data, and implements the functions for generating JSON and TXT receipts.

🛠️ Built With
C++ Standard Library - The core programming language.

JSON for Modern C++ (nlohmann/json) - Used for structured JSON receipt generation.
