/*****************************************************************************
  Copyright (c) 2011,2012 Lab of Parallel Software and Computational Science,ISCAS
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in
the documentation and/or other materials provided with the
distribution.
3. Neither the name of the ISCAS nor the names of its contributors may 
be used to endorse or promote products derived from this software 
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 **********************************************************************************/

#include <stdio.h>
#include "common.h"

int CNAME(BLASLONG row,BLASLONG col,FLOAT* src,BLASLONG srcdim,FLOAT* dest) 
{
   BLASLONG i,j;
   BLASLONG idx=0;
   BLASLONG ii;
   FLOAT *src0,*src1,*src2,*src3,*dest0;
   for (j=0; j<col/4; j+=1) 
     {
        src0 = src;
        src1 = src0+2*srcdim;
        src2 = src1+2*srcdim;
        src3 = src2+2*srcdim;
        src = src3+2*srcdim;
        dest0 = dest;
        ii = (row<<3);
        dest = dest+ii;
        for (i=0; i<row/4; i+=1) 
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src1[0];
             dest0[3] = src1[1];
             dest0[4] = src2[0];
             dest0[5] = src2[1];
             dest0[6] = src3[0];
             dest0[7] = src3[1];
             dest0[8] = src0[2];
             dest0[9] = src0[3];
             dest0[10] = src1[2];
             dest0[11] = src1[3];
             dest0[12] = src2[2];
             dest0[13] = src2[3];
             dest0[14] = src3[2];
             dest0[15] = src3[3];
             dest0[16] = src0[4];
             dest0[17] = src0[5];
             dest0[18] = src1[4];
             dest0[19] = src1[5];
             dest0[20] = src2[4];
             dest0[21] = src2[5];
             dest0[22] = src3[4];
             dest0[23] = src3[5];
             dest0[24] = src0[6];
             dest0[25] = src0[7];
             dest0[26] = src1[6];
             dest0[27] = src1[7];
             dest0[28] = src2[6];
             dest0[29] = src2[7];
             dest0[30] = src3[6];
             dest0[31] = src3[7];
             src0 = src0+8;
             src1 = src1+8;
             src2 = src2+8;
             src3 = src3+8;
             ii = (4<<3);
             dest0 = dest0+ii;
          }
        if (row&2)  
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src1[0];
             dest0[3] = src1[1];
             dest0[4] = src2[0];
             dest0[5] = src2[1];
             dest0[6] = src3[0];
             dest0[7] = src3[1];
             dest0[8] = src0[2];
             dest0[9] = src0[3];
             dest0[10] = src1[2];
             dest0[11] = src1[3];
             dest0[12] = src2[2];
             dest0[13] = src2[3];
             dest0[14] = src3[2];
             dest0[15] = src3[3];
             src0 = src0+4;
             src1 = src1+4;
             src2 = src2+4;
             src3 = src3+4;
             ii = (2<<3);
             dest0 = dest0+ii;
          }
        if (row&1)  
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src1[0];
             dest0[3] = src1[1];
             dest0[4] = src2[0];
             dest0[5] = src2[1];
             dest0[6] = src3[0];
             dest0[7] = src3[1];
             src0 = src0+2;
             src1 = src1+2;
             src2 = src2+2;
             src3 = src3+2;
             ii = (1<<3);
             dest0 = dest0+ii;
          }
     }
   if (col&2)  
     {
        src0 = src;
        src1 = src0+2*srcdim;
        src = src1+2*srcdim;
        dest0 = dest;
        ii = (row<<2);
        dest = dest+ii;
        for (i=0; i<row/4; i+=1) 
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src1[0];
             dest0[3] = src1[1];
             dest0[4] = src0[2];
             dest0[5] = src0[3];
             dest0[6] = src1[2];
             dest0[7] = src1[3];
             dest0[8] = src0[4];
             dest0[9] = src0[5];
             dest0[10] = src1[4];
             dest0[11] = src1[5];
             dest0[12] = src0[6];
             dest0[13] = src0[7];
             dest0[14] = src1[6];
             dest0[15] = src1[7];
             src0 = src0+8;
             src1 = src1+8;
             ii = (4<<2);
             dest0 = dest0+ii;
          }
        if (row&2)  
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src1[0];
             dest0[3] = src1[1];
             dest0[4] = src0[2];
             dest0[5] = src0[3];
             dest0[6] = src1[2];
             dest0[7] = src1[3];
             src0 = src0+4;
             src1 = src1+4;
             ii = (2<<2);
             dest0 = dest0+ii;
          }
        if (row&1)  
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src1[0];
             dest0[3] = src1[1];
             src0 = src0+2;
             src1 = src1+2;
             ii = (1<<2);
             dest0 = dest0+ii;
          }
     }
   if (col&1)  
     {
        src0 = src;
        src = src0+2*srcdim;
        dest0 = dest;
        ii = (row<<1);
        dest = dest+ii;
        for (i=0; i<row/4; i+=1) 
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src0[2];
             dest0[3] = src0[3];
             dest0[4] = src0[4];
             dest0[5] = src0[5];
             dest0[6] = src0[6];
             dest0[7] = src0[7];
             src0 = src0+8;
             ii = (4<<1);
             dest0 = dest0+ii;
          }
        if (row&2)  
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             dest0[2] = src0[2];
             dest0[3] = src0[3];
             src0 = src0+4;
             ii = (2<<1);
             dest0 = dest0+ii;
          }
        if (row&1)  
          {
             dest0[0] = src0[0];
             dest0[1] = src0[1];
             src0 = src0+2;
             ii = (1<<1);
             dest0 = dest0+ii;
          }
     }
   return 0;
}
