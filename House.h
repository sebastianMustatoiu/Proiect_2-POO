#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "AbstractResidentialBuilding.h"

class House : public AbstractResidentialBuilding {
private:
	int numberOfFloors;
	int gardenSurface;

public:
	House(const std::string& street_ = "", int yearOfConstruction_ = 0, int surface_ = -1, int price_ = -1,
		int numberOfFloors_ = -1, int gardenSurface_ = -1);

	~House() override;

	void Display(std::ostream& os) const override;

	void calculateTotalPrice() override;

	void renovate(int price_per_m2) override;

private:
};





#endif