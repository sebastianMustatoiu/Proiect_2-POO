#include "AbstractResidentialBuilding.h"

int AbstractResidentialBuilding::idGenerator = 1;

AbstractResidentialBuilding::AbstractResidentialBuilding(const std::string& street_, int yearOfConstruction_, int surface_, int price_)
    : street{ street_ }, yearOfConstruction{ yearOfConstruction_ }, surface{ surface_ }, price{ price_ }, id{ idGenerator++ } {}

/*void AbstractResidentialBuilding::Display() const {
    std::cout << "Building ID: " << id << std::endl;
    std::cout << "Street: " << street << std::endl;
    std::cout << "Year of Construction: " << yearOfConstruction << std::endl;
    std::cout << "Surface Area: " << surface << " m^2\n";
    std::cout << "Price per m^2: " << price << std::endl;
    //std::cout << "Total Price: " << totalPrice << std::endl;
}*/

void AbstractResidentialBuilding::setStreet(const std::string& newStreet) {
    street = newStreet;
}

std::string AbstractResidentialBuilding::getStreet() const {
    return street;
}

void AbstractResidentialBuilding::setPrice( int newPrice) {
    price = newPrice;
}

int AbstractResidentialBuilding::getPrice() const {
    return price;
}

AbstractResidentialBuilding::~AbstractResidentialBuilding() = default;

std::ostream& operator<<(std::ostream& os, const AbstractResidentialBuilding& building) {
    os << "Building ID: " << building.id << std::endl;
    os << "Street: " << building.street << std::endl;
    os << "Year of Construction: " << building.yearOfConstruction << std::endl;
    os << "Surface Area: " << building.surface << " m^2\n";
    os << "Price per m^2: " << building.price << std::endl;
    //std::cout << "Total Price: " << totalPrice << std::endl;
    building.Display(os);
    return os;
}