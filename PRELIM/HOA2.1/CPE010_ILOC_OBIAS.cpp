#include <iostream>
#include <string>

class Product {
protected:
    std::string itemName;
    double itemPrice;
    int itemCount;

public:
    Product(std::string name, double price, int count)
        : itemName(name), itemPrice(price), itemCount(count) {}

    virtual ~Product() {}

    double getAmount() const {
        return itemPrice * itemCount;
    }

    std::string getName() const {
        return itemName;
    }

    virtual std::string getType() const = 0;

    void showInfo() const {
        std::cout << getType() << " : " << itemName
                  << " | Price: " << itemPrice
                  << " | Count: " << itemCount
                  << " | Total: " << getAmount()
                  << std::endl;
    }
};

class Drink : public Product {
public:
    Drink(std::string name, double price, int count)
        : Product(name, price, count) {
        std::cout << "Added drink: " << itemName << std::endl;
    }

    ~Drink() override {
        std::cout << "Removing drink: " << itemName << std::endl;
    }

    std::string getType() const override {
        return "Drink";
    }
};

class Snack : public Product {
public:
    Snack(std::string name, double price, int count)
        : Product(name, price, count) {
        std::cout << "Added snack: " << itemName << std::endl;
    }

    ~Snack() override {
        std::cout << "Removing snack: " << itemName << std::endl;
    }

    std::string getType() const override {
        return "Snack";
    }
};

double computeTotal(Product* products[], int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += products[i]->getAmount();
    }

    return sum;
}

int main() {
    Product* storeItems[4];

    storeItems[0] = new Drink("Cola", 25, 3);
    storeItems[1] = new Drink("Juice", 30, 2);
    storeItems[2] = new Snack("Chips", 18, 5);
    storeItems[3] = new Snack("Cookies", 20, 4);

    int totalItems = 4;

    std::cout << "\nStore Items\n\n";

    for (int i = 0; i < totalItems; i++) {
        storeItems[i]->showInfo();
    }

    std::cout << "\nOverall Total: " << computeTotal(storeItems, totalItems) << std::endl;

    std::cout << "\nDeleting Cookies...\n";

    for (int i = 0; i < totalItems; i++) {
        if (storeItems[i]->getName() == "Cookies") {
            delete storeItems[i];
            storeItems[i] = storeItems[totalItems - 1];
            totalItems--;
            break;
        }
    }

    std::cout << "\nUpdated List\n\n";

    for (int i = 0; i < totalItems; i++) {
        storeItems[i]->showInfo();
    }

    std::cout << "\nNew Total: " << computeTotal(storeItems, totalItems) << std::endl;

    for (int i = 0; i < totalItems; i++) {
        delete storeItems[i];
    }

    return 0;
}