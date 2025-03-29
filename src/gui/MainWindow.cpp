#include "MainWindow.hpp"
#include <iostream>

MainWindow::MainWindow() 
    : open_rom_button("Open ROM"),
      start_emulation_button("Start Emulation"),
      status_label("Status: Idle") {

    set_title("Geo");
    set_default_size(800, 600);

    vbox.set_orientation(Gtk::Orientation::VERTICAL);
    vbox.set_spacing(10);
    vbox.set_margin(10);

    open_rom_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_open_rom));
    start_emulation_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_start_emulation));

    vbox.append(open_rom_button);
    vbox.append(start_emulation_button);
    vbox.append(status_label);

    set_child(vbox);
}

MainWindow::~MainWindow() {}

void MainWindow::on_open_rom() {
    Gtk::FileChooserDialog dialog(*this, "Open GameCube ROM", Gtk::FileChooser::Action::OPEN);
    dialog.add_button("_Cancel", Gtk::ResponseType::CANCEL);
    dialog.add_button("_Open", Gtk::ResponseType::OK);

    auto filter = Gtk::FileFilter::create();
    filter->set_name("GameCube ROMs");
    filter->add_pattern("*.iso");
    filter->add_pattern("*.gcm");
    dialog.set_filter(filter);

    if (dialog.run() == Gtk::ResponseType::OK) {
        std::string filename = dialog.get_file()->get_path();
        if (emulator.load_game(filename)) {
            status_label.set_text("Loaded game: " + filename);
        } else {
            status_label.set_text("Failed to load game: " + filename);
        }
        status_label.set_text("Loaded ROM: " + filename);
        std::cout << "ROM Selected: " << filename << std::endl;
        }
    }

void MainWindow::on_start_emulation() {
    status_label.set_text("Emulation started...");
    cpu.reset();
    cpu.execute_instruction();
    emulator.run();
    std::cout << "Emulation started..." << std::endl;
}
