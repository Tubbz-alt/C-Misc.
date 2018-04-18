#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(void) {

    FILE *infile = fopen("infile", "r");
    if (infile == NULL) {
        perror("Cannot open input file");
        exit(EXIT_FAILURE);
    }
    FILE *outfile = fopen("coutfile","w");
    if (outfile == NULL) {
        perror("Cannot open output file");
        exit(EXIT_FAILURE);
    }

    // Read file line-by-line
    char *line = NULL;
    size_t linecap = 0;
    ssize_t lineLength;
    while ((lineLength = getline(&line, &linecap, infile)) != -1) {
        // Remove trailing newline character
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            lineLength -= 1;
            line[lineLength] = 0;
        }

        // Compute MD5 hash
        unsigned char md5hash[MD5_DIGEST_LENGTH];
        MD5((unsigned char*)line, lineLength, md5hash);

        // Print hash as hex string
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
            fprintf(outfile, "%02x", md5hash[i]);
        }
        fprintf(outfile,"\n");
    }
    free(line);

    fclose(infile);
    fclose(outfile);
}
