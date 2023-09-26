#ifndef ISOILMOITURE_H
#define ISOILMOITURE_H

class ISoilMoiture
{
private:
    /* data */
public:
    ~ISoilMoiture(){} = default;
    virtual void init() = 0;
    virtual float moisturePourcentage() = 0;

};

#endif