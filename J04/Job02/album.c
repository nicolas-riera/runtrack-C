#include <unistd.h>
#include "album.h"

static void print_char(char c) {
    write(1, &c, 1);
}

static void print_string(char *str) {
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

static void print_year(int year) {
    if (year >= 1000) print_char('0' + (year / 1000) % 10);
    if (year >= 100)  print_char('0' + (year / 100) % 10);
    if (year >= 10)   print_char('0' + (year / 10) % 10);
    print_char('0' + year % 10);
}

void print_album(Album *album) {
    print_char('"');
    print_string(album->title);
    print_string("\" by \"");
    print_string(album->artist);
    print_string("\" released in ");
    print_year(album->year);
    print_string(".\n");
}  