#include <gtk/gtk.h>
#include <stdio.h>
#include "gui.h"

GtkWidget *main_window;
GtkWidget *text_view;
GtkWidget *line_number_view;
GtkWidget *status_bar;

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

void create_main_window()
{
    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *menubar;
    GtkWidget *file_menu, *edit_menu, *help_menu;
    GtkWidget *file_menu_item, *edit_menu_item, *help_menu_item;
    GtkWidget *new_item, *open_item, *save_item, *quit_item;
    GtkWidget *undo_item, *redo_item, *cut_item, *copy_item, *paste_item;
    GtkWidget *about_item;
    GtkWidget *scrolled_window;
    GtkWidget *line_scrolled_window;

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Secure Note");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);

    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(main_window), vbox);

    menubar = gtk_menu_bar_new();

    file_menu = gtk_menu_new();
    file_menu_item = gtk_menu_item_new_with_label("File");

    new_item = gtk_menu_item_new_with_label("New");
    open_item = gtk_menu_item_new_with_label("Open");
    save_item = gtk_menu_item_new_with_label("Save");
    quit_item = gtk_menu_item_new_with_label("Quit");

    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), new_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file_menu_item);

    edit_menu = gtk_menu_new();
    edit_menu_item = gtk_menu_item_new_with_label("Edit");

    undo_item = gtk_menu_item_new_with_label("Undo");
    redo_item = gtk_menu_item_new_with_label("Redo");
    cut_item = gtk_menu_item_new_with_label("Cut");
    copy_item = gtk_menu_item_new_with_label("Copy");
    paste_item = gtk_menu_item_new_with_label("Paste");

    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), undo_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), redo_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), cut_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), copy_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), paste_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_menu_item), edit_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), edit_menu_item);

    help_menu = gtk_menu_new();
    help_menu_item = gtk_menu_item_new_with_label("Help");

    about_item = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_menu_item), help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help_menu_item);

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

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
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    status_bar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), status_bar, FALSE, FALSE, 0);

    g_signal_connect(gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view)), "changed", G_CALLBACK(update_line_numbers), NULL);

    g_signal_connect(new_item, "activate", G_CALLBACK(on_menu_file_new), NULL);
    g_signal_connect(open_item, "activate", G_CALLBACK(on_menu_file_open), NULL);
    g_signal_connect(save_item, "activate", G_CALLBACK(on_menu_file_save), NULL);
    g_signal_connect(quit_item, "activate", G_CALLBACK(on_menu_file_quit), NULL);

    g_signal_connect(undo_item, "activate", G_CALLBACK(on_menu_edit_undo), NULL);
    g_signal_connect(redo_item, "activate", G_CALLBACK(on_menu_edit_redo), NULL);
    g_signal_connect(cut_item, "activate", G_CALLBACK(on_menu_edit_cut), NULL);
    g_signal_connect(copy_item, "activate", G_CALLBACK(on_menu_edit_copy), NULL);
    g_signal_connect(paste_item, "activate", G_CALLBACK(on_menu_edit_paste), NULL);

    g_signal_connect(about_item, "activate", G_CALLBACK(on_menu_help_about), NULL);

    gtk_widget_show_all(main_window);
}

void on_menu_file_new(GtkWidget *widget, gpointer data) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, "", -1);
}

void on_menu_file_open(GtkWidget *widget, gpointer data) {
    g_print("Open file clicked\n");
}

void on_menu_file_save(GtkWidget *widget, gpointer data) {
    g_print("Save file clicked\n");
}

void on_menu_file_quit(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

void on_menu_edit_undo(GtkWidget *widget, gpointer data) {
    g_print("Undo clicked\n");
}

void on_menu_edit_redo(GtkWidget *widget, gpointer data) {
    g_print("Redo clicked\n");
}

void on_menu_edit_cut(GtkWidget *widget, gpointer data) {
    g_print("Cut clicked\n");
}

void on_menu_edit_copy(GtkWidget *widget, gpointer data) {
    g_print("Copy clicked\n");
}

void on_menu_edit_paste(GtkWidget *widget, gpointer data) {
    g_print("Paste clicked\n");
}

void on_menu_help_about(GtkWidget *widget, gpointer data) {
    GtkWidget *about_dialog;
    char *license_text = NULL;
    size_t license_text_len = 0;
    FILE *license_file;

    license_file = fopen("LICENSE", "r");
    if (license_file != NULL) {
        fseek(license_file, 0, SEEK_END);
        license_text_len = ftell(license_file);
        fseek(license_file, 0, SEEK_SET);

        license_text = (char *)malloc(license_text_len + 1);
        if (license_text) {
            fread(license_text, 1, license_text_len, license_file);
            license_text[license_text_len] = '\0';
        }
        fclose(license_file);
    } else {
        license_text = "License file not found";
    }

    about_dialog = gtk_about_dialog_new();

    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), "SecureNote");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(about_dialog), "v1.0");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about_dialog),
                                  "SecureNote là một ứng dụng ghi chú bảo mật, "
                                  "cho phép bạn tạo và lưu các ghi chú được mã hóa bằng mật khẩu.");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(about_dialog),
                                   "© 2024 SecureNote Development Team");
    gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(about_dialog),
                                 license_text);

    const gchar *authors[] = {"Phạm Ngọc Hải", NULL};

    gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(about_dialog), authors);
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(about_dialog), "https://github.com/haiphamcoder/secure-note");
    gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(about_dialog), "Project GitHub");

    gtk_window_set_transient_for(GTK_WINDOW(about_dialog), GTK_WINDOW(main_window));
    gtk_window_set_modal(GTK_WINDOW(about_dialog), TRUE);
    
    gtk_dialog_run(GTK_DIALOG(about_dialog));

    gtk_widget_destroy(about_dialog);

    if (license_text != NULL) {
        free(license_text);
    }
}