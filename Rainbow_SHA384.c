#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

const char *string = "a";

int main()
{

  int sha384;
  unsigned char result[SHA384_DIGEST_LENGTH];

  SHA384(string, strlen(string), result);

  //output
  for(sha384 = 0; sha384 < SHA384_DIGEST_LENGTH; sha384++)
    printf("%02x", result[sha384]);
  printf("\n");

  return EXIT_SUCCESS;

}
