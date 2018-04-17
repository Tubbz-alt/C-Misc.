#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

const char *string = "a";

int main()
{

  int sha512;
  unsigned char result[SHA512_DIGEST_LENGTH];

  SHA512(string, strlen(string), result);

  //output
  for(sha512 = 0; sha512 < SHA512_DIGEST_LENGTH; sha512++)
    printf("%02x", result[sha512]);
  printf("\n");

  return EXIT_SUCCESS;

}
