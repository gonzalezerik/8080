
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
      case 0x13: printf(" "); break;
      case 0x14: printf(" "); break;
      case 0x15: printf(" "); break;
      case 0x16: printf(" "); break;
      case 0x17: printf(" "); break;
      case 0x18: printf(" "); break;
      case 0x19: printf(" "); break;
      case 0x1a: printf(" "); break;
      case 0x1b: printf(" "); break;
      case 0x1c: printf(" ");
      case 0x1d: printf(" ");
      case 0x1e: printf(" ");
      case 0x1f: printf(" ");

      case 0x20: printf(" ");
      case 0x21: printf(" ");
      case 0x22: printf(" ");
      case 0x23: printf(" ");
      case 0x24: printf(" ");
      case 0x25: printf(" ");
      case 0x26: printf(" ");
      case 0x27: printf(" ");
      case 0x28: printf(" ");
      case 0x29: printf(" ");
      case 0x2a: printf(" ");
      case 0x2b: printf(" ");
      case 0x2c: printf(" ");
      case 0x2d: printf(" ");
      case 0x2e: printf(" ");
      case 0x2f: printf(" ");

      case 0x30: printf(" ");
      case 0x31: printf(" ");
      case 0x32: printf(" ");
      case 0x33: printf(" ");
      case 0x34: printf(" ");
      case 0x35: printf(" ");
      case 0x36: printf(" ");
      case 0x37: printf(" ");
      case 0x38: printf(" ");
      case 0x39: printf(" ");
      case 0x3a: printf(" ");
      case 0x3b: printf(" ");
      case 0x3c: printf(" ");
      case 0x3d: printf(" ");
      case 0x3e: printf(" ");
      case 0x3f: printf(" ");


      case 0x40: printf(" ");
      case 0x41: printf(" ");
      case 0x42: printf(" ");
      case 0x43: printf(" ");
      case 0x44: printf(" ");
      case 0x45: printf(" ");
      case 0x46: printf(" ");
      case 0x47: printf(" ");
      case 0x48: printf(" ");
      case 0x49: printf(" ");
      case 0x4a: printf(" ");
      case 0x4b: printf(" ");
      case 0x4c: printf(" ");
      case 0x4d: printf(" ");
      case 0x4e: printf(" ");
      case 0x4f: printf(" ");

      case 0x50: printf(" ");
      case 0x51: printf(" ");
      case 0x52: printf(" ");
      case 0x53: printf(" ");
      case 0x54: printf(" ");
      case 0x55: printf(" ");
      case 0x56: printf(" ");
      case 0x57: printf(" ");
      case 0x58: printf(" ");
      case 0x59: printf(" ");
      case 0x5a: printf(" ");
      case 0x5b: printf(" ");
      case 0x5c: printf(" ");
      case 0x5d: printf(" ");
      case 0x5e: printf(" ");
      case 0x5f: printf(" ");

      case 0x60: printf(" ");
      case 0x61: printf(" ");
      case 0x62: printf(" ");
      case 0x63: printf(" ");
      case 0x64: printf(" ");
      case 0x65: printf(" ");
      case 0x66: printf(" ");
      case 0x67: printf(" ");
      case 0x68: printf(" ");
      case 0x69: printf(" ");
      case 0x6a: printf(" ");
      case 0x6b: printf(" ");
      case 0x6c: printf(" ");
      case 0x6d: printf(" ");
      case 0x6e: printf(" ");
      case 0x6f: printf(" ");

      case 0x70: printf(" ");
      case 0x71: printf(" ");
      case 0x72: printf(" ");
      case 0x73: printf(" ");
      case 0x74: printf(" ");
      case 0x75: printf(" ");
      case 0x76: printf(" ");
      case 0x77: printf(" ");
      case 0x78: printf(" ");
      case 0x79: printf(" ");
      case 0x7a: printf(" ");
      case 0x7b: printf(" ");
      case 0x7c: printf(" ");
      case 0x7d: printf(" ");
      case 0x7e: printf(" ");
      case 0x7f: printf(" ");

      case 0x80: printf(" ");
      case 0x81: printf(" ");
      case 0x82: printf(" ");
      case 0x83: printf(" ");
      case 0x84: printf(" ");
      case 0x85: printf(" ");
      case 0x86: printf(" ");
      case 0x87: printf(" ");
      case 0x88: printf(" ");
      case 0x89: printf(" ");
      case 0x8a: printf(" ");
      case 0x8b: printf(" ");
      case 0x8c: printf(" ");
      case 0x8d: printf(" ");
      case 0x8e: printf(" ");
      case 0x8f: printf(" ");

      case 0x90: printf(" ");
      case 0x91: printf(" ");
      case 0x92: printf(" ");
      case 0x93: printf(" ");
      case 0x94: printf(" ");
      case 0x95: printf(" ");
      case 0x96: printf(" ");
      case 0x97: printf(" ");
      case 0x98: printf(" ");
      case 0x99: printf(" ");
      case 0x9a: printf(" ");
      case 0x9b: printf(" ");
      case 0x9c: printf(" ");
      case 0x9d: printf(" ");
      case 0x9e: printf(" ");
      case 0x9f: printf(" ");

      case 0xa0: printf(" ");
      case 0xa1: printf(" ");
      case 0xa2: printf(" ");
      case 0xa3: printf(" ");
      case 0xa4: printf(" ");
      case 0xa5: printf(" ");
      case 0xa6: printf(" ");
      case 0xa7: printf(" ");
      case 0xa8: printf(" ");
      case 0xa9: printf(" ");
      case 0xaa: printf(" ");
      case 0xab: printf(" ");
      case 0xac: printf(" ");
      case 0xad: printf(" ");
      case 0xae: printf(" ");
      case 0xaf: printf(" ");

      case 0xb0: printf(" ");
      case 0xb1: printf(" ");
      case 0xb2: printf(" ");
      case 0xb3: printf(" ");
      case 0xb4: printf(" ");
      case 0xb5: printf(" ");
      case 0xb6: printf(" ");
      case 0xb7: printf(" ");
      case 0xb8: printf(" ");
      case 0xb9: printf(" ");
      case 0xba: printf(" ");
      case 0xbb: printf(" ");
      case 0xbc: printf(" ");
      case 0xbd: printf(" ");
      case 0xbe: printf(" ");
      case 0xbf: printf(" ");

      case 0xc0: printf(" ");
      case 0xc1: printf(" ");
      case 0xc2: printf(" ");
      case 0xc3: printf(" ");
      case 0xc4: printf(" ");
      case 0xc5: printf(" ");
      case 0xc6: printf(" ");
      case 0xc7: printf(" ");
      case 0xc8: printf(" ");
      case 0xc9: printf(" ");
      case 0xca: printf(" ");
      case 0xcb: printf(" ");
      case 0xcc: printf(" ");
      case 0xcd: printf(" ");
      case 0xce: printf(" ");
      case 0xcf: printf(" ");

      case 0xd0: printf(" ");
      case 0xd1: printf(" ");
      case 0xd2: printf(" ");
      case 0xd3: printf(" ");
      case 0xd4: printf(" ");
      case 0xd5: printf(" ");
      case 0xd6: printf(" ");
      case 0xd7: printf(" ");
      case 0xd8: printf(" ");
      case 0xd9: printf(" ");
      case 0xda: printf(" ");
      case 0xdb: printf(" ");
      case 0xdc: printf(" ");
      case 0xdd: printf(" ");
      case 0xde: printf(" ");
      case 0xdf: printf(" ");

      case 0xe0: printf(" ");
      case 0xe1: printf(" ");
      case 0xe2: printf(" ");
      case 0xe3: printf(" ");
      case 0xe4: printf(" ");
      case 0xe5: printf(" ");
      case 0xe6: printf(" ");
      case 0xe7: printf(" ");
      case 0xe8: printf(" ");
      case 0xe9: printf(" ");
      case 0xea: printf(" ");
      case 0xeb: printf(" ");
      case 0xec: printf(" ");
      case 0xed: printf(" ");
      case 0xee: printf(" ");
      case 0xef: printf(" ");

      case 0xf0: printf(" ");
      case 0xf1: printf(" ");
      case 0xf2: printf(" ");
      case 0xf3: printf(" ");
      case 0xf4: printf(" ");
      case 0xf5: printf(" ");
      case 0xf6: printf(" ");
      case 0xf7: printf(" ");
      case 0xf8: printf(" ");
      case 0xf9: printf(" ");
      case 0xfa: printf(" ");
      case 0xfb: printf(" ");
      case 0xfc: printf(" ");
      case 0xfd: printf(" ");
      case 0xfe: printf(" ");
      case 0xff: printf(" ");







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