#include <gtk/gtk.h>
#include "gui.h"
#include "../crypto/crypto.h"

void create_main_window() {
    GtkWidget *window;
    GtkWidget *button;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Secure Note");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    button = gtk_button_new_with_label("Create New Note");
    gtk_container_add(GTK_CONTAINER(window), button);

    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
}

void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Button clicked! Creating a new note...\n");
}
