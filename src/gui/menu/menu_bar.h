#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <gtk/gtk.h>

GtkWidget *create_menu_bar();
GtkWidget *create_file_menu();
GtkWidget *create_edit_menu();
GtkWidget *create_help_menu();

void on_menu_file_new(GtkWidget *widget, gpointer data);
void on_menu_help_about(GtkWidget *widget, gpointer data);

#endif