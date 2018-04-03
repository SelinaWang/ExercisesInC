#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
 printf(user_data, key, value);
}

int main(int argc, char** argv) {

  FILE *f = fopen("mobydick.txt", "r");

  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  gchar str[1024];
  while (fscanf(f, "%1023s", str) != EOF){
    // printf("%s\n",str);
    if (isalnum(str)) {
      if (g_hash_table_contains(hash, str)) {
        g_hash_table_replace(hash, g_strdup(str), (gpointer)(((gint64)g_hash_table_lookup(hash, str))+1));
      }
      else {
        g_hash_table_insert(hash, g_strdup(str), (gpointer)1);
      }
    }
  }

  // GHashTableIter iter;
  // gpointer key, value;
  //
  // g_hash_table_iter_init (&iter, hash);
  // while (g_hash_table_iter_next (&iter, &key, &value))
  //   {
  //     printf("%s: %s\n",(char *)key,(char *)value);
  //   }

  g_hash_table_foreach(hash, (GHFunc)iterator, "%s: %s\n");
  g_hash_table_destroy(hash);
  fclose(f);

  return 0;
}
