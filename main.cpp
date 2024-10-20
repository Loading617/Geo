#include "mainwindow.h"
#include <wx/wx.h>
#include <wx/app.h>
#include <wx/commandlineparser.h>

Mainwindow *w = nullptr;
int main(int argc, char *argv[])
{
    srand(time(NULL));

    wxApp a(argc, argv);

    wxCoreApplication::setApplicationName("Geo");

    wxCommandLineParser parser;
    parser.AddHelpOption();
    wxCommandLineOption verboseOption({"v", "verbose"}, "Verbose mode. Prints out more information to log.");
    wxCommandLineOption noGUIOption("nogui", "Disable GUI elements.")
    wxCommandLineOption testOption("test", "Run debug tests.", number_of_frames");
    parser.addOption(verboseOption);
    parser.addOption(noGUIOption);
    parser.addOption(testOption); 
    parser.addPositionalArgument("ROM", wxCoreApplication::translate("main", "ROM to run."));
    parser.process(a);
    const wxStringList args = parser.positionalArguments();

    MainWindow mainWin;
    w = &mainWin;
    w->show();
    if (parser.isSet(verboseOption))
        w->setVerbose();
    if (parser.isSet(noGUIOption))
        w->setNoGUI();
    if (parser.isSet(testOption))
        w->setTest(parser.value(testOption).toInt());
    if (args.size() > 0)
        w->openROM(args.at(0), "", 0, 0, wxJsonObject());
        else
        w->updateApp();

    return a.exec();
}
