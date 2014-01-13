/*********************************************************************
fitsarrayvv - Read and write gsl matrix structures to FITS images.

Copyright (C) 2014 Mohammad Akhlaghi
Tohoku University Astronomical Institute, Sendai, Japan.
http://astr.tohoku.ac.jp/~akhlaghi/

fitsarrayvv is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

fitsarrayvv is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with fitsarrayvv. If not, see <http://www.gnu.org/licenses/>.

**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fitsarrayvv.h"
/* 
   fitsio.h is included here only for the 
   FLEN macros in prepare_keywords. In case
   You don't need to add keywords, you don't
   need to include fitsio.h here. It is included
   in fitsarrayvv.h.  
*/
#include "fitsio.h" 

void prepare_keywords(struct keywords *keys);
void free_keywords(struct keywords *keys);

int
main(void)
{
    /* Here the type of the array can be left
    as irrelevant. In fits_to_array, the type
    will be set based on the fitstype argument 
    (in this example "FLOAT"). */
    void *array;
    int exten=0;
    char EXTname[10];
    size_t size1, size2;
    struct keywords keys;
    char infits_name[]="./SampleFITS/1.fits";
    char outfits_name[]="./fitsmatrixtest.fits";

    /* Read the fits image into the float_matrix: */
    fits_to_array(infits_name, exten, "FLOAT", 
            &array, &size1, &size2);

    printf("\nThe data in %s is now in an array\n", infits_name);

    /***********************************************

     YOU CAN DO ANYTHING YOU WANT WITH THE 
     FLOAT_MATRIX STRUCTURE HERE, 
     PLEASE ENJOY ;-).

    ************************************************/

    /* Set your added keywords, in case you don't want to
    add any, just remove this function and the declaration
    and instead of keys in array_to_fits put a NULL. */
    prepare_keywords(&keys);
 
    /* Write the matrix to a fits file: */
    strcpy(EXTname, "IMG");
    array_to_fits(outfits_name, &keys, EXTname, 
            "FLOAT", array, size1, size2);

    printf("\nThe array has been written to %s\n\n", outfits_name);

    /* Free the float_matrix data. */
    free(array);

    /* Finish: */
    return 0;
}

void prepare_keywords(struct keywords *keys)
/**********************************************************
 ** This function will prepare the keywords that will be **
 ** added to the final FITS image.                       **
 **********************************************************/
{
    /* Declarations: */
    size_t i;

    /* Set the number of the keywords: */
    keys->num_f=2;   keys->num_s=1;

    /* leave the function if no keywords are needed: */
    if (keys->num_f==0 && keys->num_s==0) return;

    /* Allocate space for the keywords: */
    keys->names_f    = malloc(keys->num_f*sizeof(char *)); 
    keys->values_f   = malloc(keys->num_f*sizeof(float ));
    keys->comments_f = malloc(keys->num_f*sizeof(char *));
    keys->names_s    = malloc(keys->num_s*sizeof(char *));
    keys->values_s   = malloc(keys->num_s*sizeof(char *));
    keys->comments_s = malloc(keys->num_f*sizeof(char *));

    /* Allocate space for the character arrays: */
    for(i=0;i<keys->num_f;i++)
    {
        keys->names_f[i]=malloc(FLEN_KEYWORD*sizeof(char));
        keys->comments_f[i]=malloc(FLEN_COMMENT*sizeof(char));
    }
    for(i=0;i<keys->num_s;i++)
    {
        keys->names_s[i]=malloc(FLEN_KEYWORD*sizeof(char));
        keys->values_s[i]=malloc(FLEN_VALUE*sizeof(char));
        keys->comments_s[i]=malloc(FLEN_COMMENT*sizeof(char));
    }
  
    /* Set the values: */
    strcpy(keys->names_f[0], "FVALUE1"); keys->values_f[0]=0.123456;
    strcpy(keys->comments_f[0], "An example float keyword");
    strcpy(keys->names_f[1], "FVALUE2"); keys->values_f[1]=1.23e10;
    strcpy(keys->comments_f[1], "Another example float keyword");
    strcpy(keys->names_s[0], "STING1"); 
    strcpy(keys->values_s[0], "fitsmatrix"); 
    strcpy(keys->comments_s[0], "An example string keyword"); 
}

void free_keywords(struct keywords *keys)
/**********************************************************
 ** Free the space allocated for all the keywords:       **
 **********************************************************/
{
    /* Declarations: */
    size_t i;

    /* Free the space for the character arrays: */
    for(i=0;i<keys->num_f;i++) 
        {free(keys->names_f[i]);free(keys->comments_f[i]);}
    for(i=0;i<keys->num_s;i++)
        {free(keys->names_s[i]);free(keys->values_s[i]);
         free(keys->comments_s[i]);}
    free(keys->names_f); free(keys->names_s);
    free(keys->values_f);  free(keys->values_s);
    free(keys->comments_f); free(keys->comments_s);
}
