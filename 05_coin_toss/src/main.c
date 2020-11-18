#include <gtk/gtk.h>

GtkWidget *g_lbl_display;

void delay(int milli_seconds);

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_lbl_display = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_display"));

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_btn_flip_clicked()
{
    gboolean result;

    result = g_random_boolean();
    if (result == TRUE) {
        gtk_label_set_text(GTK_LABEL(g_lbl_display), "Heads");
    }
    else {
        gtk_label_set_text(GTK_LABEL(g_lbl_display), "Tails");
    }
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}