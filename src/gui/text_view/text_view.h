#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include <gtk/gtk.h>

GtkWidget *create_text_view();

void update_line_numbers(GtkTextBuffer *buffer, gpointer data);
void sync_scroll(GtkAdjustment *text_adj, gpointer data);
void apply_css(GtkWidget *widget, const char *css_data);

#endif