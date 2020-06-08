#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <math.h>
class Vector2D
{
public:
    float getX()
    {
        return this->x;
    }
    float getY()
    {
        return this->y;
    }
    void setX(float xPosition)
    {
        this->x = xPosition;
    }
    void setY(float yPosition)
    {
        this->y = yPosition;
    }
    float length()
    {
        return sqrt((this->x * this->x) + (this->y * this->y));
    }
    Vector2D(float xPosition, float yPosition)
    {
        this->x = xPosition;
        this->y = yPosition;
    }
    Vector2D operator+(const Vector2D &vector2d) const
    {
        return Vector2D((this->x + vector2d.x), (this->y + vector2d.y));
    }
    friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }
    Vector2D operator*(float scalar)
    {
        return Vector2D((this->x * scalar), (this->y * scalar));
    }
    Vector2D &operator*=(float scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }
    Vector2D operator-(const Vector2D &vector2d) const
    {
        return Vector2D((this->x - vector2d.x), (this->y - vector2d.y));
    }
    friend Vector2D &operator-=(Vector2D &vector2d1, const Vector2D &vector2d2)
    {
        vector2d1.x -= vector2d2.x;
        vector2d1.y -= vector2d2.y;
        return vector2d1;
    }
    Vector2D operator/(float scalar)
    {
        return Vector2D((this->x / scalar), (this->y / scalar));
    }
    Vector2D &operator/=(float scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    void normalize()
    {
        float length = this->length();
        if (length > 0)
        {
            (*this) *= 1 / 1;
        }
    }
    //  virtual ~Vector2D();

protected:
private:
    float x;
    float y;
};
#endif // VECTOR2D_H
