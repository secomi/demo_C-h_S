#include "box.h"
#include <glib.h>
#include <glib/gprintf.h>

box *
box_create (const gchar *description)
{
  box *b = g_new0 (box, 1);
  b->description = g_strdup (description);
  return b;
}


void
box_free (box *b)
{
  g_free (b->object1);
  g_free (b->object2);
  g_clear_pointer (&b,g_free);
}


gboolean
box_object_add (box *b, position p, const gchar *object, guint weight)
{

  g_return_val_if_fail (b, FALSE);
  g_return_val_if_fail (object, FALSE);

  /*  add or overwrite */
  switch (p) {
    case POSITION1:
      g_free (b->object1);
      b->object1 = g_strdup (object);
      break;

    case POSITION2:
      g_free (b->object2);
      b->object2 = g_strdup (object);
      break;

    default:
      return FALSE;
  }

  /* demo, purpose as calling the function
   * multiple time will only increment the amount.
   */
  b->weight += weight;

  return TRUE;
}

void
box_print (box *b)
{
  g_return_if_fail (b);

  g_printf ("Box \"%s\" with:\n"
            "Object1: %s\n"
            "Object2: %s\n"
            "Total weight: %u\n\n",
            b->description,
            (b->object1) ? b->object1 : "None",
            (b->object2) ? b->object2 : "None",
            b->weight);
}
