#include <gtk/gtk.h>

typedef struct {
    GtkWidget *w_rb_1;
    GtkWidget *w_rb_2;
    GtkWidget *w_rb_5;
    GtkWidget *w_lbl_choice;
} app_widgets;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    app_widgets     *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    widgets->w_rb_1 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_1"));
    widgets->w_rb_2 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_2"));
    widgets->w_rb_5 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_5"));
    widgets->w_lbl_choice = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_choice"));

    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

void on_btn_read_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgts->w_rb_1))) {
        gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_choice), "1%");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgts->w_rb_2))) {
        gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_choice), "2%");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgts->w_rb_5))) {
        gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_choice), "5%");
    }
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
