#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int house_number;
    int apartment_number;

public:
    Address(const std::string& city, const std::string& street, int house_number, int apartment_number)
        : city(city), street(street), house_number(house_number), apartment_number(apartment_number) {}

    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream input_file("in.txt");
    std::ofstream output_file("out.txt");

    if (!input_file.is_open() || !output_file.is_open()) {
        std::cerr << "Failed to open files." << std::endl;
        return 1;
    }

    int num_addresses;
    input_file >> num_addresses;
    Address** addresses = new Address * [num_addresses];

    for (int i = 0; i < num_addresses; ++i) {
        std::string city, street;
        int house_number, apartment_number;
        input_file >> city >> street >> house_number >> apartment_number;
        addresses[i] = new Address(city, street, house_number, apartment_number);
    }

    output_file << num_addresses << std::endl;
    for (int i = num_addresses - 1; i >= 0; --i) {
        output_file << addresses[i]->get_output_address() << std::endl;
    }

    for (int i = 0; i < num_addresses; ++i) {
        delete addresses[i];
    }
    delete[] addresses;

    input_file.close();
    output_file.close();

    return 0;
}