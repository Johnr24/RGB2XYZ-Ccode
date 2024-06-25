#include "RGBtoXYZ.h"

RGBtoXYZ::RGBtoXYZ(ColorSpace space) : _colorSpace(space) {}

void RGBtoXYZ::convert(float r, float g, float b, float &x, float &y, float &z) {
  rgbToLinear(r, g, b);
  linearToXYZ(r, g, b, x, y, z);
}

void RGBtoXYZ::rgbToLinear(float &r, float &g, float &b) {
  // Assuming sRGB
  auto sRGBToLinear = [](float color) -> float {
    if (color <= 0.04045) {
      return color / 12.92;
    } else {
      return pow((color + 0.055) / 1.055, 2.4);
    }
  };

  r = sRGBToLinear(r / 255.0);
  g = sRGBToLinear(g / 255.0);
  b = sRGBToLinear(b / 255.0);
}

void RGBtoXYZ::linearToXYZ(float r, float g, float b, float &x, float &y, float &z) {
  // Select color space tristimulus values
  float matrix[3][3];
  switch (_colorSpace) {
    case SRGB_D65:
      matrix[0][0] = 0.4124564; matrix[0][1] = 0.3575761; matrix[0][2] = 0.1804375;
      matrix[1][0] = 0.2126729; matrix[1][1] = 0.7151522; matrix[1][2] = 0.0721750;
      matrix[2][0] = 0.0193339; matrix[2][1] = 0.1191920; matrix[2][2] = 0.9503041;
      break;
    case AdobeRGB_D65:
      // Example Adobe RGB (1998) with D65 illuminant coefficients
      matrix[0][0] = 0.5767309; matrix[0][1] = 0.1855540; matrix[0][2] = 0.1881852;
      matrix[1][0] = 0.2973769; matrix[1][1] = 0.6273491; matrix[1][2] = 0.0752741;
      matrix[2][0] = 0.0270343; matrix[2][1] = 0.0706872; matrix[2][2] = 0.9911085;
      break;
    case Rec2020_D65:
      // Example Rec. 2020 with D65 illuminant coefficients
      matrix[0][0] = 0.0708; matrix[0][1] = 0.292; matrix[0][2] = 0.0;
      matrix[1][0] = 0.17; matrix[1][1] = 0.797; matrix[1][2] = 0.33;
      matrix[2][0] = 0.131; matrix[2][1] = 0.046; matrix[2][2] = 0.823;
      break;
    case D65_FCOBtape:
      // Example D65 Cob Tape with D65 illuminant coefficients
      matrix[0][0] = 0.8951; matrix[0][1] = 0.2664; matrix[0][2] = -0.1614;
      matrix[1][0] = -0.7502; matrix[1][1] = 1.7135; matrix[1][2] = 0.0367;
      matrix[2][0] = 0.131; matrix[2][1] = 0.046; matrix[2][2] = 0.823;
      break;
  }

  // Apply the matrix transformation
    x = r * matrix[0][0] + g * matrix[0][1] + b * matrix[0][2];
    y = r * matrix[1][0] + g * matrix[1][1] + b * matrix[1][2];
    z = r * matrix[2][0] + g * matrix[2][1] + b * matrix[2][2];
}
