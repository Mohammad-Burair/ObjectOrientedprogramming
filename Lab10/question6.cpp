/*
name: mohammad burair
roll number: 24k 0775
section: bcs-2c
date: 04-05-2025
description: this program demonstrates binary file i/o for inventory items.
*/

#include <iostream>
#include <fstream>
#include <cstring>

class inventory_item {
private:
    int item_id;
    char item_name[20];

public:
    inventory_item(int id = 0, const char* name = "") : item_id(id) {
        strncpy(item_name, name, 19);
        item_name[19] = '\0';
    }

    void display() const {
        std::cout << "item id: " << item_id << ", name: " << item_name << std::endl;
    }

    void save_to_file(const std::string& filename) {
        std::ofstream out_file(filename, std::ios::binary);
        if (out_file) {
            out_file.write(reinterpret_cast<const char*>(this), sizeof(*this));
        }
    }

    static inventory_item load_from_file(const std::string& filename) {
        inventory_item temp;
        std::ifstream in_file(filename, std::ios::binary);
        if (in_file) {
            in_file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
        }
        return temp;
    }
};

int main() {
    inventory_item write_item(101, "chai masala");
    inventory_item write_item2(102, "biryani masala");

    write_item.display();
    write_item2.display();

    write_item.save_to_file("inventory.dat");
    write_item2.save_to_file("inventory2.dat");

    inventory_item loaded_item = inventory_item::load_from_file("inventory.dat");
    inventory_item loaded_item2 = inventory_item::load_from_file("inventory2.dat");

    loaded_item.display();
    loaded_item2.display();

    inventory_item::load_from_file("nonexistent.dat");

    return 0;
}
