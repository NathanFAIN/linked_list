#include "include.h"

linked_list_t *create_node(char *data, unsigned int size) {
    linked_list_t *node =   malloc(sizeof(*node));

    if (node == NULL || size > sizeof(node->data)) {
        exit (84);
    }
    memset(node->data + size, 0, sizeof(node->data) - size);
    memcpy(node->data, data, size);
    node->next = NULL;
    return (node);
}

void push_node(linked_list_t **list, linked_list_t *node) {
    if (*list == NULL) {
        *list = node;
    } else {
        linked_list_t *tmp = *list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

linked_list_t *pop_node(linked_list_t **list) {
    linked_list_t *node = *list;

    if (*list != NULL) {
        *list = (*list)->next;
    }
    return (node);
}

char *pop_unique_node(linked_list_t **list) {
    linked_list_t *node = *list;
    static char date[64];

    if (*list != NULL) {
        memcpy(date, (*list)->data, sizeof(date));
        *list = (*list)->next;
        free(node);
        return (date);
    }
    return (NULL);
}

unsigned int list_size(linked_list_t *list) {
    unsigned int size = 0;

    while (list != NULL) {
        list = list->next;
        size++;
    }
    return (size);
}

void destroy_list(linked_list_t **list) {
    linked_list_t *node = *list;
    linked_list_t *tmp = NULL;

    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    *list = NULL;
}

int main(void) {
    linked_list_t *list = NULL;

    push_node(&list, create_node("test", 5));
    printf("%s\n", pop_unique_node(&list));

    destroy_list(&list);
    return (0);
}