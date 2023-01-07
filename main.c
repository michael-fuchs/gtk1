#include <stdio.h>
#include <gtk/gtk.h>

static GtkWidget *number1;
static GtkWidget *number2;


static void add(GtkWidget *widget, gpointer data)
{
    int num1 = atoi(gtk_editable_get_text(GTK_EDITABLE(number1)));
    int num2 = atoi(gtk_editable_get_text(GTK_EDITABLE(number2)));
    int result = num1 + num2;
    char buffer[10];
    sprintf(buffer, "%d", result);
    gtk_editable_set_text(GTK_EDITABLE(number1), buffer);
    gtk_editable_set_text(GTK_ENTRY(number2), "");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);

    number1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number1, 0, 0, 1, 1);

    number2 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number2, 0, 1, 1, 1);

    button = gtk_button_new_with_label("Add");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

    g_signal_connect(button, "clicked", G_CALLBACK(add), NULL);

    gtk_widget_show(window);

}

int main(int argc, char **argv) {

    int status;

    GtkApplication *app = gtk_application_new("mifu.test", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return status;
}
