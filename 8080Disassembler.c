
#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

int main(){
    FILE *fptr;  //to open a file, a pointer needs to be declared
    //fptr = fopen("C:\Users\gonza\Documents\8080\invaders.h", "rb"); //rb for binary mode, w for writing mode


   if ((fptr = fopen("invaders","rb")) == NULL){ //opens file
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   

   fseek(fptr, 0L, SEEK_END); //seek to the end and get position
   int fsize = ftell(fptr); // setting the size of the file to fsize
   fseek(fptr, 0L, SEEK_SET); // seek back to the front

   unsigned char *buffer = malloc(fsize); //creating a uffer

   fread(buffer, fsize, 1, fptr); //reading the code into a buffer
   fclose(fptr);

   /*for(int i = 0; i < fsize; i++ ){
      if(buffer[i] == 0x00){
         printf("%02x ", buffer[i]);
         printf("NOP\n");
      } else 
      printf("%02x \n", buffer[i]);
   }*/

   cpu.pc = 0;


   while (cpu.pc < fsize){
      unsigned char *codeP = &buffer[cpu.pc];
      int opbytes = 1;
      printf("%04x ", cpu.pc);

      switch(*codeP){
      case 0x00: printf("NOP"); break;    
      case 0x01: printf("LXI    B,#$%02x%02x", codeP[2], codeP[1]); opbytes=3; break;    
      case 0x02: printf("STAX   B"); break;    
      case 0x03: printf("INX    B"); break;    
      case 0x04: printf("INR    B"); break;    
      case 0x05: printf("DCR    B"); break;    
      case 0x06: printf("MVI    B,#$%02x", codeP[1]); opbytes=2; break;    
      case 0x07: printf("RLC"); break;    
      case 0x08: printf("NOP"); break;    
      case 0x09: printf("DAD    B"); break;
      case 0x0a: printf("LDAX   B"); break;
      case 0x0b: printf("DCX    B"); break;
      case 0x0c: printf("INR    C"); break;
      case 0x0d: printf("DCR    C"); break;
      case 0x0e: printf("MVI    C"); opbytes = 2; break;
      case 0x0f: printf("RRC "); break;


      case 0x10: printf("NOP"); break;
      case 0x11: printf("LXI    D,"); opbytes = 3; break;
      case 0x12: printf("STAX   D"); break; 
      case 0x13: printf("INX    D"); break;
      case 0x14: printf("INR    D"); break;
      case 0x15: printf("DCR D"); break;
      case 0x16: printf("MVI D,"); opbytes = 2; break;
      case 0x17: printf("RAL"); break;
      case 0x18: printf("NOP "); break;
      case 0x19: printf("DAD    D"); break;
      case 0x1a: printf("LDAX   D"); break;
      case 0x1b: printf("DCX    D"); break;
      case 0x1c: printf("INR    R"); break;
      case 0x1d: printf("DCR    E"); break;
      case 0x1e: printf("MVI    E,"); opbytes = 2; break;
      case 0x1f: printf("RAR"); break;

      case 0x20: printf(" "); break;
      case 0x21: printf(" "); break;
      case 0x22: printf(" "); break;
      case 0x23: printf(" "); break;
      case 0x24: printf(" "); break;
      case 0x25: printf(" "); break;
      case 0x26: printf(" "); break; 
      case 0x27: printf(" "); break;
      case 0x28: printf(" "); break;
      case 0x29: printf(" "); break;
      case 0x2a: printf(" "); break;
      case 0x2b: printf(" "); break;
      case 0x2c: printf(" "); break;
      case 0x2d: printf(" "); break;
      case 0x2e: printf(" "); break;
      case 0x2f: printf(" "); break;

      case 0x30: printf(" "); break;
      case 0x31: printf(" "); break;
      case 0x32: printf(" "); break;
      case 0x33: printf(" "); break;
      case 0x34: printf(" "); break;
      case 0x35: printf(" "); break;
      case 0x36: printf(" "); break;
      case 0x37: printf(" "); break;
      case 0x38: printf(" "); break;
      case 0x39: printf(" "); break;
      case 0x3a: printf(" "); break;
      case 0x3b: printf(" "); break;
      case 0x3c: printf(" "); break;
      case 0x3d: printf(" "); break;
      case 0x3e: printf(" "); break;
      case 0x3f: printf(" ");  break;


      case 0x40: printf(" "); break;
      case 0x41: printf(" "); break;
      case 0x42: printf(" "); break;
      case 0x43: printf(" "); break;
      case 0x44: printf(" "); break;
      case 0x45: printf(" "); break;
      case 0x46: printf(" "); break; 
      case 0x47: printf(" "); break;
      case 0x48: printf(" "); break;
      case 0x49: printf(" "); break;
      case 0x4a: printf(" "); break;
      case 0x4b: printf(" "); break;
      case 0x4c: printf(" "); break;
      case 0x4d: printf(" "); break;
      case 0x4e: printf(" "); break;
      case 0x4f: printf(" "); break;

      case 0x50: printf(" "); break;
      case 0x51: printf(" "); break;
      case 0x52: printf(" "); break;
      case 0x53: printf(" "); break;
      case 0x54: printf(" "); break;
      case 0x55: printf(" "); break;
      case 0x56: printf(" "); break;
      case 0x57: printf(" "); break;
      case 0x58: printf(" "); break;
      case 0x59: printf(" "); break;
      case 0x5a: printf(" "); break;
      case 0x5b: printf(" "); break;
      case 0x5c: printf(" "); break;
      case 0x5d: printf(" "); break;
      case 0x5e: printf(" "); break;
      case 0x5f: printf(" "); break;

      case 0x60: printf(" "); break;
      case 0x61: printf(" "); break;
      case 0x62: printf(" "); break;
      case 0x63: printf(" "); break;
      case 0x64: printf(" "); break;
      case 0x65: printf(" "); break;
      case 0x66: printf(" "); break;
      case 0x67: printf(" "); break;
      case 0x68: printf(" "); break;
      case 0x69: printf(" "); break;
      case 0x6a: printf(" "); break;
      case 0x6b: printf(" "); break;
      case 0x6c: printf(" "); break;
      case 0x6d: printf(" "); break;
      case 0x6e: printf(" "); break;
      case 0x6f: printf(" "); break;

      case 0x70: printf(" "); break;
      case 0x71: printf(" "); break;
      case 0x72: printf(" "); break;
      case 0x73: printf(" "); break;
      case 0x74: printf(" "); break;
      case 0x75: printf(" "); break;
      case 0x76: printf(" "); break;
      case 0x77: printf(" "); break;
      case 0x78: printf(" "); break;
      case 0x79: printf(" "); break;
      case 0x7a: printf(" "); break;
      case 0x7b: printf(" "); break;
      case 0x7c: printf(" "); break;
      case 0x7d: printf(" "); break;
      case 0x7e: printf(" "); break;
      case 0x7f: printf(" "); break;

      case 0x80: printf(" "); break;
      case 0x81: printf(" "); break;
      case 0x82: printf(" "); break;
      case 0x83: printf(" "); break;
      case 0x84: printf(" "); break;
      case 0x85: printf(" "); break;
      case 0x86: printf(" "); break;
      case 0x87: printf(" "); break;
      case 0x88: printf(" "); break;
      case 0x89: printf(" "); break;
      case 0x8a: printf(" "); break;
      case 0x8b: printf(" "); break;
      case 0x8c: printf(" "); break;
      case 0x8d: printf(" "); break;
      case 0x8e: printf(" "); break;
      case 0x8f: printf(" "); break;

      case 0x90: printf(" "); break;
      case 0x91: printf(" "); break;
      case 0x92: printf(" "); break;
      case 0x93: printf(" "); break;
      case 0x94: printf(" "); break;
      case 0x95: printf(" "); break;
      case 0x96: printf(" "); break;
      case 0x97: printf(" "); break;
      case 0x98: printf(" "); break;
      case 0x99: printf(" "); break;
      case 0x9a: printf(" "); break;
      case 0x9b: printf(" "); break;
      case 0x9c: printf(" "); break;
      case 0x9d: printf(" "); break;
      case 0x9e: printf(" "); break;
      case 0x9f: printf(" "); break;

      case 0xa0: printf(" "); break;
      case 0xa1: printf(" "); break;
      case 0xa2: printf(" "); break;
      case 0xa3: printf(" "); break;
      case 0xa4: printf(" "); break;
      case 0xa5: printf(" "); break;
      case 0xa6: printf(" "); break;
      case 0xa7: printf(" "); break;
      case 0xa8: printf(" "); break;
      case 0xa9: printf(" "); break;
      case 0xaa: printf(" "); break;
      case 0xab: printf(" "); break;
      case 0xac: printf(" "); break;
      case 0xad: printf(" "); break;
      case 0xae: printf(" "); break;
      case 0xaf: printf(" "); break;

      case 0xb0: printf(" "); break;
      case 0xb1: printf(" "); break;
      case 0xb2: printf(" "); break;
      case 0xb3: printf(" "); break;
      case 0xb4: printf(" "); break;
      case 0xb5: printf(" "); break;
      case 0xb6: printf(" "); break;
      case 0xb7: printf(" "); break;
      case 0xb8: printf(" "); break;
      case 0xb9: printf(" "); break;
      case 0xba: printf(" "); break;
      case 0xbb: printf(" "); break;
      case 0xbc: printf(" "); break;
      case 0xbd: printf(" "); break;
      case 0xbe: printf(" "); break;
      case 0xbf: printf(" "); break;

      case 0xc0: printf(" "); break;
      case 0xc1: printf(" "); break;
      case 0xc2: printf(" "); break;
      case 0xc3: printf(" "); break;
      case 0xc4: printf(" "); break;
      case 0xc5: printf(" "); break;
      case 0xc6: printf(" "); break;
      case 0xc7: printf(" "); break;
      case 0xc8: printf(" "); break;
      case 0xc9: printf(" "); break;
      case 0xca: printf(" "); break;
      case 0xcb: printf(" "); break;
      case 0xcc: printf(" "); break;
      case 0xcd: printf(" "); break;
      case 0xce: printf(" "); break;
      case 0xcf: printf(" "); break;

      case 0xd0: printf(" "); break;
      case 0xd1: printf(" "); break;
      case 0xd2: printf(" "); break;
      case 0xd3: printf(" "); break;
      case 0xd4: printf(" "); break;
      case 0xd5: printf(" "); break;
      case 0xd6: printf(" "); break;
      case 0xd7: printf(" "); break;
      case 0xd8: printf(" "); break;
      case 0xd9: printf(" "); break;
      case 0xda: printf(" "); break;
      case 0xdb: printf(" "); break;
      case 0xdc: printf(" "); break;
      case 0xdd: printf(" "); break;
      case 0xde: printf(" "); break;
      case 0xdf: printf(" "); break;

      case 0xe0: printf(" "); break;
      case 0xe1: printf(" "); break;
      case 0xe2: printf(" "); break;
      case 0xe3: printf(" "); break;
      case 0xe4: printf(" "); break;
      case 0xe5: printf(" "); break;
      case 0xe6: printf(" "); break;
      case 0xe7: printf(" "); break;
      case 0xe8: printf(" "); break;
      case 0xe9: printf(" "); break;
      case 0xea: printf(" "); break;
      case 0xeb: printf(" "); break;
      case 0xec: printf(" "); break;
      case 0xed: printf(" "); break;
      case 0xee: printf(" "); break;
      case 0xef: printf(" "); break;

      case 0xf0: printf(" "); break;
      case 0xf1: printf(" "); break;
      case 0xf2: printf(" "); break;
      case 0xf3: printf(" "); break;
      case 0xf4: printf(" "); break;
      case 0xf5: printf(" "); break;
      case 0xf6: printf(" "); break;
      case 0xf7: printf(" "); break;
      case 0xf8: printf(" "); break;
      case 0xf9: printf(" "); break;
      case 0xfa: printf(" "); break;
      case 0xfb: printf(" "); break;
      case 0xfc: printf(" "); break;
      case 0xfd: printf(" "); break;
      case 0xfe: printf(" "); break;
      case 0xff: printf(" "); break;







      }
      printf("\n");
      cpu.pc += opbytes;
   }


   //printf("\n");
   /*for(int i = 0; i < 10; i++){
      printf("%08x",pc);
      pc++;
      int count;
      printf("%02x ", code[i]);
      count++;
      if (count >=16){
         printf("\n");
         count = 0;
         }
      }*/

}