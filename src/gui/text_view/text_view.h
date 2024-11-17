#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include <gtk/gtk.h>

GtkWidget *create_text_view();

void update_line_numbers(GtkTextBuffer *buffer, gpointer data);

#endif