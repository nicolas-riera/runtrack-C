#include <stdlib.h>

typedef struct album_item {
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;

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

AlbumItem *create_album_item(char *artist, char *title, int year) {
    AlbumItem *new_item = malloc(sizeof(AlbumItem));
    if (new_item == NULL) {
        return NULL;
    }
    new_item->artist = duplicate_string(artist);
    if (new_item->artist == NULL) {
        free(new_item);
        return NULL;
    }
    new_item->title = duplicate_string(title);
    if (new_item->title == NULL) {
        free(new_item->artist);
        free(new_item);
        return NULL;
    }
    new_item->year = year;
    new_item->next = NULL;
    return new_item;
}