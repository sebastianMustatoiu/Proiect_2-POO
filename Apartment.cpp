#include "Apartment.h"
#include <iostream>

//constructor
Apartment::Apartment(const std::string& street_, int yearOfConstruction_, int surface_, int price_, int numberOfRooms_,
    ApartmentType apartmentType_, const int* roomSizes_) : AbstractResidentialBuilding(street_, yearOfConstruction_, surface_, price_),
    numberOfRooms{ numberOfRooms_ }, apartmentType{ apartmentType_ } {
    if (roomSizes_) {
        roomSizes = new int[numberOfRooms_];
        for (int i = 0; i < numberOfRooms_; i++) {
            roomSizes[i] = roomSizes_[i];
        }
    }
    else {
        roomSizes = nullptr;
    }
}

//destructor
Apartment::~Apartment() {
    delete[] roomSizes;
}

//cc
Apartment::Apartment(const Apartment& other) : AbstractResidentialBuilding(other), 
numberOfRooms{ other.numberOfRooms }, apartmentType{ other.apartmentType }, roomSizes{ nullptr } {
    if (numberOfRooms != 0) {
        roomSizes = new int[numberOfRooms];
        for (int i = 0; i < numberOfRooms; i++) {
            roomSizes[i] = other.roomSizes[i];
        }
    }
    
}


// operator= atribuire prin copiere
Apartment& Apartment::operator=(const Apartment& other) {
    if (this != &other) {
        numberOfRooms = other.numberOfRooms;
        if (numberOfRooms != 0) {
            delete[] roomSizes;
            roomSizes = new int[numberOfRooms];
            for (int i = 0; i < numberOfRooms; i++) {
                roomSizes[i] = other.roomSizes[i];
            }
        }
    }
    return *this;
}

// constructor de mutare
Apartment::Apartment(Apartment&& other) : AbstractResidentialBuilding(other), numberOfRooms{ other.numberOfRooms }, roomSizes{ other.roomSizes } {
    other.numberOfRooms = -1;
    other.roomSizes = nullptr;
}

// operator= atribuire prin mutare
Apartment& Apartment::operator=(Apartment&& other) {
    if (this != &other) {
        numberOfRooms = other.numberOfRooms;
        roomSizes = other.roomSizes;
        other.numberOfRooms = -1;
        other.roomSizes = nullptr;

    }

    return *this;
}

void Apartment::Display(std::ostream& os) const {
    //AbstractResidentialBuilding::Display();
    os << "Apartment with " << numberOfRooms << " rooms.\n";
}

void Apartment::calculateTotalPrice() {
    totalPrice = surface * price;
    std::cout << "Total price for the apartment is: " << totalPrice << std::endl;
}

void Apartment::renovate(int price_per_m2) {
    price = price + price_per_m2;
    std::cout << "Renovation cost for this apartment is: " << price_per_m2 * surface << std::endl;
    calculateTotalPrice();

}
