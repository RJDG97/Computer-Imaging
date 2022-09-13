#pragma once

void MyFrame::OnSave(wxCommandEvent& WXUNUSED(event))
{

}

void MyFrame::OnSaveAs(wxCommandEvent& WXUNUSED(event))
{

}

void MyFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
{

}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true is to force the frame to close
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format
    (
        "Welcome to %s!\n"
        "\n"
        "This is the CS 370 Assignment 1\n"
        "running under %s.",
        wxVERSION_STRING,
        wxGetOsDescription()
    ),
        "About wxWidgets minimal sample",
        wxOK | wxICON_INFORMATION,
        this);
}