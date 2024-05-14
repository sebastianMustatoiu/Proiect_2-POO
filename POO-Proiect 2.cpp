#include <iostream>
#include <vector>
#include "Apartment.h"
#include "House.h"
#include "ApartmentType.h"

int main() {
    /*// Crearea unui apartament
    int roomSizes[] = { 20, 30, 25 };
    Apartment myApartment("Main Street", 2000, 100, 2000, 3, AT_MULTIPLE_ROOM, roomSizes);

    // Afisarea detaliilor apartamentului
    std::cout << "Apartment details:" << std::endl;
    myApartment.Display();
    myApartment.calculateTotalPrice();
    std::cout << std::endl;

    // Crearea unei case
    House myHouse("Second Street", 1995, 200, 1500, 2, 50);

    // Afisarea detaliilor casei
    std::cout << "House details:" << std::endl;
    myHouse.Display();
    myHouse.calculateTotalPrice();
    std::cout << std::endl;*/

    std::vector<AbstractResidentialBuilding*> buildings;

    int roomSizes[] = { 20, 30, 25 };
    buildings.push_back(new Apartment("Main Street", 2000, 100, 2000, 3, AT_MULTIPLE_ROOM, roomSizes));

    buildings.push_back(new House("Second Street", 1995, 200, 1500, 2, 50));

    for (const auto& building : buildings) {
        std::cout << *building;
        building->calculateTotalPrice();
        std::cout << "============================\n";  
    }

    std::cout << "\nLet's renovate the buildings!\n\n";
    for (auto& building : buildings) {
        building->renovate(100);
    }

    for (auto& building : buildings) {
        delete building;
    }

    return 0;
}
