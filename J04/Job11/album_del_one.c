#include <stdlib.h>

typedef struct album_item {
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;

void album_del_one(AlbumItem **list, AlbumItem *elem) {
    if (list == NULL || *list == NULL || elem == NULL) {
        return;
    }

    if (*list == elem) {
        *list = elem->next;
        
        if (elem->artist != NULL) {
            free(elem->artist);
        }
        if (elem->title != NULL) {
            free(elem->title);
        }
        free(elem);
        return;
    }

    AlbumItem *current = *list;
    while (current->next != NULL && current->next != elem) {
        current = current->next;
    }

    if (current->next == elem) {
        current->next = elem->next;
        
        if (elem->artist != NULL) {
            free(elem->artist);
        }
        if (elem->title != NULL) {
            free(elem->title);
        }
        free(elem);
    }
}