#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include <gtk/gtk.h>

GtkWidget *create_tool_bar();

void on_tool_bar_new(GtkWidget *widget, gpointer data);
void on_tool_bar_quit(GtkWidget *widget, gpointer data);

#endif