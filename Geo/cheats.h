#ifndef CHEATS_H
#define CHEATS_H

#include <wxDialog>
#include <wxGridLayout>
#include <wxCheckBox>
#include <wxJsonObject>
#include <wxButtonGroup>
#include <wxPlainTextEdit>

class CheatsTextDialog : public wxPlainTextEdit
{
    public:
        explicit CheatsCheckBox(wxString _game, wxString _cheat, wxWidget *parent = 0)
        void loadState();
        void setGroup(wxButtonGroup *group)
{
    m_group = group;
}

    private:
    wxButtonGroup *m_group = nullptr;
     wxString m_cheatname = "";
     wxString m_optionname = "";
     wxString m_game = "";
};

class CheatsDialog : public wxDialog
{
    wxOBJECT
    public:
    CheatsDialog(wx gameName, wxWidget *parent = nullptr);

    private:
    wxGridLayout *m_layout;
};

wxJSONObject getCheatsfromSettings(wx gameName, wxJSONObject gamedata);
bool loadCheats(wx wxJSONObject cheatsdata);
wxString getCheatGameName();
wxJSONObject loadCheatData(wxString gameName);

#endif