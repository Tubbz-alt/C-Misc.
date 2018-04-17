//-----------Import Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>


//------------------------------Main Function-----------------------------//
int main()
{

//------Define infile, outfile, file length. Define string to read.------//
  FILE *infile, *outfile;
  char *string = NULL;
  size_t len = 0;
  ssize_t read;
//------Open File stream for read(r) and write (w). Error Handling.------//
  //Part of MD5 Hash Function (Take out of While Loop for Optimization)
  int md5;
  unsigned char result[MD5_DIGEST_LENGTH];
  //
  
  infile = fopen("file.txt", "r");
  if (infile == NULL)
    exit(EXIT_FAILURE);

  outfile = fopen("MD.txt","w"); // (faster)
  //outfile = fopen("MD.txt","a"); (slower)
  if (outfile == NULL)
    exit(EXIT_FAILURE);
//-------------Read line-by-line in using a while loop.------------------//
  while ((read = getline(&string, &len, infile)) != -1) {
    /*printf("Retrieved line of length %u :\n", read);
    printf("%s", line);
    const char *string = "a";*/

     string[strcspn(string, "\n")] = 0; // Remove newline '\n'

//-------------------------MD5 Hash Function---------------------------//


      MD5(string, strlen(string), result);

      //output
      //Using for loop to iterate untill the hash length is reached
      for(md5 = 0; md5 < MD5_DIGEST_LENGTH; md5++)
        /*printf("%02x", result[md5]);
      printf("\n");*/
      fprintf(outfile,"%02x",result[md5]); //convert the hash to hex
      fprintf(outfile,"\n"); //newline for the output file

  }

  free(string); //free string
  fclose(infile); // close file streams
  fclose(outfile);
  exit(EXIT_SUCCESS); //Program Ends
}
