#include <unistd.h>
#include <stdlib.h>
#include "album.h"

static int get_strlen(char *str) {
    int len = 0;
    while (str[len]) len++;
    return len;
}

static char *duplicate_string(char *str) {
    int len = get_strlen(str);
    char *copy = malloc((len + 1) * sizeof(char));
    if (!copy) return NULL;
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
    if (!new_item) return NULL;
    new_item->artist = duplicate_string(artist);
    new_item->title = duplicate_string(title);
    new_item->year = year;
    new_item->next = NULL;
    return new_item;
}

void push_back_album(AlbumItem **list, AlbumItem *album) {
    if (!list || !album) return;
    album->next = NULL;
    if (*list == NULL) {
        *list = album;
        return;
    }
    AlbumItem *current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = album;
}

void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*)) {
    if (!list || !*list || !(*list)->next || !cmp) return;
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

void clear_list(AlbumItem **list) {
    if (!list || !*list) return;
    AlbumItem *current = *list;
    AlbumItem *next_node;
    while (current != NULL) {
        next_node = current->next;
        if (current->artist) free(current->artist);
        if (current->title) free(current->title);
        free(current);
        current = next_node;
    }
    *list = NULL;
}

static void print_char(char c) {
    write(1, &c, 1);
}

static void print_string(char *str) {
    if (!str) return;
    write(1, str, get_strlen(str));
}

static void print_year(int year) {
    if (year >= 1000) print_char('0' + (year / 1000) % 10);
    if (year >= 100)  print_char('0' + (year / 100) % 10);
    if (year >= 10)   print_char('0' + (year / 10) % 10);
    print_char('0' + year % 10);
}

void print_album(AlbumItem *album) {
    print_char('"');
    print_string(album->title);
    print_string("\" by \"");
    print_string(album->artist);
    print_string("\" released in ");
    print_year(album->year);
    print_string(".\n");
}