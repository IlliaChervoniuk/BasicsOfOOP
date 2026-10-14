#include "vector2.h"
#include <cstring>
#include <iostream>

vector2::vector2() : x(0.0), y(0.0), name(nullptr) {}

vector2::vector2(double x, double y, const char* name) : x(x), y(y), name(nullptr) {
    if (name != nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

vector2::vector2(const vector2& other) : x(other.x), y(other.y), name(nullptr) {
    if (other.name != nullptr) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
}

vector2::~vector2() {
    if (name != nullptr) {
        delete[] name;
    }
}

double vector2::getX() const {
    return x;
}

double vector2::getY() const {
    return y;
}

char* vector2::getName() const {
    return name;
}

void vector2::setX(double x) {
    this->x = x;
}

void vector2::setY(double y) {
    this->y = y;
}

void vector2::setName(const char* name) {
    if (this->name != nullptr) {
        delete[] this->name;
        this->name = nullptr;
    }
    if (name != nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

std::string vector2::to_string() {
    std::string res = "";
    if (name != nullptr) {
        res += "Vector '" + std::string(name) + "': ";
    } else {
        res += "Vector: ";
    }
    res += "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    return res;
}


vector2 vector2::operator +(const vector2& other) {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "+");
		strcpy(new_name + len1 + 1, other.name);
	}
	return vector2(
		this->x + other.x,
		this->y + other.y,
		new_name);
}

vector2 vector2::operator -(const vector2 &other) {
    char *new_name = NULL;
    if (this->name != NULL && other.name != NULL) {
        size_t len1 = strlen(this->name);
        size_t len = len1 + strlen(other.name) + 2;
        new_name = new char[len];
        strcpy(new_name, this->name);
        strcpy(new_name + len1, +"-");
        strcpy(new_name + len1 + 1, other.name);
    }
    return vector2(
        this->x - other.x,
        this->y - other.y, new_name);
}

vector2& vector2::operator =(const vector2& other) {
	this->x = other.x;
	this->y = other.y;
	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
		std::cout << "Copy assignment: copy from " << (void*)other.name << " to "
		 	<< (void*)(this->name) << std::endl;
	}
	else {
		this->name = NULL;
	}
	return *this;
}

vector2& vector2::operator =(vector2&& other) noexcept {
	this->x = other.y;
	this->x = other.y;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move assignment: take from " << (void*)this->name << std::endl;
	return *this;
}