#include "tool_bar.h"

GtkWidget* create_tool_bar() {
    GtkWidget *tool_bar;
    GtkToolItem *new_button;
    GtkToolItem *open_button;
    GtkToolItem *save_button;
    GtkToolItem *separator;
    GtkToolItem *quit_button;

    tool_bar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(tool_bar), GTK_TOOLBAR_ICONS);

    GtkWidget *new_icon = gtk_image_new_from_icon_name("document-new", GTK_ICON_SIZE_LARGE_TOOLBAR);
    new_button = gtk_tool_button_new(new_icon, "New");
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), new_button, -1);

    GtkWidget *open_icon = gtk_image_new_from_icon_name("document-open", GTK_ICON_SIZE_LARGE_TOOLBAR);
    open_button = gtk_tool_button_new(open_icon, "Open");
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), open_button, -1);

    GtkWidget *save_icon = gtk_image_new_from_icon_name("document-save", GTK_ICON_SIZE_LARGE_TOOLBAR);
    save_button = gtk_tool_button_new(save_icon, "Save");
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), save_button, -1);

    separator = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), separator, -1);

    GtkWidget *quit_icon = gtk_image_new_from_icon_name("application-exit", GTK_ICON_SIZE_LARGE_TOOLBAR);
    quit_button = gtk_tool_button_new(quit_icon, "Quit");
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), quit_button, -1);

    g_signal_connect(new_button, "clicked", G_CALLBACK(on_tool_bar_new), NULL);
    g_signal_connect(quit_button, "clicked", G_CALLBACK(on_tool_bar_quit), NULL);

    return tool_bar;
}

void on_tool_bar_new(GtkWidget *widget, gpointer data)
{
    g_print("New file clicked\n");
}

void on_tool_bar_quit(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}