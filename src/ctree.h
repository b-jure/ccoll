#ifndef __COL_TREE_H__
#define __COL_TREE_H__

#if !defined(__COL_LIB_INSIDE__) && !defined(__COL_TREE_C_FILE__)
#error "Only <collib.h> can be included directly."
#endif

#define __COL_H_FILE__
#include "core.h"
#undef __COL_H_FILE__
#include <stdbool.h>
#include <stddef.h>

typedef struct _CTree CTree;

/*
 * 'CTree' constructor.
 * Returns pointer to the 'CTree'.
 * Requires 'CCompareKeyFn', a comparison function
 * for sorting the keys (fn pointer).
 * Optional argument 'CFreeKeyFn', a function pointer
 * if provided will run each time we remove key
 * from the 'CTree' with the removed key as its
 * argument.
 * If NULL *USER* is required to free the memory
 * not the CTree.
 */
CTree *ctree_new(CCompareKeyFn, CFreeKeyFn);

/*
 * Free's up the tree and additionally all
 * values inside of it only and only if the user
 * provided 'CFreeKeyFn' when he created
 * the tree using 'ctree_new'.
 */
void ctree_free(CTree *);

/*
 * Inserts the 'cptr' (key) into the 'CTree'.
 * ('CTree' accepts duplicate key values)
 * If the value is inserted it returns true,
 * otherwise false. If the 'CTree' or 'cptr'
 * are NULL then it also returns false.
 */
bool ctree_insert(CTree *, cptr);

/*
 * Removes the 'cptr' from the 'CTree'.
 * Returns true if key was removed.
 * Returns false if key was not found.
 */
bool ctree_remove(CTree *, cptr);

/*
 * Returns current size of the tree.
 * This would represent the difference between
 * (amount of inserts - amount of valid removals)
 * from the tree.
 * This counts duplicate key values that were
 * inserted, for a concrete size use 'ctree_size_concrete'.
 */
cuint ctree_size(CTree *);

/*
 * Returns concrete size of the tree.
 * Does not count the nodes storing the same
 * key value, because they are not directly stored
 * as duplicates in memory.
 * You can say it returns amount of nodes inside
 * the 'CTree' that are allocated in memory.
 */
cuint ctree_size_concrete(CTree *);

/*
 * Experimental:
 * Returns size of the CTree in bytes representing
 * total amount of nodes stored inside the CTree.
 * Nodes storing the same key value are not
 * literally stored as duplicates so they don't count.
 */
size_t ctree_size_bytes(CTree *);

#endif