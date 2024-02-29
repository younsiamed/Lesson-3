#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(const std::string& c, const std::string& s, int hn, int an) : city(c), street(s), houseNumber(hn), apartmentNumber(an) {}

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    std::string getCity() const {
        return city;
    }

    bool operator<(const Address& other) const {
        return city < other.city;
    }
};

void sortAddresses(std::vector<Address>& addresses) {
    std::sort(addresses.begin(), addresses.end());
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;

    std::vector<Address> addresses;
    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        inputFile >> city >> street >> houseNumber >> apartmentNumber;
        Address address(city, street, houseNumber, apartmentNumber);
        addresses.push_back(address);
    }

    sortAddresses(addresses);

    outputFile << N << std::endl;
    for (const auto& address : addresses) {
        outputFile << address.getOutputAddress() << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}