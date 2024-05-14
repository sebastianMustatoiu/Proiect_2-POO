#include "House.h"


House::House(const std::string& street_, int yearOfConstruction_, int surface_, int price_,
	int numberOfFloors_, int gardenSurface_) : AbstractResidentialBuilding(street_, yearOfConstruction_, surface_, price_),
	numberOfFloors{ numberOfFloors_ }, gardenSurface{ gardenSurface_ }
{
	//std::cout << "Created a house\n";
}

House::~House() {}

void House::Display(std::ostream& os) const {
    //AbstractResidentialBuilding::Display();
    os << "House with " << numberOfFloors << " floors and " << gardenSurface << "m^2 of garden\n";
}

void House::calculateTotalPrice() {
    totalPrice = surface * price;
    std::cout << "Total price for the house is: " << totalPrice << std::endl;
}

void House::renovate(int price_per_m2) {
    price = price + price_per_m2;
    std::cout << "Renovation cost for this house is: " << price_per_m2 * surface << std::endl;
    calculateTotalPrice();

}

