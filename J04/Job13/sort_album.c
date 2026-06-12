#include <stddef.h>

typedef struct album_item {
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;

void sort_album(AlbumItem **list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL) {
        return;
    }

    int swapped;
    AlbumItem *current;
    AlbumItem *last_checked = NULL;

    do {
        swapped = 0;
        current = *list;

        while (current->next != last_checked) {
            if (current->year > current->next->year) {
                char *temp_artist = current->artist;
                char *temp_title = current->title;
                int temp_year = current->year;

                current->artist = current->next->artist;
                current->title = current->next->title;
                current->year = current->next->year;

                current->next->artist = temp_artist;
                current->next->title = temp_title;
                current->next->year = temp_year;

                swapped = 1;
            }
            current = current->next;
        }
        last_checked = current;
    } while (swapped);
}

void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*)) {
    if (list == NULL || *list == NULL || (*list)->next == NULL || cmp == NULL) {
        return;
    }

    int swapped;
    AlbumItem *current;
    AlbumItem *last_checked = NULL;

    do {
        swapped = 0;
        current = *list;

        while (current->next != last_checked) {
            if (cmp(current, current->next) > 0) {
                char *temp_artist = current->artist;
                char *temp_title = current->title;
                int temp_year = current->year;

                current->artist = current->next->artist;
                current->title = current->next->title;
                current->year = current->next->year;

                current->next->artist = temp_artist;
                current->next->title = temp_title;
                current->next->year = temp_year;

                swapped = 1;
            }
            current = current->next;
        }
        last_checked = current;
    } while (swapped);
}