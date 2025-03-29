#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "../emulator/CPU.hpp"
#include "../emulator/Emulator.hpp"
#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    virtual ~MainWindow();

private:
    CPU cpu;
    void on_open_rom();
    void on_start_emulation();

    Emulator emulator;
    Gtk::Box vbox;
    Gtk::Button open_rom_button, start_emulation_button;
    Gtk::Label status_label;
};

#endif
