fitsarrayvv
=========

FITS image to C array and vice versa.

This very simple library is made to facilitate reading and writing
`FITS` images into `C` arrays. The functions used to read or write
a `C` array into a `FITS` image are completely indepenedent of the
type of the array. All the user has to do is to set the string 
argument `fitstype` to the desired type in the function.
Currently this program can read and write `C` arrays of type `float`, 
`unsigned char`, `signed short` and `signed long`. Adding other types
is trivial: Add a new function to `./src/fitsmatrix.c`, like the 
ones that are already there only changing the types.

It also includes a `keywords` structure so you can fill in all
the keywords you want to add to your final FITS image during
the execution of your program.

----------------------------------------
Prerequisites
----------------------------------------
1. `cfitsio`: In order to read and write `FITS` files. You 
can see an explanation on how to install it here (it is very
easy to install):
http://astr.tohoku.ac.jp/~akhlaghi/cfitsiowcslibinstall.html .

---------------------------------------
How to use it:
---------------------------------------
You just have to put the two `fitsmatrix.c` and `fitsmatrix.h` files
into your source files and include `fitsmatrix.h` in which ever 
`.c` file you want to read or write `FITS` images. 

I have made a very simple program reading and writing a `FITS` file
as an example. To test if it is working correctly, you just have to 
run `make` in the directory you downloaded the source to in order 
to compile the program. To see it in action, run `./testprog`. 
This test program can also act as a guide on how to implement this 
code into your program. There are lots of comments to guide you.

----------------------------------------
Comments and suggestions:
----------------------------------------
If you find any problems in this program please contact me so 
I can correct them. I would also be very glad to hear any 
suggestions or comments you might have, thank you.

makhlaghi@gmail.com 

akhlaghi@astr.tohoku.ac.jp

http://astr.tohoku.ac.jp/~akhlaghi/

----------------------------------------
Copyright:
----------------------------------------
Copyright (C) 2013 Mohammad Akhlaghi

Tohoku University Astronomical Institute

http://astr.tohoku.ac.jp/~akhlaghi/

fitsarrayvv is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

fitsarrayvv is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with fitsarrayvv.  If not, see <http://www.gnu.org/licenses/>.
