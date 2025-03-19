#include <gtkmm/application.h>
#include "gui/MainWindow.hpp"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("com.example.Geo");
    MainWindow window;
    return app->run(window);
}
