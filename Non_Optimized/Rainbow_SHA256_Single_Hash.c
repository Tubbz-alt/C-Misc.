#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

const char *string = "a";

int main()
{

  int sha256;
  unsigned char result[SHA256_DIGEST_LENGTH];

  SHA256(string, strlen(string), result);

  //output
  for(sha256 = 0; sha256 < SHA256_DIGEST_LENGTH; sha256++)
    printf("%02x", result[sha256]);
  printf("\n");

  return EXIT_SUCCESS;

}
