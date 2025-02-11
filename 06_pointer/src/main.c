#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}

void on_btn_print_txt_clicked(GtkButton *button, GtkLabel *text_label)
{
    gtk_label_set_text(text_label, "You clicked the button!");
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
