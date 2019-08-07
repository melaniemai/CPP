/*    @file fractal.cpp
      @author Melanie Mai
      @date 7/18/19

            @description
*/
#include <iostream>
#include <stdlib.h>
#include <sstream>
// Use your myComplex class!


// Import and setup the CImg library
#define cimg_display 0
#include "CImg.h"
using namespace cimg_library;

using namespace std;

#include "myComplex.h"
// The fn we are creating the fractal of.
// f(x) = x^3 - 1
// Const reference for speed.
myComplex f(myComplex& a) {
    return a*a*a - 1;
    //return (a*a*a + 1)/(a*a);
}

// The derivitive of the above function.
// f(x) = 3 * x^2
// Const reference for speed.
myComplex df(myComplex& a){
    return a*a*3.0;
    //return (a*a*a - 2 )/(a*a*a);
}

// Global variable so we can see what the resulting point was.
// Useful ONLY if you need to know the root for colorig purposes.
// Alternatively newton could send back a struct.
static myComplex prev_one;

// Performs newton's estimation given a Complex starting point,
// maximum itterations, and a delta limit for how close it needs to
// be until it stops.
// Assumes f(Complex) and df(Complex) are defined.
unsigned newton(myComplex cur, unsigned int max_steps, double limit){
  prev_one = myComplex(1000,1000);
  unsigned steps = 0;
  while((cur - prev_one).getMagnitude() > limit && steps < max_steps){
    steps++;
    prev_one = cur;
    cur =  cur - f(cur)/df(cur);
    //cur = cur.subtraction(f(cur).division(df(cur)));
  }
  return steps;
}

// Convenience function to set the red, green, and blue channels
// at a given pixel location in the image.
void setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue, cil::CImg<unsigned char>& image){
  *(image.data(x,y,0,0)) = red;
  *(image.data(x,y,0,1)) = green;
  *(image.data(x,y,0,2)) = blue;
}

int main(int argc, char* argv[]){

  // We accept 3 command-line paramters, filename, x and y
  // If no paramters are given, it will save a 800x600 image
  // to image.png

  string filename = "c:\\temp\\fractal.png";
  if(argc >= 2){
    filename = argv[1];
  }

  // Default Image size
  unsigned int width  = 400;
  unsigned int height = 400;

  if(argc >= 3){  // Width was given
    width = static_cast<unsigned>(atoi(argv[2]));
  }
  if(argc >= 4){  // Height was given
    height = static_cast<unsigned>(atoi(argv[3]));
  }

  // Box bounds
  double urr = 100.0;
  double uri = 100.0;

  double llr = -100.0;
  double lli = -100.0;

  double dx = (urr-llr) / static_cast<double>(width);
  double dy = (uri-lli) / static_cast<double>(height);

  cil::CImg<unsigned char> image(width,height,1, 3, 255);
  for(int x = 0; x < width; x++){
    for(int y = 0; y < height; y++){
      // Calculate where in the complex plane this point is
      double real = static_cast<double>(x) * dx + llr;
      double imaginary = static_cast<double>(y) * dy * -1 + uri;

      // See how many steps it takes to converge at that point.
      unsigned steps = newton(myComplex(real,imaginary), 200, 0.00001);

      // Set the pixels the manual way ****************************
      // Grayscale

      //*(image.data(x,y,0,0)) = steps * 7 % 256; // red channel
      //*(image.data(x,y,0,1)) = steps * 7 % 256; // green channel
      //*(image.data(x,y,0,2)) = steps * 7 % 256; // blue channel

      // 3 Color - One for each root
      // Defaults
      *(image.data(x,y,0,0)) = 0; // red channel
      *(image.data(x,y,0,1)) = 0; // green channel
      *(image.data(x,y,0,2)) = 0; // blue channel
      if((prev_one - myComplex(-0.5, 0.866)).getMagnitude() < 0.5){
        // Red
        *(image.data(x,y,0,0)) = steps * 10 % 256; // red channel
      }else if((prev_one - myComplex(1, 0)).getMagnitude() < 1){
        // Green
        *(image.data(x,y,0,1)) = steps / 8 % 256; // green channel
      }else{
        // Blue
        *(image.data(x,y,0,2)) = steps *2 + 8 % 256; // blue channel
      }


      // New pixel setting function ******************************
      // Grayscale
      //unsigned char brightness = steps * 7 % 256;
     // setRGB(x, y, brightness, brightness, brightness, image);

      // 3 Color - One for each root
     /* unsigned char brightness = steps * 7 % 256;
      if((prev_one - myComplex(-0.5, 0.866)).getMagnitude() < 0.5){
        // Red
        setRGB(x, y, brightness, 0, 0, image);
      }else if((prev_one - myComplex(1, 0)).getMagnitude() < 1){
        // Green
        setRGB(x, y, 0, brightness, 0, image);
      }else{
        // Blue
        setRGB(x, y, 0, 0, brightness, image);
      }
      */
    }
  }

  // save the image
  cout << "Saving: " << filename << " Width: " << width;
  cout << " Height: " << height << endl;
  // Saves the image
  image.save(filename.c_str());

  return 0;
}
