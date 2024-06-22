#include "RGBtoXYZ.h"

RGBtoXYZ converter_SRGB(RGBtoXYZ::SRGB_D65); // Initialize the converter for sRGB color space with D65 illuminant
RGBtoXYZ converter_AdobeRGB(RGBtoXYZ::AdobeRGB_D65); // Initialize the converter for Adobe RGB (1998) color space with D65 illuminant
RGBtoXYZ converter_Rec2020(RGBtoXYZ::Rec2020_D65); // Initialize the converter for Rec. 2020 color space with D65 illuminant

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  float r = 255; // Red value
  float g = 0;   // Green value
  float b = 0;   // Blue value

  float x, y, z; // Variables to hold the XYZ values

  // Convert RGB to XYZ
  converter_SRGB.convert(r, g, b, x, y, z);

  // Print the results
  Serial.print("RGB(");
  Serial.print(r);
  Serial.print(", ");
  Serial.print(g);
  Serial.print(", ");
  Serial.print(b);
  Serial.print(") -> XYZ(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.print(z);
  Serial.println(")");
  Serial.println();
  converter_AdobeRGB.convert(r, g, b, x, y, z);
  // print adobeRGB
  Serial.print("AdobeRGB(");
  Serial.print("RGB(");
  Serial.print(r);
  Serial.print(", ");
  Serial.print(g);
  Serial.print(", ");
  Serial.print(b);
  Serial.print(") -> XYZ(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.print(z);
  Serial.println(")");
  Serial.println();
  converter_Rec2020.convert(r, g, b, x, y, z);
  // print Rec2020
  Serial.print("Rec2020(");
  Serial.print("RGB(");
  Serial.print(r);
  Serial.print(", ");
  Serial.print(g);
  Serial.print(", ");
  Serial.print(b);
  Serial.print(") -> XYZ(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.print(z);
  Serial.println(")");
  Serial.println();
  

  delay(2000); // Wait for 2 seconds before the next conversion
}