# Newbie Engine
Bare bone newbie-created game engine built upon OpenGL.

## Copyright
Copyright © 2019 Hajun Kim, Undergraduate student in KAIST. All rights reserved. 

## Version Control

## Development
Described iterative development sequece makes sure every part of the software works correctly. 
1. Come up with a new concept or an abstraction. 
1. Design and implement the abstraction. 
1. Conduct some unit tests for the abstraction by pre-written unit_test_main functions. 
1. Conduct some global tests for the entire system by pre-written global_test_main functions.

## Documentation

## Build

## Environment 

## Debugging
Debugging process is completely separated into four parts described below.
1. General debugging
1. OpenGL GLFW debug output
1. Debugging Framebuffer rendering
1. Memory leak detection

General debugging tools are supported in files, Debug.hpp and Debug.cpp. Debugging supported by Newbie Engine covers the following.
1. Per module debugging
1. Combined module debugging
1. Main global flow debugging 
Everything mentioned above can be achieved by enabling or disabling preprocessor macro **#define DEBUG**.
