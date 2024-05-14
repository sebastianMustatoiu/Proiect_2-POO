#ifndef APARTMENT_H
#define APARTMENT_H

#include "AbstractResidentialBuilding.h"
#include "ApartmentType.h"


class Apartment : public AbstractResidentialBuilding {
private:
	int numberOfRooms;
	int* roomSizes;
	ApartmentType apartmentType;

public:

	void Display(std::ostream& os) const override;

	void calculateTotalPrice() override;

	//constructor
	Apartment(const std::string& street_ = "", int yearOfConstruction_ = 0, int surface_ = -1, int price_ = -1, int numberOfRooms_ = -1,
	ApartmentType apartmentType_ = ApartmentType::AT_NONE, const int* roomSizes_ = nullptr);

	//cc
	Apartment(const Apartment& other);

	// operator= atribuire prin copiere
	Apartment& operator=(const Apartment& other);

	// constructor de mutare
	Apartment(Apartment&& other);

	// operator= atribuire prin mutare
	Apartment& operator=(Apartment&& other);

	//destructor
	~Apartment() override;

	void renovate(int price_per_m2) override;

};

#endif