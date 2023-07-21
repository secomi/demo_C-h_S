#include <glib.h>
#include <stdlib.h>
#include "box.h"



int
main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char **argv)
{
  box *b = box_create ("my package");

  box_object_add (b, POSITION1, "pen", 10);
  box_print (b);

  box_object_add (b, POSITION2, "books", 25);
  box_print (b);                /*  */

  box_free (b);

  return EXIT_SUCCESS;
}
