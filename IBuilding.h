#ifndef IBUILDING_H
#define IBUILDING_H

class IBuilding {
public:
	//virtual void Display() const = 0;
	virtual void calculateTotalPrice()  = 0;

	virtual ~IBuilding() = 0; //destrucotr virtual

private:
};

#endif
