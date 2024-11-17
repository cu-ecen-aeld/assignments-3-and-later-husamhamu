#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid arguments: Expected 2, got %d", argc - 1);
        printf("Usage: %s <file_path> <string>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    const char *string_to_write = argv[2];

    FILE *file = fopen(file_path, "w");
    if (!file) {
        syslog(LOG_ERR, "Error opening file %s", file_path);
        perror("Error");
        return 1;
    }

    fprintf(file, "%s", string_to_write);
    fclose(file);

    syslog(LOG_DEBUG, "Writing %s to %s", string_to_write, file_path);
    closelog();
    return 0;
}
