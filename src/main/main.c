#include <gtk/gtk.h>
#include "../gui/main_window/main_window.h"

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    gtk_widget_show_all(create_main_window());
    gtk_main();
    return 0;
}
