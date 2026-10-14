#pragma once
#include <string>


class vector2 {
private:
    double x;
    double y;
    char* name;
public:
    vector2();
    vector2(double x, double y, const char* name);
    vector2(const vector2& other);

    ~vector2();

    double getX() const;
    double getY() const;
    char* getName() const;

    void setX(double x);
    void setY(double y);
    void setName(const char* name);
    std::string to_string() const;

    vector2 operator +(const vector2& other);
    vector2 operator -(const vector2& other);
    vector2& operator =(const vector2& other);
    vector2& operator =(vector2&& other) noexcept;
    void operator +=(const vector2& other);
    void operator -=(const vector2& other);
    friend vector2 operator *(const vector2& v1, const vector2& v2);
    friend vector2 operator /(const vector2& v1, const vector2& v2);
};
vector2 operator *(const vector2& v1, const vector2& v2);
vector2 operator /(const vector2& v1, const vector2& v2);
std::ostream& operator << (std::ostream& out, const vector2& v);