#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "album.h"

#define BUFFER_SIZE 1

static int compare_strings(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i]) return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

static int cmp_artist(AlbumItem *a, AlbumItem *b) {
    return compare_strings(a->artist, b->artist);
}

static int cmp_title(AlbumItem *a, AlbumItem *b) {
    return compare_strings(a->title, b->title);
}

static int cmp_year(AlbumItem *a, AlbumItem *b) {
    return a->year - b->year;
}

static void print_error(char *msg) {
    int len = 0;
    while (msg[len]) len++;
    write(2, msg, len);
    write(2, "\n", 1);
}

static int parse_file(char *filename, AlbumItem **list) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        print_error("File not found");
        return 0;
    }

    char buffer[4096];
    int buf_idx = 0;
    char c;
    int state = 0; 
    
    char artist[512] = {0};
    char title[512] = {0};
    int year = 0;

    while (read(fd, &c, BUFFER_SIZE) > 0) {
        if (c == ',' && state < 2) {
            buffer[buf_idx] = '\0';
            int start = 0;
            while (buffer[start] == ' ') start++;
            int end = buf_idx - 1;
            while (end >= start && buffer[end] == ' ') end--;
            buffer[end + 1] = '\0';

            if (state == 0) {
                int j = 0;
                while (buffer[start + j]) {
                    artist[j] = buffer[start + j];
                    j++;
                }
                artist[j] = '\0';
                state = 1;
            } else if (state == 1) {
                int j = 0;
                while (buffer[start + j]) {
                    title[j] = buffer[start + j];
                    j++;
                }
                title[j] = '\0';
                state = 2;
            }
            buf_idx = 0;
        } else if (c == '\n' || c == '\r') {
            if (buf_idx > 0 || state == 2) {
                buffer[buf_idx] = '\0';
                int start = 0;
                while (buffer[start] == ' ') start++;
                
                year = 0;
                while (buffer[start] >= '0' && buffer[start] <= '9') {
                    year = year * 10 + (buffer[start] - '0');
                    start++;
                }

                if (state == 2) {
                    AlbumItem *new_node = create_album_item(artist, title, year);
                    if (new_node) {
                        push_back_album(list, new_node);
                    }
                }
                state = 0;
                buf_idx = 0;
            }
        } else {
            if (buf_idx < 4095) {
                buffer[buf_idx++] = c;
            }
        }
    }

    if (state == 2 && buf_idx > 0) {
        buffer[buf_idx] = '\0';
        int start = 0;
        while (buffer[start] == ' ') start++;
        year = 0;
        while (buffer[start] >= '0' && buffer[start] <= '9') {
            year = year * 10 + (buffer[start] - '0');
            start++;
        }
        AlbumItem *new_node = create_album_item(artist, title, year);
        if (new_node) {
            push_back_album(list, new_node);
        }
    }

    close(fd);
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_error("Incorrect format");
        return 1;
    }

    int (*cmp_func)(AlbumItem*, AlbumItem*) = NULL;
    if (compare_strings(argv[2], "artist") == 0) cmp_func = cmp_artist;
    else if (compare_strings(argv[2], "title") == 0) cmp_func = cmp_title;
    else if (compare_strings(argv[2], "year") == 0) cmp_func = cmp_year;
    else {
        print_error("Sort method does not exist");
        return 1;
    }

    AlbumItem *list = NULL;
    if (!parse_file(argv[1], &list)) {
        return 1;
    }

    sort_album_by(&list, cmp_func);

    AlbumItem *current = list;
    while (current != NULL) {
        print_album(current);
        current = current->next;
    }

    clear_list(&list);
    return 0;
}