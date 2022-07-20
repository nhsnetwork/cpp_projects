#pragma once

#include <string>

class Animal {
private:
	float height = 0;
	float weight = 0;
	bool isNocturnal = false;
public:
	void setHeight(float h) { height = h; }
	float getHeight() {	return height;	}
	void setWeight(float w) { weight = w;	}
	float getWeight() {	return weight; }
	void setNocturnal(bool n) { isNocturnal = n; }
	bool ifNocturnal() { return isNocturnal; }
	virtual std::string getClassName() { return "Animal"; }
};

class Tiger : public Animal {
private:
	short num_of_teeth = 12;
	std::string type = "";
public:
	void set_num_of_teeth(short n) { num_of_teeth = n; }
	std::string getClassName() { return "Tiger"; }
	std::string getType() {	return type; }

	Tiger(const std::string t) {
		type = t;
		this->setNocturnal(true);
	}
	/*
	//Constructor can be initialized in line in the following way
	Tiger(const std::string t) : type(t) {
		this->setNocturnal(true);
	}
	*/
};

void test_class_features() {


	// ************************** Testing Class Features ************************** //
	Tiger t("Royal Bengal");

	//Testing methods from overridden class
	std::cout << t.getClassName() << std::endl;
	//Testing method from sub class
	std::cout << t.getType() << std::endl;
	//Testing if the inherited member is set properly when sub class object is constructed
	std::cout << std::boolalpha << t.ifNocturnal() << std::endl;

	//Testing polymorphism
	Animal& a = t;
	std::cout << a.getClassName() << std::endl;

	//Testing instantiation of objects at STACK
	Tiger* p;
	{
		Tiger c("Cheetah");
		p = &c;
	} // Tiger pointer p should no longer have the address of c since it is out of scope
	  // This is because the stack is cleared for the scoped object c
	  // Verify this by observing the memory of p while in debug mode at this point


	//Testing instantiation of objects at HEAP
	Tiger* p1;
	{
		Tiger* c1 = new Tiger("Cheetah");
		p1 = c1;
		delete c1;
	} // Tiger pointer p1 should still hold the value of memory address of c1.
	  // This is because c1 is pointed to object that is created in the heap.
	  // Observe by debugging and watch for the p1 (while commenting "delete c1")
	  // To prevent memory leak, c1 needs to be destroyed manually.


	// **************************  Templates ************************** //
}

