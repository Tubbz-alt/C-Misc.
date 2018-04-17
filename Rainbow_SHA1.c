#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

const char *string = "a";

int main()
{

  int sha1;
  unsigned char result[SHA_DIGEST_LENGTH];

  SHA1(string, strlen(string), result);

  //output
  for(sha1 = 0; sha1 < SHA_DIGEST_LENGTH; sha1++)
    printf("%02x", result[sha1]);
  printf("\n");

  return EXIT_SUCCESS;

}
