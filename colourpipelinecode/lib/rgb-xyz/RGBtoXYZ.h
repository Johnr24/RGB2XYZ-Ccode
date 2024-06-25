// Updated RGBtoXYZ.h
#ifndef RGBtoXYZ_h
#define RGBtoXYZ_h

#include "Arduino.h"

class RGBtoXYZ {
  public:
    enum ColorSpace { SRGB_D65, AdobeRGB_D65, Rec2020_D65, D65_FCOBtape};
    RGBtoXYZ(ColorSpace space = SRGB_D65);
    void convert(float r, float g, float b, float &x, float &y, float &z);
  private:
    ColorSpace _colorSpace;
    float _r, _g, _b;
    //void rgbToLinear(float &r, float &g, float &b); not currently used as no gamma correction is applied
    void linearToXYZ(float r, float g, float b, float &x, float &y, float &z);
};
class XYZtoRGB {
  public:
    enum ColorSpace { SRGB_D65, AdobeRGB_D65, Rec2020_D65, D65_FCOBtape};
    XYZtoRGB(ColorSpace space = SRGB_D65);
    void convert(float x, float y, float z, float &r, float &g, float &b);
  private:
    ColorSpace _colorSpace;
    float _x, _y, _z;
    void linearToRGB(float x, float y, float z, float &r, float &g, float &b);
};

#endif