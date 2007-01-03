/*
**  mempool.h
**
**  Header for mempool.c
**
**  The type alloc_handle_t provides an opaque reference to the
**  alloc pool - only the alloc routines know its structure.
*/

// Handle associated with a memory pool
typedef struct
{
   long  dummy;
}  alloc_handle_t;

// Creates a new memory pool and returns a handle to it
alloc_handle_t * AllocInit(void);

// Changes the current memory pool
alloc_handle_t * AllocSetPool(alloc_handle_t *);

// Returns a block of memory from the current pool
char * Alloc(long);

// Resets the current memory pool for reuse
void AllocReset(void);

// Frees the memory in the current pool 
void AllocFreePool(void);
