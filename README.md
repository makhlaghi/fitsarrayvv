fitsarrayvv
===========

FITS image to C array and vice versa.

This very simple library is made to facilitate reading and writing
`FITS` images into `C` arrays. The functions used to read or write a
`C` array into a `FITS` image are completely indepenedent of the type
of the array. All the user has to do is to set the string argument
`fitstype` to the desired type in the function.  The 6 data types
defined by the FITS standard (the `BITPIX` keyword in the FITS header)
[supported by `cfitsio`
](http://heasarc.gsfc.nasa.gov/docs/software/fitsio/c/c_user/node20.html)
can be read using this short program. See below for `LONGLONG_IMG`.

It also includes a `keywords` structure so you can fill in all the
keywords you want to add to your final FITS image during the execution
of your program. If it is not necessary for you, just pass a `NULL` in
its place.


Prerequisites
-------------

1. `cfitsio`: In order to read and write `FITS` files. You can see an
explanation on how to install it
[here](http://astr.tohoku.ac.jp/~akhlaghi/cfitsiowcslibinstall.html .)
(it is very easy to install):



How to use it:
--------------

You just have to put the two `fitsarrayvv.c` and `fitsarrayvv.h` files
into your source files and include them in your `Makefile` (like the
example here) and include `fitsarrayvv.h` in which ever `.c` file you
want to read or write `FITS` images. `fitsio.h` is included in
`fitsarrayvv.h`.

Both functions to read and write an array to a FITS image return
void. The former's outputs are put in the pointer variables that you
input to it and the second doesn't need any output (if it fails it
will halt, I will fix this later to return a non zero value!).

To read a FITS image just define a `void *` variable and pass its
address to `fits_to_array()`. Once this function is finished, this
pointer will point to the array containing the data in your desired
fits image, what ever its data type was. You can check the data type
of the array with the `bitpix` parameter that is also output. The
values of `bitpix` are [defined by cfitsio
](http://heasarc.gsfc.nasa.gov/docs/software/fitsio/c/c_user/node20.html).

Just note that if you want to use this newly created array in the same
function that you called `fits_to_array()`, you have to copy the `void
*` to a pointer to the type of the image. If you want to send
it into another function, you don't have to do anything. What ever the
input array to that function's type is, this `void *` will easily be
copied into it.

I have made a very simple program reading and writing a `FITS` file as
an example. To test if it is working correctly, you just have to run
`make` in the directory you downloaded the source to in order to
compile the program. To see it in action, run `./testprog`.  It will
read the FITS image in the `SampleFITS` directory, tell you the average
value of pixels in that image and write it to a new FITS image in the
main program directory. This test program can also act as a guide on
how to implement this code into your program. There are lots of
comments to guide you.


Data types:
-----------

As it is written now, `fitsarrayvv` supports only 5 of the 6 standard
FITS data types: `BYTE_IMG`, `SHORT_IMG`, `LONG_IMG`, `FLOAT_IMG` and
`DOUBLE_IMG`. In `f2a_readalloc()` I have also kept an option for
`LONGLONG_IMG`, but since the `long long` type is not supported in
`C89` or `C90`, I have commented it out and warned the user. In case
you want to use `C99` (which supports this type), simply correct this
function.


Comments and suggestions:
-------------------------
If you find any problems in this program please contact me so 
I can correct them. I would also be very glad to hear any 
suggestions or comments you might have, thank you.

makhlaghi@gmail.com 

akhlaghi@astr.tohoku.ac.jp

http://astr.tohoku.ac.jp/~akhlaghi/


Copyright:
----------
Copyright (C) 2013, 2014 Mohammad Akhlaghi

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
