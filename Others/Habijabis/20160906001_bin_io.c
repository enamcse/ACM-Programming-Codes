/**
* E:\Dropbox\Code\Others\Habijabis\20160906001.c
* Created on: 2016-09-06-17.28.46, Tuesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/
#include<stdio.h>
#include<stdint.h>
int main()
{
//    uint8_t c,i;
//    for(i=0; i<5;i++)
//    {
//        scanf("%u", &c);
//        printf("%c %u %u",c,c,i);
//    }
    uint8_t *buffer = "This is a great thing I think!";
    FILE *write_ptr;

    write_ptr = fopen("test.bin","wb");  // w for write, b for binary

    fwrite(buffer,31,1,write_ptr); // write 10 bytes from our buffer
    fclose(write_ptr);

    FILE *fileptr;
//    char *buffer;
    long filelen;

    fileptr = fopen("test.bin", "rb");  // Open the file in binary mode
    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
    fread(buffer, filelen, 1, fileptr); // Read in the entire file
    printf("%s %d\n", buffer,filelen);
    fclose(fileptr); // Close the file
    return 0;
}
