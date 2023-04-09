#include <sys/ioctl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
 		fprintf(stderr, "Failed to ioctl: %s\n", strerror(errno));
 		return 1;
    }

    printf("lines: %d\n", w.ws_row);
    printf("columns: %d\n", w.ws_col);

    return 0;
}
