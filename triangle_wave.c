#include<at89c51xd2.h> 
idata unsigned char count; 
void main(){ 
 while(1) 
 { 
  for(count=0; count!=0x7f;count++) 
  { 
   P0=count; 
  } 
  for(count=0x7f; count!=0;count--) 
  { 
   P0=count; 
  } 
 }
}