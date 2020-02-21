#ifndef __HOUSE_BUILDER_H__
#define __HOUSE_BUILDER_H__

#include<iostream>
#include<string>

// Product
class HOUSE
{
private:
	std::string m_description;
public:
	HOUSE(const std::string &houseType) { m_description = "Type House: " + houseType; }
	void setWindow(const std::string &window) { m_description += "\n Window: " + window; }
	void setDoor(const std::string &door) { m_description += "\n Door: " + door; }
	void setBathroom(const std::string &bathroom) { m_description += "\n Bathroom: " + bathroom; }
	void setKitchen(const std::string &kitchen) { m_description += "\n Kitchen: " + kitchen; }
	void setFloor(const std::string &floor) { m_description += "\n Floor: " + floor; }

	std::string getDescription() const { return m_description; }
};
// Builder interface
class HOUSE_BUILDER
{
protected:
	HOUSE* m_result;
public:
	virtual void buildWindow() = 0;
	virtual void buildDoor() = 0;
	virtual void buildBathroom() = 0;
	virtual void buildKitchen() = 0;
	virtual void buildFloor() = 0;

	HOUSE* getResult() const { return m_result; }
};
// Concrete Builder
class LAVISH_HOUSE_BUILDER : public HOUSE_BUILDER
{
public:
	LAVISH_HOUSE_BUILDER() { m_result = new HOUSE("Lavish"); }
	virtual void buildWindow() { m_result->setWindow("Gold Window"); }
	virtual void buildDoor() { m_result->setDoor("Inox Door"); }
	virtual void buildBathroom() { m_result->setBathroom("Royal Bathroom"); }
	virtual void buildKitchen() { m_result->setKitchen("5-star Kitchen"); }
	virtual void buildFloor() { m_result->setFloor("Wooden Floor"); }
};
class NORMAL_HOUSE_BUILDER : public HOUSE_BUILDER
{
public:
	NORMAL_HOUSE_BUILDER() { m_result = new HOUSE("Normal"); }
	virtual void buildWindow() { m_result->setWindow("None"); }
	virtual void buildDoor() { m_result->setDoor("Wooden Door"); }
	virtual void buildBathroom() { m_result->setBathroom("Ouside Bathroom"); }
	virtual void buildKitchen() { m_result->setKitchen("1-star Kitchen"); }
	virtual void buildFloor() { m_result->setFloor("Xi-mang Floor"); }
};
// Director
class DIRECTOR
{
private:
	HOUSE_BUILDER* m_builder;
public:
	void setBuilder(HOUSE_BUILDER* builder) { m_builder = builder; }
	void construct()
	{
		m_builder->buildWindow();
		m_builder->buildDoor();
		m_builder->buildBathroom();
		m_builder->buildKitchen();
		m_builder->buildFloor();
	}
};

#endif