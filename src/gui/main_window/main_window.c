#include <stdio.h>
#include "main_window.h"
#include "menu/menu_bar.h"
#include "tool_bar/tool_bar.h"
#include "text_view/text_view.h"
#include "status_bar/status_bar.h"

GtkWidget *main_window;

GtkWidget *create_main_window()
{
    GtkWidget *vbox;
    GtkWidget *menu_bar;
    GtkWidget *tool_bar;
;   GtkWidget *text_view;
    GtkWidget *status_bar;

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Secure Note");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);

    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(main_window), vbox);

    menu_bar = create_menu_bar();
    gtk_box_pack_start(GTK_BOX(vbox), menu_bar, FALSE, FALSE, 0);

    tool_bar = create_tool_bar();
    gtk_box_pack_start(GTK_BOX(vbox), tool_bar, FALSE, FALSE, 0);

    text_view = create_text_view();
    gtk_box_pack_start(GTK_BOX(vbox), text_view, TRUE, TRUE, 0);

    status_bar = create_status_bar();
    gtk_box_pack_start(GTK_BOX(vbox), status_bar, FALSE, FALSE, 0);

    return main_window;
}