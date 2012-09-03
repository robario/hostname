#include <stdio.h>
#include <netdb.h>

int main(int argc, char** argv) {
    if (argc == 2 && strcmp(argv[1], "-f") == 0) {
        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr("127.0.0.1");
        char hostname[NI_MAXHOST];
        int r = getnameinfo((struct sockaddr*)&address, sizeof(address),
                            hostname, sizeof(hostname),
                            0, 0, 0);
        if (r == 0) {
            puts(hostname);
        } else {
            fputs(gai_strerror(r), stderr);
        }
        return r;
    }
    return execv("/usr/bin/hostname", argv);
}
