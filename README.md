# Image Filter Studio

Console-based image processing app built in C++.

## Features
- Load real JPG/PNG images
- Apply 9 image filters
- Admin and Customer roles
- File-based data management

## Filters
1. Grayscale
2. Invert
3. Brightness Adjust
4. Contrast Stretch
5. Red Channel
6. Green Channel
7. Blue Channel
8. Flip Horizontal
9. Flip Vertical

## OOP Concepts Used
- Abstraction
- Inheritance
- Polymorphism
- Encapsulation
- Friend Class
- Operator Overloading
- Virtual Destructor
- Static Functions

## How to Compile
g++ -o program main.cpp pixel.cpp image.cpp
imageIO.cpp filter.cpp grayscalefilter.cpp
invertfilter.cpp brightnessfilter.cpp
contrastfilter.cpp redchannelfilter.cpp
greenchannelfilter.cpp bluechannelfilter.cpp
fliphorizontalfilter.cpp flipverticalfilter.cpp
filtersession.cpp user.cpp admin.cpp customer.cpp
customerfilemanager.cpp catalogfilemanager.cpp
sessionfilemanager.cpp

## Technologies
- Language: C++
- Library: stb_image
- IDE: Dev C++
