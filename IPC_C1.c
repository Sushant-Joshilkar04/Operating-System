#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME1 "comm_pipe1"
#define FIFO_NAME2 "comm_pipe2"

int main()
{
    char s[300], vowel[20], send[300];
    int num, fd1, fd2, sig, k = 0, i = 0, wordcnt = 0, charcnt = 0, linecnt = 0;

    mknod(FIFO_NAME1, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME2, S_IFIFO | 0666, 0);
    printf("fifo 2nd side connected, waiting for other process to connect to the 1st end of fifo pipe...\n");
    fd1 = open(FIFO_NAME1, O_RDONLY);
    fd2 = open(FIFO_NAME2, O_WRONLY);
    printf("established connection\n");

    if ((num = read(fd1, s, 300)) == -1)
        perror("read");
    else {
        s[num] = '\0';
        printf("read %d bytes: \"%s\"\n", num, s);
        k = 0;
        vowel[0] = '\0';

        int in_word = 0; 

        for (i = 0; i < num; i++) {
         
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowel[k] = s[i];
                k++;
            }

            
            if ((s[i] != ' ' && s[i] != '.' && s[i] != '\n') && !in_word) {
                in_word = 1; 
                wordcnt++;
            } else if (s[i] == ' ' || s[i] == '.' || s[i] == '\n') {
                in_word = 0; 
            }

            
            if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
                linecnt++;
                i += 2; 
            }

            
            if (s[i] != '.' && s[i] != ' ') {
                charcnt++;
            }
        }

        vowel[k] = '\0';

  
        sprintf(send, "For the given sentence:\nWord count: %d\nVowel count: %d\nCharacter count: %d\nLine count: %d\n",
                wordcnt, k, charcnt, linecnt);

        if ((sig = write(fd2, send, strlen(send))) != -1)
            printf("\nWritten successfully to file 2\n");
        else
            printf("\nError in writing to file 2\n");
    }

    return 0;
}
