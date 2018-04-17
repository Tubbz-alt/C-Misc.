#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

const char *string = "a";

int main()
{

  int md5;
  unsigned char result[MD5_DIGEST_LENGTH];

  MD5(string, strlen(string), result);

  //output
  for(md5 = 0; md5 < MD5_DIGEST_LENGTH; md5++)
    printf("%02x", result[md5]);
  printf("\n");

  return EXIT_SUCCESS;

}
