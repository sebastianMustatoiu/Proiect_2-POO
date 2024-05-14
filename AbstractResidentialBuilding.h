#ifndef ABSTRACTRESIDENTIALBUILDING_H
#define ABSTRACTRESIDENTIALBUILDING_H

#include <string>
#include <iostream>
#include "IBuilding.h"

class AbstractResidentialBuilding : public IBuilding{
private:
    static int idGenerator;
protected:
    std::string street;
    const int id;
    int yearOfConstruction;
    int surface; //m^2
    int price; //per m^2
    int totalPrice;
public:
    AbstractResidentialBuilding(const std::string& street_ = "", int yearOfConstruction_ = 0, int surface_ = -1, int price_ = -1);

    virtual void Display(std::ostream& os) const = 0;

    virtual void calculateTotalPrice() = 0;

    virtual  ~AbstractResidentialBuilding() = 0;

    virtual void renovate(int price_per_m2) = 0;

    void setStreet(const std::string& newStreet);
    std::string getStreet() const;

    void setPrice(int newPrice);
    int getPrice() const;

    friend std::ostream& operator<<(std::ostream& os, const AbstractResidentialBuilding& building);


};

#endif
