#ifndef GUI_H
#define GUI_H

void create_main_window();
void on_menu_file_new(GtkWidget *widget, gpointer data);
void on_menu_file_open(GtkWidget *widget, gpointer data);
void on_menu_file_save(GtkWidget *widget, gpointer data);
void on_menu_file_quit(GtkWidget *widget, gpointer data);
void on_menu_edit_undo(GtkWidget *widget, gpointer data);
void on_menu_edit_redo(GtkWidget *widget, gpointer data);
void on_menu_edit_cut(GtkWidget *widget, gpointer data);
void on_menu_edit_copy(GtkWidget *widget, gpointer data);
void on_menu_edit_paste(GtkWidget *widget, gpointer data);
void on_menu_help_about(GtkWidget *widget, gpointer data);

#endif
