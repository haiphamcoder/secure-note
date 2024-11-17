#include <gtk/gtk.h>
#include "text_view.h"

GtkWidget *line_number_view;
GtkWidget *text_view;

void apply_css(GtkWidget *widget, const char *css_data)
{
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider, css_data, -1, NULL);

    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(provider);
}

GtkWidget *create_text_view()
{
    GtkWidget *hbox;
    GtkWidget *scrolled_window;
    GtkWidget *line_scrolled_window;

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    line_scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(line_scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    line_number_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(line_number_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(line_number_view), FALSE);

    apply_css(line_number_view, "textview { font-family: 'Monospace'; font-size: 15px; }");

    gtk_container_add(GTK_CONTAINER(line_scrolled_window), line_number_view);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    text_view = gtk_text_view_new();

    apply_css(text_view, "textview { font-family: 'Monospace'; font-size: 15px; }");

    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    gtk_box_pack_start(GTK_BOX(hbox), line_scrolled_window, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), scrolled_window, TRUE, TRUE, 0);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    g_signal_connect(gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(scrolled_window)), "value-changed", G_CALLBACK(sync_scroll), line_scrolled_window);
    g_signal_connect(buffer, "changed", G_CALLBACK(update_line_numbers), NULL);

    update_line_numbers(buffer, NULL);

    return hbox;
}

void update_line_numbers(GtkTextBuffer *buffer, gpointer data)
{
    GtkTextIter iter;
    int line_count = 1;
    char line_numbers[1024] = "";

    gtk_text_buffer_get_start_iter(buffer, &iter);

    while (TRUE)
    {
        if (!gtk_text_iter_forward_line(&iter)){
            break;
        }
        sprintf(line_numbers + strlen(line_numbers), "%d\n", line_count);
        line_count++;
    }
    sprintf(line_numbers + strlen(line_numbers), "%d", line_count);

    GtkTextBuffer *line_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(line_number_view));
    gtk_text_buffer_set_text(line_buffer, line_numbers, -1);
}

void sync_scroll(GtkAdjustment *text_adj, gpointer data)
{
    GtkAdjustment *line_adj = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(data));
    gtk_adjustment_set_value(line_adj, gtk_adjustment_get_value(text_adj));
}
