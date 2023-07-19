#ifndef __DEMO_BOX_H__
#define __DEMO_BOX_H__

#include <glib.h>

typedef struct box
{
  guint weight;
  gchar *description;
  gchar *object1;
  gchar *object2;
} box;

typedef enum position
{
  POSITION1 = 1,
  POSITION2
} position;



/*
 * Creates a new container with 2 possible positions
 *
 * the returned box should be freed with box_free when no longer
 * needed.
 *
 * Parameters:
 * - description: the description of the box
 *
 * returns:
 * a newly allocated box, to be freed by the caller.
 *
 */
box *box_create (const gchar *description);

/*
 * Frees the memory pointed by b
 *
 * Parameters:
 * - b: the box to free
 */
void box_free (box *b);


gboolean box_object_add (box *b, position p, const gchar *object, guint weight);

/*
 * dump box content
 */
void box_print (box *b);


#endif  /* __DEMO_BOX_H__ */
