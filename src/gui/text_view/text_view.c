#include "text_view.h"

GtkWidget *line_number_view;

GtkWidget *create_text_view()
{
    GtkWidget *hbox;
    GtkWidget *text_view;
    GtkWidget *scrolled_window;
    GtkWidget *line_scrolled_window;

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    line_scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(line_scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    line_number_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(line_number_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(line_number_view), FALSE);
    gtk_container_add(GTK_CONTAINER(line_scrolled_window), line_number_view);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    gtk_box_pack_start(GTK_BOX(hbox), line_scrolled_window, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), scrolled_window, TRUE, TRUE, 0);

    g_signal_connect(gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view)), "changed", G_CALLBACK(update_line_numbers), NULL);

    return hbox;
}

void update_line_numbers(GtkTextBuffer *buffer, gpointer data)
{
    GtkTextIter iter;
    int line_count = 0;
    char line_numbers[1024] = "";

    gtk_text_buffer_get_start_iter(buffer, &iter);
    while (!gtk_text_iter_is_end(&iter))
    {
        line_count++;
        sprintf(line_numbers + strlen(line_numbers), "%d\n", line_count);
        gtk_text_iter_forward_line(&iter);
    }

    GtkTextBuffer *line_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(line_number_view));
    gtk_text_buffer_set_text(line_buffer, line_numbers, -1);
}

