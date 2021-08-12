#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;  //to open a file, a pointer needs to be declared
    //fptr = fopen("C:\Users\gonza\Documents\8080\invaders.h", "rb"); //rb for binary mode, w for writing mode


   if ((fptr = fopen("invaders.h","rb")) == NULL){ //opens file
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

   int pc = 0;
   int k = 0;
   unsigned char *code = &buffer[pc];

   while (k < fsize){

      int count;
      printf("\t  ");

      while (k < 16){
         printf("%02x ", pc); //number of bytes used;
         pc++;
         k++;
      }

      printf("\n");
      pc = k;

      printf("%08x: ", pc);

      for (int i = 0; i < 16; i++){
         printf("%02x ", code[k]); //Prints out row of 16 codes
         k++;
      }

  }
   pc = 0;
   printf("\n\n");

   while (pc < fsize){
      int opbytes = 1;    
      printf ("%04x ", pc);

      switch (code[pc])    
      {    
        case 0x00: printf("NOP"); break;    
        case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes=3; break;    
        case 0x02: printf("STAX   B"); break;    
        case 0x03: printf("INX    B"); break;    
        case 0x04: printf("INR    B"); break;    
        case 0x05: printf("DCR    B"); break;    
        case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes=2; break;    
        case 0x07: printf("RLC"); break;    
        case 0x08: printf("NOP"); break;    
        /* ........ */    
        case 0x3e: printf("MVI    A,#0x%02x", code[1]); opbytes = 2; break;    
        /* ........ */    
        case 0xc3: printf("JMP    $%02x%02x",code[2], code[1]); opbytes = 3; break;    
        /* ........ */    
      }
      printf("\n"); 
      pc += opbytes;
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