#ifndef LOADERPARAMETERS_H
#define LOADERPARAMETERS_H
#include <string>
class LoaderParameters
{
public:
    LoaderParameters(int xPosition, int yPosition, int width, int height, std::string textureId)
    {
        this->xPosition = xPosition;
        this->yPosition = yPosition;
        this->width = width;
        this->height = height;
        this->textureId = textureId;
    }
    int getXPosition() const
    {
        return xPosition;
    }
    int getYPosition() const
    {
        return yPosition;
    }
    int getWidth() const
    {
        return width;
    }
    int getHeight() const
    {
        return height;
    }
    std::string getTextureId() const
    {
        return textureId;
    }

private:
    int xPosition;
    int yPosition;
    int width;
    int height;
    std::string textureId;
};
#endif // LOADERPARAMETERS_H
