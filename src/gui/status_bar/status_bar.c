#include "status_bar.h"

GtkWidget *create_status_bar()
{
    GtkWidget *status_bar;

    status_bar = gtk_statusbar_new();

    return status_bar;
}