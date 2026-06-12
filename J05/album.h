typedef struct album_item {
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;

AlbumItem *create_album_item(char *artist, char *title, int year);
void push_back_album(AlbumItem **list, AlbumItem *album);
void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*));
void clear_list(AlbumItem **list);
void print_album(AlbumItem *album);