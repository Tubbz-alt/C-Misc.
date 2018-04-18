#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

// Format the data as a hexadecimal string. The buffer must have
// space for `2 * length + 1` characters.
const char *hexString(unsigned char *data, size_t length, char *buffer) {
    const char *hexDigits = "0123456789abcdef";
    char *dest = buffer;
    for (size_t i = 0; i < length; i++) {
        *dest++ = hexDigits[data[i] >> 4];
        *dest++ = hexDigits[data[i] & 0x0F];
    }
    *dest = 0;
    return buffer;
}

int main(void) {
    FILE *infile = fopen("infile", "r");
    if (infile == NULL) {
        perror("Cannot open input file");
        exit(EXIT_FAILURE);
    }
    FILE *outfile = fopen("cout3","w");
    if (outfile == NULL) {
        perror("Cannot open output file");
        exit(EXIT_FAILURE);
    }

    // Read file line-by-line
    char *line = NULL;
    size_t linecap = 0;
    ssize_t lineLength;
    while ((lineLength = getline(&line, &linecap, infile)) != -1) {
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            // Remove newline character
            lineLength -= 1;
            line[lineLength] = 0;
        }

        // Compute MD5 hash
        unsigned char md5hash[MD5_DIGEST_LENGTH];
        MD5((unsigned char*)line, lineLength, md5hash);

        // Print hash as hex string
        char hexBuffer[2 * MD5_DIGEST_LENGTH + 1];
        fputs(hexString(md5hash, MD5_DIGEST_LENGTH, hexBuffer), outfile);
        fputc('\n', outfile);
    }
    free(line);

    // Close output files
    fclose(infile);
    fclose(outfile);
}
