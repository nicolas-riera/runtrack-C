#include <stdlib.h>
#include "album.h"

static int get_strlen(char *str) {
    int len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

static char *duplicate_string(char *str) {
    int len = get_strlen(str);
    char *copy = malloc((len + 1) * sizeof(char));
    if (copy == NULL) {
        return NULL;
    }
    int i = 0;
    while (i < len) {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}

Album *create_album(char *artist, char *title, int year) {
    Album *new_album = malloc(sizeof(Album));
    if (new_album == NULL) {
        return NULL;
    }
    new_album->artist = duplicate_string(artist);
    if (new_album->artist == NULL) {
        free(new_album);
        return NULL;
    }
    new_album->title = duplicate_string(title);
    if (new_album->title == NULL) {
        free(new_album->artist);
        free(new_album);
        return NULL;
    }
    new_album->year = year;
    return new_album;
}