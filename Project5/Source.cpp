#include "Header.h"

using namespace std;

int main() {
    vector<Product> cart;
    int choice = -1;

    cout << "Welcome to Blyzenko!" << endl;

    while (true) {
        showinfo();
        cout << "Choose a product number: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice > 0 && choice <= (int)storeProducts.size()) {
            cart.push_back(storeProducts[choice - 1]);
            cout << ">> Added: " << storeProducts[choice - 1].name << endl;
        }
        else {
            cout << ">> Invalid choice!" << endl;
        }
    }

    if (!cart.empty()) {
        double discount = 0;
        cout << "\nEnter discount percentage (0 if no discount): ";
        cin >> discount;

        if (discount < 0 || discount > 100) {
            cout << "Invalid discount! Setting to 0%." << endl;
            discount = 0;
        }

        cout << "\nProcessing your receipt..." << endl;
        saveJsonReceipt(cart, discount);
        saveTxtReceipt(cart, discount);
        cout << "\nDone! Have a nice day!" << endl;
    }
    else {
        cout << "Cart is empty. Goodbye!" << endl;
    }

    return 0;
}