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

int count_album_item(AlbumItem *list) {
    int count = 0;
    AlbumItem *current = list;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

static int compare_strings(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }
    return s1[i] == s2[i];
}

void reverse_list(AlbumItem **list) {
    if (list == NULL || *list == NULL) {
        return;
    }

    AlbumItem *prev = NULL;
    AlbumItem *current = *list;
    AlbumItem *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *list = prev;
}

void clear_list(AlbumItem **list) {
    if (list == NULL || *list == NULL) {
        return;
    }

    AlbumItem *current = *list;
    AlbumItem *next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        
        if (current->artist != NULL) {
            free(current->artist);
        }
        if (current->title != NULL) {
            free(current->title);
        }
        
        free(current);
        current = next_node;
    }

    *list = NULL;
}

void push_back_album(AlbumItem **list, AlbumItem *album) {
    if (list == NULL || album == NULL) {
        return;
    }

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

void push_front_album(AlbumItem **list, AlbumItem *album) {
    if (list == NULL || album == NULL) {
        return;
    }

    album->next = *list;
    *list = album;
}

AlbumItem *find_album(AlbumItem *list, const char *title) {
    AlbumItem *current = list;
    
    while (current != NULL) {
        if (compare_strings(current->title, title)) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
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