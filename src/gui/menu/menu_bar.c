#include <gtk/gtk.h>
#include "menu_bar.h"

GtkWidget *main_window;

GtkWidget *create_menu_bar(GtkWidget *widget)
{
    main_window = widget;
    GtkWidget *menu_bar;
    GtkWidget *file_menu, *edit_menu, *help_menu;

    menu_bar = gtk_menu_bar_new();

    file_menu = create_file_menu();
    edit_menu = create_edit_menu();
    help_menu = create_help_menu();

    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), edit_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), help_menu);

    return menu_bar;
}

GtkWidget *create_file_menu()
{
    GtkWidget *file_menu;
    GtkWidget *file_menu_item, *file_menu_new_item,
        *file_menu_open_item, *file_menu_save_item, *file_menu_quit_item;

    file_menu = gtk_menu_new();
    file_menu_item = gtk_menu_item_new_with_label("File");

    file_menu_new_item = gtk_menu_item_new_with_label("New");
    file_menu_open_item = gtk_menu_item_new_with_label("Open");
    file_menu_save_item = gtk_menu_item_new_with_label("Save");
    file_menu_quit_item = gtk_menu_item_new_with_label("Quit");

    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_new_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_open_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_save_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_quit_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);

    g_signal_connect(file_menu_new_item, "activate", G_CALLBACK(on_menu_file_new), NULL);
    g_signal_connect(file_menu_quit_item, "activate", G_CALLBACK(gtk_main_quit), NULL);

    return file_menu_item;
}

GtkWidget *create_edit_menu()
{
    GtkWidget *edit_menu;
    GtkWidget *edit_menu_item, *edit_menu_undo_item,
        *edit_menu_redo_item, *edit_menu_cut_item, *edit_menu_copy_item,
        *edit_menu_paste_item;

    edit_menu = gtk_menu_new();
    edit_menu_item = gtk_menu_item_new_with_label("Edit");

    edit_menu_undo_item = gtk_menu_item_new_with_label("Undo");
    edit_menu_redo_item = gtk_menu_item_new_with_label("Redo");
    edit_menu_cut_item = gtk_menu_item_new_with_label("Cut");
    edit_menu_copy_item = gtk_menu_item_new_with_label("Copy");
    edit_menu_paste_item = gtk_menu_item_new_with_label("Paste");

    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_menu_undo_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_menu_redo_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_menu_cut_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_menu_copy_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_menu_paste_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_menu_item), edit_menu);

    return edit_menu_item;
}

GtkWidget *create_help_menu()
{
    GtkWidget *help_menu;
    GtkWidget *help_menu_item, *help_menu_about_item;

    help_menu = gtk_menu_new();
    help_menu_item = gtk_menu_item_new_with_label("Help");

    help_menu_about_item = gtk_menu_item_new_with_label("About");

    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), help_menu_about_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_menu_item), help_menu);

    g_signal_connect(help_menu_about_item, "activate", G_CALLBACK(on_menu_help_about), NULL);

    return help_menu_item;
}

void on_menu_file_new(GtkWidget *widget, gpointer data)
{
    g_print("New file clicked\n");
}

void on_menu_help_about(GtkWidget *widget, gpointer data)
{
    GtkWidget *about_dialog;
    char *license_text = NULL;
    size_t license_text_len = 0;
    FILE *license_file;

    license_file = fopen("LICENSE", "r");
    if (license_file == NULL)
    {
        license_file = fopen("/usr/local/share/secure-note/LICENSE", "r");
    }

    if (license_file != NULL)
    {
        fseek(license_file, 0, SEEK_END);
        license_text_len = ftell(license_file);
        fseek(license_file, 0, SEEK_SET);

        license_text = (char *)malloc(license_text_len + 1);
        if (license_text)
        {
            fread(license_text, 1, license_text_len, license_file);
            license_text[license_text_len] = '\0';
        }
        fclose(license_file);
    }
    else
    {
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

    if (license_text != NULL)
    {
        free(license_text);
    }
}