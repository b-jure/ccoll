#define _CTREE_TEST_FILE_

#include "../include/ctree.h"
#include "ctree_test.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// TODO: Fix tests also after fixing the API
void ctree_test_insert_nodup(void);
void ctree_test_insert_dup(void);

int
main()
{
    PRINT_TEST_FILE("[avltre_test_insert]")
    PRINT_TEST("avltree_test_insert_nodup")
    ctree_test_insert_nodup();
    PRINT_SUCCESS

    PRINT_TEST("avltree_test_insert_dup")
    ctree_test_insert_dup();
    PRINT_SUCCESS

    return 0;
}

void
ctree_test_insert_nodup(void)
{
    Avltree_char tree = ctree_new((int (*)(void*, void*)) strcmp);
    assert(tree != NULL);

    avltree_insert(tree, "Mark");
    assert(avltree_size(tree) == 1);
    avltree_insert(tree, "Tony");
    assert(avltree_size(tree) == 2);
    avltree_insert(tree, "Apollo");
    assert(avltree_size(tree) == 3);
    avltree_insert(tree, "Bale");
    assert(avltree_size(tree) == 4);
    avltree_insert(tree, "Diavolo");
    assert(avltree_size(tree) == 5);
    avltree_insert(tree, "Eren");
    assert(avltree_size(tree) == 6);
    avltree_insert(tree, "Platinum");
    assert(avltree_size(tree) == 7);
    avltree_insert(tree, "Rusty");
    assert(avltree_size(tree) == 8);

    avltree_free(tree);
    return;
}

void
ctree_test_insert_dup(void)
{
    Avltree_char tree = ctree_new((int (*)(void*, void*)) strcmp);
    assert(tree != NULL);

    avltree_insert(tree, "Mark");
    assert(avltree_size(tree) == 1);
    avltree_insert(tree, "Tony");
    assert(avltree_size(tree) == 2);
    avltree_insert(tree, "Mark");
    assert(avltree_size(tree) == 3);
    avltree_insert(tree, "Tony");
    assert(avltree_size(tree) == 4);
    avltree_insert(tree, "Mark");
    assert(avltree_size(tree) == 5);
    avltree_insert(tree, "Mark");
    assert(avltree_size(tree) == 6);
    avltree_insert(tree, "Tony");
    assert(avltree_size(tree) == 7);
    avltree_insert(tree, "Platinum");
    assert(avltree_size(tree) == 8);
    avltree_insert(tree, "Platinum");
    assert(avltree_size(tree) == 9);
    avltree_insert(tree, "Eren");
    assert(avltree_size(tree) == 10);

    avltree_free(tree);
    return;
}
